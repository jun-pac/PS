
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

#define N 400030
#define MOD 998244353
#define INF 1000000007 

string s;
ll DP[N];

void Solve(){
    ll n;
    cin>>n;
    cin>>s;
    // i시점에 두개이상산다면, 비싼거는 현재 i
    // 1개만 사는 선택지는 뒤로 미뤄도 됨.
    // i번째까지 결국 공짜로 사는 거를 i/2번보다 많이는 하면 안된다!
    ll mxsum=0;
    ll last=n; // 사용이 불가피한 최소의 원소
    gnr(i,n-1,1){
        if(s[i]=='1'){
            if(last>i){
                mxsum+=i+1;
                last=i-1;
            }
            else{
                if(last-2>=0){
                    mxsum+=i+1;
                    last-=2;
                }
            }
        }
    }
    cout<<(n*(n+1))/2-mxsum<<'\n';
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

