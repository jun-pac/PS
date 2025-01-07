
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

#define N 400030
#define MOD 998244353
const ll INF=10000000000000007; 
ll a[N], b[N], suma[N];
vc<int> redges[N];

class segtree{
public:	
	ll seg[1<<20];
	segtree(){}
	segtree(int n){}
	
	void build_seg(int idx, int l, int r){
		if(l==r){
			seg[idx]=INF;
			return;
		}
		int mid=(l+r)>>1;
		build_seg(2*idx,l,mid);
		build_seg(2*idx+1,mid+1,r);
		seg[idx]=min(seg[2*idx],seg[2*idx+1]); // Modify
	}

	void update_seg(int idx, int l, int r, int t_idx, ll val){
		if(l==r){
			seg[idx]=val; // Modify
			return;
		}
		int mid=(l+r)>>1;
		if(t_idx<=mid) update_seg(2*idx,l,mid,t_idx, val);
		else update_seg(2*idx+1,mid+1,r,t_idx, val);
		seg[idx]=min(seg[2*idx],seg[2*idx+1]); // Modify
	}

	ll find_seg(int idx, int l, int r, int t_l, int t_r){
        if(t_l<=l && r<=t_r) return seg[idx];
		int mid=(l+r)>>1;
        ll ans=INF;
		if(t_l<=mid) ans=min(ans,find_seg(2*idx,l,mid,t_l,t_r)); // Modify
		if(t_r>mid) ans=min(ans,find_seg(2*idx+1,mid+1,r,t_l,t_r)); // Modify
		return ans;
	}
};

segtree seg;

void Solve(){
    // a: score
    // b: next
    int n;
    cin>>n;
    rng(i,0,n-1) redges[i].clear();

    rng(i,0,n-1) cin>>a[i];
    rng(i,0,n-1){
        cin>>b[i];
        b[i]--;
        if(b[i]<=i) continue;
        redges[b[i]].pb(i);
    }

    rng(i,0,n-1) suma[i]=(i==0?0LL:suma[i-1])+a[i];
    seg.build_seg(1,0,n-1);
    seg.update_seg(1,0,n-1,0,0); // Æ÷±âÇÑ score
    
    rng(i,1,n-1){
        ll res=INF;
        for(int j:redges[i]){
            res=min(res,a[j]+seg.find_seg(1,0,n-1,j,i-1));
        }
        seg.update_seg(1,0,n-1,i,res);
    }
    ll mx=a[0];
    rng(i,1,n-1){
        mx=max(mx,suma[i]-seg.find_seg(1,0,n-1,i,i));
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

