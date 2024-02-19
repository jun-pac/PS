
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

#define N_node 4000000 // V log|Y_RANGE| 
#define NX 200002
#define Y_RANGE 200002

pll datas[N];
ll sdata[N];


class node{
public:
    node(){}
    node operator+(node b){
        node res;
        // Implement. 예시는 단순히 개수 세는 것.
        // 왼쪽에 더해지는 node의 l_idx, r_idx를 보존한다.
        res.l_idx=l_idx, res.r_idx=r_idx;
        res.val=val+b.val;
        return res;
    }
    int l_idx=-1, r_idx=-1; // 여기서 idx는 본인의 idx를 말한다.
    long long val=0;    
};

class PST{
public:
    int seg_root[NX]; // X-wise root idx.
    node seg[N_node]; // All node datas
    int cur_x=0, s_cnt=0; // s_cnt는 현재까지 사용한 node의 개수
    PST(){}
    void push(int y_idx, ll y_val){
        // Pusing one element generate anothor root. Regardless of the val x.
        seg_root[cur_x]=s_cnt++;
        update_seg(seg_root[cur_x],(cur_x==0?-1:seg_root[cur_x-1]),0,Y_RANGE-1,y_idx,y_val);
        cur_x++;
    }
    node query(long long x, long long y1, long long y2){
        return find_seg(seg_root[x],0,Y_RANGE-1,y1,y2);
    }
    void clear(){
        for(int i=0; i<s_cnt; i++) seg[i]=node();
        cur_x=s_cnt=0;
    }

private:
    void update_seg(int idx, int prev_idx, int l, int r, int t_idx, long long val){
        // previous segtree의 idx도 같이 관리. (첫 번째 layer의 경우는 -1)
        if(l==r){
            // Implement. 과거의 데이터에 덮어씌우는 것은 이부분이 유일.
            seg[idx].val=val;
            if(prev_idx!=-1) seg[idx]=seg[idx]+seg[prev_idx];
            return;
        }
        int mid=(l+r)>>1;
        if(t_idx<=mid){
            seg[idx].l_idx=s_cnt++;
            seg[idx].r_idx=(prev_idx==-1?-1:seg[prev_idx].r_idx);
            update_seg(seg[idx].l_idx,(prev_idx==-1?-1:seg[prev_idx].l_idx),l,mid,t_idx,val);
        }
        else{
            seg[idx].r_idx=s_cnt++;
            seg[idx].l_idx=(prev_idx==-1?-1:seg[prev_idx].l_idx);
            update_seg(seg[idx].r_idx,(prev_idx==-1?-1:seg[prev_idx].r_idx),mid+1,r,t_idx,val);
        }
        // 아래의 덧셈연산은 l_idx와 r_idx를 보존하기 위한 방법 
        if(seg[idx].l_idx!=-1) seg[idx]=seg[idx]+seg[seg[idx].l_idx];
        if(seg[idx].r_idx!=-1) seg[idx]=seg[idx]+seg[seg[idx].r_idx];
    }
    node find_seg(int idx, int l, int r, int t_l, int t_r){
        if(t_l<=l && r<=t_r) return seg[idx];
        int mid=(l+r)>>1;
        node res;
        if(t_l<=mid && seg[idx].l_idx!=-1) res=res+find_seg(seg[idx].l_idx,l,mid,t_l,t_r);
        if(t_r>mid && seg[idx].r_idx!=-1) res=res+find_seg(seg[idx].r_idx,mid+1,r,t_l,t_r);
        return res;
    }
};

PST pst;

void Solve(){
    int n;
    cin>>n;
    rng(i,0,n-1){
        cin>>datas[i].fi;
        datas[i].se=i;
    }
    rng(i,0,n-1) sdata[i]=datas[i].fi;
    sort(datas,datas+n);
    sort(sdata,sdata+n);

    
    //build(root[0],0,INF-1);
    rng(i,0,n-1){
        pst.push(datas[i].se,datas[i].fi);
    }
    int q;
    cin>>q;
    ll res=0;
    rng(i,0,q-1){
        ll a,b,c;
        cin>>a>>b>>c;
        ll l,r,x;
        l=a^res;
        r=b^res;
        x=c^res;
        assert(1<=l && l<=n && 0<=r && r<=n && x<=INF);
        int pos=lower_bound(sdata,sdata+n,x+1)-sdata;
        // pos-1을 하고 pos+1을 해야..
        pos--;
        if(pos==-1) res=0;
        else res=pst.query(pos,l-1,r-1).val;
        cout<<res<<'\n';
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

