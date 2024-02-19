// 
//./E<test

#include <bits/stdc++.h>
#define endl '\n'
#define cediv(a,b) ((a)%(b)==0?((a)/(b)):((a)/(b))+1)
#define fi first
#define se second
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++) 

int dx[4] = {-1,1,0,0}; 
int dy[4] = {0,0,-1,1}; 





using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;

template<typename T>
inline T umax(T &u, T v){return u = max(u, v);}
template<typename T>
inline T umin(T &u, T v){return u = min(u, v);}

int r,c,n; 

const int MAXN = 502; 
int a[MAXN][MAXN]; 
int trap[MAXN][MAXN]; 
int hosu[MAXN][MAXN]; 
int dp[MAXN][MAXN][20]; 
const int inf = 1e9; 

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> r >> c >> n; 
    rep(i,r){
        rep(j,c) {
            cin >> a[i][j]; 
            rep(k,20) dp[i][j][k] = inf; 
        }
    }
    rep(i,r){
        rep(j,c){
            int flag = 1; 
            for(int k=0;k<4;k++){
                // k=0,1 일 때 a 값이 더 작아야됨 
                
                if(k==0 || k==1){
                    if(i+dx[k]<0||i+dx[k]>r) flag=0; 
                    if(a[i+dx[k]][j]==-1 ) flag = 0; 
                    if(a[i+dx[k]][j] >= a[i][j]) flag = 0; 
                }
                if(k==2 || k==3){
                    if(j+dy[k]<0||j+dy[k]>c) flag=0; 
                    if(a[i][j+dy[k]]==-1 ) flag = 0; 
                    if(a[i][j+dy[k]] >= a[i][j]) flag = 0; 
                }
            }
            hosu[i][j] = flag; 
        }
    }
    rep(i,r) dp[i][c][0] = 0; 
    for(int l=c-1;l>=0;l--){
        rep(i,r){
            if(a[i][l]==-1) continue; 
            rep(k,11){
                if(hosu[i][l]==1){
                    if(k==0) continue; 
                    dp[i][l][k] = a[i][l] + min({dp[i+1][l][k-1],dp[i][l][k-1],((i==0)? inf : dp[i-1][l][k-1])}); 
                }
                else { 
                    dp[i][l][k] = a[i][l] + min({dp[i+1][l][k],dp[i][l][k],((i==0)? inf : dp[i-1][l][k])}); 
                }
            }
        }
    }
    int m = inf; 
    for(int i=0;i<r;i++){
        m = min(m, dp[i][0][n]); 
    }
    if(m==inf) cout << "impossible"; 
    else cout << m; 


    return 0;
}