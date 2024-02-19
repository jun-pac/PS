
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


pll copys[N];
ll lengs[N];
string s;
ll c;

char find_char(ll pos){
    ll bd=upper_bound(lengs,lengs+c+1,pos)-lengs;
    assert(bd!=c+1);

    if(bd==0) return s[pos];
    // copys[bd-1].fi, copys[bd-1].se
    ll dev=pos-lengs[bd-1]; // lengs[bd-1]은 pos보다 작거나 같죠 
    // 근데 이제 bd=1이라면 bd-1을 쓰는 게 맞죠
    return find_char(copys[bd-1].fi+dev);
}

void Solve(){
    ll n,q;
    cin>>n>>c>>q;
    ll a,b,x;
    cin>>s;
    lengs[0]=n;
    rng(i,0,c-1){
        cin>>a>>b;
        a--, b--;
        copys[i]={a,b};
        lengs[i+1]=lengs[i]+b-a+1;
    }
    //rng(i,0,c) cout<<"c "<<lengs[i]<<'\n';
    rng(i,0,q-1){
        cin>>x;
        x--;
        cout<<find_char(x)<<'\n';
    }
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

