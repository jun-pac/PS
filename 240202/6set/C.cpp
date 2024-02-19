
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
    ll a,b,r;
    cin>>a>>b>>r;
    // (a^x) - (b^x) 
    // 비트별로
    if(a==b){
        cout<<0<<'\n';
        return;
    }
    if(a<b) swap(a,b);

    ll mn=(1LL<<62);
    ll x=0;
    int cnt=0;
    bool checkneed=0, aadd=0;
    // 처음에 아무것도 안 더함
    gnr(i,60,0){
        bool aa=a&(1LL<<i);
        bool bb=b&(1LL<<i);
        if(aa != bb){
            cnt++;
            if(cnt==1){
                if(r>=(1LL<<i)) checkneed=1;
                if(aa) aadd=1;
                else aadd=0;
            }
            else if((aadd?aa:bb) && (x+(1LL<<i)<=r)) x+=(1LL<<i);
        }
    }
    mn=min(mn,abs((a^x)-(b^x)));

    if(checkneed){
        x=0;
        cnt=0;
        aadd=!aadd;
        gnr(i,60,0){
            bool aa=a&(1LL<<i);
            bool bb=b&(1LL<<i);
            if(aa != bb){
                cnt++;
                if(cnt==1){
                    x+=(1LL<<i);
                    if(aa) aadd=1;
                    else aadd=0;
                }
                else if((aadd?bb:aa) && (x+(1LL<<i)<=r)) x+=(1LL<<i);
            }
        }
        mn=min(mn,abs((a^x)-(b^x)));
    }
    

    cout<<mn<<'\n';
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

