
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

class segtree{
public:	
	ll seg[1<<20];
	segtree(){}
	
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

	void update_seg(int idx, int l, int r, int t_idx){
		if(l==r){
			seg[idx]=1; // Modify
			return;
		}
		int mid=(l+r)>>1;
		if(t_idx<=mid) update_seg(2*idx,l,mid,t_idx);
		else update_seg(2*idx+1,mid+1,r,t_idx);
		seg[idx]=(seg[2*idx]+seg[2*idx+1]); // Modify
	}

	ll find_seg(int idx, int l, int r, int t_l, int t_r){
		if(t_l<=l && r<=t_r) return seg[idx];
		ll mid=(l+r)>>1, ans=0;
		if(t_l<=mid) ans=(ans+find_seg(2*idx,l,mid,t_l,t_r)); // Modify
		if(t_r>mid) ans=(ans+find_seg(2*idx+1,mid+1,r,t_l,t_r)); // Modify
		return ans;
	}
};

segtree seg;

ll p[N], q[N], invp[N];

void Solve(){
    ll n,k;
    cin>>n>>k;
    rng(i,0,n-1) cin>>p[i];
    rng(i,0,n-1) p[i]--;
    rng(i,0,n-1) invp[p[i]]=i;
    seg.build_seg(1,0,n-1);
    ll p_inv=0;
    rng(i,0,n-1){
        p_inv+=seg.find_seg(1,0,n-1,p[i],n-1);
        seg.update_seg(1,0,n-1,p[i]);
    }
    seg.build_seg(1,0,n-1);

    ll tot=(n*(n-1))/2;
    ll p_ori=tot-p_inv;
    // cout<<"p_inv, p_ori "<<p_inv<<' '<<p_ori<<'\n';
    ll tar=(k-p_inv)/2;
    if(k<p_inv || (k-p_inv)%2==1 || tar>p_ori){
        cout<<"NO\n";
        return;
    }
    else{
        cout<<"YES\n";
        fill(q,q+n,-1);
        ll l=0, r=n-1;
        rng(i,0,n-1){
            ll idx=invp[i];
            ll num=n-1-idx-seg.find_seg(1,0,n-1,idx,n-1);
            //cout<<"idx tar, num "<<idx+1<<' '<<tar<<' '<<num<<'\n';
            if(num>=tar){
                q[i]=r-num+tar;
                rng(j,0,n-1){
                    if(q[p[j]]==-1){
                        if(l==q[i]){
                            l++;
                        }
                        q[p[j]]=l++;
                    } 
                }
                
                tar=0;
                break;
            }
            else{
                q[i]=r--;
                tar-=num;
            }
            seg.update_seg(1,0,n-1,idx);
        }
        //assert(tar==0 && l==r+1);
        //cout<<"tar : "<<tar<<' '<<l<<' '<<r<<'\n'; 
        rng(i,0,n-1) cout<<q[i]+1<<' '; 
        cout<<'\n';
        // rng(i,0,n-1) cout<<q[p[i]]+1<<' '; 
        // cout<<'\n';
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

