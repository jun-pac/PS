
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
// random_device rd; 
// mt19937 gen(rd());
// uniform_int_distribution<> dist(0, INF); // random integer from [0, INF] // dist(gen)
// 중요한 건 대소관계가 유지된다는 거임(같아질수는 있음)

pll datas[N];


class lazy_cnt_tree{
public:
	lazy_cnt_tree(){}
	int seg[1<<20];
	void build_seg(int idx, int l, int r){
		if(l==r){
			seg[idx]=l+1;
			return;
		}
		int mid=(l+r)>>1;
		build_seg(2*idx,l,mid);
		build_seg(2*idx+1,mid+1,r);
		seg[idx]=0; // For multiple use
	}
	void update_seg(int idx, int l, int r, int t_l, int t_r, int val){
		if(t_l<=l && r<=t_r){
			seg[idx]+=val;
			return;
		}
		int mid=(l+r)>>1;
		if(t_l<=mid) update_seg(2*idx,l,mid,t_l,t_r,val);
		if(t_r>mid) update_seg(2*idx+1,mid+1,r,t_l,t_r,val);
	}

	int find_seg(int idx, int l, int r, int t_idx){
		if(l==r) return seg[idx];
		int res=seg[idx];
		int mid=(l+r)>>1;
		if(t_idx<=mid) res=res+find_seg(2*idx,l,mid,t_idx);
		if(t_idx>mid) res=res+find_seg(2*idx+1,mid+1,r,t_idx);
		return res;
	}
};

lazy_cnt_tree lct;

void Solve(){
    int n;
    cin>>n;
    rng(i,0,n-1) cin>>datas[i].fi>>datas[i].se;
    lct.build_seg(1,0,N-1); // 1, ... ,n까지
    rng(i,0,n-1){
        if(lct.find_seg(1,0,N-1,N-1) < datas[i].fi || lct.find_seg(1,0,N-1,0) > datas[i].se) continue;
        int s,e,l,r;
        // s는 datas[i].fi이상인 값을 가지는 최소의 녀석.
        l=0, r=N-1;
        while(l<r){
            int mid=(l+r)>>1;
            if(lct.find_seg(1,0,N-1,mid) >= datas[i].fi) r=mid;
            else l=mid+1;
        }
        s=l;
        // e는 datas[i].se이하의 값을 가지는 최대의 녀석. 
        l=0, r=N-1;
        while(l<r){
            int mid=(l+r+1)>>1;
            if(lct.find_seg(1,0,N-1,mid) <= datas[i].se) l=mid;
            else r=mid-1;
        }
        e=l;
        lct.update_seg(1,0,N-1,s,e,1);
    }
    
    int q;
    cin>>q;
    rng(i,0,q-1){
        ll x;
        cin>>x;
        cout<<lct.find_seg(1,0,N-1,x-1)<<'\n';
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

