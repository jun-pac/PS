
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

void Solve(){
    string s;
    cin>>s;
    ll n=s.size();
    int n1=0;
    rng(i,0,n-1) if(s[i]=='1')n1++;
    if(n1==0){
        cout<<0<<'\n';
        return;
    }
    if(n1==n){
        cout<<n*n<<'\n';
        return;
    }
    // atleast 1 
    ll mx=1;
    ll last=-1;
    ll i=0;
    while(i<2*n){
        if(s[i%n]=='1'){
            last=i;
            while(i<2*n && s[i%n]=='1') i++;
            mx=max(mx,i-last);
        }
        i++;
    }
    ll res=0;
    rng(i,1,mx){
        res=max(res,i*(mx+1-i));
    }
    cout<<res<<'\n';
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

