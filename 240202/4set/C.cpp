
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
#define MOD 999999893
#define INF 1000000007 
#define MAX_DIGIT 62

// Remember (ak)*(bk)^(-1) === a*b^(-1) === (ak%P)*(bk%P)^(-1) (mod P)
long long ari_inv(long long num){
    // Calculate num^(MOD-2)
    long long res=1, mult=num;
    for(int i=0; i<MAX_DIGIT; i++){
        if((MOD-2)&(1LL<<i)){
            res=(res*mult)%MOD;
        }
        mult=(mult*mult)%MOD;
    }
    return res;
}

ll bigpow(ll num){
    long long res=1, mult=2;
    for(int i=0; i<MAX_DIGIT; i++){
        if(num&(1LL<<i)){
            res=(res*mult)%MOD;
        }
        mult=(mult*mult)%MOD;
    }
    return res;
}

void Solve(){
    int n;
    cin>>n;
    //rng(i,0,10) cout<<bigpow(i)<<'\n';
    //cout<<ari_inv(7)<<'\n';
    if(n==1) cout<<0<<'\n';
    else if(n%2==0){
        ll m=n/2;
        ll denom=-bigpow(2*m-1)+bigpow(m+1)-1;
        denom%=MOD;
        ll up=bigpow(m)-1;
        up%=MOD;
        ll res=up*ari_inv(denom)%MOD;
        cout<<(res+MOD)%MOD<<'\n';
    }
    else{
        ll m=n/2;
        ll up=bigpow(m)-1;
        up%=MOD;
        ll denom=(bigpow(2*m)+bigpow(m+1)-1);
        denom%=MOD;
        ll res=up*ari_inv(denom)%MOD;
        cout<<(res+MOD)%MOD<<'\n';
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

