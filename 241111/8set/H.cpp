
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007

ll DP[100][8];

int main(){
    ll n;
    cin>>n;
    ll res=1;
    
    // 2ĭ
    DP[0][2]=DP[0][1]=DP[0][0]=1;
    DP[0][3]=0;
    for(int i=1; i<=n; i++){
        DP[i][0]=DP[i-1][0]+DP[i-1][1]+DP[i-1][2];
        DP[i][1]=DP[i-1][0]+DP[i-1][2];
        DP[i][2]=DP[i-1][0]+DP[i-1][1];
        DP[i][3]=0;    
        for(int j=0; j<4; j++) DP[i][j]%=MOD;
    }
    res=res*DP[n][0]%MOD*DP[n][0]%MOD;

    // 3ĭ
    DP[0][5]=DP[0][4]=DP[0][1]=DP[0][2]=DP[0][0]=1;
    DP[0][3]=DP[0][6]=DP[0][7]=0;
    for(int i=1; i<=n; i++){
        DP[i][0]=DP[i-1][0]+DP[i-1][1]+DP[i-1][2]+DP[i-1][4]+DP[i-1][5];
        DP[i][1]=DP[i-1][0]+DP[i-1][2]+DP[i-1][4];
        DP[i][2]=DP[i-1][0]+DP[i-1][1]+DP[i-1][4]+DP[i-1][5];
        DP[i][4]=DP[i-1][0]+DP[i-1][1]+DP[i-1][2];
        DP[i][5]=DP[i-1][0]+DP[i-1][2];
        DP[0][3]=DP[0][6]=DP[0][7]=0;
        for(int j=0; j<4; j++) DP[i][j]%=MOD;
    }
    res=res*DP[n][0]%MOD;
    
    // Ans
    cout<<(res+MOD)%MOD<<'\n';
    return 0;
}

