
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
    int n;
    cin>>n;
    if(n%2==0){
        cout<<"YES\n";
        rng(i,0,n-1) cout<<(i%2==0?1:-1)<<' ';
        cout<<'\n';
    }
    else{
        if(n==3){
            cout<<"NO\n";
        }
        else{
            cout<<"YES\n";
            if(n%4==1){
                int m=n/2;
                rng(i,0,n-1) cout<<(i%2==0?-m+1:m)<<' '; cout<<'\n';
            }
            else{
                int m=n/2;
                rng(i,0,n-1) cout<<(i%2==0?-m+1:m)<<' '; cout<<'\n';
            }
            // n=2m+1
            // m*(as) + (m+1)*(-as+s) = s
            // ma+(m+1)(-a+1)=1 => a(m-m-1)+m+1=1 => a=m;
            // n=3의 경우는 0s 1s 0s
            // n=5의 경우는 2s -s 2s -s 2s가 아니라 -s 2s -s 2s -s인데?
        }
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

