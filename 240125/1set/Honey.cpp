
#include <bits/stdc++.h>
using namespace std;
#define rng(i,a,b) for(int i=int(a);i<=int(b);i++)
#define rep(i,b) rng(i,0,b-1)  
#define gnr(i,b,a) for(int i=int(b);i>=int(a);i--)
#define per(i,b) gnr(i,b-1,0)

int ans[2000][2000];

void fill_hex(int n, int x, int y, int val){
    if(n==1){
        ans[x][y]=val;
        return;
    }
    // ans[x][y]=valÀÓ
    rng(i,0,n-2) ans[x+i][y+i]=val++;
    rng(i,0,n-2) ans[x+n-1+2*i][y+n-1]=val++;
    rng(i,0,n-2) ans[x+3*n-3+i][y+n-1-i]=val++;
    rng(i,0,n-2) ans[x+4*n-4-i][y-i]=val++;
    rng(i,0,n-2) ans[x+3*n-3-2*i][y-n+1]=val++;
    rng(i,0,n-2) ans[x+n-1-i][y-n+1+i]=val++;
    fill_hex(n-1,x+2,y,val);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin>>n;
    int cnt=0;
    fill_hex(n,0,n-1,1);   
    rng(i,0,n-1){
        int num=i+1;
        rng(j,0,num-1) cout<<ans[i][n-num+2*j]<<' ';
    }
    rng(i,n,3*n-4){
        if(i%2==n%2) rng(j,0,n-2) cout<<ans[i][1+2*j]<<' ';
        else rng(j,0,n-1) cout<<ans[i][2*j]<<' '; 
    }
    rng(i,3*n-3,4*n-4){
        int num=4*n-3-i;
        rng(j,0,num-1) cout<<ans[i][n-num+2*j]<<' ';
    }
    cout<<'\n';
    return 0;
}

