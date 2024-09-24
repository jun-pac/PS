
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define rng(i,a,b) for(int i=int(a);i<=int(b);i++)
#define gnr(i,b,a) for(int i=int(b);i>=int(a);i--)
typedef long long ll;
using pii=pair<int,int>;
using ull=unsigned long long;

ll profit[5050];
uint16_t datas[505][5050];
pii temp[5050];
ull small[5050][100];
ull cur_small[100];
ll DP[5050];

__attribute__((optimize("Ofast,unroll-loops"),target("avx,avx2,fma")))


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int m,n; // m : show, n : models
    cin>>m>>n;

    rng(i,0,n-1) cin>>profit[i];
    rng(i,0,m-1){
        rng(j,0,n-1) cin>>datas[i][j];
        rng(j,0,n-1) temp[j]={datas[i][j],j};
        rng(k,0,n/64) cur_small[k]=0; // maximum n/64+1

        sort(temp,temp+n);
        int cur=0;
        rng(j,0,n-1){
            while(temp[cur].fi<temp[j].fi){
                cur_small[temp[cur].se/64]|=((ull)1<<(temp[cur].se%64));
                cur++;
            }
            if(i==0) rng(k,0,n/64) small[temp[j].se][k]=cur_small[k];
            else rng(k,0,n/64) small[temp[j].se][k]=small[temp[j].se][k]&cur_small[k];
        }
    }
    fill(DP,DP+n,0);
    ll mx=0;
    rng(i,0,n-1){
        DP[temp[i].se]=profit[temp[i].se];
        rng(j,0,n-1){
            if(small[temp[i].se][temp[j].se/64]&((ull)1<<(temp[j].se%64))){
                DP[temp[i].se]=max(DP[temp[i].se],DP[temp[j].se]+profit[temp[i].se]);
            }
        }
        mx=max(mx,DP[temp[i].se]);
    }
    cout<<mx<<'\n';
    return 0;
}

