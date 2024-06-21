#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool DFS(vector<int> adj[],vector<int> &visit,int node,int par){
      
  visit[node]=1;

  for(int i=0;i<adj[node].size();i++){
    if(adj[node][i]==par) continue;

    if(visit[adj[node][i]]){
        return true;

    }
    else{
        if(DFS(adj,visit,adj[node][i],node))
        return true;
    }
  }
         
return false;

}


void cycle(vector<int> adj[],int v){

    vector<int> visit(v,0);

    for(int i=0;i<v;i++){

        if(!visit[i]){
           if( DFS(adj,visit, i,-1)){
           cout<<"YES";
           return;
           } 
        }
    }

    cout<<"NO";
  
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