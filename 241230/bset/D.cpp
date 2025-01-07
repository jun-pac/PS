
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
#define INF 2000000007000000007 

ll A[N], B[N]; // A[i] for odd value

class node{
public:
    node(){}
    node(ll a, ll b){
        even=b;
        odd=a;
    }
    ll even, odd;
    node operator+(node b){
        // 
        node res;
        if(even%2==0) res.even=even^b.even;
        else res.even=even^b.odd;
        if(odd%2==0) res.odd=odd^b.odd;
        else res.odd=odd^b.even;
        return res;
    }
};

class segtree{
public:	
	node seg[1<<19];
	
	void build_seg(int idx, int l, int r){
		if(l==r){
			seg[idx]=node(A[l], B[l]);
			return;
		}
		int mid=(l+r)>>1;
		build_seg(2*idx,l,mid);
		build_seg(2*idx+1,mid+1,r);
		seg[idx]=(seg[2*idx]+seg[2*idx+1]); // Modify
	}

	void update_seg(int idx, int l, int r, int t_idx, ll a, ll b){
		if(l==r){
			seg[idx]=node(a,b); // Modify
			return;
		}
		int mid=(l+r)>>1;
		if(t_idx<=mid) update_seg(2*idx,l,mid,t_idx, a,b);
		else update_seg(2*idx+1,mid+1,r,t_idx, a,b);
		seg[idx]=(seg[2*idx]+seg[2*idx+1]); // Modify
	}

	node find_seg(int idx, int l, int r, int t_l, int t_r){
		if(t_l<=l && r<=t_r) return seg[idx];
		int mid=(l+r)>>1;
        node ans;
        bool clean=1;
		if(t_l<=mid){
            ans=find_seg(2*idx,l,mid,t_l,t_r);
            clean=1;
        }
		if(t_r>mid){
            if(!clean) ans=(ans+find_seg(2*idx+1,mid+1,r,t_l,t_r));
            else ans=find_seg(2*idx+1,mid+1,r,t_l,t_r);
        }
		return ans;
	}
};

segtree seg;

void Solve(){
    int n,m;
    cin>>n>>m;
    rng(i,0,n-1) cin>>A[i];
    rng(i,0,n-1) cin>>B[i];
    seg.build_seg(1,0,n-1);
    rng(i,0,m-1){
        ll c;
        ll d,a,b;
        cin>>c>>d>>a>>b;
        if(c==1){
            // modify
            d--;
            seg.update_seg(1,0,n-1,d,a,b);
            A[d]=a;
            B[d]=b;
        }
        else{
            // print
            // is it possible to make Y 
            auto res=seg.find_seg(1,0,n-1,0,n-1);
            ll mn=INF;
            if(res.even%2==d%2){
                mn=min(mn,d^(res.even));
            }
            if(res.odd%2!=d%2){
                mn=min(mn,d^(res.odd));
            }
            cout<<(mn==INF?-1:mn)<<'\n';
        }
    }
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

