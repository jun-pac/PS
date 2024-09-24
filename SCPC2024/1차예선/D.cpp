
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
__attribute__((optimize("Ofast,unroll-loops"),target("avx,avx2,fma")))

#define N 300030
#define MOD 998244353
#define INF 1000000007 

ll A[N], B[N];
ll AB[N], AB1[N], BA1[N];
ll datas[N];

#define LOG2 20

class RMQ{
public:
	long long sp_table[LOG2][N]; // NlogN size sparse table
	long long LG[N+1]; // LG[idx]=floor(log_2[idx]) 
	// Note that sp_table RMQ if fast(O(1) for each query), but it is immutable
	int info;
	void build_sparse(int n, int tp){
		if(tp==0) for(int i=0; i<n; i++) sp_table[0][i]=AB[i];
        if(tp==1) for(int i=0; i<n; i++) sp_table[0][i]=AB1[i];
        if(tp==2) for(int i=0; i<n; i++) sp_table[0][i]=BA1[i];
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
		assert(a<=b);
		int lgn=LG[b-a+1];
		return max(sp_table[lgn][a],sp_table[lgn][b-(1<<lgn)+1]);
	}
};
RMQ mAB, mAB1, mBA1;

void Solve(int tt){
    int ans=0;
    ll n,L;
    cin>>n>>L;
    rng(i,0,n-1) cin>>A[i];
    rng(i,0,n-1) cin>>B[i];
    sort(A,A+n);
    sort(B,B+n);
    ll mx=abs(A[0]-B[0]);
    rng(i,0,n-1){
        AB[i]=abs(A[i]-B[i]);
        mx=max(AB[i],mx);
    }
    rng(i,0,n-2) AB1[i]=abs(A[i]-B[i+1]);
    rng(i,0,n-2) BA1[i]=abs(A[i+1]-B[i]);
    if(L<mx){
        cout<<"Case #"<<tt+1<<'\n';
        cout<<-1<<'\n';
        return;
    }
    mAB.build_sparse(n,0);
    mAB1.build_sparse(n-1,1);
    mBA1.build_sparse(n-1,2);    

    rng(i,0,n-2){
        // A에서 B쪽으로.
        int l=i+1, r=n-1;
        while(l<r){
            int mid=(l+r+1)>>1;
            if(max(B[mid]-A[i],mBA1.query(i,mid-1))<=L) l=mid;
            else r=mid-1;
        }
        if(max(B[l]-A[i],mBA1.query(i,l-1))<=L) mx=max(max(B[l]-A[i],mBA1.query(i,l-1)),mx);
    }
    rng(i,0,n-2){
        // A에서 B쪽으로.
        int l=i+1, r=n-1;
        while(l<r){
            int mid=(l+r+1)>>1;
            if(max(A[mid]-B[i],mAB1.query(i,mid-1))<=L) l=mid;
            else r=mid-1;
        }
        if(max(A[l]-B[i],mAB1.query(i,l-1))<=L) mx=max(max(A[l]-B[i],mAB1.query(i,l-1)),mx);
    }
    cout<<"Case #"<<tt+1<<'\n';
    cout<<mx<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    rng(tt,0,t-1){
        Solve(tt);
    }
    return 0;
}

