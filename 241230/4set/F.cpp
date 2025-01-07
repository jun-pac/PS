
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
__attribute__((optimize("Ofast,unroll-loops"),target("avx,avx2,fma")))

ll datas[N], edata[N], odata[N];
int DP[5000001];

typedef complex<double> cpx;
const int SZ =(1<<24); // ans
// const int SZ =(1<<22); // ÀÌ°Ç µÈ´Ù..?
// const int SZ =(1<<20);

void FFT(cpx g[], bool inv = false){
    int n = SZ;
    for(int i = 1, j = 0; i < n; ++i){
        // j : bitwise reverse of i (10110 -> 01101)
        int b = n/2;
        while(!((j ^= b) & b)) b /= 2; // find left-most 1 bit of j, then reverse all the visited bit.
        // 1110xx -> 0001xx
        if(i < j) swap(g[i], g[j]);
    }
    for(int k = 1; k < n; k *= 2){
        double a = (inv ? M_PI/k : -M_PI/k);
        cpx w(cos(a), sin(a));
        for(int i = 0; i < n; i += k*2){
            cpx wp(1, 0);
            for(int j = 0; j < k; ++j){
                cpx x = g[i+j], y = g[i+j+k] * wp;
                g[i+j] = x + y;
                g[i+j+k] = x - y;
                wp *= w;
            }
        }
    }
    if(inv){
        for(int i = 0; i < n; ++i)
            g[i] /= n;
    }
}


ll get_f(int n){
    if(n>=5000001){
        if(n%2==0) return DP[n/2];
        else return n;
    }
    else{
        if(n%2==0) return DP[n]=DP[n/2];
        else return DP[n]=n;
    }
}

cpx s[SZ];

void Solve(){
    int n ;
    cin>>n;
    rng(i,0,n-1) cin>>datas[i];
    sort(datas,datas+n);
    ll en=0, on=0;
    rng(i,0,n-1){
        if(datas[i]%2==0) edata[en++]=datas[i];
        else odata[on++]=datas[i];
    }
    ll esum=0;
    ll osum=0;
    rng(i,0,en-1) esum+=edata[i];
    rng(i,0,on-1) osum+=odata[i];

    rng(i,1,datas[n-1]) get_f(i);


    ll temp=0;
    rng(i,0,n-1) temp+=get_f(datas[i]); // 2*datas[i]±îÁö´Â È£ÃâµÉ ÀÏÀÌ ¾øÀ½
    ll res=0;

    // Â¦ Â¦
    fill(s,s+SZ,cpx(0,0));
    rng(i,0,en-1) s[edata[i]/2]=cpx(1,0);
    FFT(s);
    rng(i,0,SZ-1) s[i]=s[i]*s[i];
    FFT(s,true);
    rng(i,1,datas[n-1]){
        ll val=s[i].real()+0.5;
        res+=val*get_f(i);
    }

    // Â¦ È¦, È¦ Â¦
    res+=2*esum*on + 2*osum*en;


    // È¦ È¦
    fill(s,s+SZ,cpx(0,0));
    rng(i,0,on-1) s[odata[i]/2]=cpx(1,0);
    FFT(s);
    rng(i,0,SZ-1) s[i]=s[i]*s[i];
    FFT(s,true);
    rng(i,0,datas[n-1]){
        ll val=s[i].real()+0.5;
        res+=val*get_f(i+1);
    }

    cout<<(res+temp)/2<<'\n';
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

