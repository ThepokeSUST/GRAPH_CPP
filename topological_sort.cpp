#include<iostream>
#include<vector>
#include<map>
#include<stack>

using namespace std;

void DFS(vector<int> adj[],int node,stack<int> &s,vector<int> &visited){
    visited[node]=1;
    for(int i=0;i<adj[node].size();i++){
        if(!visited[adj[node][i]]){
            DFS(adj,adj[node][i],s,visited);
        }
    }
    s.push(node);
}

vector<int> topo_sort(vector<int> adj[],int v){

    stack<int> s;
    vector<int> visited(v,0);
    for(int i=0;i<v;i++){
        if(!visited[i]){
            DFS(adj,i,s,visited);
        }
    }
    vector<int> ans;

    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
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

   for(auto ele: ans) cout<<rmp[ele]<<" ";
}