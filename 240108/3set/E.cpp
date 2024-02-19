
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

class node{
public:
    node(){}
    node operator+(node b){
        node result;
        result.val=max(val,b.val); // Modify
        return result;
    }
    int val=0, lazy_val=0;
};

class lazy_seg{
public:
	node seg[1<<20];
	
	lazy_seg(){}
	
	void build_seg(int idx, int l, int r){
		if(l==r){
			seg[idx].val=0;
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
		seg[2*idx].val+=seg[idx].lazy_val;
		seg[2*idx].lazy_val+=seg[idx].lazy_val;
		seg[2*idx+1].val+=seg[idx].lazy_val;
		seg[2*idx+1].lazy_val+=seg[idx].lazy_val;
		seg[idx].lazy_val=0;
	}
	
	void update_seg(int idx, int l, int r, int t_l, int t_r, int val){
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



vc<int> child[N];
int datas[N];
int in[N], out[N], cnt;
stack<int> st[N];
ll res;
int n;
lazy_seg s;



void DFS1(int idx){
    in[idx]=cnt++;
    for(int next : child[idx]){
        DFS1(next);    
    }
    out[idx]=cnt-1;
}

void DFS2(int idx){
    for(int next : child[idx]) DFS2(next);
    while(!st[datas[idx]].empty() && in[idx]<=in[st[datas[idx]].top()] && in[st[datas[idx]].top()]<=out[idx]){
        int next=st[datas[idx]].top();
        s.update_seg(1,0,n-1,in[next],out[next],-1);
        st[datas[idx]].pop();
    }
    s.update_seg(1,0,n-1,in[idx],out[idx],1);
    st[datas[idx]].push(idx);
    if(child[idx].size()==0) return;

    vc<ll> vals;
    vals.reserve(child[idx].size());
    rng(i,0,(int)child[idx].size()-1){
        int next = child[idx][i];
        vals.pb(s.find_seg(1,0,n-1,in[next],out[next]).val);
    }
    sort(all(vals));
    reverse(all(vals));
    // if(child[idx].size()>1){
    //     cout<<"idx "<<idx<<' '<<vals[0]<<' '<<vals[1]<<endl;
    // }
    ll temp=(vals.size()==1 ? vals[0] : vals[0]*vals[1]);
    res=max(res,temp);
}

void Solve(){
    int x,y;
    cin>>n;
    rng(i,0,n-1) child[i].clear();
    rng(i,0,n-2){
        cin>>x;
        x--;
        child[x].pb(i+1);
    }
    rng(i,0,n-1){
        cin>>datas[i];
        datas[i]--;
    }
    
    // DFS1
    cnt=0;
    DFS1(0);
    //rng(i,0,n-1) cout<<in[i]<<' '; cout<<endl;
    //rng(i,0,n-1) cout<<out[i]<<' '; cout<<endl;

    // DFS2
    res=1;
    rng(i,0,n-1){
        while(!st[i].empty()) st[i].pop();
    }
    s.build_seg(1,0,n-1);
    DFS2(0);
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

