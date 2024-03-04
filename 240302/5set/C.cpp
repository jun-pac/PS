
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
__attribute__((optimize("Ofast,unroll-loops"),target("avx,avx2,fma")))

map<pii,int> mp;
ll datas[N];
vc<int> divs;
bool is_div[N];
ll sum[N];
ll bucket[N];

class segtree{
public:	
	int seg[1<<19];
	int info;
	segtree(){}
	segtree(int n){}
	
	void build_seg(int idx, int l, int r){
		if(l==r){
			// seg[idx]=datas[l];
			return;
		}
		int mid=(l+r)>>1;
		build_seg(2*idx,l,mid);
		build_seg(2*idx+1,mid+1,r);
		seg[idx]=(seg[2*idx]+seg[2*idx+1]); // Modify
	}

	void update_seg(int idx, int l, int r, int t_idx, int val){
		if(l==r){
			seg[idx]=val; // Modify
			return;
		}
		int mid=(l+r)>>1;
		if(t_idx<=mid) update_seg(2*idx,l,mid,t_idx, val);
		else update_seg(2*idx+1,mid+1,r,t_idx, val);
		seg[idx]=(seg[2*idx]+seg[2*idx+1]); // Modify
	}

	int find_seg(int idx, int l, int r, int t_l, int t_r){
		if(t_l<=l && r<=t_r) return seg[idx];
		int mid=(l+r)>>1, ans=0;
		if(t_l<=mid) ans=(ans+find_seg(2*idx,l,mid,t_l,t_r)); // Modify
		if(t_r>mid) ans=(ans+find_seg(2*idx+1,mid+1,r,t_l,t_r)); // Modify
		return ans;
	}
};

segtree seg;

void Solve(){
    int cnt=0;
    int n,q;
    cin>>n>>q;
    rng(i,0,n-1) cin>>datas[i];
    divs.clear();
    mp.clear();

    fill(is_div,is_div+n,0);
    for(int i=1; i<=(int)sqrt(n); i++){
        if(n%i==0){
            is_div[i]=1;
            is_div[n/i]=1;
        }
    }
    rng(i,1,n) if(is_div[i]) divs.pb(i);
    for(int d : divs){
        // d는 간격이다. 개수가 아니라
        int m=n/d; // m은 개수
        rng(i,0,n-1) sum[i]=(i<d?0:sum[i-d])+datas[i];
        // naming을 어떻게 할 것인지 
        rng(i,0,d-1){
            mp[{d,i}]=cnt;
            bucket[cnt]=;
            cnt++;
        }
    }

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

