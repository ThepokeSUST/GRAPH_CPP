#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<utility>
#include<climits>
using namespace std;
vector<int> short_path(vector<pair<int,int> > adj[],int st,int v){
   
   vector<int> visit(v,0);
   vector<int> dis(v,INT32_MAX);

   priority_queue< pair<int,int>  , vector<pair<int,int> > ,greater<pair<int,int>>> q;

   q.push({0,st});
   dis[st]=0;

   for(int j=0;j<v-1;j++){
    
    int idx= q.top().second;
  //  cout<<idx<<endl;
    q.pop();

    if(visit[idx]==1) continue;

    visit[idx]=1;
        
        
       for(int i=0;i<adj[idx].size();i++){
            int cur=adj[idx][i].first;
            int value=adj[idx][i].second;

           if(!visit[cur] and dis[cur]> dis[idx]+value)
             {dis[cur]=dis[idx]+value;
               q.push({dis[cur],cur});
             }

       }

   

   }

return dis;
} 
int main(){

    
    int v,e; //v stands for vertex & e stands for edge...... 
    cin>>v>>e;
    
    map<char,int> mp;
    map<int,char> rmp;
    //we assume that vertexs denoted as a upper case letters......
    for(int i=0;i<v;i++){
        char ch=65+i;
        mp[ch]=i;
        rmp[i]=ch;
    }
    //now constract adj list for undirected graph
    vector< pair<int,int> > adj[v];
    for(int i=0;i<e;i++){

        string str;
        int cost;
        cin>>str>> cost;

        adj[mp[str[0]]].push_back({mp[str[1]],cost});
        adj[mp[str[1]]].push_back({mp[str[0]],cost});

    }
  
  char st;
  cin>>st;

  vector<int> ans=short_path(adj,mp[st],v);

  for(auto ele: ans) cout<<ele<<" ";


}