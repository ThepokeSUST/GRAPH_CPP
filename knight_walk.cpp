#include<iostream>
#include<vector>
#include<queue>

using namespace std;
int A[]={-2,-2,1,-1,2,2,1,-1};
int B[]={1,-1,-2,-2,1,-1,2,2};

bool valid(int i,int j,int n){
return (i<n and j<n and i>=0 and j>=0);
}

int find(int n,int a,int b,int x,int y){
     queue< pair<int,int> > q;
     vector< vector<int> > visit(n,vector<int> (n,0));
     q.push({a,b});
     int ans=0;
     visit[a][b]=1;

     while(not q.empty()){
         
         int t=q.size();
         while(t--){
            int curi=q.front().first;
            int curj=q.front().second;
               q.pop();
            for(int k=0;k<8;k++){

                int newi=curi+A[k];
                int newj=curj+B[k];
                 if(newi==x and newj==y) return ans+1;
                if(valid(newi,newj,n) and not visit[newi][newj]){
                    visit[newi][newj]=1;
                    q.push({newi,newj});
                }
            }
         }
         ans++;
     }

     return -1;

}
void solve(){

  int n;
  cin>>n;
  
  int a,b,x,y;
  cin>>a>>b>>x>>y;

  cout<<find(n,a,b,x,y);




}
int main(){
    solve();
}