
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

ll datas[N];
ll DP[N];
ll inter[N]; // (j+1)**2 + DP[j]
pair<double,pll> st[N];

void Solve(){
    int n;
    cin>>n;
    rng(i,0,n-1) cin>>datas[i];
    DP[0]=0;
    inter[0]=1;
    int stsz=0;
    st[stsz++]={-INF,{inter[0],-2*0}};    
    
    rng(i,1,n-1){
        pair<double,pll> temp={i,{0,0}};
        double ta, ty, tx, a, y, x;
        int idx=upper_bound(st,st+stsz,temp)-st-1;

        ty=st[idx].se.fi;
        ta=st[idx].se.se;
        cout<<"i idx, ty ta:"<<i<<' '<<idx<<' '<<ty<<' '<<ta<<'\n';

        DP[i]=ty+ta*i+i*i-2*i;
        cout<<"DP "<<DP[i]<<'\n';
        inter[i]=DP[i]+(i+1)*(i+1);
        while(stsz>0){
            temp=st[stsz-1];
            ta=temp.se.se, ty=temp.se.fi, tx=temp.fi;
            a=-2*i, y=inter[i];
            x=(y-ty)/(ta-a);
            if(x>tx){
                break;
            }
            stsz--;
        }
        st[stsz++]={x,{inter[i],-2*i}};
    }

    ll ans=n*n;
    rng(i,0,n-1) ans=min(ans,DP[i]+(n-1-i)*(n-1-i));
    cout<<ans<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    // cin>>t;
    while(t--){
        Solve();
    }
    return 0;
}

