
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

ll datas[N], b[N];

class lazy_cnt_tree{
public:
	lazy_cnt_tree(){}
	ll seg[1<<19];
	void build_seg(int idx, int l, int r){
		if(l==r){
			seg[idx]=datas[l];
			return;
		}
		int mid=(l+r)>>1;
		build_seg(2*idx,l,mid);
		build_seg(2*idx+1,mid+1,r);
		seg[idx]=0; // For multiple use
	}
	void update_seg(int idx, int l, int r, int t_l, int t_r, long long val){
		if(t_l<=l && r<=t_r){
			seg[idx]+=val;
			return;
		}
		int mid=(l+r)>>1;
		if(t_l<=mid) update_seg(2*idx,l,mid,t_l,t_r,val);
		if(t_r>mid) update_seg(2*idx+1,mid+1,r,t_l,t_r,val);
	}

	ll find_seg(int idx, int l, int r, int t_idx){
		if(l==r) return seg[idx];
		ll res=seg[idx];
		int mid=(l+r)>>1;
		if(t_idx<=mid) res=res+find_seg(2*idx,l,mid,t_idx);
		if(t_idx>mid) res=res+find_seg(2*idx+1,mid+1,r,t_idx);
		return res;
	}
};

lazy_cnt_tree lct;

void Solve(){
    ll n,m;
    cin>>n>>m;
    rng(i,0,n-1) cin>>datas[i];
    rng(i,0,m-1) cin>>b[i];

    lct.build_seg(1,0,n-1);
    //cout<<"here"<<endl;

    rng(i,0,m-1){
        ll st=b[i];
        ll bulk=lct.find_seg(1,0,n-1,st);
        lct.update_seg(1,0,n-1,st,st,-bulk);

        // st+1부터 bulk개임
        ll off=bulk/n;
        bulk=bulk%n;
        //cout<<bulk<<' '<<n<<'\n';
        if(off>0) lct.update_seg(1,0,n-1,0,n-1,off);

        //bulk<n
        if(bulk!=0){
            int last=(st+bulk)%n;
            assert(last!=st);
            if(last>st) lct.update_seg(1,0,n-1,st+1,last,1);
            else{
                if(st!=n-1) lct.update_seg(1,0,n-1,st+1,n-1,1);
                lct.update_seg(1,0,n-1,0,last,1);
            }
        }
    }
    rng(i,0,n-1) cout<<lct.find_seg(1,0,n-1,i)<<' ';
    cout<<'\n';

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

