
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
			seg[idx]=val; // Modify
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

void Solve(){
    int n,q;
    cin>>n>>q;
    seg.build_seg(1,0,n-1);

    rng(i,0,q-1){
        char c;
        cin>>c;
        if(c=='?'){
            int a,b;
            cin>>a>>b;
            a--, b--;
            if(a>b) swap(a,b);
            if(seg.find_seg(1,0,n-1,a,a)==1 || seg.find_seg(1,0,n-1,b,b)==1){
                // cout<<seg.find_seg(1,0,n-1,a,a)<<' '<<seg.find_seg(1,0,n-1,b,b)<<'\n';
                cout<<"impossible\n";
            }
            else{
                int v1=(a+1<b?seg.find_seg(1,0,n-1,a+1,b-1):0);
                int v2=(a>0?seg.find_seg(1,0,n-1,0,a-1):0)+(b<n-1?seg.find_seg(1,0,n-1,b+1,n-1):0);
                // cout<<v1<<' '<<v2<<'\n';
                if(v1==0 || v2==0) cout<<"possible\n";
                else cout<<"impossible\n";
            }

        }
        else if(c=='-'){
            int a;
            cin>>a;
            a--;
            seg.update_seg(1,0,n-1,a,1);

        }
        else{
            int a;
            cin>>a;
            a--;
            seg.update_seg(1,0,n-1,a,0);

        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    // cin>>t;
    while(t--){
        Solve();
    }
    return 0;
}

