
#include <bits/stdc++.h>
using namespace std;
#define rng(i,a,b) for(int i=int(a);i<=int(b);i++)
#define gnr(i,b,a) for(int i=int(b);i>=int(a);i--)
typedef long long ll;
__attribute__((optimize("Ofast,unroll-loops"),target("avx,avx2,fma")))

ll INF=1000000007;
ll datas[101], sum[101];
ll DP[101][101][101];
ll DP_ij[101][101];

ll get_DP(int i, int j, int num_last){
    if(num_last==1){
        assert(i<=j && DP_ij[i][j]!=-1);
        return min(INF,DP_ij[i][j]+sum[j]-(i==0?0:sum[i-1]));
    }
    if(DP[i][j][num_last]!=-1) return DP[i][j][num_last];
    assert(i<j);
    int len=j-i+1;
    if(num_last>len) return DP[i][j][num_last]=INF;
    if(num_last==len) return DP[i][j][num_last]=sum[j]-(i==0?0:sum[i-1]);
    ll res=INF;
    rng(k,1,len-(num_last-1)){
        res=min(res,get_DP(i,j-k,num_last-1)+get_DP(j-k+1,j,1));
    }
    return DP[i][j][num_last]=res;
}

void Solve(){
    int n,l,r;
    cin>>n>>l>>r;
    rng(i,0,n-1) cin>>datas[i];
    //sort(datas,datas+n);
    rng(i,0,n-1) rng(j,0,n-1) fill(DP[i][j],DP[i][j]+n+1,-1);
    rng(i,0,n-1) fill(DP_ij[i],DP_ij[i]+n,-1);
    rng(i,0,n-1) sum[i]=(i==0?0:sum[i-1])+datas[i];

    // Main DP
    rng(i,0,n-1) DP_ij[i][i]=0;
    rng(i,1,n-1){ // i+1°³¸¦ ´Ù·é´Ù.
        rng(j,0,n-1-i){
            ll mn=INF;
            rng(num_last,l,r){
                //cout<<"in DP[i][j] "<<j<<' '<<j+i<<' '<<num_last<<'\n';
                mn=min(mn,get_DP(j,j+i,num_last));
                //cout<<"out DP[i][j] "<<j<<' '<<j+i<<' '<<num_last<<' '<<DP[j][j+i][num_last]<<'\n';
            }
            DP_ij[j][j+i]=mn;
        }
    }
    cout<<(DP_ij[0][n-1]>=INF?0:DP_ij[0][n-1])<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    //cin>>t;
    while(t--){
        Solve();
    }
    return 0;
}

