
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
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

#define N 100030
#define MOD 998244353
#define INF 3000000000000000000

long long fact[N], f_inv[N];

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

pll count(ll n, ll k){ // return {}
    // 남은 원소, 남은 group
    ll leftov=n%k;
    ll r=n/k;
    ll res=(k-leftov)*(r/2*((r+1)/2-1))+(leftov)*((r+1)/2*((r+2)/2-1));
    ll odd_num=k-leftov, even_num=leftov;
    if(r%2==0) swap(odd_num,even_num);
    if(n/k==1) return {res,nCr(k,leftov)}; 
    ll cnt=0;
    rng(i,0,odd_num/2){
        cnt=(cnt+(fact[k]*f_inv[odd_num-2*i])%MOD*(f_inv[even_num+i]*f_inv[i]%MOD))%MOD;
    }
    return {res,cnt%MOD};    
}

void Solve(){
    ll n,k,cnt=0;
    cin>>n>>k;
    k++;
    ll mn=INF;
    if(k==2){
        if(n%2==0){
            cout<<((n/2)*((n/2)-1))<<' '<<1<<endl;
        }
        else{
            cout<<((n/2)*((n/2)-1))/2+((n/2+1)*((n/2)))/2<<' '<<2<<endl;
        }
        return;
    }
    for(ll i=n/(2*k-2); i<=n/(2*k-2)+1; i++){
        if(i<=0) continue;
        if(i+i+1+k-2>n) break;
        auto res=count(n-i-i-1,k-2);
        ll cur=(i*(i-1)/2+i*(i+1)/2);
        if(res.fi+cur<mn){
            mn=res.fi+cur;
            cnt=(res.se*2)%MOD;
        }
        else if(res.fi+cur==mn){
            cnt=(cnt+res.se*2)%MOD;
        }
    }
    for(ll i=n/(2*k-2); i<=n/(2*k-2)+1; i++){
        if(i<=0) continue;
        if(i+i+k-2>n) break;
        auto res=count(n-i-i,k-2);
        ll cur=i*(i-1);
        if(res.fi+cur<mn){
            mn=res.fi+cur;
            //cout<<"de "<<mn<<' '<<res.se<<'\n';
            cnt=(res.se)%MOD;
        }
        else if(res.fi+cur==mn){
            //cout<<"de "<<mn<<' '<<res.se<<'\n';
            cnt=(cnt+res.se)%MOD;
        }
    }
    cout<<mn<<' '<<(cnt%MOD+MOD)%MOD<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    fill_fact();
    cin>>t;
    while(t--){
        Solve();
    }
    return 0;
}

