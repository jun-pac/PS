
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
//__attribute__((optimize("Ofast,unroll-loops"),target("avx,avx2,fma")))

#define N 300030
#define MOD 998244353
#define INF 1000000007 

ll datas[N];
pll qs[N];
int lmx[N], rmx[N]; // 둘 다 idx를 저장하는 건 맞음. 그런데 같은 게 여러개면 왼쪽으로 갈지 오른쪽으로 갈지
bool visited[N];
int rbig[N], lbig[N]; // rbig은 자신보다 오른쪽에서 자기보다 큰 최초의 원소의 idx. 없으면 -1 
int res[N];

#define LOG2 20

class RMQ{
public:
	long long sp_table[LOG2][N]; // NlogN size sparse table
	long long LG[N+1]; // LG[idx]=floor(log_2[idx]) 
	// Note that sp_table RMQ if fast(O(1) for each query), but it is immutable
	int info;
	void build_sparse(int n){
		for(int i=0; i<n; i++) sp_table[0][i]=datas[i];
		for(int idx=1; (1<<idx)<=n; idx++){
			for(int i=0; i+(1<<idx)<=n; i++){
				sp_table[idx][i]=max(sp_table[idx-1][i],sp_table[idx-1][i+(1<<(idx-1))]);
			}   
		}
		LG[1]=0;
		for(int i=2; i<=n; i++) LG[i]=LG[i/2]+1;
	}
	long long query(int a, int b){
		// [a,b] minimum query
		assert(a<=b);
		int lgn=LG[b-a+1];
		return max(sp_table[lgn][a],sp_table[lgn][b-(1<<lgn)+1]);
	}
};
RMQ rmq;

class RMQ_M{ // minimum query
public:
	long long sp_table[LOG2][N]; // NlogN size sparse table
	long long LG[N+1]; // LG[idx]=floor(log_2[idx]) 
	// Note that sp_table RMQ if fast(O(1) for each query), but it is immutable
	int info;
	void build_sparse(int n){
		for(int i=0; i<n; i++) sp_table[0][i]=datas[i];
		for(int idx=1; (1<<idx)<=n; idx++){
			for(int i=0; i+(1<<idx)<=n; i++){
				sp_table[idx][i]=min(sp_table[idx-1][i],sp_table[idx-1][i+(1<<(idx-1))]);
			}   
		}
		LG[1]=0;
		for(int i=2; i<=n; i++) LG[i]=LG[i/2]+1;
	}
	long long query(int a, int b){
		// [a,b] minimum query
		assert(a<=b);
		int lgn=LG[b-a+1];
		return min(sp_table[lgn][a],sp_table[lgn][b-(1<<lgn)+1]);
	}
};
RMQ_M rmq_m;


vector<int> edges[N], child[N];
int parent[N], depth[N], in[N], top[N];
int sz[N], inv_in[N]; // HLD내부적으로 필요. inv_in은 seg의 초기화에 필요.
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

bool flag;

class lazy_seg{
public:
	int seg[1<<19];
	
	lazy_seg(){}
	
	void build_seg(int idx, int l, int r){
		if(l==r){
			seg[idx]=datas[inv_in[l]];
            if(flag){
                if(rbig[inv_in[l]]!=n && rbig[inv_in[l]]!=inv_in[l]+1) seg[idx]+=rmq_m.query(inv_in[l],rbig[inv_in[l]]);
                else seg[idx]=INF;
            }
            else{
                if(lbig[inv_in[l]]!=-1 && lbig[inv_in[l]]!=inv_in[l]-1) seg[idx]+=rmq_m.query(lbig[inv_in[l]],inv_in[l]);
                else seg[idx]=INF;
            }
		}
		else{
			int mid=(l+r)>>1;
			build_seg(2*idx,l,mid);
			build_seg(2*idx+1,mid+1,r);
			seg[idx]=min(seg[2*idx],seg[2*idx+1]);
		}
	}
	
	int find_seg(int idx, int l, int r, int t_l, int t_r){
		if(t_l<=l && r<=t_r){
			return seg[idx];
		}
		int result=INF;
		int mid=(l+r)>>1;
		if(t_l<=mid) result=min(result,find_seg(2*idx,l,mid,t_l,t_r));
		if(t_r>mid) result=min(result,find_seg(2*idx+1,mid+1,r,t_l,t_r));
		return result;
	}
};

lazy_seg s;

int query(int a, int b){
	int result=INF;
	while(top[a]!=top[b]){
		if(depth[top[a]]<depth[top[b]]) swap(a,b);
		result=min(result,s.find_seg(1,0,n-1,in[top[a]],in[a])); // 더하는 순서가 중요하다면 잘 확인할 것
		a=parent[top[a]];
	}
	result=min(result,s.find_seg(1,0,n-1,min(in[a],in[b]),max(in[a],in[b])));
	return result;
}


void Solve(){
    int n,q;
    cin>>n>>q;
    rng(i,0,n-1) cin>>datas[i];
    rmq.build_sparse(n);
    rmq_m.build_sparse(n);

    rng(i,0,q-1){
        int a,b;
        cin>>a>>b;
        a--, b--;
        qs[i]={a,b};
        int mx=rmq.query(a,b);
        int l=a, r=b;
        while(l<r){
            int mid=(l+r)>>1;
            if(rmq.query(a,mid)==mx) r=mid;
            else l=mid+1;
        }
        lmx[i]=l;
        l=a, r=b;
        while(l<r){
            int mid=(l+r+1)>>1;
            if(rmq.query(mid,b)==mx) l=mid;
            else r=mid-1;
        }
        rmx[i]=l;
        res[i]=min(datas[a]+datas[a+1]+rmq.query(a+2,b),datas[b]+datas[b-1]+rmq.query(a,b-2)); // dummy data
        if(lmx[i]!=a && lmx[i]!=b) res[i]=mx+datas[a]+datas[b];
        if(rmx[i]!=a && rmx[i]!=b) res[i]=mx+datas[a]+datas[b];
    }

    // 2 1 3 layout
    flag=1;
    rng(i,0,n-1) edges[i].clear();
    rng(i,0,n-1) child[i].clear();
    rng(i,0,n-1){
        if(rmq.query(i,n-1)==datas[i]) rbig[i]=n;
        else{
            int l=i+1, r=n-1;
            while(l<r){
                int mid=(l+r)>>1;
                if(rmq.query(i,mid)>datas[i]) r=mid;
                else l=mid+1;
            }
            rbig[i]=l;
            edges[i].pb(l);
            edges[l].pb(i);
        }
    }
    DFS(n-1,-1);
    DFS1(n-1);
    DFS2(n-1);
    rng(i,0,n-1) inv_in[in[i]]=i;
    s.build_seg(1,0,n-1);    
    rng(i,0,q-1){
        res[i]=min(res[i],s.find_seg(1,0,n-1,qs[i].fi,qs[i].se));
    }





    // 3 1 2 layout
    flag=0;
    rng(i,0,n-1) edges[i].clear();
    rng(i,0,n-1) child[i].clear();
    gnr(i,n-1,0){
        if(rmq.query(0,i)==datas[i]) lbig[i]=-1;
        else{
            int l=0, r=i-1;
            while(l<r){
                int mid=(l+r+1)>>1;
                if(rmq.query(mid,i)>datas[i]) l=mid;
                else r=mid-1;
            }
            lbig[i]=l;
            edges[i].pb(l);
            edges[l].pb(i);
        }
    }
    DFS(n-1,-1);
    DFS1(n-1);
    DFS2(n-1);
    rng(i,0,n-1) inv_in[in[i]]=i;
    s.build_seg(1,0,n-1);    
    rng(i,0,q-1){
        res[i]=min(res[i],s.find_seg(1,0,n-1,qs[i].fi,qs[i].se));
    }


    rng(i,0,q-1) cout<<res[i]<<'\n';
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

