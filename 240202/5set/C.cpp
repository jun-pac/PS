
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

ll datas[N], sum[N];
priority_queue<ll> lpq, rpq;

void Solve(){
    ll n,m;
    cin>>n>>m;
    m--;
    ll res=0;
    rng(i,0,n-1) cin>>datas[i];
    if(m!=0 && datas[m]>0){
        datas[m]*=-1;
        res++;
    }
    rng(i,0,n-1) sum[i]=(i==0?0:sum[i-1])+datas[i];
    
    // left-wise greedy
    while(!lpq.empty()) lpq.pop(); // 이제까지의 가장 큰 +를 단죄한다
    ll offset=0;
    gnr(i,m-1,0){
        if(sum[i]+offset<sum[m]){
            while(!lpq.empty() && sum[i]+offset<sum[m]){
                ll val=lpq.top();
                lpq.pop();
                offset+=2*val;
                res++;
            }
            assert(sum[i]+offset>=sum[m]);
        }
        if(datas[i]>0) lpq.push(datas[i]); 
    }

    // right-wise greedy
    offset=0;
    while(!rpq.empty()) rpq.pop(); // 이제까지의 가장 작은 -를 단죄한다
    rng(i,m+1,n-1){
        if(datas[i]<0) rpq.push(-datas[i]); 
        if(sum[i]+offset<sum[m]){
            while(!rpq.empty() && sum[i]+offset<sum[m]){
                ll val=rpq.top();
                rpq.pop();
                offset+=2*val; // 음수였던 것을 +로 바꾸는 과정. 여전히 +다.
                res++;
            }
            assert(sum[i]+offset>=sum[m]);
        }
    }
    cout<<res<<'\n';
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

