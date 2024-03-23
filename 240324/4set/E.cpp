
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
#define INF 1000000007 

#define SZ 1<<21
#define MOD 998244353
#define AA 119
#define BB 23
#define PR 3
#define MAX_DIGIT 62
ll fact[N], f_inv[N];

void fill_fact(){
    fact[0]=1;
    for(int i=1; i<N; i++) fact[i]=fact[i-1]*i%MOD;
    fill(f_inv,f_inv+N,1);
    for(int k=0; k<30; k++){
        for(int i=0; i<N; i++){
            f_inv[i]=f_inv[i]*f_inv[i]%MOD;
            if((MOD-2)&(1<<(29-k))) f_inv[i]=f_inv[i]*fact[i]%MOD;
        }
    }
}

long long nCr(int n, int r){
    return ((fact[n]*f_inv[r])%MOD)*f_inv[n-r]%MOD;
}


ll DP[(1<<20)][21];
ll get_DP(int n, int k){
    assert(k!=0);
    int cnt=0;
    while((1<<(cnt+1))<=n) cnt++;
    if((1<<cnt)==n) return DP[n][cnt];
    

}

long long ari_inv(long long num){
    long long res=1, mult=num;
    for(ll i=0; i<MAX_DIGIT; i++){
        if((MOD-2)&(1LL<<i)){
            res=(res*mult)%MOD;
        }
        mult=(mult*mult)%MOD;
    }
    return res;
}


// 출력이 음수가 될 수 있음!!
void NTT(ll g[], bool inv = false){
    ll n = SZ;
    ll w_pow[n+1];
    ll bit_cnt=0;
    for(; bit_cnt<=BB; bit_cnt++){
        if((n>>bit_cnt) == 1) break;
    }
    assert ((n>>bit_cnt)==1);

    // w^n % MOD == 1 이어야 함.
    // w = PR^((p-1) / n) = PR ^ (a*2^(b-bit_cnt))
    ll w = 1;
    ll pow = AA<<(BB-bit_cnt);
    ll mul = PR;
    for(int i=0; i<MAX_DIGIT; i++){
        if(pow&(1LL<<i)) w=(w*mul)%MOD;
        mul=(mul*mul)%MOD;
    }
    w = (inv ? w : ari_inv(w));
    
    for(ll i = 1, j = 0; i < n; ++i){
        ll b = n/2;
        while(!((j ^= b) & b)) b /= 2;
        if(i < j) swap(g[i], g[j]);
    }

    ll cnt=0;
    for(ll k = 1; k < n; k *= 2){
        cnt++;
        ll ww = w; // ww^(2*k) % MOD == 1 이어야 함. ww=w^(n/(2*k))=w^(2^(bit_cnt-cnt))
        for(ll i=0; i<bit_cnt-cnt; i++) ww=(ww*ww)%MOD;
        for(ll i=0; i<k; i++) w_pow[i]=(i==0?1:(w_pow[i-1]*ww)%MOD);
        for(ll i = 0; i < n; i += k*2){
            ll wp = 1;
            for(ll j = 0; j < k; ++j){
                ll x = g[i+j], y = g[i+j+k]*w_pow[j]; //MOD*MOD+MOD가 ll로 표현된다면 중간과정에서 %MOD 필요없음.
                g[i+j] = (x + y); 
                g[i+j+k] = (x - y);
            }
        }
        for(int i=0; i<n; i++) g[i]%=MOD; // 위의 for문 동안 한 번만 방문
    }
    if(inv){
        ll ari_n = ari_inv(n);
        for(ll i = 0; i < n; ++i)
            g[i] = (g[i]*ari_n)%MOD;
    }
}

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

ll a[N], b[N];
ll asum[N], bsum[N];

void Solve(){
    int n,q;
    cin>>n>>q;
    rng(i,0,n-1) cin>>a[i];
    rng(i,0,n-1) cin>>b[i];
    rng(i,0,n-1) asum[i]=(i==0?0:asum[i-1])+a[i];
    rng(i,0,n-1) bsum[i]=(i==0?0:bsum[i-1])+b[i];
    rng(i,0,q-1){
        int l,r;
        cin>>l>>r;
        ll ain=asum[r]-(l==0?0:asum[l-1]);
        ll aout=asum[n-1]-ain;
        ll bin=bsum[r]-(l==0?0:bsum[l-1]);
        ll bout=bsum[n-1]-bout;

        if(bin==bout){
            if(ain>aout) cout<<1<<'\n';
            else cout<<0<<'\n';
        }
        else if(bin>bout){
            ll bb=bin-bout;
            ll aa=aout-ain;
            if(aa<0) cout<<1<<'\n';
            else if(aa>=bb) cout<<0<<'\n';
            else{

            }
        }
        else{
            ll bb=bout-bin;
            ll aa=ain-aout;
            if(aa<=0) cout<<0<<'\n';
            else if(aa>bb) cout<<1<<'\n';
            else{

            }
        }
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

