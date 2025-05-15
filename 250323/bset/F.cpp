
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
// random_device rd; 
// mt19937 gen(rd());
// uniform_int_distribution<> dist(0, INF); // random integer from [0, INF] // dist(gen)

int datas[N];
int ldp[N], rdp[N], cnt[N], lclosest_idx[N], last[N];

class node{
public:
    // Do something!
    node(){}
    //node(int val){this->val=val;}
    node operator+(node b){
        node result;
        result.val=max(val,b.val); // Modify
        return result;
    }
    int val=0, lazy_val=0;
};

class lazy_seg{
public:
    node seg[1<<20];
    
    lazy_seg(){}
    //lazy_seg(int n){}
    
    void build_seg(int idx, int l, int r){
        if(l==r){
            seg[idx].val=0; // seg[idx].val=datas[l];
            seg[idx].lazy_val=0;
        }
        else{
            int mid=(l+r)>>1;
            build_seg(2*idx,l,mid);
            build_seg(2*idx+1,mid+1,r);
            seg[idx]=(seg[2*idx]+seg[2*idx+1]);
        }
    }
    
    void update_down(int idx, int l, int r){
        if(l==r) return;
        int mid=(l+r)>>1;
        // seg[2*idx], seg[2*idx+1]
        seg[2*idx].val+=seg[idx].lazy_val;
        seg[2*idx].lazy_val+=seg[idx].lazy_val;
        seg[2*idx+1].val+=seg[idx].lazy_val;
        seg[2*idx+1].lazy_val+=seg[idx].lazy_val;
        // seg[idx]의 lazy_val초기화
        seg[idx].lazy_val=0;
    }
    
    void update_seg(int idx, int l, int r, int t_l, int t_r, int val){
        update_down(idx, l, r);
        if(t_l<=l && r<=t_r){
            // // seg[idx].val과 seg[idx].lazy_val업데이트
            seg[idx].val+=val;
            seg[idx].lazy_val+=val;
            return;
        }
        int mid=(l+r)>>1;
        if(t_l<=mid) update_seg(2*idx,l,mid,t_l,t_r,val);
        if(t_r>mid) update_seg(2*idx+1,mid+1,r,t_l,t_r,val);
        seg[idx]=(seg[2*idx]+seg[2*idx+1]);
    }
    
    node find_seg(int idx, int l, int r, int t_l, int t_r){
        update_down(idx, l, r);
        if(t_l<=l && r<=t_r){
            return seg[idx];
        }
        node result;
        int mid=(l+r)>>1;
        if(t_l<=mid) result=(result+find_seg(2*idx,l,mid,t_l,t_r));
        if(t_r>mid) result=(result+find_seg(2*idx+1,mid+1,r,t_l,t_r));
        return result;
    }
};

lazy_seg s;


void Solve(){
    int n;
    cin>>n;
    rng(i,0,n-1) cin>>datas[i];
    int cur=0;
    fill(cnt,cnt+n+2,0);
    gnr(i,n-1,0){
        if(cnt[datas[i]]==0) cur++;
        cnt[datas[i]]++;
        rdp[i]=cur;
    }
    
    cur=0;
    fill(cnt,cnt+n+2,0);
    rng(i,0,n-1){
        if(cnt[datas[i]]==0) cur++;
        cnt[datas[i]]++;
        ldp[i]=cur;
    }

    fill(last,last+n,-1);
    rng(i,0,n-1){
        lclosest_idx[i]=last[datas[i]];
        last[datas[i]]=i;
    }

    s.build_seg(1,0,n-1);
    s.update_seg(1,0,n-1,1,1,2);
    int mx=s.find_seg(1,0,n-1,1,1).val+rdp[2];
    rng(i,2,n-2){
        // Not all ranges are meaningful. I mean, it dependes on sth that can't calculated
        int idx=lclosest_idx[i];
        int st=max(1,idx+1);
        s.update_seg(1,0,n-1,st,i,1);
        s.update_seg(1,0,n-1,i,i,ldp[i-1]);

        // cout<<datas[i]<<' '<<st<<' '<<s.find_seg(1,0,n-1,1,i).val<<' '<<rdp[i+1]<<'\n';
        mx=max(mx,s.find_seg(1,0,n-1,1,i).val+rdp[i+1]);
    }
    cout<<mx<<'\n';


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

