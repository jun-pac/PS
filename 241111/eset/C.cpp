
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

int datas[N];

int DFS(int l, int r, int val){ // 하나는 제거
    if(l==r) return val;
    else if(l>r) return -1;
    int mid=(l+r)>>1;
    int mx=val;
    int cur=val;
    rng(i,l,mid-1){
        if(datas[i]>cur) cur++;
        else if(datas[i]<cur) cur--;
        mx=max(mx,cur); // mid는 무조건 제거하는 시나리오
    }
    int nextcur=cur;
    if(datas[mid]>nextcur) nextcur++;
    else if(datas[mid]<nextcur) nextcur--;

    cur=mx;
    rng(i,mid+1,r){
        if(datas[i]>cur) cur++;
        else if(datas[i]<cur) cur--;
        cur=max(cur,mx);
    }
    // cout<<l<<' '<<r<<' '<<mx<<' '<<res<<'\n';
    int lmx=DFS(l,mid-1,val);
    rng(i,mid,r){
        if(datas[i]>lmx) lmx++;
        else if(datas[i]<lmx) lmx--;
    }
    int rmx=DFS(mid+1,r,nextcur);
    int res=max(cur,max(lmx,rmx));
    return res;
}

void Solve(){
    int n;
    cin>>n;
    rng(i,0,n-1) cin>>datas[i];
    cout<<DFS(0,n-1,0)<<'\n';
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

