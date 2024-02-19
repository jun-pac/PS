
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

int datas[202];
array<int,3> seg[202]; // seg[i]는 {end, start,idx}순으로 정렬됨
int DP[202]; // [i][is_back] 마지막으로 쓰인 게 i라는 전제임

void Solve(){
    int n;
    cin>>n;
    rng(i,0,n-1) cin>>datas[i];
    rng(i,0,n-1){
        int l=max(0,i-datas[i]+1);
        int r=min(n-1,i+datas[i]-1);
        seg[2*i]={i,l,i};
        seg[2*i+1]={r,i,i};
    }
    sort(seg,seg+2*n);

    // main DP
    fill(DP,DP+2*n,INF);
    DP[0]=1;
    rng(i,1,2*n-1){
        int l=seg[i][1], r=seg[i][0];
        if(l==0) DP[i]=1;
        rng(j,0,i-1){
            if(seg[j][0]>=l-1 && seg[j][2]!=seg[i][2]) DP[i]=min(DP[i],DP[j]+1);
        }
        //cout<<"DP "<<i<<" ( "<<l<<' '<<r<<" ) "<<DP[i]<<endl;
    }

    int res=INF;
    rng(i,0,2*n-1){
        if(seg[i][0]>=n-1) res=min(res,DP[i]);
    }
    cout<<res<<'\n';
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

