
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
#define LOG2 20

random_device rd; 
mt19937 gen(rd());
uniform_int_distribution<> dist(0, INF); // random integer from [0, INF] // dist(gen)

ll datas[N];
ll pos[N], neg[N];
ll temp[N];

class RMQ{
public:
	long long sp_table[LOG2][N]; // NlogN size sparse table
	long long LG[N+1]; // LG[idx]=floor(log_2[idx]) 
	// Note that sp_table RMQ if fast(O(1) for each query), but it is immutable
	int info;
	void build_sparse(int n){
		for(int i=0; i<n; i++) sp_table[0][i]=datas[i];
		for(int idx=1; (1<<idx)<=n; idx++){
			for(int i=0; i+(1<<idx)<=n; i++){
				sp_table[idx][i]=max(sp_table[idx-1][i],sp_table[idx-1][i+(1<<(idx-1))]);
			}   
		}
		LG[1]=0;
		for(int i=2; i<=n; i++) LG[i]=LG[i/2]+1;
	}
	long long query(int a, int b){
		// [a,b] max query
		assert(a<=b);
		int lgn=LG[b-a+1];
		return max(sp_table[lgn][a],sp_table[lgn][b-(1<<lgn)+1]);
	}
};

RMQ rmq_plus_right;

void Solve(){
    int n;
    cin>>n;
    for(int i=0; i<=n-1; i++) cin>>datas[i];
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

