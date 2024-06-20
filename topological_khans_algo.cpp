#include<iostream>
#include<vector>
#include<map>
#include<queue>

using namespace std;

vector<int> indegree(vector<int> adj[],int v){
    vector<int> inDeg(v,0);
    vector<int> visited(v,0);
    for(int i=0;i<v;i++){
         
         for(int j=0;j<adj[i].size();j++){
            inDeg[adj[i][j]]++;
         }
     
        }
        return inDeg;
    }


vector<int> topo_sort(vector<int> adj[],int v){

      vector<int> inDeg=indegree(adj,v);
      vector<int> ans;
      queue<int> q;

      for(int i=0;i<v;i++){

        if(inDeg[i]==0){
            q.push(i);
        }
       
      }

      while(!q.empty()){
        int node=q.front();
        ans.push_back(node);
        q.pop();

        for(int i=0;i<adj[node].size();i++){

            inDeg[adj[node][i]]--;
            if(inDeg[adj[node][i]]==0){
                q.push(adj[node][i]);
            }
        }
      }

      return ans;
}

int main(){

   int v,e;
   cin>>v>>e;
   map<char,int> mp;
   map<int,char> rmp;
   for(int i=0;i<v;i++){
    char ch=65+i;
    mp[ch]=i;
    rmp[i]=ch;
   } 
   vector<int> adj[v];

   for(int i=0;i<e;i++){
    string str;
    cin>>str;
    adj[mp[str[0]]].push_back(mp[str[1]]);  
   }
  
  vector<int> ans=topo_sort(adj,v);
  
  for(int i=0;i<v;i++){
    cout<<rmp[ans[i]]<<" ";
  }
}