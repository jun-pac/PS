
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

ll datas[301][301]; // idx, time이라는 점 주의
ll sum[301][301];
int long1[301];

void Solve(){
    int n;
    cin>>n;
    rng(i,0,n-1){
        rng(j,0,n-1) cin>>datas[i][j];
        rng(j,0,n-1) sum[i][j]=(j==0?0:sum[i][j-1])+datas[i][j];
        long1[i]=0;
        rng(j,0,n-2) if(sum[i][n-1]-sum[i][n-1-j-1]==j+1) long1[i]=j+1;
    }
    sort(long1,long1+n);
    // rng(i,0,n-1) cout<<"long1 "<<long1[i]<<'\n';
    int mx=n-1;
    rng(i,1,n-1){
        int num=n-(lower_bound(long1,long1+n,i)-long1);
        // num-1+i개가 새로운 upperbound
        mx=min(mx,num-1+i);
    }
    // cout<<mx+1<<'\n';
    cout<<min(mx+1,n)<<'\n';
    // rng(i,0,n-1){
    //     rng(j,0,n){
    //         // 뒤에서 j개를 쓰는 것
    //         int temp=sum[i][n-1]-(j==n?0:sum[i][n-1-j]);
    //     }
    // }    

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

