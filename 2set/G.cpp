
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
#define MOD 1000000007
random_device rd; 
mt19937 gen(rd());

#define MAX_DIGIT 63
ll powab(ll a, ll b){
    // Calculate a^b
    ll res=1, mult=a;
    for(int i=0; i<MAX_DIGIT; i++){
        if(b&(1LL<<i)){
            res=(res*mult)%MOD;
        }
        mult=(mult*mult)%MOD;
    }
    return res;
}

void Solve(){
    ll l,r,k;
    cin>>l>>r>>k;
    if(k==1){
        ll v2 = powab(10,r);
        ll v1 = powab(10,l);
        cout<<((v2-v1)%MOD+MOD)%MOD<<'\n';
        return;
    }
    if(k<=9){
        ll v=9/k+1;
        ll v2 = powab(v,r);
        ll v1 = powab(v,l);
        cout<<((v2-v1)%MOD+MOD)%MOD<<'\n';
        return;
    }
    else cout<<0<<'\n';


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

