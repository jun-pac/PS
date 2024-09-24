
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

int datas[N];
int last_idx[N];
vc<int> pos[N];

class node{
public:
    node operator+(node b){
        node res;
        res.mx=max(mx,b.mx);
        res.mn=min(mn,b.mn);
        res.mxidx=(mx>=b.mx?mxidx:b.mxidx);
        res.mnidx=(mn<=b.mn?mnidx:b.mnidx);
        return res;
    }
    int mx, mn, mxidx, mnidx;
};

class segtree{
public:	
	node seg[1<<20];
	int info;
	segtree(){}
	segtree(int n){}
	
	void build_seg(int idx, int l, int r){
		if(l==r){
			seg[idx].mx=datas[l];
            seg[idx].mn=datas[l];
            seg[idx].mxidx=seg[idx].mnidx=l;
			return;
		}
		int mid=(l+r)>>1;
		build_seg(2*idx,l,mid);
		build_seg(2*idx+1,mid+1,r);
		seg[idx]=(seg[2*idx]+seg[2*idx+1]); 
	}

	void update_seg(int idx, int l, int r, int t_idx){
        // disable
		if(l==r){
			seg[idx].mx=-INF;
            seg[idx].mn=INF;
			return;
		}
		int mid=(l+r)>>1;
		if(t_idx<=mid) update_seg(2*idx,l,mid,t_idx);
		else update_seg(2*idx+1,mid+1,r,t_idx);
		seg[idx]=(seg[2*idx]+seg[2*idx+1]);
	}

	node find_seg(int idx, int l, int r, int t_l, int t_r){
		if(t_l<=l && r<=t_r) return seg[idx];
		int mid=(l+r)>>1;
        node ans;
        ans.mn=INF, ans.mx=-INF;
		if(t_l<=mid) ans=(ans+find_seg(2*idx,l,mid,t_l,t_r)); // Modify
		if(t_r>mid) ans=(ans+find_seg(2*idx+1,mid+1,r,t_l,t_r)); // Modify
		return ans;
	}
};

segtree seg;

void Solve(){
    int n;
    cin>>n;
    rng(i,0,n-1) cin>>datas[i];
    int num=0;
    rng(i,0,n) pos[i].clear();
    rng(i,0,n-1){
        if(pos[datas[i]].size()==0) num++;
        pos[datas[i]].pb(i);
    }
    seg.build_seg(1,0,n-1);
    set<int> st;
    rng(i,1,n) if(pos[i].size()!=0) st.insert(*prev(pos[i].end())); // 여기에는 idx를 넣는다. set에서 가장 작은값은 쉽게 찾죠?
    vc<int> ans;
    int curidx=0; // 시작하는 지점
    rng(i,0,num-1){
        if(i%2==0){
            // [curidx, *st.begin()] 가장 큰 것
            int r=*st.begin();
            node res=seg.find_seg(1,0,n-1,curidx,r);
            ans.pb(res.mx);
            curidx=res.mxidx+1;
            for(int idx : pos[res.mx]){
                seg.update_seg(1,0,n-1,idx);
            }
            st.erase(*prev(pos[res.mx].end()));
        }
        else{
            int r=*st.begin();
            node res=seg.find_seg(1,0,n-1,curidx,r);
            //cout<<"even : "<<curidx<<' '<<r<<' '<<datas[r]<<' '<<res.mn<<' '<<res.mnidx<<'\n';
            ans.pb(res.mn);
            curidx=res.mnidx+1;
            for(int idx : pos[res.mn]){
                seg.update_seg(1,0,n-1,idx);
            }
            st.erase(*prev(pos[res.mn].end()));
        }
    }
    cout<<num<<'\n';
    rng(i,0,num-1) cout<<ans[i]<<' ';
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

