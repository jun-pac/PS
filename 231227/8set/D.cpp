
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

ll ps[N], qs[N], invp[N], invq[N];

using namespace std;
class segtree{
public:	
	int seg[1<<19];
	int info;
	segtree(){}
	segtree(int n){}
	
	void build_seg(int idx, int l, int r){
		if(l==r){
			seg[idx]=0;
			return;
		}
		int mid=(l+r)>>1;
		build_seg(2*idx,l,mid);
		build_seg(2*idx+1,mid+1,r);
		seg[idx]=(seg[2*idx]+seg[2*idx+1]); // Modify
	}

	void update_seg(int idx, int l, int r, int t_idx, int val){
		if(l==r){
			seg[idx]=val;
			return;
		}
		int mid=(l+r)>>1;
		if(t_idx<=mid) update_seg(2*idx,l,mid,t_idx, val);
		else update_seg(2*idx+1,mid+1,r,t_idx, val);
		seg[idx]=(seg[2*idx]+seg[2*idx+1]); // Modify
	}

	int find_seg(int idx, int l, int r, int t_l, int t_r){
		if(t_l<=l && r<=t_r) return seg[idx];
		int mid=(l+r)>>1, ans=0;
		if(t_l<=mid) ans=(ans+find_seg(2*idx,l,mid,t_l,t_r)); // Modify
		if(t_r>mid) ans=(ans+find_seg(2*idx+1,mid+1,r,t_l,t_r)); // Modify
		return ans;
	}
};

segtree seg;
segtree seg2;

ll bignum[30], smallnum[30];

ll n,k;
inline ll calcbig(ll m){
    if(k<=m+1) return 0;
    else return (((k-m-1)*(k-m))/2)%MOD;
}
inline ll calcsmall(ll m){
    if(k<=m+1) return k*k;
    else return (m*k+((k+m+1)*(k-m))/2)%MOD;
}


void Solve(){
    cin>>n>>k;
    rng(i,0,n-1) cin>>ps[i]; // 전부 홀수, 1, ... 2n-1의 perm.
    rng(i,0,k-1) cin>>qs[i]; // 0, ... ,k-1의 perm
    rng(i,0,n-1) invp[ps[i]/2]=i;
    rng(i,0,k-1) invq[qs[i]]=i;
    
    ll samep=0;
    seg.build_seg(1,0,k-1);
    rng(i,0,k-1){
        samep+=seg.find_seg(1,0,k-1,invq[i],k-1);
        seg.update_seg(1,0,k-1,invq[i],1);
    }
    samep%=MOD;
    samep=samep*n%MOD;

    fill(bignum,bignum+20,0);
    fill(smallnum,smallnum+20,0);
    seg2.build_seg(1,0,n-1);
    rng(i,0,n-1){
        ll val=ps[i];
        seg2.update_seg(1,0,n-1,val/2,1);
        rng(j,0,19){
            if((val/2+1)/2>(val-1)/2){
                val=val/2;
                continue;
            }
            smallnum[j]+=(val-1)/2-(val/2+1)/2+1-seg2.find_seg(1,0,n-1,(val/2+1)/2,(val-1)/2);
            if(val==1) break;
            val=val/2;
        }
        val=ps[i];
        rng(j,0,19){
            if(val>=2*n) break;
            if(val/2>min(n-1,val-1)){
                val=val*2;
                continue;
            }
            bignum[j]+=min(n-1,val-1)-val/2+1-seg2.find_seg(1,0,n-1,val/2,min(n-1,val-1));
            val=val*2;
        }
    }

    ll res=0;
    rng(i,0,19){
        res+=((smallnum[i]%MOD)*calcsmall(i))%MOD;
        res%=MOD;
    }
    rng(i,0,19){
        res+=((bignum[i]%MOD)*calcbig(i))%MOD;
        res%=MOD;
    }
    //cout<<samep<<' '<<res<<endl;
    cout<<((samep+res)%MOD+MOD)%MOD<<'\n';
    
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

