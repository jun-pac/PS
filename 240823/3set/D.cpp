
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

vc<int> edges[N];
int dist[N];
int res[N];

class segtree{
public:	
	int seg[1<<19];
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

	void update_seg(int idx, int l, int r, int t_idx, int val){
		if(l==r){
			seg[idx]=min(seg[idx],val); // Modify
			return;
		}
		int mid=(l+r)>>1;
		if(t_idx<=mid) update_seg(2*idx,l,mid,t_idx, val);
		else update_seg(2*idx+1,mid+1,r,t_idx, val);
		seg[idx]=min(seg[2*idx],seg[2*idx+1]); // Modify
	}

	int find_seg(int idx, int l, int r, int t_l, int t_r){
		if(t_l<=l && r<=t_r) return seg[idx];
		int mid=(l+r)>>1, ans=INF;
		if(t_l<=mid) ans=min(ans,find_seg(2*idx,l,mid,t_l,t_r)); // Modify
		if(t_r>mid) ans=min(ans,find_seg(2*idx+1,mid+1,r,t_l,t_r)); // Modify
		return ans;
	}
};

segtree seg;

void Solve(){
    int n,m;
    cin>>n>>m;
    rng(i,0,n-1) edges[i].clear();
    rng(i,0,n-2) edges[i].pb(i+1);
    rng(i,0,m-1){
        int a,b;
        cin>>a>>b;
        a--, b--;
        edges[a].pb(b);
    }
    queue<pii> q;
    q.push({0,0});
    fill(dist,dist+n,-1);
    while(!q.empty()){
        int idx=q.front().fi;
        int d=q.front().se;
        q.pop();
        if(dist[idx]!=-1){
            continue;
        }
        dist[idx]=d;
        for(int next : edges[idx]){
            if(dist[next]==-1) q.push({next,d+1});
        }
    }
    seg.build_seg(1,0,n-1);
    res[0]=1; // Bessie가 이기는게 1임
    rng(i,1,n-2){
        // i-1에서 갈 수 있는 것들을 전부 고려하는 거죠
        for(int next : edges[i-1]){
            seg.update_seg(1,0,n-1,next,dist[i-1]+1-next);
        }
        int mn=seg.find_seg(1,0,n-1,i+1,n-1);
        //cout<<"mn "<<i<<' '<<mn<<'\n';
        if(mn<-i) res[i]=0;
        else res[i]=1;
    }
    rng(i,0,n-2) cout<<res[i];
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

