#include<iostream>
#include<vector>

using namespace std;

   bool DFS(vector<int> adj[],vector<int> & visit,vector<int> &path,int node,int par){
             
             visit[node]=1;
             path[node]=1;
             for(int i=0;i<adj[node].size();i++){
                 int cur=adj[node][i];
                 if(cur==par) continue;

                 if(path[cur]){
                    return true;
                 }
                 else{
                    if(not visit[cur])
                        if(DFS(adj,visit,path,cur,node))
                           return true;
                   
                 }
             }
              path[node]=0;
             return false;
   }

  void cycle(vector<int> adj[],int v){

    vector<int> visit(v,0);
    vector<int> path(v,0);
     for(int i=0;i<v;i++){
        if(not visit[i]){
             if(DFS(adj,visit,path,i,-1)){
                cout<<"YES";
                return;
             }
        }
     }

     cout<<"No";
     

  }
int main(){
    int v,e;
    cin>>v>>e;
    vector<int> adj[v];

    for(int i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
       adj[b].push_back(a);
    }
  
  cycle(adj, v);


}