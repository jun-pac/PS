
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
#define INF 1000000000000000007 

ll x,y,z,k;

ll get_cost(ll n){
    ll curz=z;
    ll num=(n-1)/k;
    ll res=n*x+num*y;
    curz-=k*(num*(1+num))/2;
    if(curz>0) res+=cediv(curz,n)*y;
    return res;
}


void Solve(){
    cin>>x>>y>>z>>k;
    if(k<=300){
        ll mn=INF;
        ll i=1;
        while(1){
            // ll num=(i-1)/k;
            // ll curz=z-k*(num*(1+num))/2;
            // cout<<i<<' '<<get_cost(i)<<' '<<num<<' '<<curz<<'\n';
            mn=min(mn,get_cost(i));
            if(abs(k*((i-1)/k+1)*((i-1)/k)/2)>z) break;
            i++;
        }
        cout<<mn<<'\n';
    }
    else{
        ll mn=INF;
        rng(i,0,z/k){
            ll s=i*k+1,e=min(z,i*k+k);

            ll num=i;
            ll curz=z-k*(num*(1+num))/2;
            if(curz<0) mn=min(mn,(s*x+i*y));
            else{
                mn=min(mn,get_cost(s));
                // curz의 모든 약수들
                ll sq=sqrt(curz+1);
                for(ll j=1; j<=sq; j++){
                    ll val=j;
                    if(s<=val && val<=e){
                        mn=min(mn,get_cost(val));
                    }
                    val=cediv(curz,j);
                    if(s<=val && val<=e){
                        mn=min(mn,get_cost(val));
                    }
                }
            }
        }
        cout<<mn<<'\n';
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

