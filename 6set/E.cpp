
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

#define N 500030
#define MOD 998244353
#define INF 1000000007 

string s;

int datas[N];

class segtree{
public:	
	int seg[1<<20];
	segtree(){}
	segtree(int n){}
	
	void build_seg(int idx, int l, int r){
		if(l==r){
			seg[idx]=datas[l];
			return;
		}
		int mid=(l+r)>>1;
		build_seg(2*idx,l,mid);
		build_seg(2*idx+1,mid+1,r);
		seg[idx]=max(seg[2*idx],seg[2*idx+1]); // Modify
	}

	void update_seg(int idx, int l, int r, int t_idx, int val){
		if(l==r){
			seg[idx]=(seg[idx]+val)%2; // Modify
			return;
		}
		int mid=(l+r)>>1;
		if(t_idx<=mid) update_seg(2*idx,l,mid,t_idx, val);
		else update_seg(2*idx+1,mid+1,r,t_idx, val);
		seg[idx]=max(seg[2*idx],seg[2*idx+1]); // Modify
	}

	int find_seg(int idx, int l, int r, int t_l, int t_r){
		if(t_l<=l && r<=t_r) return seg[idx];
		int mid=(l+r)>>1, ans=0;
		if(t_l<=mid) ans=max(ans,find_seg(2*idx,l,mid,t_l,t_r)); // Modify
		if(t_r>mid) ans=max(ans,find_seg(2*idx+1,mid+1,r,t_l,t_r)); // Modify
		return ans;
	}
};

segtree seg;

void Solve(){
    int n,q;
    cin>>n>>q;
    cin>>s;
    if(n==1){
        rng(i,0,q-1){
            int c,a,b;
            cin>>c>>a>>b;
            if(c==2) cout<<"Yes\n";
        }
        return;
    }
    rng(i,0,n-2) datas[i]=(s[i]==s[i+1]); // 다르면 0 (정상임)
    //rng(i,0,n-2) cout<<datas[i]<<' '; cout<<'\n';
    seg.build_seg(1,0,n-2); // n-2
    rng(i,0,q-1){
        int c,a,b;
        cin>>c>>a>>b;
        if(c==1){
            a-=2; b-=1;
            if(a!=-1) seg.update_seg(1,0,n-2,a,1);
            if(b!=n-1) seg.update_seg(1,0,n-2,b,1);
        }
        else{
            a-=1;
            b-=2;
            if(a>b) cout<<"Yes\n";
            else{
                int mx=seg.find_seg(1,0,n-2,a,b);
                //cout<<"mx "<<mx<<'\n';
                cout<<(mx==0?"Yes\n":"No\n");
            }
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

