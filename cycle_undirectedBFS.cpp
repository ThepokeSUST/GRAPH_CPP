#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool BFS(vector<int> adj[],vector<int> &visit,int node){
     

     queue< pair<int,int> > q;
     q.push({ node ,-1});
     visit[node]=1;
     while(not q.empty()){
        int cur=q.front().first;
        int par=q.front().second;
        q.pop();
     for(int i=0;i<adj[cur].size();i++){

        if(adj[cur][i]==par) continue;

        if(visit[adj[cur][i]]){
            return true;
        }
        else{
            q.push({adj[cur][i],cur});
            visit[adj[cur][i]]=1;
        }
     }
}
return false;
}

void cycle(vector<int> adj[],int v){

    vector<int> visit(v,0);

    for(int i=0;i<v;i++){
        if(not visit[i]){
            if(BFS(adj,visit,i)){
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

   cycle(adj,v);

}