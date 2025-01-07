
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
		seg[idx]=(seg[2*idx]+seg[2*idx+1]); 
	}

	void update_seg(int idx, int l, int r, int t_idx, int val){
		if(l==r){
			seg[idx]+=val; // Modify
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

#define MAX_DIGIT 62

// Remember (ak)*(bk)^(-1) === a*b^(-1) === (ak%P)*(bk%P)^(-1) (mod P)
long long ari_inv(long long num){
    // Calculate num^(MOD-2)
    long long res=1, mult=num;
    for(int i=0; i<MAX_DIGIT; i++){
        if((MOD-2)&(1LL<<i)){
            res=(res*mult)%MOD;
        }
        mult=(mult*mult)%MOD;
    }
    return res;
}


int datas[N];

void Solve(){
    ll n,k;
    cin>>n>>k;
    rng(i,0,n-1){
        cin>>datas[i];
        datas[i]--;
    }
    seg.build_seg(1,0,n-1);
    ll curinv=0;
    ll sum=0;
    rng(i,0,k-1){
        seg.update_seg(1,0,n-1,datas[i],1);
        if(datas[i]!=n-1) curinv+=seg.find_seg(1,0,n-1,datas[i]+1,n-1);
    }
    sum+=curinv;
    rng(i,0,n-k-1){
        // i제거
        if(datas[i]!=0) curinv-=seg.find_seg(1,0,n-1,0,datas[i]-1);
        seg.update_seg(1,0,n-1,datas[i],-1);

        // i+k추가
        seg.update_seg(1,0,n-1,datas[i+k],1);
        if(datas[i+k]!=n-1) curinv+=seg.find_seg(1,0,n-1,datas[i+k]+1,n-1);
        
        sum+=curinv;
        sum%=MOD;
    }
    
    ll tot=0;
    seg.build_seg(1,0,n-1);
    rng(i,0,n-1){
        seg.update_seg(1,0,n-1,datas[i],1);
        if(datas[i]!=n-1) tot+=seg.find_seg(1,0,n-1,datas[i]+1,n-1);
    }
    tot%=MOD;

    ll res=tot+(k*(k-1)/2)%MOD*ari_inv(2)%MOD-sum*ari_inv(n-k+1)%MOD;

    cout<<(res%MOD+MOD)%MOD<<'\n';

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

