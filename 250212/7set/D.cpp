
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

ll a[N], b[N];
multiset<ll> aset, bset;

void Solve(){
    int n,m;
    cin>>n>>m;
    rng(i,0,n-1) cin>>a[i];
    rng(i,0,m-1) cin>>b[i];
    sort(a,a+n);
    sort(b,b+m);
    ll asum=0, bsum=0;
    rng(i,0,n-1) asum+=a[i];
    rng(i,0,m-1) bsum+=b[i];
    if(asum!=bsum){
        cout<<"No\n";
        return;
    }
    aset.clear();
    bset.clear();
    rng(i,0,n-1) aset.insert(a[i]);
    rng(i,0,m-1) bset.insert(b[i]);

    while(!bset.empty()){
        if(bset.size() > aset.size()){
            cout<<"No\n";
            return;
        }
        auto temp=bset.begin();
        ll bval=(*temp);
        if(bval < (*(aset.begin()))){
            cout<<"No\n";
            return;
        }
        auto tempa=aset.lower_bound(bval);
        if(tempa==aset.end() || (*tempa) != bval){
            bset.erase(temp);
            bset.insert(bval/2);
            bset.insert((bval+1)/2);
        }
        else{
            bset.erase(temp);
            aset.erase(tempa);
        }
    }
    if(aset.empty() && bset.empty()){
        cout<<"Yes\n";
    }
    else cout<<"No\n";
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

