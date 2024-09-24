
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


class nnz_seg{
public:
	pair<int,int> seg[1<<19]; // {cnt, nnz}
	nnz_seg(){}

	void build_seg(int idx, int l, int r){
		if(l==r){
			seg[idx].first=seg[idx].second=0;
		}
		else{
			int mid=(l+r)>>1;
			build_seg(2*idx,l,mid);
			build_seg(2*idx+1,mid+1,r);
            seg[idx].first=seg[idx].second=0;
		}
	}
	
	void update_seg(int idx, int l, int r, int t_l, int t_r, int val){
		if(t_l<=l && r<=t_r){
			seg[idx].first+=val;
            if(l==r) seg[idx].second=(seg[idx].first>0);
            else if(seg[idx].first>0) seg[idx].second=r-l+1;
            else seg[idx].second=seg[2*idx].second+seg[2*idx+1].second;
			return;
		}
		int mid=(l+r)>>1;
		if(t_l<=mid) update_seg(2*idx,l,mid,t_l,t_r,val);
		if(t_r>mid) update_seg(2*idx+1,mid+1,r,t_l,t_r,val);
        if(seg[idx].first==0) seg[idx].second=seg[2*idx].second+seg[2*idx+1].second;
	}
	
	int find_seg(int idx, int l, int r, int t_l, int t_r){
		if(t_l<=l && r<=t_r){
			return seg[idx].second;
		}
		int result=0;
		int mid=(l+r)>>1;
        if(seg[idx].first>0) return r-l+1;
		if(t_l<=mid) result=(result+find_seg(2*idx,l,mid,t_l,t_r));
		if(t_r>mid) result=(result+find_seg(2*idx+1,mid+1,r,t_l,t_r));
		return result;
	}
};

nnz_seg s;


vc<int> edges[N];
pii es[N];

void Solve(){
    int n,m;
    cin>>n>>m;
    rng(i,0,n-1) edges[i].clear();
    rng(i,0,m-1){
        int a,b;
        cin>>a>>b;
        a--, b--;
        if(a>b) swap(a,b);
        es[i]={a,b};
        edges[a].pb(b);
        edges[b].pb(a);
    }
    // 하나를 X로 정하면 나머지는 모두 방향이 정해짐. 
    // 이걸 lazyseg로 관리하면 되겠네
    // 뭔가가 바뀌는 개수는 어차피 거기서 시작하는 숫자와 똑같음
    
    // i번째 segment가 없어진다?
    // i-1, i번째
    // 0번째 segment가 없는 경우를 생각
    int mn=n-1;
    s.build_seg(1,0,n-1);
    rng(i,0,m-1){
        int a=es[i].fi;
        int b=es[i].se;
        if(a==0){
            swap(a,b);
            b=n;
        }
        s.update_seg(1,0,n-1,a,b-1,1);
    }
    mn=min(mn,s.find_seg(1,0,n-1,0,n-1));
    rng(k,1,n-1){
        // 이제 없어지는 segment가 k가 된 것이죠
        for(int next : edges[k]){
            if(next>k){
                s.update_seg(1,0,n-1,k,next-1,-1);
                s.update_seg(1,0,n-1,0,k-1,1);
                s.update_seg(1,0,n-1,next,n-1,1);
            }
            else{
                s.update_seg(1,0,n-1,k,n-1,-1);
                if(next!=0) s.update_seg(1,0,n-1,0,next-1,-1);
                s.update_seg(1,0,n-1,next,k-1,1);
            }
            mn=min(mn,s.find_seg(1,0,n-1,0,n-1));
        }   
    }
    cout<<mn<<'\n';
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

