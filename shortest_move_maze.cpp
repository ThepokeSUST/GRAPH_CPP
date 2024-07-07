#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int A[]={0,0,1,-1};
int B[]={1,-1,0,0};

bool valid(int i,int j,int n,int m){
     
     return i<n and j<m and i>=0 and j>=0;
}
int find(vector< vector<int>> &v,int st,int en,int x,int y,int n,int m){
     
     if(x==0 and y==0) return 0;

     if(v[0][0]==0) return -1;
     

     queue< pair<int ,int> > q;
     // v[0][0]=0;
      q.push({0,0});
       v[0][0]=0;
     int ans=0;
      while( not q.empty()){
         
        int t=q.size();
        while(t--){
          int a=q.front().first;
          int b=q.front().second;
          q.pop();
         

          for(int k=0;k<4;k++){
            int newi=a+A[k];
            int newj=b+B[k];

            if(newi==x and newj==y) return ans+1;

            if( valid(newi,newj,n,m) and v[newi][newj]){
                 v[newi][newj]=0;
                 q.push({newi,newj});
            }
    
          }
        
            
        }
          ans++;

      }

      return -1;

}

void solve(){

    int n,m;
    cin>>n>>m;

    vector< vector<int> > v(n,vector<int> (m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cin>>v[i][j];
    }
    //sourse (0,0)...
    int x,y;
    cin>>x>>y;
    cout<<find(v,0,0,x,y,n,m);
}

int main(){
    solve();
}