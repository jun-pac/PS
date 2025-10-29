
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

int ans[40];
int DP[40][450]; // i number, j sum // pred


void Solve(){
    int n,k;
    cin>>n>>k;
    int tar=(n*(n-1))/2-k;
    rng(i,0,n) fill(DP[i], DP[i]+tar+1, -1);
    // if(tar==0){
    //     rng(i,0,n-1) cout<<n-i<<' ';
    //     cout<<'\n';
    //     return;
    // }
    rng(i,1,n){
        if((i*(i-1))/2 <= tar) DP[i][(i*(i-1))/2]=i;
        rng(j,1,i-1){
            if((j*(j-1))/2 > tar) break;
            rng(k,(j*(j-1))/2,tar) if(DP[i-j][k-(j*(j-1))/2]!=-1) DP[i][k] = j;
        }
    }

    if(DP[n][tar]==-1){
        cout<<0<<'\n';
        return;
    }
    vc<int> chunk;
    int sum=0;
    int num=n;
    while(num>0){
        assert(DP[num][tar]!=-1);
        if(DP[num][tar]>1){
            // cout<<"chunkval "<<DP[num][tar]<<'\n';
            chunk.pb(DP[num][tar]); 
            // sum+=DP[num][tar];
        }
        int ret=(DP[num][tar]*(DP[num][tar]-1))/2;
        num=num-DP[num][tar];
        tar = tar-ret;
    }
    int cur=n;
    for(auto val: chunk){
        
        rng(i,0,val-1) cout<<cur-val+1+i<<' ';
        cur-=val;
    }
    while(cur>=1){
        cout<<cur<<' ';
        cur--;
    }
    cout<<'\n';

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

