
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

#define N 500030
#define MOD 998244353
#define INF 1000000007 
__attribute__((optimize("Ofast,unroll-loops"),target("avx,avx2,fma")))

ll datas[N];

#define LOG2 21

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
				sp_table[idx][i]=min(sp_table[idx-1][i],sp_table[idx-1][i+(1<<(idx-1))]);
			}   
		}
		LG[1]=0;
		for(int i=2; i<=n; i++) LG[i]=LG[i/2]+1;
	}
	long long query(int a, int b){
		// [a,b] minimum query
		assert(a<=b);
		int lgn=LG[b-a+1];
		return min(sp_table[lgn][a],sp_table[lgn][b-(1<<lgn)+1]);
	}
};
RMQ rmq;

class lazy_cnt_tree{
public:
	lazy_cnt_tree(){}
	long long seg[1<<20];
	void build_seg(int idx, int l, int r){
		if(l==r){
			seg[idx]=0;
			return;
		}
		int mid=(l+r)>>1;
		build_seg(2*idx,l,mid);
		build_seg(2*idx+1,mid+1,r);
		seg[idx]=0; // For multiple use
	}
	void update_seg(int idx, int l, int r, int t_l, int t_r, long long val){
		if(t_l<=l && r<=t_r){
			seg[idx]=max(seg[idx],val);
			return;
		}
		int mid=(l+r)>>1;
		if(t_l<=mid) update_seg(2*idx,l,mid,t_l,t_r,val);
		if(t_r>mid) update_seg(2*idx+1,mid+1,r,t_l,t_r,val);
	}

	long long find_seg(int idx, int l, int r, int t_idx){
		if(l==r) return seg[idx];
		long long res=seg[idx];
		int mid=(l+r)>>1;
		if(t_idx<=mid) res=max(res,find_seg(2*idx,l,mid,t_idx));
		if(t_idx>mid) res=max(res,find_seg(2*idx+1,mid+1,r,t_idx));
		return res;
	}
};

lazy_cnt_tree lct;

void Solve(){
    int n;
    cin>>n;
    rng(i,0,n-1) cin>>datas[i];
    lct.build_seg(1,0,n-1);

    rmq.build_sparse(n);
    rng(i,0,n-1){
        int s,e;
        int l=0, r=i;
        while(l<r){
            int mid=(l+r)>>1;
            if(rmq.query(mid,i)<datas[i]) l=mid+1;
            else r=mid;
        }
        s=l;
        l=i, r=n-1;
        while(l<r){
            int mid=(l+r+1)>>1;
            if(rmq.query(i,mid)<datas[i]) r=mid-1;
            else l=mid;
        }
        e=l;
        if(0<=s-1) lct.update_seg(1,0,n-1,0,s-1,(e-s+1)*datas[i]);
        lct.update_seg(1,0,n-1,s,e,(e-s)*datas[i]);
        if(e+1<=n-1) lct.update_seg(1,0,n-1,e+1,n-1,(e-s+1)*datas[i]);
        if(0<s-1 && datas[s-2]>=datas[i]){
            int ls;
            l=0, r=s-2;
            while(l<r){
                int mid=(l+r)>>1;
                if(rmq.query(mid,s-2)<datas[i]) l=mid+1;
                else r=mid;
            }
            ls=l;
            lct.update_seg(1,0,n-1,s-1,s-1,(e-ls)*datas[i]);
        }
        if(e+1<n-1 && datas[e+2]>=datas[i]){
            int rs;
            l=e+2, r=n-1; 
            while(l<r){
                int mid=(l+r+1)>>1;
                if(rmq.query(e+2,mid)<datas[i]) r=mid-1;
                else l=mid;
            }
            rs=r;
            lct.update_seg(1,0,n-1,e+1,e+1,(rs-s)*datas[i]);
            //cout<<"right "<<i<<' '<<e+1<<' '<<(rs-s)<<' '<<datas[i]<<"\n";
        }
    }
    rng(i,0,n-1) cout<<lct.find_seg(1,0,n-1,i)<<' ';
    cout<<'\n';    
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

