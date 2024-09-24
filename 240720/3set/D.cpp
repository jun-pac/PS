
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
//__attribute__((optimize("Ofast,unroll-loops"),target("avx,avx2,fma")))

#define N 300030
#define MOD 998244353
#define INF 1000000007 
string S,T;

// 15*16385 개의 state
int min_dist[15][17000];
int n;

void dijkstra(int s){
    priority_queue<pair<int,pii>> pq;
	pq.push({0,{n,s}});
    while(!pq.empty()){
        auto temp=pq.top();
		int dist=-temp.fi;
        int pos=temp.se.fi;
        int idx=temp.se.se;
		pq.pop();
		if(min_dist[pos][idx]!=-1) continue;
		min_dist[pos][idx]=dist;
        //cout<<pos<<' '<<idx<<' '<<dist<<'\n';
        rng(i,0,pos-2){
            int npos=i;
            int nidx=0;
            int temp=idx%(1<<(n-i-2));
            int AB=(idx-temp)%(1<<(n-i));
            temp=temp-(temp%(1<<(n-pos)));
            nidx=(idx-AB-temp)+(temp<<2)+(AB>>(pos-i-2));
            assert(nidx<(1<<n));
            if(min_dist[npos][nidx]==-1) pq.push({-(dist+1),{npos,nidx}});
        }
        rng(i,pos+2,n){
            int npos=i;
            int nidx=0;
            int AB=idx%(1<<(n-i+2));
            int temp=(idx-AB)%(1<<(n-pos));
            AB=AB-(AB%(1<<(n-i)));
            nidx=(idx-AB-temp)+(temp>>2)+(AB<<(i-pos-2));
            assert(nidx<(1<<n));
            if(min_dist[npos][nidx]==-1) pq.push({-(dist+1),{npos,nidx}});
        }
	}
}

void Solve(){
    cin>>n;
    cin>>S;
    cin>>T;
    rng(i,0,n) fill(min_dist[i],min_dist[i]+(1<<n),-1);
    int st=0; // 시작하는 number
    int end=0;
    rng(i,0,n-1) st=(st*2)+(S[i]=='B'?1:0);
    rng(i,0,n-1) end=(end*2)+(T[i]=='B'?1:0);
    dijkstra(st);
    cout<<min_dist[n][end]<<'\n';
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

