
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

#define N 100030
#define MOD 998244353
#define INF 1000000007 

ll datas[N], sum[N];
// 아 뭐여 first v locked card네
// 남은 게 다 0이 아닌이상 상관이 없네요
// 어디서 멈추느냐가 중요한건데,
// 문제는 모든 위치에서 멈출 수 있는 건 아닌 것 같습니다
// Greedy하게 가장 작은 것들만 이용해서 넘긴다고 해도?
// 그건 안된다!
// 결국 어디까지 도달할 수 있는지가 중요한건데, 마지막부분이 0,0,0... 이런거면 쌉손해죠 호호


void Solve(){ 
    int n; 
    cin>>n;
    rng(i,0,n-1) cin>>datas[i];
    rng(i,0,n-1){
        cin>>datas[i];
        sum[i]=(i==0?0:sum[i-1])+datas[i];

    }
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

