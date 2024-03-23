
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define cediv(a,b) ((a)%(b)==0?((a)/(b)):((a)/(b))+1)
#define rng(i,a,b) for(int i=int(a);i<=int(b);i++)
#define rep(i,b) rng(i,0,b-1)  
#define gnr(i,b,a) for(int i=int(b);i>=int(a);i--)
#define per(i,b) gnr(i,b-1,0)
#define pb push_back
#define eb emplace_back
#define bg begin()
#define ed end()
#define all(x) x.bg,x.ed
#define si(x) int(x.size())
template<class t> using vc=vector<t>;
template<class t> using vvc=vc<vc<t>>;
typedef long long ll;
using pii=pair<int,int>;
using vi=vc<int>;
using uint=unsigned;
using ull=unsigned long long;
using pil=pair<int,ll>;
using pli=pair<ll,int>;
using pll=pair<ll,ll>;
using t3=tuple<int,int,int>;

#define N 300030
#define MOD 998244353
#define INF 1000000000000007 
// DP에서, 나까지 오는 최소의 cost, "현재 남은 비용", "나까지 오는데 필요한 최대의 cost"를 고려해야 함.

vc<pii> dir;
ll P[100][100],R[100][100],D[100][100];
pll DP[6400][6400]; // DP[idx][maxp_idx]={min_step, min_leftover given min_step};

void Solve(){
    int n;
    cin>>n;
    rng(i,0,n-1){
        rng(j,0,n-1){
            cin>>P[i][j];
        }
    }
    rng(i,0,n-1){
        rng(j,0,n-2){
            cin>>R[i][j];
        }
    }
    rng(i,0,n-2){
        rng(j,0,n-1){
            cin>>D[i][j];
        }
    }

    rng(i,0,n*n-1){
        rng(j,0,n*n-1) DP[i][j]={INF,0};
    }
    DP[0][0]={0,0};

    rng(i,0,n-1){
        rng(j,0,n-1){
            // DP[i*n+j] <- DP[(i-1)*n+j]
            int idx=i*n+j;
            if(i!=0){
                int pastidx=(i-1)*n+j;
                rng(ii,0,i-1){
                    rng(jj,0,j){
                        int maxp_idx=ii*n+jj;
                        if(DP[pastidx][maxp_idx].fi>=INF) continue;

                        int new_maxp_idx=(P[i][j]>P[ii][jj]?idx:maxp_idx);
                        ll cur_step=DP[pastidx][maxp_idx].fi;
                        ll cur_left=DP[pastidx][maxp_idx].se;
                        if(cur_left>=D[i-1][j]){
                            cur_step++;
                            cur_left-=D[i-1][j];
                        }
                        else{
                            ll temp=cediv(D[i-1][j]-cur_left,P[ii][jj]);
                            cur_step+=temp+1;
                            cur_left=cur_left+temp*P[ii][jj]-D[i-1][j];
                        }
                        pll tt={cur_step,cur_left};
                        if(tt<=DP[idx][new_maxp_idx]){
                            DP[idx][new_maxp_idx]=tt;
                        }
                    }
                }
            }
            if(j!=0){
                int pastidx=i*n+j-1;
                rng(ii,0,i){
                    rng(jj,0,j-1){
                        int maxp_idx=ii*n+jj;
                        if(DP[pastidx][maxp_idx].fi>=INF) continue;

                        int new_maxp_idx=(P[i][j]>P[ii][jj]?idx:maxp_idx);
                        ll cur_step=DP[pastidx][maxp_idx].fi;
                        ll cur_left=DP[pastidx][maxp_idx].se;
                        if(cur_left>=R[i][j-1]){
                            cur_step++;
                            cur_left-=R[i][j-1];
                        }
                        else{
                            ll temp=cediv(R[i][j-1]-cur_left,P[ii][jj]);
                            cur_step+=temp+1;
                            cur_left=cur_left+temp*P[ii][jj]-R[i][j-1];
                        }
                        pll tt={cur_step,cur_left};
                        if(tt<=DP[idx][new_maxp_idx]){
                            DP[idx][new_maxp_idx]=tt;
                        }
                    }
                }
            }
        }
    }
    ll res=INF;
    rng(i,0,n*n-1) res=min(res,DP[n*n-1][i].fi);
    cout<<res<<'\n';
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

