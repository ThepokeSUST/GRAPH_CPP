#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;

void BFS_TRAVERSE(vector<int> adj[],int v){


  vector<int> visit(v,0);
 queue<int> q;
  q.push(0);
  visit[0]=1;
  
  while(!q.empty()){
    int cur=q.front();
    q.pop();
    cout<<cur<<" ";

    for(int i=0;i<adj[cur].size();i++)
      
      if(not visit[adj[cur][i]]){
        q.push(adj[cur][i]);
        visit[adj[cur][i]]=1;

      }


  }



}

int main(){
   int v,e;

   cin>>v>>e;
   vector<int> adj[v];

   map< char ,int > mp;
   int idx=0;
   for(int i=1;i<=e;i++){
     string str;
     cin>>str;

     if(mp.find(str[0])==mp.end()){
       mp[str[0]]=idx++;
     }
     if(mp.find(str[1])==mp.end()){
        mp[str[1]]=idx++;

     }
    //direacted unwaighted graph
     adj[mp[str[0]]].push_back(mp[str[1]]);
     
   }

   BFS_TRAVERSE(adj,v);

}