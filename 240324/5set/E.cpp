
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

#define N 200030
#define MOD 998244353
ll INF=100000000000007;
ll col[N];
ll val[N];
pll mxval[N];
ll DP[N][501]; // [i][j] : i는 제거가 안됨. 앞에서 j개를 제거
ll sum[N];
set<pll> mnset[N];

void Solve(){
    int n,k;
    cin>>n>>k;
    rng(i,0,n-1) cin>>col[i]>>val[i];
    int last_col=col[0];
    int last_idx=0;
    int mn_k=0;
    ll cur_mx=val[0];
    int nn=0;

    rng(i,1,n-1){
        if(col[i]!=last_col){
            mxval[nn++]={last_col,cur_mx};
            mn_k+=i-last_idx-1;
            last_col=col[i];
            cur_mx=val[i];
            last_idx=i;
        }
        else{
            cur_mx=max(cur_mx,val[i]);
        }
    }
    mxval[nn++]={last_col,cur_mx};
    mn_k+=n-last_idx-1;
    //cout<<"mn_k "<<mn_k<<'\n';

    if(k<mn_k) cout<<-1<<'\n';
    else{
        int m=k-mn_k;
        n=nn;
        //cout<<"nm "<<n<<' '<<m<<'\n';
        rng(i,0,n-1) sum[i]=(i==0?0:sum[i-1])+mxval[i].se;
        if(m==0){
            cout<<sum[n-1]<<'\n';
            return;
        }
        if(m==n){
            cout<<0<<'\n';
            return;
        }
        rng(i,0,n) fill(DP[i],DP[i]+m+1,INF);
        DP[0][0]=0;
        mnset[0].insert({sum[n-1]-sum[0],mxval[0].fi}); // 값, color

        rng(i,1,n-1){
            rng(j,0,min(m,i)){
                // rng(dd,0,j){
                //     if(i-dd-1==-1) DP[i][j]=sum[i-1];
                //     else if(mxval[i-dd-1].fi!=mxval[i].fi) DP[i][j]=min(DP[i][j],DP[i-dd-1][j-dd]+sum[i-1]-sum[i-dd-1]);
                // }
                if(j==0) DP[i][j]=0;
                else if(i==j) DP[i][j]=sum[i-1];
                else{
                    auto it=mnset[(i-1-j)].begin();
                    if(it->se==mxval[i].fi){
                        if(mnset[(i-1-j)].size()>=2){
                            DP[i][j]=(next(it)->fi)-(sum[n-1]-sum[i-1]);
                        }
                    }
                    else DP[i][j]=(it->fi)-(sum[n-1]-sum[i-1]);
                }

                if(j==0) mnset[i].clear();
                if(!mnset[(i-j)].empty() && mnset[(i-j)].begin()->se==mxval[i].fi){
                    auto it=mnset[(i-j)].begin();
                    if(DP[i][j]+sum[n-1]-sum[i]<(it->fi)){
                        mnset[(i-j)].erase(*it);
                        mnset[(i-j)].insert({DP[i][j]+sum[n-1]-sum[i],mxval[i].fi});
                    } 
                }
                else mnset[(i-j)].insert({DP[i][j]+sum[n-1]-sum[i],mxval[i].fi});
            }
        }
        ll m_del_mn=DP[n-1][m];
        rng(i,1,m) m_del_mn=min(m_del_mn,DP[n-1-i   ][m-i]+sum[n-1]-sum[n-1-i]);
        cout<<sum[n-1]-m_del_mn<<'\n';
    }

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

