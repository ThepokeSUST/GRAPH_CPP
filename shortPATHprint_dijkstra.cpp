#include<bits/stdc++.h>

using namespace std;



void short_path(vector<pair<int,int>> adj[],int st,int en,int v,map<int,char> rmp){

   vector<bool> visit(v,0);
   vector<int> dis(v,INT_MAX);
   vector<int> par(v);
   
   priority_queue< pair<int,int> ,vector<pair<int,int>> , greater<pair<int,int>>> q;
   
   dis[st]=0;
   par[st]=-1;

   q.push({0,st});

   while(!q.empty()){
   
    int cur=q.top().second;
    q.pop(); 
    if(visit[cur]) continue;

    visit[cur]=1;
   
    for(int i=0;i<adj[cur].size();i++){
           int node=adj[cur][i].first;
           int value=adj[cur][i].second;
        if(!visit[node] and dis[node]> dis[cur]+value){
            dis[node]=value+dis[cur];
            par[node]=cur;
            q.push({dis[node],node});
        }
        
    }



   }

stack<int> stk;
int idx=en;

while(idx>-1){
    stk.push(idx);
    idx=par[idx];
    
}



  cout<<"distance "<<dis[en]<<endl;

   while(!stk.empty()){
    cout<<rmp[stk.top()]<<" -";
    stk.pop();
   }
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
    vector< pair<int,int> > adj[v];


    for(int i=0;i<e;i++){
        string str;
        cin>>str;
       int cost;
       cin>>cost;

       adj[mp[str[0]]].push_back({mp[str[1]],cost});
       adj[mp[str[1]]].push_back({mp[str[0]],cost});

    }

   char st,ds;
   cin>>st>>ds;
  
  short_path(adj,mp[st],mp[ds],v,rmp);


}