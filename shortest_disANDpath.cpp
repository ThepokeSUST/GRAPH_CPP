#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<stack>

using namespace std;
 
void  short_path(vector<int> adj[],map<char,int> &mp,map<int,char> rmp,int v,char st,char ds){

   vector<int> visit(v,0);
   vector<int> dis(v);
   vector<int> par(v);
    
   visit[mp[st]]=1;
   dis[mp[st]]=0;
   par[mp[st]]=-1;
  
  queue<int> q;
  q.push(mp[st]);
   
   while(!q.empty()){
      int cur=q.front();
      q.pop();

      for(int i=0;i<adj[cur].size();i++){
        if(visit[adj[cur][i]]==0){
          q.push(adj[cur][i]);
          par[adj[cur][i]]=cur;
          dis[adj[cur][i]]=1+dis[cur];
        }
        if(adj[cur][i]==mp[ds]){
          goto level;
        }
      }

   }
   level:
   stack<int> path;

    int D=mp[ds];
    while(D!=-1){
      path.push(D);
      D=par[D];
    }
   
    cout<<"distence "<<dis[mp[ds]]<<endl;
   cout<<"path->";
    while(!path.empty()){
      cout<<rmp[path.top()]<<"-";
      path.pop();
    } 

 }

int main(){

 int v,e;

   cin>>v>>e;
   vector<int> adj[v];

   map< char ,int > mp;
   map<int,char> rmp;
   int idx=0;
   for(int i=1;i<=e;i++){
     string str;
     cin>>str;

     if(mp.find(str[0])==mp.end()){
       mp[str[0]]=idx++;
       rmp[mp[str[0]]]=str[0];
     }
     if(mp.find(str[1])==mp.end()){
        mp[str[1]]=idx++;
        rmp[mp[str[1]]]=str[1];

     }
    //direacted unwaighted graph
     adj[mp[str[0]]].push_back(mp[str[1]]);
         
   }

   char st,en;
   cout<<"enter source and distance ";
   cin>>st>>en;
    short_path(adj,mp,rmp,v,st,en);

   
}