
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fi first
#define se second
#define rng(i,a,b) for(int i=int(a);i<=int(b);i++)
#define rep(i,b) rng(i,0,b-1)  
#define gnr(i,b,a) for(int i=int(b);i>=int(a);i--)
typedef long long ll;
#define MOD 1000000007

int ball[1505];
ll DP[1505][1505]; // [i][k] i번째 원소가 현재 pos이하. (0~i)원소 합쳐서 k번 이동. (0~i)의 배치의 경우의 수
int pos[1505]; // ball의 pos
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll n,k,t,cnt=0,res=0;
    cin>>n>>k;
    rng(i,0,n-1){
        cin>>t;
        if(t) pos[cnt++]=i;
    }
    rng(p,0,n-1){
        gnr(i,cnt-1,max(1LL,cnt-n+p)){
            int mv=abs(pos[i]-p);
            rng(j,mv,k){
                DP[i][j]=(DP[i][j]+DP[i-1][j-mv])%MOD;
            }
        }
        DP[0][abs(pos[0]-p)]++;
    }
    for(int j=k%2; j<=k; j+=2){
        res=(res+DP[cnt-1][j])%MOD;
    }
    cout<<(res+MOD)%MOD<<'\n';
}  
