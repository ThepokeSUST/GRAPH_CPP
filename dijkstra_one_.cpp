#include<iostream>
#include<vector>
#include<map>

using namespace std;

   vector<int> shortest_path(vector< pair<int,int> > adj[],map<char,int> &mp ,char st,int v){
            
            vector<int> visit(v,0);
            vector<int> dis( v, INT_FAST32_MAX);

            dis[ mp[st]]=0;

            for(int i=0;i<v-1;i++){
               
               int idx=-1;
               int value=INT32_MAX;
               for(int K=0;K<v;K++){
                if(!visit[K] and dis[K]<value){
                    idx=K;
                    value=dis[K];
                }
               }
               if(idx==-1) break;

              visit[idx]=1;

               for(int J=0;J<adj[idx].size();J++){
                    
                    if(!visit[adj[idx][J].first] and dis[ adj[idx][J].first ]> dis[idx]+adj[idx][J].second){
                        dis[adj[idx][J].first]=dis[idx]+adj[idx][J].second;
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
        cin>>str>>cost;

        adj[mp[str[0]]].push_back({mp[str[1]],cost});
        adj[mp[str[1]]].push_back({mp[str[0]],cost});

    }
  
  char st;
  cin>>st;
   
vector<int> ans=shortest_path(adj,mp,st,v);
  
for(auto ele:ans) cout<<ele<<" ";
}