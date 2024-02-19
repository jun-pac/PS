
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
int a[N], b[N];
unordered_map<int,int> um;
int l[N], r[N];

#define LOG2 20

class RMQ{
public:
	long long sp_table[LOG2][N]; // NlogN size sparse table
	long long LG[N+1]; // LG[idx]=floor(log_2[idx]) 
	// Note that sp_table RMQ if fast(O(1) for each query), but it is immutable
	int info;
	void build_sparse(int n){
		for(int i=0; i<n; i++) sp_table[0][i]=b[i];
		for(int idx=1; (1<<idx)<=n; idx++){
			for(int i=0; i+(1<<idx)<=n; i++){
				sp_table[idx][i]=min(sp_table[idx-1][i],sp_table[idx-1][i+(1<<(idx-1))]);
			}   
		}
		LG[1]=0;
		for(int i=2; i<=n; i++) LG[i]=LG[i/2]+1;
	}
	long long query(int a, int b){
		// [a,b] minimum query
        //cout<<a<<' '<<b<<'\n';
		assert(a<=b);
		int lgn=LG[b-a+1];
		return min(sp_table[lgn][a],sp_table[lgn][b-(1<<lgn)+1]);
	}
};
class RMQ2{
public:
	long long sp_table[LOG2][N]; // NlogN size sparse table
	long long LG[N+1]; // LG[idx]=floor(log_2[idx]) 
	// Note that sp_table RMQ if fast(O(1) for each query), but it is immutable
	int info;
	void build_sparse(int n){
		for(int i=0; i<n; i++) sp_table[0][i]=a[i];
		for(int idx=1; (1<<idx)<=n; idx++){
			for(int i=0; i+(1<<idx)<=n; i++){
				sp_table[idx][i]=max(sp_table[idx-1][i],sp_table[idx-1][i+(1<<(idx-1))]);
			}   
		}
		LG[1]=0;
		for(int i=2; i<=n; i++) LG[i]=LG[i/2]+1;
	}
	long long query(int a, int b){
		// [a,b] minimum query
        //cout<<a<<' '<<b<<'\n';
		assert(a<=b);
		int lgn=LG[b-a+1];
		return max(sp_table[lgn][a],sp_table[lgn][b-(1<<lgn)+1]);
	}
};

RMQ rmq;
RMQ2 rmq2;

void Solve(){
    int n;
    cin>>n;
    rng(i,0,n-1) cin>>a[i];
    rng(i,0,n-1) cin>>b[i];
    bool flag=1;
    rng(i,0,n-1) if(a[i]>b[i]) flag=0;
    if(!flag){
        cout<<"NO"<<'\n';
        return;
    }
    um.clear();
    rng(i,0,n-1){
        um[a[i]]=i+1;
        if(um[b[i]]==0) l[i]=-1;
        else l[i]=um[b[i]]-1;
    }
    um.clear();
    gnr(i,n-1,0){
        um[a[i]]=i+1;
        if(um[b[i]]==0) r[i]=n;
        else r[i]=um[b[i]]-1;
    }
    rmq.build_sparse(n);
    rmq2.build_sparse(n);

    rng(i,0,n-1){
        if(l[i]==-1 && r[i]==n){
            flag=0;
        }
        else if(l[i]==-1){
            if(rmq.query(i,r[i])<b[i] || rmq2.query(i,r[i])>b[i]) flag=0;
        }
        else if(r[i]==n){
            if(rmq.query(l[i],i)<b[i] || rmq2.query(l[i],i)>b[i]) flag=0;
        }
        else{
            if((rmq.query(i,r[i])<b[i] || rmq2.query(i,r[i])>b[i]) && (rmq.query(l[i],i)<b[i] || rmq2.query(l[i],i)>b[i])) flag=0;
        }
    }
    cout<<(flag?"YES":"NO")<<'\n';
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

