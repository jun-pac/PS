
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

string mp[7];
int sum[24];

void Solve(){
    int d,h;
    rng(i,0,6) cin>>mp[i];
    cin>>d>>h;
    int mx=0;
    rng(i,0,(1<<7)-1){
        int cnt=0;
        rng(j,0,6) if(i&(1<<j)) cnt++;
        if(cnt!=d) continue;
        fill(sum,sum+24,0);
        rng(j,0,6){
            if(i&(1<<j)){
                rng(k,0,23){
                    sum[k]+=(mp[j][k]=='.'?1:0);
                }
            }
        }
        sort(sum,sum+24);
        int temp=0;
        rng(j,0,h-1) temp+=sum[23-j];
        mx=max(mx,temp);
    }

    cout<<fixed;
    cout.precision(12);
    long double numer=d*h;
    cout<<(mx/numer)<<'\n';    
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

