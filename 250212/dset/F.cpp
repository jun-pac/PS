
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
random_device rd; 
mt19937 gen(rd());
uniform_int_distribution<> dist(0, INF); // random integer from [0, INF] // dist(gen)

int datas[N];

class segtree{
public:	
    int seg[1<<20];
    int info;
    segtree(){}
    
    void build_seg(int idx, int l, int r){
        if(l==r){
            seg[idx]=1;
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
int ans[N];

void Solve(){
    int n;
    cin>>n;
    rng(i,0,n-1){
        cin>>datas[i];
    }
    seg.build_seg(1,0,n-1);
    gnr(i,n-1,0){
        int l=0, r=n-1;

        // [l,r]
        while(l<r){
            int mid=(l+r)/2;
            if(seg.find_seg(1,0,n-1,0,mid) >= datas[i]){
                r=mid;
            }
            else l=mid+1;
        }  
        ans[l]=i+1;
        seg.update_seg(1,0,n-1,l,0);
    }
    rng(i,0,n-1) cout<<ans[i]<<' ';
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

