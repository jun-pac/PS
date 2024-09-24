
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

vector<int> edges[N], child[N];
int parent[N], depth[N], in[N], top[N];
int sz[N], inv_in[N]; // HLD내부적으로 필요. inv_in은 seg의 초기화에 필요.
int n, cnt; 
ll val[N];
int order[N];


void DFS(int idx, int p){
	child[idx].reserve(edges[idx].size()-1);
	for(int i=0; i<edges[idx].size(); i++){
		int next=edges[idx][i];
		if(next!=p){
			child[idx].push_back(next);
			DFS(next,idx);
		}
	}
}

void DFS1(int idx=0){
	sz[idx]=1;
	for(int i=0; i<child[idx].size(); i++){
		int next=child[idx][i];
		parent[next]=idx;
		depth[next]=depth[idx]+1;
		DFS1(next);
		sz[idx]+=sz[next];
		if(sz[next]>sz[child[idx][0]]) swap(child[idx][0],child[idx][i]);
	}
}

void DFS2(int idx=0){
	in[idx]=cnt++;
	for(int i=0; i<child[idx].size(); i++){
		int next=child[idx][i];
		top[next]=(i==0?top[idx]:next);
		DFS2(next);
	}
}

class node{
public:
    ll mx=0, sum=0;
    node operator+(node b){
        node res;
        res.mx=max(mx,b.mx);
        res.sum=sum+b.sum;
        return res;
    }
};

class segtree{
public:	
	node seg[1<<19];
	int info;
	segtree(){}
	segtree(int n){}
	
	void build_seg(int idx, int l, int r){
		if(l==r){
			seg[idx].sum=val[inv_in[l]];
            seg[idx].mx=order[inv_in[l]];
			return;
		}
		int mid=(l+r)>>1;
		build_seg(2*idx,l,mid);
		build_seg(2*idx+1,mid+1,r);
		seg[idx]=(seg[2*idx]+seg[2*idx+1]); // Modify
	}

	node find_seg(int idx, int l, int r, int t_l, int t_r){
		if(t_l<=l && r<=t_r) return seg[idx];
		int mid=(l+r)>>1;
        node ans;
        ans.mx=ans.sum=0;
		if(t_l<=mid) ans=(ans+find_seg(2*idx,l,mid,t_l,t_r)); // Modify
		if(t_r>mid) ans=(ans+find_seg(2*idx+1,mid+1,r,t_l,t_r)); // Modify
		return ans;
	}
};

segtree seg;

class lazy_cnt_tree{
public:
	lazy_cnt_tree(){}
	long long seg[1<<19];
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
	void update_seg(int idx, int l, int r, int t_l, int t_r, long long val){
		if(t_l<=l && r<=t_r){
			seg[idx]+=val;
			return;
		}
		int mid=(l+r)>>1;
		if(t_l<=mid) update_seg(2*idx,l,mid,t_l,t_r,val);
		if(t_r>mid) update_seg(2*idx+1,mid+1,r,t_l,t_r,val);
	}

	long long find_seg(int idx, int l, int r, int t_idx){
		if(l==r) return seg[idx];
		long long res=seg[idx];
		int mid=(l+r)>>1;
		if(t_idx<=mid) res=res+find_seg(2*idx,l,mid,t_idx);
		if(t_idx>mid) res=res+find_seg(2*idx+1,mid+1,r,t_idx);
		return res;
	}
};

lazy_cnt_tree lct;

void update_query(int a, int b){
    while(top[a]!=top[b]){
		if(depth[top[a]]<depth[top[b]]) swap(a,b);
		lct.update_seg(1,0,n-1,in[top[a]],in[a],1);
		a=parent[top[a]];
	}
	if(a!=b) lct.update_seg(1,0,n-1,min(in[a],in[b])+1,max(in[a],in[b]),1);
}


node find_query(int a, int b){
    node res;
    res.mx=res.sum=0; 
	while(top[a]!=top[b]){
		if(depth[top[a]]<depth[top[b]]) swap(a,b);
		res=res+seg.find_seg(1,0,n-1,in[top[a]],in[a]);
		a=parent[top[a]];
	}
	if(a!=b) res=res+seg.find_seg(1,0,n-1,min(in[a],in[b])+1,max(in[a],in[b]));
    return res;
}

ll mul[N];
vc<pll> mulidx;
pll qs[N];

void Solve(){
    cin>>n;
    cnt=0;
    ll tot;
    cin>>tot;
    rng(i,0,n-1) edges[i].clear();
    rng(i,0,n-1) child[i].clear();
    rng(i,1,n-1){
        int p;
        cin>>p;
        p--;
        edges[p].pb(i);
        edges[i].pb(p);
    }
    DFS(0,-1);
    DFS1(0);
    DFS2(0);
    lct.build_seg(1,0,n-1);
    rng(i,0,n-1) update_query(i,(i+1)%n);
    rng(i,1,n-1) mul[i]=lct.find_seg(1,0,n-1,in[i]);
    // cout<<"MUL : ";
    // rng(i,1,n-1) cout<<lct.find_seg(1,0,n-1,in[i])<<' ';
    // cout<<'\n';
    rng(i,0,n-1) inv_in[in[i]]=i;

    rng(i,0,n-2){
        ll idx, v;
        cin>>idx>>v;
        idx--;
        qs[i]={idx,v};
        order[idx]=i;
        val[idx]=v;
    }
    seg.build_seg(1,0,n-1);
    mulidx.clear(); // {mx, sum} // (i, i+1)의 mx가 어딘지를
    rng(i,0,n-1){
        node temp=find_query(i,(i+1)%n);
        mulidx.pb({temp.mx,temp.sum});
        //cout<<i<<' '<<(i+1)%n<<' '<<temp.mx<<' '<<temp.sum<<'\n';
    }
    sort(all(mulidx));

    
    ll offset=0;
    ll left=n;
    rng(i,0,n-2){
        pll ff={i,-1};
        int idx=lower_bound(mulidx.begin(),mulidx.end(),ff)-mulidx.begin();
        tot-=qs[i].se;
        offset+=qs[i].se*mul[qs[i].fi];
        while(idx<n && mulidx[idx].fi==i){
            left--;
            idx++;
        }
        cout<<tot*left+offset<<' ';
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

