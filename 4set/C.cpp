
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
		for(int i=0; i<n; i++) sp_table[0][i]=temp[i];
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
RMQ rmq_plus_left; 
RMQ rmq_neg_right; 
RMQ rmq_neg_left; 

void Solve(){
    // Whatever Bob does, Alice can revert it and earn money.
    // Bob will never get what he want
    // Alice does something -> Bob ends

    int n;
    cin>>n;
    rng(i,0,n-1) cin>>datas[i];
    int posnum=(n+1)/2;
    int negnum=n-posnum;

    ll res=0, mx=0;
    rng(i,0,n-1) res=res+(i%2?-datas[i]:datas[i]);
    mx=res;

    // cout<<"RES "<<res<<'\n';


    rng(i,0,posnum-1) temp[i]=-2*datas[2*i]+2*i;
    rmq_plus_right.build_sparse(posnum);

    rng(i,0,posnum-1) temp[i]=-2*datas[2*i]+n-1-2*i;
    rmq_plus_left.build_sparse(posnum);
    // cout<<"q 0 0 "<<temp[0]<<' '<<rmq_plus_left.query(0,0)<<'\n';
    // cout<<posnum<<' '<<negnum<<"\n";

    rng(i,0,negnum-1) temp[i]=2*datas[2*i+1]+2*i+1;
    rmq_neg_right.build_sparse(negnum);

    rng(i,0,negnum-1) temp[i]=2*datas[2*i+1]+n-1-(2*i+1);
    rmq_neg_left.build_sparse(negnum);
    
    rng(i,0,n-1){
        ll addi=0;
        if(i%2==0){
            addi=max(addi,(ll)((n%2==0?n-2:n-1) - i));
            addi=max(addi,(ll)(i));
            // right side
            if(i!=n-1){
                // cout<<"W? "<<rmq_neg_right.query(i/2, negnum-1)<<' '<<datas[i]<<'\n';
                addi=max(addi,rmq_neg_right.query(i/2, negnum-1)-2*datas[i]-i);
                // cout<<"ad "<<addi<<'\n';
            }

            // left side
            if(i!=0) addi=max(addi,rmq_neg_left.query(0, i/2-1)-2*datas[i]-(n-1-i));

        }
        else{
            addi=max(addi,(ll)((n%2==0?n-1:n-2) - i));
            addi=max(addi,(ll)(i-1));
            // right side
            if(i!=2*negnum-1) addi=max(addi,rmq_plus_right.query(i/2+1, posnum-1)+2*datas[i]-i);

            // left side
            if(i!=1){
                // cout<<"w? "<<rmq_plus_left.query(0, i/2)<<' '<<2*datas[i]<<'\n';
                addi=max(addi,rmq_plus_left.query(0, i/2)+2*datas[i]-(n-1-i));
            }
        }
        // cout<<"ad "<<i<<' '<<addi<<"\n";
        mx=max(mx,res+addi);
    }
    cout<<mx<<'\n';
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

