
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

vc<int> aa,bb,cc;
vc<pii> tot;
map<int,int> DP;
int datas[20];
int ns;

int DFS(int state){
    if(DP[state]!=0) return DP[state]; // 0이면 안건든 것. 1+1이면 aoki가 이김, 0+1면 t가 이김
    bool st=(state&(1<<(2*ns))); // st=0이면 ta가 start, 1이면 aoki차례
    int res=(st==0?1:0); // 이기는 수가 하나라도 있어야 이기는 것.

    int mul=1;
    rng(i,0,ns-1){
        int cur=(state%(4*mul))/mul; // 
        // cout<<i<<' '<<datas[i]<<' '<<cur<<'\n';
        if(cur==st){// 내 차례임
            int temp=DFS(state+(2-cur)*mul+(-st+1-st)*(1<<(2*ns))); // 내 카드가 그냥 2가 되는 것
            if(st==0 && temp==1) res=0;
            if(st==1 && temp==2) res=1;
            rng(k,0,i-1){
                int ashival=(1<<(2*k));
                if((state%(4*ashival))/ashival==2 && datas[k]<datas[i]){
                    temp=DFS(state+(2-cur)*mul+(cur-2)*ashival+(-st+1-st)*(1<<(2*ns))); // 내 카드가 그냥 2가 되는 것
                    if(st==0 && temp==1) res=0;
                    if(st==1 && temp==2) res=1;
                }
            }
        }
        mul*=4;
    }

    return DP[state]=res+1;
    
}

void Solve(){
    int n,m,l;
    cin>>n>>m>>l;
    ns=n+m+l;
    rng(i,0,n-1){
        int x;
        cin>>x;
        aa.pb(x);
        tot.pb({x,0});
    }
    rng(i,0,m-1){
        int x;
        cin>>x;
        bb.pb(x);
        tot.pb({x,1});
    }
    rng(i,0,l-1){
        int x;
        cin>>x;
        cc.pb(x);
        tot.pb({x,2});
    }
    sort(all(tot));
    int state=0;
    int mul=1;
    rng(i,0,(int)tot.size()-1){
        // a:0 b:1 c:2
        state+=tot[i].se*mul;
        datas[i]=tot[i].fi;
        mul*=4;
    }
    // state+=mul; // For Takahashi start;
    cout<<(DFS(state)==2?"Aoki":"Takahashi")<<'\n';
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

