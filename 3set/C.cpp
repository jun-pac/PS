
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

int a[200],b[200],c[200];
map<int,int> mp;

void Solve(){
    int n,m,l;
    cin>>n;
    rng(i,0,n-1) cin>>a[i];
    cin>>m;
    rng(i,0,m-1) cin>>b[i];
    cin>>l;
    rng(i,0,l-1) cin>>c[i];
    int q;
    rng(i,0,n-1){
        rng(j,0,m-1){
            rng(k,0,l-1){
                mp[a[i]+b[j]+c[k]]++;
            }
        }
    }
    cin>>q;
    rng(i,0,q-1){
        int x;
        cin>>x;
        cout<<(mp[x]==0?"No\n":"Yes\n");
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

