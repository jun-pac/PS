
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
uniform_int_distribution<> dist(0, INF); // random integer from [0, INF]
// val = dist(gen)

ll a[N], b[N];

class segtree{
public:	
	pll seg[1<<19];
	ll randmul[N];
	segtree(){}
	segtree(int n){}
	
	void build_seg(int idx, int l, int r){
		if(l==r){
			seg[idx]={randmul[a[l]],randmul[b[l]]};
			return;
		}
		int mid=(l+r)>>1;
		build_seg(2*idx,l,mid);
		build_seg(2*idx+1,mid+1,r);
		seg[idx]={(seg[2*idx].fi+seg[2*idx+1].fi)%MOD,(seg[2*idx].se+seg[2*idx+1].se)%MOD}; 
	}

	pll find_seg(int idx, int l, int r, int t_l, int t_r){
		if(t_l<=l && r<=t_r) return seg[idx];
		ll mid=(l+r)>>1;
        pll ans={0,0};
		if(t_l<=mid){
            pll temp=find_seg(2*idx,l,mid,t_l,t_r);
            ans={(ans.fi+temp.fi)%MOD,(ans.se+temp.se)%MOD}; // Modify
        }
		if(t_r>mid){
            pll temp=find_seg(2*idx+1,mid+1,r,t_l,t_r); // Modify
            ans={(ans.fi+temp.fi)%MOD,(ans.se+temp.se)%MOD};
        }
		return ans;
	}
};

#define M 4
segtree seg[M];


void Solve(){
    int n,q;
    cin>>n>>q;
    rng(i,0,n-1) cin>>a[i];
    rng(i,0,n-1) cin>>b[i];
    rng(k,0,M-1){
        rng(i,0,n-1) seg[k].randmul[i]=dist(gen);
        seg[k].build_seg(1,0,n-1);
    }
    rng(i,0,q-1){
        int l,r,a,b;
        cin>>l>>r>>a>>b;
        a--, r--, b--, l--;
        if(r-l!=b-a) cout<<"No\n";
        else{
            bool flag=1;
            rng(k,0,M-1){
                pll res;
                res.fi=seg[k].find_seg(1,0,n-1,l,r).fi;
                res.se=seg[k].find_seg(1,0,n-1,a,b).se;
                if((res.fi%MOD+MOD)%MOD != (res.se%MOD+MOD)%MOD){
                    flag=0;
                }
            }
            cout<<(flag?"Yes\n":"No\n");
        }
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

