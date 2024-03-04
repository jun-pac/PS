
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
ll sum[N], DP[N]; // l_sum[idx]=
ll DP_temp[N];

class segtree{
public:	
	pii seg[1<<20]; // mx, mn
	int info;
	segtree(){}
	segtree(int n){}
	
	void build_seg(int idx, int l, int r){
		if(l==r){
			seg[idx]={datas[l],datas[l]};
			return;
		}
		int mid=(l+r)>>1;
		build_seg(2*idx,l,mid);
		build_seg(2*idx+1,mid+1,r);
		seg[idx].fi=max(seg[2*idx].fi,seg[2*idx+1].fi);
        seg[idx].se=min(seg[2*idx].se,seg[2*idx+1].se);
    }

	pii find_seg(int idx, int l, int r, int t_l, int t_r){
		if(t_l<=l && r<=t_r) return seg[idx];
		int mid=(l+r)>>1;
        pii ans={0,INF};
		if(t_l<=mid){
            auto temp=find_seg(2*idx,l,mid,t_l,t_r);
            ans.fi=max(ans.fi,temp.fi);
            ans.se=min(ans.se,temp.se);
        }
		if(t_r>mid){
            auto temp=find_seg(2*idx+1,mid+1,r,t_l,t_r);
            ans.fi=max(ans.fi,temp.fi);
            ans.se=min(ans.se,temp.se);
        }
		return ans;
	}
};

segtree seg;


void Solve2(int n){
    fill(DP,DP+n,INF);
    seg.build_seg(1,0,n-1);
    rng(i,0,n-1) sum[i]=(i==0?0:sum[i-1])+datas[i];
    DP[0]=INF;
    rng(i,1,n-1){
        if(datas[i-1]>datas[i]) DP[i]=1;
        else if(sum[i-1]<=datas[i]) DP[i]=INF;
        else{
            pii temp=seg.find_seg(1,0,n-1,0,i-1);
            if(temp.fi==temp.se) continue; // INF임 그냥

            int l=0,r=i-1; // sum[l,i-1]>datas[i]인 최대의 l
            while(l<r){
                int mid=(l+r+1)>>1;
                if(sum[i-1]-(mid==0?0:sum[mid-1])>datas[i]) l=mid;
                else r=mid-1;
            }
            int s=0, e=l; // [s,i-1]에서 다른게 하나라도 있어야 함.
            while(s<e){
                int mid=(s+e+1)>>1;
                temp=seg.find_seg(1,0,n-1,mid,i-1);
                if(temp.fi!=temp.se) s=mid;
                else e=mid-1;
            }
            // [s,i-1] reduce가 답.
            DP[i]=i-s;
        }
    }
}

void Solve(){
    int n;
    cin>>n;
    rng(i,0,n-1) cin>>datas[i];
    Solve2(n);
    rng(i,0,n-1) DP_temp[i]=DP[i];
    reverse(datas,datas+n);
    Solve2(n);
    rng(i,0,n-1) cout<<(min(DP_temp[i],DP[n-1-i])==INF?-1:min(DP_temp[i],DP[n-1-i]))<<' ';
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

