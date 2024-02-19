
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
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

ll a[N], b[N];
priority_queue<pll> q;

void Solve(){
    int n;
    cin>>n;
    rng(i,0,n-1) cin>>a[i];
    rng(i,0,n-1) cin>>b[i];
    while(!q.empty()) q.pop();
    int cnt=0;
    rng(i,0,n-1){
        if(a[i]!=0 && b[i]!=0) q.push({a[i]+b[i],i});
    }
    while(!q.empty()){
        if(cnt%2==0){
            a[q.top().se]--;
            b[q.top().se]=0;
            q.pop();
        }
        else{
            a[q.top().se]=0;
            b[q.top().se]--;
            q.pop();
        }
        cnt++;
    }
    ll res=0;
    rng(i,0,n-1) res+=a[i]-b[i];
    cout<<res<<'\n';
}
// alice입장에서는 지가 많이 가진 것을 포기해서, 상대방이 그것으로 공격을 할 수 없게.
// 상대방은 해당 색의 구슬을 모두 잃게되므로 이후에 공격을 할 수 없음.
// 서로 공격을 막 하게 되면 이제 n번의 턴이 지나면 더 이상 공격을 할 수가 없음.
// 그때 이제 남은 것을 서로 까먹기 시작하면서

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--){
        Solve();
    }
    return 0;
}

