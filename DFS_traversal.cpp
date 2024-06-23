#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void DFS(vector<int> adj[],vector<int> &visit,int node,vector<int> &ans){
   
   visit[node]=1;
   ans.push_back(node);
   
   for(int i=0;i<adj[node].size();i++){

    if(not visit[adj[node][i]]){
        DFS(adj,visit,adj[node][i],ans);
    }
   }
}

int main(){

    int v,e;
    cin>>v>>e;
  vector<int> adj[v];
   

   for(int i=0;i<e;i++){
    int a,b;
    cin>>a>>b;

    adj[a].push_back(b);

   }
vector<int> visit(v,0);
vector<int> ans;

for(int i=0;i<v;i++){

    if(not visit[i])
      DFS(adj,visit,i,ans);

}
 

   for(auto ele: ans) cout<<ele<<" ";

}