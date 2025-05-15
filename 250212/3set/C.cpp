
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

string p;
ll mp[1001][1001];
bool visited[1001][1001];
ll rcnt[1001], ccnt[1001];
ll rsum[1001], csum[1001];
void Solve(){
    int n,m;
    cin>>n>>m;
    int pl=n+m-2;
    cin>>p;
    rng(i,0,n-1) rng(j,0,m-1){
        cin>>mp[i][j];
    }
    fill(rcnt,rcnt+n,0);
    fill(ccnt,ccnt+m,0);
    fill(rsum,rsum+n,0);
    fill(csum,csum+m,0);
    rng(i,0,n-1) fill(visited[i],visited[i]+m,0);
    int x=0, y=0;
    visited[x][y]=1;
    rcnt[x]++;
    ccnt[y]++;
    rng(i,0,n+m-3){
        if(p[i]=='D') x++;
        else y++;
        visited[x][y]=1;
        rcnt[x]++;
        ccnt[y]++;
    }
    rng(i,0,n-1){
        int temp=0;
        rng(j,0,m-1) temp+=mp[i][j];
        rsum[i]=temp;
    }
    rng(j,0,m-1){
        int temp=0;
        rng(i,0,n-1) temp+=mp[i][j];
        csum[j]=temp;
    }
    x=0, y=0;
    mp[x][y]=(p[0]=='D'?0-rsum[x]:0-csum[y]);
    rsum[x]+=mp[x][y];
    csum[y]+=mp[x][y];
    rng(i,0,n+m-3){
        if(p[i]=='D') x++;
        else y++;
        if(i==n+m-3){
            mp[x][y]=0-rsum[x];
        }
        else{
            mp[x][y]=(p[i+1]=='D'?0-rsum[x]:0-csum[y]);
        }
        rsum[x]+=mp[x][y];
        csum[y]+=mp[x][y];
    }
    rng(i,0,n-1){
        rng(j,0,m-1) cout<<mp[i][j]<<' ';
        cout<<'\n';
    }
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

