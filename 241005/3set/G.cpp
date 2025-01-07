
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
uniform_int_distribution<> dist(0, INF); // random integer from [0, INF] // dist(gen)

ll A[N], B[N];

class segtree{
public:	
	ll seg[1<<18];
	segtree(){}
	segtree(int n){}
	
	void build_seg(int idx, int l, int r){
		if(l==r){
			seg[idx]=A[l];
			return;
		}
		int mid=(l+r)>>1;
		build_seg(2*idx,l,mid);
		build_seg(2*idx+1,mid+1,r);
		seg[idx]=(seg[2*idx]+seg[2*idx+1]); 
	}

	void update_seg(int idx, int l, int r, int t_idx, int val){
		if(l==r){
			seg[idx]=val;
			return;
		}
		int mid=(l+r)>>1;
		if(t_idx<=mid) update_seg(2*idx,l,mid,t_idx, val);
		else update_seg(2*idx+1,mid+1,r,t_idx, val);
		seg[idx]=(seg[2*idx]+seg[2*idx+1]); 
	}

	ll find_seg(int idx, int l, int r, int t_l, int t_r){
		if(t_l<=l && r<=t_r) return seg[idx];
		ll mid=(l+r)>>1, ans=0;
		if(t_l<=mid) ans=(ans+find_seg(2*idx,l,mid,t_l,t_r)); 
		if(t_r>mid) ans=(ans+find_seg(2*idx+1,mid+1,r,t_l,t_r)); 
		return ans;
	}
};

segtree seg;
set<int> bidx; // 2이상의 값을 가지는 아이들의 모임

void Solve(){
    int n;
    cin>>n;
    rng(i,0,n-1) cin>>A[i];
    rng(i,0,n-1) cin>>B[i];
    rng(i,0,n-1) if(B[i]>=2) bidx.insert(i);
    int q;
    cin>>q;
    seg.build_seg(1,0,n-1);

    rng(i,0,q-1){
        ll a,l,r;
        cin>>a>>l>>r;
        if(a==1){
            l--;
            A[l]=r;
            seg.update_seg(1,0,n-1,l,r);
        }
        else if(a==2){
            l--;
            ll prb=B[l];
            B[l]=r;
            if(prb>=2 && r<2){
                bidx.erase(l);
            }
            else if(prb<2 && r>=2){
                bidx.insert(l);
            }
        }
        else{
            l--, r--;
            // [l,r]에서의 쿼리
            // [l,r]에서 2이상인 b의 위치를 빠르게 찾는 것. -- set으로
            // 나머지구간에서 a의 합을 빠르게 구하는 것 -- 그냥 세그
            ll val=A[l];
            int lastidx=l;
            l++;
            auto curb=bidx.lower_bound(l);
            while(curb!=bidx.end() && (*curb)<=r){
                if(lastidx+1<=(*curb)-1) val=val+seg.find_seg(1,0,n-1,lastidx+1,(*curb)-1);
                //cout<<"curb : "<<(*curb)<<' '<<val<<'\n';

                lastidx=(*curb);
                val=max(val+A[lastidx],val*B[lastidx]);
                curb=next(curb);
            }
            if(lastidx!=r) val=val+seg.find_seg(1,0,n-1,lastidx+1,r);
            cout<<val<<'\n';
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

