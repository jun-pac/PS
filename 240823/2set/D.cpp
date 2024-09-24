
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
    ll n,x;
    cin>>n>>x;
    ll cnt=0;
    rng(a,1,600){
        // if a==b
        if(x-a-a<a || (n-a*a)/(2*a)<a) break;
        // (a,a,a)
        cnt++;
        // (a,a,c)
        cnt+=(min(x-a-a,(n-a*a)/(a+a))-(a+1)+1)*3;
        
        rng(b,a+1,1000){
            if(x-a-b<b || (n-a*b)/(a+b)<b) break;
            // (a,b,b)
            cnt+=3;
            cnt+=(min(x-a-b,(n-a*b)/(a+b))-(b+1)+1)*6;
        }
    }
    cout<<cnt<<'\n';
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

