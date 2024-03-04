
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
#define M 60
#define MOD 998244353
#define INF 1000000007 
__attribute__((optimize("Ofast,unroll-loops"),target("avx,avx2,fma")))

ll datas[N];
ll fibo[M], fibosum[M]; // 44까지만 고려.
priority_queue<pair<ll,ll>> pq;

void Solve(){
    int n;
    cin>>n;
    rng(i,0,n-1) cin>>datas[i];
    while(!pq.empty()) pq.pop();
    rng(i,0,n-1) pq.push({datas[i],i});
    ll sum=0;
    rng(i,0,n-1) sum+=datas[i];
    int last=lower_bound(fibosum,fibosum+M,sum)-fibosum;
    if(fibosum[last]!=sum){
        cout<<"No\n";
        return;
    }
    bool flag=1;
    int lidx=-1;
    gnr(i,last,0){
        if(pq.empty()){
            flag=0;
            break;
        }
        auto mx=pq.top();
        pq.pop();
        // mx.fi가 무조건 fibosum[last]이상이다.
        // 나머지는 절대로 fibosum[last]보다 클 수 없다.
        // 나머지 중 fibosum[last]와 같은 것이 하나 있을 수는 있다. (last가 홀수일 경우)
        // 연속하면 안된다는 조건은 어떻게 사용?
        if(mx.fi<fibo[last]){
            flag=0;
            break;
        }
        if(lidx==mx.se){
            if(!pq.empty() && pq.top().fi==fibo[last]){
                lidx=pq.top().se;
                pq.pop();
                pq.push(mx);
            }
            else{
                flag=0;
                break;
            }
        }
        if(!pq.empty() && pq.top().fi>fibo[last]){
            flag=0;
            break;
        }
        if(mx.fi>fibo[last]) pq.push({mx.fi-fibo[last],mx.se});
        lidx=mx.se;
    }
    // fibo[0] + ... + fibo[last]
    if(!flag || !pq.empty()){
        cout<<"No\n";
    }
    else cout<<"Yes\n";
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    fibo[0]=1;
    fibo[1]=1;
    rng(i,2,M-1){
        fibo[i]=fibo[i-1]+fibo[i-2];
        //cout<<i<<' '<<fibo[i]<<'\n';
    }
    rng(i,0,M-1) fibosum[i]=(i==0?0:fibosum[i-1])+datas[i];

    int t=1;
    cin>>t;
    while(t--){
        Solve();
    }
    return 0;
}

