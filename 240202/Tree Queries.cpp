
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

vc<int> edges[N];
int pivot[N];
vc<int> dels[N];
pii s_qs[N]; // {pivot_idx, idx}
bool visited[N];
int cnt;
int in[N], out[N], invin[N];
int depth[N];
int ans[N];


void DFS(int idx, int d){
    visited[idx]=1;
    depth[idx]=d;
    in[idx]=cnt++;
    for(auto next : edges[idx]){
        if(!visited[next]) DFS(next,d+1);
    }
    out[idx]=cnt;
    //cout<<"in out "<<idx<<' '<<in[idx]<<' '<<out[idx]<<'\n';
}

class node{
public:
    // Do something!
    node(){}
    //node(int val){this->val=val;}
    node operator+(node b){
        node result;
        result.val=max(val,b.val); // Modify
        return result;
    }
    ll val=0, lazy_val=0;
};

class lazy_seg{
public:
	node seg[1<<19];
	
	lazy_seg(){}
	//lazy_seg(int n){}
	
	void build_seg(int idx, int l, int r){
		if(l==r){
			seg[idx].val=depth[invin[l]];
			seg[idx].lazy_val=0;
		}
		else{
			int mid=(l+r)>>1;
			build_seg(2*idx,l,mid);
			build_seg(2*idx+1,mid+1,r);
			seg[idx]=(seg[2*idx]+seg[2*idx+1]);
		}
	}
	
	void update_down(int idx, int l, int r){
		if(l==r) return;
		int mid=(l+r)>>1;
		// seg[2*idx], seg[2*idx+1]
		seg[2*idx].val+=seg[idx].lazy_val;
		seg[2*idx].lazy_val+=seg[idx].lazy_val;
		seg[2*idx+1].val+=seg[idx].lazy_val;
		seg[2*idx+1].lazy_val+=seg[idx].lazy_val;
		// seg[idx]의 lazy_val초기화
		seg[idx].lazy_val=0;
	}
	
	void update_seg(int idx, int l, int r, int t_l, int t_r, ll val){
		update_down(idx, l, r);
		if(t_l<=l && r<=t_r){
			seg[idx].val+=val;
			seg[idx].lazy_val+=val;
			return;
		}
		int mid=(l+r)>>1;
		if(t_l<=mid) update_seg(2*idx,l,mid,t_l,t_r,val);
		if(t_r>mid) update_seg(2*idx+1,mid+1,r,t_l,t_r,val);
		seg[idx]=(seg[2*idx]+seg[2*idx+1]);
	}
	
	node find_seg(int idx, int l, int r, int t_l, int t_r){
		update_down(idx, l, r);
		if(t_l<=l && r<=t_r){
			return seg[idx];
		}
		node result;
		int mid=(l+r)>>1;
		if(t_l<=mid) result=(result+find_seg(2*idx,l,mid,t_l,t_r));
		if(t_r>mid) result=(result+find_seg(2*idx+1,mid+1,r,t_l,t_r));
		return result;
	}
};

lazy_seg s;
int n,q;
pii child_inout[N];

void main_DFS(int idx){
    visited[idx]=1;

    int qidx=lower_bound(s_qs,s_qs+q,make_pair(idx,-1))-s_qs;
    while(qidx!=q && s_qs[qidx].fi==idx){
        // idx가 지금 시작하는.
        int oriidx=s_qs[qidx].se;
        int mxin=0, mnout=n;
        for(auto next : dels[oriidx]){
            if(in[next]<=in[idx] && out[idx]<=out[next]){ 
                mxin=max(mxin,child_inout[next].fi);
                mnout=min(mnout,child_inout[next].se);
            }
            else s.update_seg(1,0,n-1,in[next],out[next]-1,-INF);
        }
        int res=s.find_seg(1,0,n-1,mxin,mnout-1).val;
        ans[oriidx]=res;
        for(auto next : dels[oriidx]){
            if(!(in[next]<=in[idx] && out[idx]<=out[next])){
                s.update_seg(1,0,n-1,in[next],out[next]-1,INF);
            }
        }
        qidx++;
    }
    
    for(int i=0; i<(int)edges[idx].size(); i++){
        int next = edges[idx][i];
        if(visited[next]) continue;
        child_inout[idx]={in[next],out[next]};
        s.update_seg(1,0,n-1,0,n-1,1);
        s.update_seg(1,0,n-1,in[next],out[next]-1,-2);

        main_DFS(next);
        
        s.update_seg(1,0,n-1,0,n-1,-1);
        s.update_seg(1,0,n-1,in[next],out[next]-1,2);
    }
}

void Solve(){
    int a,b;
    cin>>n>>q;
    rng(i,0,n-2){
        cin>>a>>b;
        a--, b--;
        edges[a].pb(b);
        edges[b].pb(a);
    }
    rng(i,0,q-1){
        cin>>a;
        a--;
        pivot[i]=a;
        cin>>b;
        rng(j,0,b-1){
            cin>>a;
            a--;
            dels[i].pb(a);
        }
        s_qs[i]={pivot[i],i};
    }
    sort(s_qs,s_qs+q);
    DFS(0,0);
    rng(i,0,n-1) invin[in[i]]=i;
    s.build_seg(1,0,n-1);
    fill(visited,visited+n,0);
    main_DFS(0);
    rng(i,0,q-1) cout<<ans[i]<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    //cin>>t;
    while(t--){
        Solve();
    }
    return 0;
}

