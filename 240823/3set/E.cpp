
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

ll datas[N];
ll sum[N];
bool pos[N];

class segtree{
public:	
	ll seg[1<<19];
	segtree(){}
	segtree(int n){}
	
	void build_seg(int idx, int l, int r){
		if(l==r){
			seg[idx]=datas[l]-(l==0?0:sum[l-1]);
			return;
		}
		int mid=(l+r)>>1;
		build_seg(2*idx,l,mid);
		build_seg(2*idx+1,mid+1,r);
		seg[idx]=min(seg[2*idx],seg[2*idx+1]); // Modify
	}

	ll find_seg(int idx, int l, int r, int t_l, int t_r){
		if(t_l<=l && r<=t_r) return seg[idx];
		ll mid=(l+r)>>1, ans=0;
		if(t_l<=mid) ans=max(ans,find_seg(2*idx,l,mid,t_l,t_r)); // Modify
		if(t_r>mid) ans=max(ans,find_seg(2*idx+1,mid+1,r,t_l,t_r)); // Modify
		return ans;
	}
};

segtree seg;

void Solve(){
    int n,x;
    cin>>n>>x;
    assert(n==x);
    rng(i,0,n-1) cin>>datas[i];
    rng(i,0,n-1) sum[i]=(i==0?0:sum[i-1])+datas[i];
    int last_suc=-1;
    int res=0;
    seg.build_seg(1,0,n-1);
    rng(i,0,n-1){
        if(last_suc==-1){
            if(seg.find_seg(1,0,n-1,i+1,n-1)<=0){
                res++;
                last_suc=i;
            } 
        }
        else{
            if(sum[i]-sum[last_suc]>=datas[last_suc]){
                res++;
                last_suc=i;
                continue;
            }
            int l=i, r=n-1;
            while(l<r){
                int mid=(l+r)>>1;
                if(sum[mid]-sum[last_suc]>=datas[last_suc]) r=mid;
                else l=mid+1;
            }
            assert(i<l);
            if(seg.find_seg(1,0,n-1,i+1,l)+sum[last_suc]<=0){
                res++;
                last_suc=i;
            } 
        }
    }
    cout<<res<<'\n';
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

