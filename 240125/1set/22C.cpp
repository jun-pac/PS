
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
#define INF 1000000007 

int sum[4];
int wins[4];
int dd[10][10];
int n,m;

array<int,9> memo[10];

void compete(int a, int b, int idx){
    int ch=0, wa=0, wb=0;
    int mxa=-1, mxb=-1, mxidxa, mxidxb;
    rng(u,0,m-1) if(mxa<dd[a][u]) mxa=dd[a][u], mxidxa=u;
    rng(u,0,m-1) if(mxb<dd[b][u]) mxb=dd[b][u], mxidxb=u;
    if(sum[a]>sum[b]) wins[a]++, wa=1;
    if(sum[a]<sum[b]) wins[b]++, wb=1;
    if((wa && mxa>mxb) || (wb && mxa<mxb)){
        ch=1;
        dd[a][mxidxa]=mxb;
        dd[b][mxidxb]=mxa;
        sum[a]=sum[a]+mxb-mxa;
        sum[b]=sum[b]+mxa-mxb;
    }
    memo[idx]={a,b,ch,wa,wb,mxa,mxb,mxidxa,mxidxb};
}

void back(int idx){
    int a=memo[idx][0], b=memo[idx][1], ch=memo[idx][2], wa=memo[idx][3], wb=memo[idx][4];
    int mxa=memo[idx][5], mxb=memo[idx][6], mxidxa=memo[idx][7], mxidxb=memo[idx][8];
    if(wa) wins[a]--;
    if(wb) wins[b]--;
    if(ch){
        dd[a][mxidxa]=mxa;
        dd[b][mxidxb]=mxb;
        sum[a]=sum[a]+mxa-mxb;
        sum[b]=sum[b]+mxb-mxa;
    }    
}


int solution(vector<vector<int>> datas) {
    int ans = 0;
    n = datas.size();
    m = datas.size();
    rng(i,0,n-1) rng(j,0,m-1) dd[i][j]=datas[i][j];
    rng(i,0,n-1){
        int s=0;
        rng(j,0,m-1) s+=dd[i][j];
        sum[i]=s;
    }

    vc<pii> cp;
    cp.pb({0,1});
    cp.pb({1,2});
    cp.pb({2,0});
    cp.pb({3,0});
    cp.pb({3,1});
    cp.pb({3,2});
    rng(i,0,3) wins[i]=0;
    if(n==3){
        rng(i,0,2){
            int a=cp[i].fi, b=cp[i].se; compete(a,b,0);
            rng(j,0,2){
                int a=cp[j].fi, b=cp[j].se; compete(a,b,1);
                rng(k,0,2){
                    int a=cp[k].fi, b=cp[k].se; compete(a,b,2);
                    bool flag=1;
                    rng(u,0,n-1) if(wins[u]==0) flag=0;
                    if(flag) ans++; 
                    back(2);
                }
                back(1);
            }
            back(0);
        }
    }
    if(n==4){
        rng(i,0,5){
            int a=cp[i].fi, b=cp[i].se; compete(a,b,0);
            rng(j,0,5){
                int a=cp[j].fi, b=cp[j].se; compete(a,b,1);
                rng(k,0,5){
                    int a=cp[k].fi, b=cp[k].se; compete(a,b,2);
                    rng(r,0,5){
                        int a=cp[r].fi, b=cp[r].se; compete(a,b,3);
                        bool flag=1;
                        rng(u,0,n-1) if(wins[u]==0) flag=0;
                        if(flag) ans++; 
                        back(3);
                    }
                    back(2);
                }
                back(1);
            }
            back(0);
        }
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vc<vc<int>> dd(n);
    rng(i,0,n-1) dd[i].resize(m);
    rng(i,0,n-1){
        rng(j,0,m-1) cin>>dd[i][j]; 
    }
    cout<<solution(dd)<<'\n';
    return 0;
}

