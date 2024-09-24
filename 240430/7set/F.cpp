
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

#define N 100030
#define MOD 998244353
#define INF 1000000007 
__attribute__((optimize("Ofast,unroll-loops"),target("avx,avx2,fma")))


int datas[N];
vc<int> edges[N], child[N];
int parent[N], depth[N], in[N], top[N];
int sz[N], inv_in[N]; // HLD내부적으로 필요. inv_in은 seg의 초기화에 필요.
int n, cnt; 
ll mp[10][N];

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

// parent[루트], top[루트], depth[루트]업데이트 해줘야 함.
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

    node operator+(node b){
        node result;
        rng(i,0,9) result.val[i]=(b.val[i]+val[i])%MOD;
        return result;
    }
    ll val[10];
};

class lazy_seg{
public:
	node seg[1<<18];
		
	void build_seg(int idx, int l, int r){
		if(l==r){
			// Do something!
            rng(i,0,9) seg[idx].val[i]=mp[i][datas[l]];
		}
		else{
			int mid=(l+r)>>1;
			build_seg(2*idx,l,mid);
			build_seg(2*idx+1,mid+1,r);
			seg[idx]=seg[2*idx]+seg[2*idx+1];
		}
	}
	
	node find_seg(int idx, int l, int r, int t_l, int t_r){
		if(t_l<=l && r<=t_r){
			return seg[idx];
		}
		node result;
		int mid=(l+r)>>1;
		if(t_l<=mid) result=result+find_seg(2*idx,l,mid,t_l,t_r);
		if(t_r>mid) result=result+find_seg(2*idx+1,mid+1,r,t_l,t_r);
		return result;
	}
};

lazy_seg s;

node query(int a, int b){
	node result;
	while(top[a]!=top[b]){
		if(depth[top[a]]<depth[top[b]]) swap(a,b);
		result=result+s.find_seg(1,0,n-1,in[top[a]],in[a]); // 더하는 순서가 중요하다면 잘 확인할 것
		a=parent[top[a]];
	}
	result=result+s.find_seg(1,0,n-1,min(in[a],in[b]),max(in[a],in[b]));
	return result;
}


void Solve(){
    int n;
    cin>>n;
    rng(i,0,n-1) cin>>datas[i];
    rng(i,0,n-2){
        int a,b;
        cin>>a>>b;
        a--, b--;
        edges[a].pb(b);
        edges[b].pb(a);
    }
    DFS(0,-1);
    DFS1();
    DFS2();

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(0, MOD-1);
    rng(i,0,10) cout<<dis(gen)<<'\n';


    rng(i,0,n-1) mp[0][i]=1;
    rng(i,0,n-1) mp[1][i]=i;
    rng(k,2,9) rng(i,0,n-1) mp[k][i]=dis(gen);
    s.build_seg(1,0,n-1);
    
    int q;
    cin>>q;
    rng(i,0,q-1){
        int a1, a2, b1, b2, k;
        cin>>a1>>a2>>b1>>b2>>k;
        a1--, a2--, b1--, b2--;
        node a=query(a1,a2);
        node b=query(b1,b2);
        bool flag=1;
        rng(j,0,9) if((a.val[i]-b.val[i])%MOD==0) flag=0;
        if(!flag) cout<<0<<'\n';
        else cout<<1<<'\n';
    }

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

