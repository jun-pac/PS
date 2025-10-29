
#include <bits/stdc++.h>
using namespace std;
#define rng(i,a,b) for(int i=a;i<=b;i++)
#define gnr(i,b,a) for(int i=b;i>=a;i--)
#define N 830
#define INF 1000000007 

int DP[N][N];
int datas[N];

int DFS(int l, int r){
    if(l>=r) return 0;
    if(DP[l][r]!=-1) return DP[l][r];
    
    int idx=l+1; // first position with datas[idx]!=datas[l]
    while(idx<=r && datas[idx]==datas[l]) idx++;
    if(idx>r) return DP[l][r]=0;

    int res=INF;
    rng(k,idx,r){
        // if(l==6 && r==7) cout<<"67 "<<k<<' '<<DFS(l,idx-1)<<' '<<DFS(idx,k)<<' '<<
        res=min(res,DFS(l,idx-1)+DFS(idx,k)+1+(k+1<=r?DFS(k+1,r)+(datas[k+1]==datas[l]?0:1):0));
    }
    DP[l][r]=res;
    // cout<<"DP "<<l<<' '<<r<<' '<<DP[l][r]<<'\n';
    return DP[l][r];
}


int main(){
    int n;
    cin>>n;
    rng(i,0,n-1) cin>>datas[i+1];
    rng(i,0,n) rng(j,i,n) DP[i][j]=-1;
    cout<<DFS(0,n)<<'\n';
}

