
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

#define N 200030
#define MOD 998244353
#define INF 1000000007 


using namespace std;

vector<int> edges[N], child[N];
int parent[N], depth[N], in[N], top[N];
int sz[N], inv_in[N]; // HLD���������� �ʿ�. inv_in�� seg�� �ʱ�ȭ�� �ʿ�.
int n, cnt; 

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

// parent[��Ʈ], top[��Ʈ], depth[��Ʈ]������Ʈ ����� ��.
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
	in[idx]=cnt;
	for(int i=0; i<child[idx].size(); i++){
		int next=child[idx][i];
		top[next]=(i==0?top[idx]:next);
		cnt++;
		DFS2(next);
	}
}

class node{
public:
    // Do something!
    node(){}
    node(){
        
    }
    node operator+(node b){
        node result;
        // Do something!
        return result;
    }
    // int val, lazy_val;
};

class lazy_seg{
public:
	node seg[1<<19];
	
	lazy_seg(){}
	lazy_seg(int n){
	    //fill(seg,seg+n,node());
	}
	
	void build_seg(int idx, int l, int r){
		if(l==r){
			// Do something!
		}
		else{
			int mid=(l+r)>>1;
			build_seg(2*idx,l,mid);
			build_seg(2*idx+1,mid+1,r);
			seg[idx]=seg[2*idx]+seg[2*idx+1];
		}
	}
	
	void update_down(int idx, int l, int r){
		if(l==r) return;
		int mid=(l+r)>>1;
		// seg[2*idx], seg[2*idx+1]
		
		// seg[idx]�� lazy_val�ʱ�ȭ
		
	}
	
	void update_seg(int idx, int l, int r, int t_l, int t_r, int val){
		if(t_l<=l && r<=t_r){
			// seg[idx].val�� seg[idx].lazy_val������Ʈ
			return;
		}
		update_down(idx, l, r);
		int mid=(l+r)>>1;
		if(t_l<=mid) update_seg(2*idx,l,mid,t_l,t_r,val);
		if(t_r>mid) update_seg(2*idx+1,mid+1,r,t_l,t_r,val);
		seg[idx]=seg[2*idx]+seg[2*idx+1];
	}
	
	node find_seg(int idx, int l, int r, int t_l, int t_r){
		if(t_l<=l && r<=t_r){
			return seg[idx];
		}
		update_down(idx, l, r);
		node result;
		int mid=(l+r)>>1;
		if(t_l<=mid) result=result+find_seg(2*idx,l,mid,t_l,t_r);
		if(t_r>mid) result=result+find_seg(2*idx+1,mid+1,r,t_l,t_r);
		return result;
	}
};

lazy_seg s;

int get_LCA(int a,int b){ 
	while(top[a]!=top[b]){
		if(depth[top[a]]<depth[top[b]]) swap(a,b);
		a=parent[top[a]];
	}
	return (in[a]<in[b]?a:b);
}

node query(int a, int b){
	node result;
	while(top[a]!=top[b]){
		if(depth[top[a]]<depth[top[b]]) swap(a,b);
		result=result+s.find_seg(1,0,n-1,in[top[a]],in[a]); // ���ϴ� ������ �߿��ϴٸ� �� Ȯ���� ��
		a=parent[top[a]];
	}
	result=result+s.find_seg(1,0,n-1,min(in[a],in[b]),max(in[a],in[b]));
	return result;
}

void update_query(int a, int b, int val){
	while(top[a]!=top[b]){
		if(depth[top[a]]<depth[top[b]]) swap(a,b);
		s.update_seg(1,0,n-1,in[top[a]],in[a],val);
		a=parent[top[a]];
	}
	s.update_seg(1,0,n-1,min(in[a],in[b]),max(in[a],in[b]),val);
}

void Solve(){

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

