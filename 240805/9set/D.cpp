
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
//__attribute__((optimize("Ofast,unroll-loops"),target("avx,avx2,fma")))

#define N 500030
#define MOD 998244353
#define INF 1000000007 

int datas[N];
int DP[N];
int n,k;

int check(int val){
    DP[0]=(datas[0]>=val?1:0);
    rng(i,1,n-1){
        // 현재 i+1칸임에 유의
        if((i+1)%k==1){
            DP[i]=max((datas[i]>=val?1:0),(i<k?0:DP[i-k]));
        }
        else{
            DP[i]=max((i<k?0:DP[i-k]),(datas[i]>=val?1:0)+DP[i-1]);
        }
    }
    return DP[n-1];
}

void Solve(){
    cin>>n>>k;
    rng(i,0,n-1) cin>>datas[i];
    int num=(n-1)%k+1;
    //cout<<"num "<<num<<' '<<(num+2)/2<<'\n';
    // val이 중간값이 되기 위해서는
    // val이상인 것이 (num+1)/2개는 남아있어야 함.
    int l=1, r=INF;
    while(l<r){
        int mid=(l+r+1)>>1;
        if(check(mid)>=(num+2)/2) l=mid;
        else r=mid-1;
    }
    cout<<l<<'\n';
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

