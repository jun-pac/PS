
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
__attribute__((optimize("Ofast,unroll-loops"),target("avx,avx2,fma")))
ll datas[N];

class node{
public:
    node operator+(node b){
        node result;
        result.mx=max(b.mx,mx);
        result.mxidx=(b.mx<mx?mxidx:b.mxidx);
        result.sum=b.sum+sum;
        return result;
    }
    ll mx=0, mxidx=0, sum=0;
};

class segtree{
public:	
	node seg[1<<19]; // mx,mxidx,sum
	segtree(){}
	segtree(int n){}
	
	void build_seg(int idx, int l, int r){
		if(l==r){
		    seg[idx].mx=datas[l];
            seg[idx].mxidx=l;
            seg[idx].sum=datas[l];
            //cout<<l<<' '<<r<<' '<<seg[idx].mx<<' '<<seg[idx].sum<<' '<<idx<<' '<<datas[idx]<<'\n';
			return;
		}
		int mid=(l+r)>>1;
		build_seg(2*idx,l,mid);
		build_seg(2*idx+1,mid+1,r);
		seg[idx]=seg[2*idx]+seg[2*idx+1];
        //cout<<l<<' '<<r<<' '<<seg[idx].mx<<' '<<seg[idx].sum<<'\n';
	}

	void update_seg(int idx, int l, int r, int t_idx, ll val){
		if(l==r){
			seg[idx].mx=val;
            seg[idx].mxidx=t_idx;
            seg[idx].sum=val;
			return;
		}
		int mid=(l+r)>>1;
		if(t_idx<=mid) update_seg(2*idx,l,mid,t_idx, val);
		else update_seg(2*idx+1,mid+1,r,t_idx, val);
        seg[idx]=seg[2*idx]+seg[2*idx+1];
	}

	node find_seg(int idx, int l, int r, int t_l, int t_r){
		if(t_l<=l && r<=t_r) return seg[idx];
		int mid=(l+r)>>1;
        node ans;
        ans.mx=0;
        ans.sum=0;
		if(t_l<=mid){
            node temp=find_seg(2*idx,l,mid,t_l,t_r);
            ans=ans+temp;
        }
		if(t_r>mid){
            node temp=find_seg(2*idx+1,mid+1,r,t_l,t_r);
            ans=ans+temp;
        }
		return ans;
	}
};

segtree seg;
int n;
ll BFS(int l, int r){
    if(r-l+1<3){
        return -1;
    }
    priority_queue<pii> pq; // 큰 것 순으로 방문
    pq.push({r-l+1,l});
    while(!pq.empty()){
        pii ttp=pq.top();
        pq.pop();
        l=ttp.se, r=ttp.fi+ttp.se-1;
        node temp=seg.find_seg(1,0,n-1,l,r);
        //cout<<l<<' '<<r<<' '<<temp.mx<<' '<<temp.idx<<' '<<temp.sum<<'\n';
        if(temp.mx*2<temp.sum){
            return r-l+1;
        }
        if(temp.mxidx-1-l+1>=3) pq.push({temp.mxidx-1-l+1,l});
        if(r-(temp.mxidx+1)+1>=3) pq.push({r-(temp.mxidx+1)+1,temp.mxidx+1});
    }
    return -1;
}

void Solve(){
    int q;
    cin>>n>>q;
    rng(i,0,n-1) cin>>datas[i];
    //rng(i,0,n-1) cout<<datas[i]<<'\n';
    seg.build_seg(1,0,n-1);
    rng(i,0,q-1){
        ll a,l,r;
        cin>>a>>l>>r;
        if(a==1) cout<<BFS(l-1,r-1)<<'\n';
        else seg.update_seg(1,0,n-1,l-1,r);
    }    

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

