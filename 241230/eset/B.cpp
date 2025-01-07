
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
random_device rd; 
mt19937 gen(rd());
uniform_int_distribution<> dist(0, INF); // random integer from [0, INF] // dist(gen)

pii datas[N];
int val[N];
int cnt[400040];
int is_sum[400040];

void Solve(){
    int n;
    cin>>n;
    rng(i,0,n-1) cin>>datas[i].fi>>datas[i].se;
    rng(i,0,n-1){
        if(datas[i].fi==datas[i].se) val[i]=datas[i].fi;
        else val[i]=-1;
    }
    fill(cnt,cnt+2*n+1,0);
    fill(is_sum,is_sum+2*n+1,0);
    rng(i,0,n-1) if(val[i]!=-1) cnt[val[i]]++;
    rng(i,0,2*n) is_sum[i]=(i==0?0:is_sum[i-1])+(cnt[i]==0?0:1);
    rng(i,0,n-1){
        if(val[i]==-1){
            if(is_sum[datas[i].se]-is_sum[datas[i].fi-1]==datas[i].se-datas[i].fi+1){
                cout<<0;
            }
            else cout<<1;
        }
        else{
            if(cnt[val[i]]==1) cout<<1;
            else cout<<0;
        }
    } 
    cout<<'\n';

}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--){
        Solve();
    }
    return 0;
}

