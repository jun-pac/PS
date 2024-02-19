
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
#define INF 1000000000000007 

int n;
ll datas[N];
ll sum[N], DP[N];
class segtree{
public:	
	ll seg[1<<18];
	int info;
	segtree(){}
	segtree(int n){}
	
	void build_seg(int idx, int l, int r){
		if(l==r){
			seg[idx]=0;
			return;
		}
		int mid=(l+r)>>1;
		build_seg(2*idx,l,mid);
		build_seg(2*idx+1,mid+1,r);
		seg[idx]=0;
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

bool check(ll mx){
    //cout<<"check : "<<mx<<'\n';
    if(sum[n-1]<=mx) return 1;
    seg.build_seg(1,0,n-1);
    DP[0]=datas[0];
    seg.update_seg(1,0,n-1,0,DP[0]);
    int l=-1; // [l,i-1]이 직전 block으로서 가능한 범위임
    // l에다 했으면 datas[l+1], ... , datas[i-1] = sum[i-1] - sum[l] <= mx일 때만 가능
    rng(i,1,n-1){
        while(l<i-1 && sum[i-1]-(l==-1?0:sum[l])>mx) l++;
        // DP[i]= max(DP[l], ... , DP[i-1]) + datas[i];
        if(l==-1) DP[i]=datas[i];
        else DP[i]=seg.find_seg(1,0,n-1,l,i-1)+datas[i];
        seg.update_seg(1,0,n-1,i,DP[i]);
    }
    while(l<n-1 && sum[n-1]-(l==-1?0:sum[l])>mx) l++;

    ll res=INF;
    assert(l!=-1);
    res=min(res,seg.find_seg(1,0,n-1,l,n-1));
    return res<=mx;
}

void Solve(){
    cin>>n;
    rng(i,0,n-1) cin>>datas[i];
    rng(i,0,n-1) sum[i]=(i==0?0:sum[i-1]) + datas[i];
    ll l=0, r=sum[n-1];
    while(l<r){
        ll mid=(l+r)>>1;
        if(check(mid)) r=mid;
        else l=mid+1;
    }
    cout<<l<<'\n';
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

