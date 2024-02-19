
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

#define N 500030
#define MOD 998244353
#define INF 1000000007 

ll as[N], bs[N], cs[N];
ll DP[N]; // DP[i]는 i기준 앞에서 넘어오는 게 없을 때
ll toidx[N]; // i기준 넘어오는 게 없을 때 어디까지 full인지, 안채워지면 i-1을 넣자
ll lefts[N]; // 잔여 처리능력

void Solve(){
    int n,q;
    cin>>n>>q;
    rng(i,0,n-1) cin>>as[i];
    rng(i,0,n-1) cin>>bs[i];
    rng(i,0,n-2) cin>>cs[i];
    ll idx, a,b,c;
    gnr(i,n-1,0){
        if(i==n-1){
            DP[i]=min(as[i],bs[i]);
            if(as[i]>=bs[i]) toidx[i]=i;
            else{
                toidx[i]=i-1;
                lefts[i]=bs[i]-as[i];
            }
        }
        else{
            if(as[i]>=bs[i]){
                
            }
            else{
                lefts[i]=bs[i]-as[i];
                DP[i]=as[i]+DP[i+1];
            }
        }
    }
    rng(i,0,q-1){
        cin>>idx>>a>>b>>c;
        idx--;
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

