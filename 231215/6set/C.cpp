
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
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
pll DP[N];


using namespace std;
class segtree{
public:	
	ll seg[1<<19];
	int info;
	segtree(){}
	segtree(int n){}
	
	void build_seg(int idx, int l, int r){
		if(l==r){
			seg[idx]=sum[l];
			return;
		}
		int mid=(l+r)>>1;
		build_seg(2*idx,l,mid);
		build_seg(2*idx+1,mid+1,r);
		seg[idx]=min(seg[2*idx],seg[2*idx+1]); // Modify
	}

	ll find_seg(int idx, int l, int r, int t_l, int t_r){
		if(t_l<=l && r<=t_r) return seg[idx];
		ll mid=(l+r)>>1, ans=1000000000000000LL;
		if(t_l<=mid) ans=min(ans,find_seg(2*idx,l,mid,t_l,t_r)); // Modify
		if(t_r>mid) ans=min(ans,find_seg(2*idx+1,mid+1,r,t_l,t_r)); // Modify
		return ans;
	}
};

segtree seg;

void Solve(){
    int n;
    cin>>n;
    rng(i,0,n-1) cin>>datas[i];
    if(n==1){
        cout<<datas[0]<<'\n';
        return;
    }
    rng(i,0,n-1) sum[i]=(i==0?0:sum[i-1])+datas[i];
    ll ans=sum[n-1], k=1;
    rng(i,0,n-2){
        // a[i] a[i+1]사이의 경계
        if(sum[n-1]-sum[i]>0){
            k++;
            ans+=sum[n-1]-sum[i];
        }
    }
    cout<<ans<<'\n';
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

