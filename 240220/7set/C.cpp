
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
#define INF 1000300007 

ll datas[N];
//set<int> vals;
vc<ll> ans;
pll dur[N]; // {last, first}

#define N_node 9000000 // V log|Y_RANGE| scale 

class node{
public:
    node(){}
    int l_idx=-1, r_idx=-1; // 여기서 idx는 본인의 idx를 말한다.
    int val=0;    
};

class PST{
public:
    node seg[N_node]; // All node datas
    int s_cnt=2; // s_cnt는 현재까지 사용한 node의 개수
    void clear(){
        for(int i=0; i<s_cnt; i++) seg[i]=node();
        s_cnt=2;
    }

    void update_seg(int idx, int l, int r, int t_idx, int val){
        //assert(idx!=-1);
        //cout<<idx<<' '<<l<<' '<<r<<' '<<s_cnt<<'\n';
        if(l==r){
            // Implement. 과거의 데이터에 덮어씌우는 것은 이부분이 유일.
            seg[idx].val=val;
            return;
        }
        //cout<<idx<<' '<<l<<' '<<r<<' '<<s_cnt<<endl;
        int mid=(l+r)>>1;
        if(t_idx<=mid){
            if(seg[idx].l_idx==-1){
                seg[idx].l_idx=s_cnt;
                //cout<<"??? "<<idx<<' '<<s_cnt<<'\n';
                seg[s_cnt]=node();
                //cout<<s_cnt<<' '<<seg[s_cnt].l_idx<<' '<<seg[s_cnt].r_idx<<endl;
                s_cnt++;
            }
            //cout<<"l ? "<<seg[idx].l_idx<<' '<<s_cnt<<'\n';
            update_seg(seg[idx].l_idx,l,mid,t_idx,val);
        }
        else{
            if(seg[idx].r_idx==-1){
                seg[idx].r_idx=s_cnt;
                seg[s_cnt]=node();
                s_cnt++;
            }
            //cout<<"r ? "<<seg[idx].r_idx<<'\n';
            update_seg(seg[idx].r_idx,mid+1,r,t_idx,val);
        }
        // 아래의 덧셈연산은 l_idx와 r_idx를 보존하기 위한 방법 
        int temp=0;
        if(seg[idx].l_idx!=-1) temp+=seg[seg[idx].l_idx].val;
        if(seg[idx].r_idx!=-1) temp+=seg[seg[idx].r_idx].val;
        //cout<<"update "<<idx<<' '<<l<<' '<<r<<' '<<temp<<'\n';
        seg[idx].val=temp;
    }
    int find_seg(int idx, int l, int r, int t_l, int t_r){
        if(t_l<=l && r<=t_r){
            return seg[idx].val;
        }
        int mid=(l+r)>>1;
        int res=0;
        if(t_l<=mid && seg[idx].l_idx!=-1) res=res+find_seg(seg[idx].l_idx,l,mid,t_l,t_r);
        if(t_r>mid && seg[idx].r_idx!=-1) res=res+find_seg(seg[idx].r_idx,mid+1,r,t_l,t_r);
        return res;
    }
};

PST pst;

void Solve(){
    int n;
    cin>>n;
    //while(!pq.empty()) pq.pop();
    //delidx.clear();
    ans.clear();
    pst.clear();
    rng(i,0,n-1) cin>>datas[i];
    rng(i,0,n-1) dur[i]={datas[i]+1,(datas[i]+i+1)};
    sort(dur,dur+n);
    //rng(i,0,n-1) cout<<dur[i][0]<<' '<<dur[i][1]<<' '<<dur[i][2]<<'\n';
    gnr(i,n-1,0){
        ll r=dur[i].se;
        ll l=dur[i].fi;
        // {i,r}가장 우측 빈칸을 찾는 게 목표
        //cout<<"lr "<<l<<' '<<r<<' '<<pst.find_seg(1,0,INF,l,r)<<'\n';
        if(pst.find_seg(1,0,INF,l,r)==r-l+1) continue;
        ll e=r;
        ll s=l;
        while(s<e){
            ll mid=(s+e+1)>>1;
            if(pst.find_seg(1,0,INF,mid,r)==r-mid+1) e=mid-1;
            else s=mid;
        }
        pst.update_seg(1,0,INF,s,1);
        // cout<<"up "<<s<<'\n';
        // cout<<"terr "<<pst.find_seg(1,0,INF,0,INF)<<'\n';
        // cout<<"terr "<<pst.find_seg(1,0,INF,0,2)<<'\n';
        // cout<<"terr "<<pst.find_seg(1,0,INF,2,3)<<'\n';
        // cout<<"terr "<<pst.find_seg(1,0,INF,3,3)<<'\n';
        // cout<<"terr "<<pst.find_seg(1,0,INF,3,4)<<'\n';
        // cout<<"terr "<<pst.find_seg(1,0,INF,4,5)<<'\n';
        ans.pb(s); // 이게 정렬이 안돼있다 ㅅㅂ...
    }
    sort(all(ans));
    reverse(all(ans));
    rng(i,0,(int)ans.size()-1) cout<<ans[i]<<' '; cout<<'\n';
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

