
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

// 방향별로 map을 만들어서 관리해주면 되는 문제였음. pass
set<ll> sl, sr, sd, su;
// 근데 이거 개수를 센다고 해도 뭐 풀수가 있는건가?
// 잘 모르겠죠 그죠

pll es[N];
void Solve(){
    ll n,m;
    cin>>n>>m;
    ll cnt=0;
    rng(i,0,m-1){
        ll a,b;
        cin>>a>>b;
        a--, b--;
        es[i]={a,b};
        if(sl.find(a)==sl.end()){
            sl.insert(a);
        }
        if(sr.find(b)==sr.end()){
            sr.insert(b);
        }
        if(sd.find(a-b)==sd.end()){
            sd.insert(a-b);
        }
        if(su.find(a+b)==su.end()){
            su.insert(a+b);
        }

    }
    map<pll,ll> mp;
    rng(i,0,m-1){
        rng(j,0,i-1){
            
        }
    }
    cout<<n*n-cnt<<'\n';
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

