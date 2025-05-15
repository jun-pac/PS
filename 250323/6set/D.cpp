
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

int datas[N], cnt[N];


#define LOG2 20

class RMQ{
public:
	long long sp_table[LOG2][N]; // NlogN size sparse table
	long long LG[N+1]; // LG[idx]=floor(log_2[idx]) 
	// Note that sp_table RMQ if fast(O(1) for each query), but it is immutable
	int info;
	void build_sparse(int n){
		for(int i=0; i<n; i++) sp_table[0][i]=cnt[i];
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

RMQ rmq;

class segtree{
public:	
    int seg[1<<19];
    int info;
    segtree(){}
    segtree(int n){}
    
    void build_seg(int idx, int l, int r){
        if(l==r){
            seg[idx]=cnt[l];
            return;
        }
        int mid=(l+r)>>1;
        build_seg(2*idx,l,mid);
        build_seg(2*idx+1,mid+1,r);
        seg[idx]=max(seg[2*idx],seg[2*idx+1]); // Modify
    }

    int find_seg(int idx, int l, int r, int t_l, int t_r){
        if(t_l<=l && r<=t_r) return seg[idx];
        int mid=(l+r)>>1, ans=0;
        if(t_l<=mid) ans=max(ans,find_seg(2*idx,l,mid,t_l,t_r)); // Modify
        if(t_r>mid) ans=max(ans,find_seg(2*idx+1,mid+1,r,t_l,t_r)); // Modify
        return ans;
    }
};

segtree seg;

class xorsegtree{
public:	
    int seg[1<<19];
    
    void build_seg(int idx, int l, int r){
        if(l==r){
            seg[idx]=datas[l];
            return;
        }
        int mid=(l+r)>>1;
        build_seg(2*idx,l,mid);
        build_seg(2*idx+1,mid+1,r);
        seg[idx]=seg[2*idx]^seg[2*idx+1]; // Modify
    }

    int find_seg(int idx, int l, int r, int t_l, int t_r){
        if(t_l<=l && r<=t_r) return seg[idx];
        int mid=(l+r)>>1, ans=0;
        if(t_l<=mid) ans=ans^find_seg(2*idx,l,mid,t_l,t_r); // Modify
        if(t_r>mid) ans=ans^find_seg(2*idx+1,mid+1,r,t_l,t_r); // Modify
        return ans;
    }
};

xorsegtree xorseg;

void Solve(){
    int n,q;
    cin>>n>>q;
    rng(i,0,n-1) cin>>datas[i];
    rng(i,0,n-1){
        int temp=datas[i];
        cnt[i]=0;
        while(temp!=0){
            temp>>=1;
            cnt[i]++;
        }
        // cout<<cnt[i]<<' ';
    }
    // cout<<'\n';
    // seg.build_seg(1,0,n-1);
    rmq.build_sparse(n);
    xorseg.build_seg(1,0,n-1);

    rng(i,0,q-1){
        int cur=0;
        cin>>cur;
        int curcnt=0;
        int curidx=n-1;
        int temp=cur;
        while(temp!=0){
            temp>>=1;
            curcnt++;
        }
        // [mid, curidx] 처음으로 curcnt이상의 값이 나오면 stop
        int ans=0;
        while(curidx>=0){
            int l=0, r=curidx;
            if(rmq.query(l,r)<curcnt){
                ans+=curidx-l+1;
                break;
            }
            while(l<r){
                int mid=(l+r+1)>>1;
                if(rmq.query(mid,curidx)>=curcnt) l=mid;
                else r=mid-1;               
            }
            if(l!=curidx) cur=cur^xorseg.find_seg(1,0,n-1,l+1,curidx);
            // cout<<"de "<<l<<' '<<curidx<<' '<<cur<<'\n';
            if(datas[l]>cur){
                ans+=curidx-l;
                break;
            }
            else{
                ans+=curidx-l+1;
                cur=cur^datas[l];
                curidx=l-1;
                temp=cur;
                curcnt=0;
                while(temp!=0){
                    temp>>=1;
                    curcnt++;
                }
            }
        }
        cout<<ans<<' ';
    }
    cout<<'\n';
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

