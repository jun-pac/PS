
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

#define N 1000001
#define MOD 998244353
#define INF 1000000007 
#define LOG2 21
int datas[N];


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
		// [a,b] minimum query
		assert(a<=b);
		int lgn=LG[b-a+1];
		return max(sp_table[lgn][a],sp_table[lgn][b-(1<<lgn)+1]);
	}
};

int leftend[N], rightend[N]; // inclusive
RMQ rmq;
int sqrtN=2000;

class Query{
public:
	int idx, s, e;
	bool operator < (Query &x){
		if(s/sqrtN != x.s/sqrtN) return s/sqrtN < x.s/sqrtN;
		return e < x.e;
	}
};

Query qs[N];
ll ans[N];
ll val=0;


// class segtree{
// public:	
// 	int seg[1<<21];
// 	int info;
// 	segtree(){}
// 	segtree(int n){}
	
// 	void build_seg(int idx, int l, int r){
// 		if(l==r){
// 			seg[idx]=0;
// 			return;
// 		}
// 		int mid=(l+r)>>1;
// 		build_seg(2*idx,l,mid);
// 		build_seg(2*idx+1,mid+1,r);
// 		seg[idx]=(seg[2*idx]+seg[2*idx+1]); // Modify
// 	}

// 	void update_seg(int idx, int l, int r, int t_idx, int val){
// 		if(l==r){
// 			seg[idx]+=val; // Modify
// 			return;
// 		}
// 		int mid=(l+r)>>1;
// 		if(t_idx<=mid) update_seg(2*idx,l,mid,t_idx, val);
// 		else update_seg(2*idx+1,mid+1,r,t_idx, val);
// 		seg[idx]=(seg[2*idx]+seg[2*idx+1]); // Modify
// 	}

// 	int find_seg(int idx, int l, int r, int t_l, int t_r){
// 		if(t_l<=l && r<=t_r) return seg[idx];
// 		int mid=(l+r)>>1, ans=0;
// 		if(t_l<=mid) ans=(ans+find_seg(2*idx,l,mid,t_l,t_r)); // Modify
// 		if(t_r>mid) ans=(ans+find_seg(2*idx+1,mid+1,r,t_l,t_r)); // Modify
// 		return ans;
// 	}
// };


struct FenwickTree {
    int bit[N];
    int n=N;

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

FenwickTree seg_right;
FenwickTree seg_left;



int n,s,e;
inline void go(int idx){
    if(s==e){
        val=0;
    }
    else if(idx==e){
        val+=idx-max(s,leftend[idx]);
        val+=seg_right.sum(idx,n-1);
    }
    else{
        val+=min(e,rightend[idx])-idx;
        val+=seg_left.sum(0,idx);
    }
    seg_right.add(rightend[idx],1);
    seg_left.add(leftend[idx],1);
}

inline void back(int idx){
    seg_right.add(rightend[idx],-1);
    seg_left.add(leftend[idx],-1);
    if(s==e) val=0;
    else if(idx==e){
        val-=idx-max(s,leftend[idx]);
        val-=seg_right.sum(idx,n-1);
    }
    else{
        val-=min(e,rightend[idx])-idx;
        val-=seg_left.sum(0,idx);
    }
}


void Solve(){
    int q;
    cin>>n>>q;
    rng(i,0,n-1) cin>>datas[i];
    rmq.build_sparse(n);
    // seg_right(n);
    // seg_left(n);
    // seg_right.build_seg(1,0,n-1);
    // seg_left.build_seg(1,0,n-1);
    seg_right.n=n;
    seg_left.n=n;
    leftend[0]=0;
    rng(i,1,n-1){
        if(datas[i-1]>datas[i]) leftend[i]=i;
        else{
            int l=0, r=i-1;
            while(l<r){
                int mid=(l+r)>>1;
                if(rmq.query(mid,i-1)<datas[i]) r=mid;
                else l=mid+1;
            }
            leftend[i]=l;
        }
    }

    rightend[n-1]=n-1;
    gnr(i,n-2,0){
        if(datas[i+1]>datas[i]) rightend[i]=i;
        else{
            int l=i+1, r=n-1;
            while(l<r){
                int mid=(l+r+1)>>1;
                if(rmq.query(i+1,mid)<datas[i]) l=mid;
                else r=mid-1;
            }
            rightend[i]=l;
        }
    }

    rng(i,0,q-1){
        int a,b;
        cin>>a>>b;
        a--, b--;
        qs[i].s=a;
        qs[i].e=b;
        qs[i].idx=i;
        // cout<<i<<' '<<a<<' '<<b<<'\n';
    }
    sort(qs,qs+q);
    // rng(i,0,q-1) cout<<qs[i].s<<' '<<qs[i].e<<' '<<qs[i].idx<<'\n';
    
    val=0;
    s = qs[0].s, e = qs[0].s-1;
    for(int i=qs[0].s; i<=qs[0].e; i++){
		go(++e);
	}
    // cout<<"idx "<<qs[0].idx<<' '<<s<<' '<<e<<' '<<val<<'\n';
    ans[qs[0].idx] = val;
    rng(i,1,q-1){
        while(s > qs[i].s) go(--s);
        while(e < qs[i].e) go(++e);
        while(s < qs[i].s) back(s), s++;
		while(e > qs[i].e) back(e), e--;
        ans[qs[i].idx]=val;
    }

    rng(i,0,q-1) cout<<ans[i]<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    // cin>>t;
    while(t--){
        Solve();
    }
    return 0;
}

