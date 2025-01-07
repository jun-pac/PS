
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
random_device rd; 
mt19937 gen(rd());
uniform_int_distribution<> dist(0, INF); // random integer from [0, INF] // dist(gen)

int datas[N];
#define LOG2 20

class leftmx{ // i-a[i]
public:
	long long sp_table[LOG2][N]; 
	long long LG[N+1]; 
	void build_sparse(int n){
		for(int i=0; i<n; i++) sp_table[0][i]=i-datas[i];
		for(int idx=1; (1<<idx)<=n; idx++){
			for(int i=0; i+(1<<idx)<=n; i++){
				sp_table[idx][i]=max(sp_table[idx-1][i],sp_table[idx-1][i+(1<<(idx-1))]);
			}   
		}
		LG[1]=0;
		for(int i=2; i<=n; i++) LG[i]=LG[i/2]+1;
	}
	long long query(int a, int b){
		assert(a<=b);
		int lgn=LG[b-a+1];
		return max(sp_table[lgn][a],sp_table[lgn][b-(1<<lgn)+1]);
	}
};

class rightmn{ // i+a[i]
public:
	long long sp_table[LOG2][N]; 
	long long LG[N+1]; 
	void build_sparse(int n){
		for(int i=0; i<n; i++) sp_table[0][i]=i+datas[i];
		for(int idx=1; (1<<idx)<=n; idx++){
			for(int i=0; i+(1<<idx)<=n; i++){
				sp_table[idx][i]=min(sp_table[idx-1][i],sp_table[idx-1][i+(1<<(idx-1))]);
			}   
		}
		LG[1]=0;
		for(int i=2; i<=n; i++) LG[i]=LG[i/2]+1;
	}
	long long query(int a, int b){
		assert(a<=b);
		int lgn=LG[b-a+1];
		return min(sp_table[lgn][a],sp_table[lgn][b-(1<<lgn)+1]);
	}
};

leftmx lmx;
rightmn rmn;
int incompat[N];


void Solve(){
    int n;
    cin>>n;
    rng(i,0,n-1) cin>>datas[i];
    rng(i,0,n-1) datas[i]--;
    lmx.build_sparse(n);
    rmn.build_sparse(n);
    rng(i,0,n-2){
        int temp=-1;
        int ridx=datas[i]+i;
        // if(ridx<=n-1){
        //     if(i-datas[ridx]==i) temp=ridx;
        // }
        if(ridx<n-1 && lmx.query(ridx+1,n-1)>i){
            int l=ridx+1, r=n-1;
            while(l<r){
                int mid=(l+r+1)>>1;
                if(lmx.query(mid,n-1)>i) l=mid;
                else r=mid-1;
            }
            temp=l;
        }
        incompat[i]=temp;
    }
    int mxincom=0;
    int cnt=0;
    rng(i,0,n-1){
        bool flag=1;
        if(i!=0){
            // leftcheck. [0,i-1]'s datas[j]+j>=i
            if(rmn.query(0,i-1)<i) flag=0;
        }
        if(i!=n-1){
            if(lmx.query(i+1,n-1)>i) flag=0;
        }
        if(i!=0){
            if(mxincom>=i) flag=0;
        }
        if(flag) cnt++;
        mxincom=max(mxincom,incompat[i]);
    }
    cout<<cnt<<'\n';
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

