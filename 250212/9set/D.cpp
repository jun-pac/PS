
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

ll datas[20];

// map<ll,ll> mp;
ll q[2][5000000][13];
ll ans[5000000];

void Solve(){
    int n;
    cin>>n;
    rng(i,0,n-1) cin>>datas[i];

    q[1][0][0]=1; // 0은 언제나 길이
    q[1][0][1]=datas[0];
    int m=1;

    rng(k,1,n-1){
        int nm=0;
        rng(tt,0,m-1){
            int curlen=q[k%2][tt][0];
            // if(k==1) cout<<"initial "<<curlen<<'\n';
            rng(j,1,curlen){
                q[k%2][tt][j]+=datas[k];
                rng(i,0,curlen) q[(k+1)%2][nm][i]=q[k%2][tt][i];
                q[k%2][tt][j]-=datas[k];
                nm++;
            }
            q[(k+1)%2][nm][0]=curlen+1;
            rng(i,1,curlen) q[(k+1)%2][nm][i]=q[k%2][tt][i];
            q[(k+1)%2][nm][curlen+1]=datas[k];
            nm++;
        }
        m=nm;
        // cout<<"m ; "<<m<<' '<<nm<<'\n';
    }
    int cnt=0;
    rng(tt,0,m-1){
        ll val=0;
        int curlen=q[n%2][tt][0];
        rng(j,1,curlen){
            val=val^q[n%2][tt][j];
        }
        ans[tt]=val;
    }
    sort(ans,ans+m);
    cout<<unique(ans,ans+m)-ans<<'\n';
    
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

