
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
int cnt[N];
int leftmost[N];

void Solve(){
    int n;
    cin>>n;

    fill(cnt,cnt+n+1,0);
    rng(i,0,n-1) cin>>datas[i];
    int res=0;
    rng(i,0,n-1){
        if(datas[i]<=n) cnt[datas[i]]++;
    }
    int cntz=cnt[0];

    if(cntz==0) cout<<n<<'\n';
    else{
        bool flag=1;
        
        fill(leftmost,leftmost+n+1,-1);

        rng(i,0,n-1) if(datas[i]<=n){
            if(leftmost[datas[i]]==-1) leftmost[datas[i]]=i; 
        }
        int leftz=leftmost[0];
   
        rng(i,1,n){
            // cout<<"i "<<i<<' '<<leftz<<'\n';
            if(cnt[i]==0) break;
            else if(cnt[i]>1){
                if(leftmost[i]<leftz){
                    flag=0;
                    break;
                }
            }
            else{
                if(leftmost[i]<leftz){
                    leftz=leftmost[i];
                }
            }
        }
        if(flag) cout<<n-cntz+1<<'\n';
        else cout<<n-cntz<<'\n';
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

