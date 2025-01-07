
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

using namespace std;


class lazy_cnt_tree{
public:
	lazy_cnt_tree(){}
	long long seg[1<<19];
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
			seg[idx]+=val;
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
		if(t_idx<=mid) res=res+find_seg(2*idx,l,mid,t_idx);
		if(t_idx>mid) res=res+find_seg(2*idx+1,mid+1,r,t_idx);
		return res;
	}
};

lazy_cnt_tree lct;

class RMQ{
public:
	int sp_table[LOG2][N]; // NlogN size sparse table
	int LG[N+1]; // LG[idx]=floor(log_2[idx]) 
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
	int query(int a, int b){
		int lgn=LG[b-a+1];
		return max(sp_table[lgn][a],sp_table[lgn][b-(1<<lgn)+1]);
	}
};

RMQ rmq;
int ans[N];
array<int,3> qs[N]; // {mx,r,idx}
pii sort_h[N];
void Solve(){
    int n,q;
    cin>>n>>q;
    rng(i,0,n-1) cin>>datas[i];
    rng(i,0,n-1) sort_h[i]={datas[i],i};

    rmq.build_sparse(n);
    // preprocessing이 필요하다. 모든 r에 대해서 답 구해놓기
    rng(i,0,q-1){
        int l,r;
        cin>>l>>r;
        l--, r--;
        array<int,3> temp={rmq.query(l+1,r),r,i};
        qs[i]=temp;
    }
    sort(qs,qs+q);
    reverse(qs,qs+q);
    sort(sort_h,sort_h+n);
    reverse(sort_h,sort_h+n);
    lct.build_seg(1,0,n-1);
    int last=sort_h[0].fi;
    int qidx=0;
    rng(i,0,n-1){
        if(sort_h[i].fi!=last){
            while(qidx<q && qs[qidx][0]>=last){
                ans[qs[qidx][2]]=lct.find_seg(1,0,n-1,qs[qidx][1]);
                qidx++;
            }
        }
        int idx=sort_h[i].se;
        int h=sort_h[i].fi;
        if(idx==0){

        }
        else if(rmq.query(0,idx-1) <= h){
            lct.update_seg(1,0,n-1,0,idx-1,1);
        }
        else{
            int l=0, r=idx-1;
            while(l<r){
                int mid=(l+r+1)>>1;
                if(rmq.query(mid,idx-1)>h) l=mid;
                else r=mid-1;
            }
            lct.update_seg(1,0,n-1,l,idx-1,1);
        }
        last=sort_h[i].fi;
    }
    while(qidx<q){
        ans[qs[qidx][2]]=lct.find_seg(1,0,n-1,qs[qidx][1]);
        qidx++;
    }

    rng(i,0,q-1) cout<<ans[i]<<'\n';

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

