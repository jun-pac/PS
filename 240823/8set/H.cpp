
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

#define N 4000020
#define MOD 998244353
#define INF 1000000007 

// 이거 약간 금광세그 st로 주어진 구간에서 가장 긴 연속한 빈구간은 찾을 수 있음.
// [l,r]에 해가 있는가 -> [l,r+k-1]에서 최대로 연속한 빈구간의 길이가 k이상인가?
// 금광세그를 만들면 O(nlogn^2)으로 체크 가능
// 근데 금광세그가 복잡도가 나오나 이게
// int 4개씩 써도 64MB밖에 안됨 이론적으로는
int visited[N];
int curnum=0;

class node{
public:
    node operator+(node b){
        node res;
        res.lmx=(lmx==tnum?lmx+b.lmx:lmx);
        res.rmx=(b.rmx==b.tnum?b.rmx+rmx:b.rmx);
        res.tmx=max(rmx+b.lmx,max(tmx,b.tmx));
        res.tnum=tnum+b.tnum;
        return res;
    }
    int lmx, rmx, tmx, tnum; // 빈구간에 관심이 있는거니까
};

class segtree_gold{
public:
    node seg[1<<23];
    void build_seg(int idx, int l, int r){
        if(l==r){
            if(visited[l]==curnum){
                seg[idx].lmx=0;
                seg[idx].rmx=0;
                seg[idx].tmx=0;
                seg[idx].tnum=1;
            }
            else{
                seg[idx].lmx=1;
                seg[idx].rmx=1;
                seg[idx].tmx=1;
                seg[idx].tnum=1;
            }
            return;
        }
        int mid=(l+r)>>1;
        build_seg(2*idx,l,mid);
        build_seg(2*idx+1,mid+1,r);
        seg[idx]=seg[2*idx]+seg[2*idx+1];
    }
    void update_seg(int idx, int l, int r, int tidx){
        if(l==r){ // ==tidx
            if(visited[l]==curnum){
                seg[idx].lmx=0;
                seg[idx].rmx=0;
                seg[idx].tmx=0;
                seg[idx].tnum=1;
            }
            else{
                seg[idx].lmx=1;
                seg[idx].rmx=1;
                seg[idx].tmx=1;
                seg[idx].tnum=1;
            }
            return;
        }
        int mid=(l+r)>>1;
        if(tidx<=mid) update_seg(2*idx,l,mid,tidx);
        else update_seg(2*idx+1,mid+1,r,tidx);
        seg[idx]=seg[2*idx]+seg[2*idx+1];
    }
    node find_seg(int idx, int l, int r, int tl, int tr){
        if(tl<=l && r<=tr) return seg[idx];
        int mid=(l+r)>>1;
        node res;
        res.lmx=res.rmx=res.tmx=res.tnum=0;
        if(tl<=mid) res=res+find_seg(2*idx,l,mid,tl,tr);
        if(tr>mid) res=res+find_seg(2*idx+1,mid+1,r,tl,tr);
        return res;
    }
};
segtree_gold s;


void Solve(){
    curnum++;
    int n;
    cin>>n;
    set<int> datas;
    rng(i,0,n-1){
        int a;
        cin>>a;
        datas.insert(a);
        visited[a]=curnum;
        s.update_seg(1,0,N-1,a);
    }   
    
    int m;
    cin>>m;
    rng(i,0,m-1){
        char c;
        cin>>c;
        int k;
        cin>>k;
        if(c=='+'){
            visited[k]=curnum;
            datas.insert(k);
            s.update_seg(1,0,N-1,k);
        }
        else if(c=='-'){
            visited[k]=0;
            datas.erase(k);
            s.update_seg(1,0,N-1,k);
        }
        else{
            //findseg
            int l=1, r=2000001;
            while(l<r){
                int mid=(l+r)>>1;
                //cout<<"range, k, max conseq : "<<l<<' '<<mid+k-1<<' '<<k<<' '<<s.find_seg(1,0,N-1,l,mid+k-1).tmx<<'\n';
                if(s.find_seg(1,0,N-1,l,mid+k-1).tmx>=k) r=mid;
                else l=mid+1;
            }
            cout<<l<<' ';
        }
    } 
    cout<<'\n';
    //set에 있는 것들을 제거해줘야.
    for(auto val : datas){
        visited[val]=0;
        s.update_seg(1,0,N-1,val);
    }
}   

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    cin>>t;
    curnum=1;
    s.build_seg(1,0,N-1);
    while(t--){
        Solve();
    }
    return 0;
}

