
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

#define MAX_DIGIT 62

long long ari_inv(long long num){
    long long res=1, mult=num;
    for(int i=0; i<MAX_DIGIT; i++){
        if((MOD-2)&(1LL<<i)){
            res=(res*mult)%MOD;
        }
        mult=(mult*mult)%MOD;
    }
    return res;
}

inline ll ppow(ll p, ll num){
    // p^num % MOD
    ll tempn=num%(MOD-1), res=1, mult=p;
    for(int i=0; i<MAX_DIGIT; i++){
        if(tempn&(1LL<<i)){
            res=(res*mult)%MOD;
        }
        mult=(mult*mult)%MOD;
    }
    return res;
}

ll pred[N];

void Solve(){
    ll n,p,k;
    cin>>n>>p>>k;
    ll linemul=((ppow(p,n)-1)*ari_inv(p-1))%MOD;
    //cout<<"line "<<linemul<<'\n';
    // linemul = p^n-1 mod 998.. = p^ 
    
    pred[0]=0;
    ll sum=1;
    rng(i,0,min(k,n)){
        if(i==0) cout<<0<<' ';
        else{
            ll mul=ppow(p,(n-i+1)*i);
            ll res=ppow(linemul,i)*(mul-sum)%MOD;
            sum=(sum+res)%MOD;
            cout<<(res+MOD)%MOD<<' ';
        }
    }
    rng(i,min(k,n)+1,k){
        cout<<0<<' ';
    }
    cout<<"\n";

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

