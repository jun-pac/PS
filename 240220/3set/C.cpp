
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
    int n,m;
    cin>>m>>n;
    // 종국에는 m의 약수가 계속 살아남는다.
    // m보다 작은 어떤 값으로 줄이는 것은 쉬운 일이다.
    // 즉 n은 m의 1이 아닌 가장 작은 약수보다도 작아야 한다는 말이다.
    if(m==1){
        cout<<"YES\n";
        return;
    }
    if(n>=m){
        cout<<"NO\n";
        return;
    }
    rng(i,2,min(n,(int)sqrt(m))){
        if(m%i==0){
            cout<<"NO\n";
            return;
        }    
    }
    cout<<"YES\n";
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

