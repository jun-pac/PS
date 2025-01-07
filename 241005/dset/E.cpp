
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
#define MAX_DIGIT 62

ll a[N];
ll p[N];
ll bit_prob[10];
ll cov_prob[10][10];

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


void Solve(){
    ll n;
    cin>>n;
    rng(i,0,n-1) cin>>a[i];
    rng(i,0,n-1) cin>>p[i];
    ll denom=ari_inv(10000);
    rng(k,0,n-1) p[k]=(p[k]*denom)%MOD;
    rng(i,0,9){
        // bit_prob
        ll p1=0;
        ll bit=(1<<i);
        rng(k,0,n-1){
            if(a[k]&bit){
                ll newp1=(p1*(1-p[k])+(1-p1)*(p[k]))%MOD;
                p1=newp1;
            }
        }
        bit_prob[i]=p1;
    }

    rng(i,0,9){
        rng(j,i+1,9){
            ll p11=0, p00=1, p10=0, p01=0;
            ll np11, np00, np10, np01;
            ll b1=(1<<i), b2=(1<<j);
            rng(k,0,n-1){
                if((a[k]&b1) && (a[k]&b2)){
                    np00=p00*(1-p[k])+p11*p[k];
                    np01=p01*(1-p[k])+p10*p[k];
                    np10=p10*(1-p[k])+p01*p[k];
                    np11=p11*(1-p[k])+p00*p[k];
                }
                else if((a[k]&b1) && (!(a[k]&b2))){
                    np00=p00*(1-p[k])+p10*p[k];
                    np01=p01*(1-p[k])+p11*p[k];
                    np10=p10*(1-p[k])+p00*p[k];
                    np11=p11*(1-p[k])+p01*p[k];
                }
                else if((!(a[k]&b1)) && (a[k]&b2)){
                    np00=p00*(1-p[k])+p01*p[k];
                    np01=p01*(1-p[k])+p00*p[k];
                    np10=p10*(1-p[k])+p11*p[k];
                    np11=p11*(1-p[k])+p10*p[k];
                }
                else{
                    np00=p00;
                    np01=p01;
                    np10=p10;
                    np11=p11;
                }
                p00=np00%MOD;
                p01=np01%MOD;
                p10=np10%MOD;
                p11=np11%MOD;
            }
            cov_prob[i][j]=p11;
        }
    }
    ll res=0;
    rng(i,0,9){
        res=(res+(1<<(2*i))*bit_prob[i])%MOD;
    }
    rng(i,0,9){
        rng(j,i+1,9){
            res=(res+2*(1<<(i+j))*cov_prob[i][j])%MOD;
        }
    }
    cout<<(res%MOD+MOD)%MOD<<'\n';
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

