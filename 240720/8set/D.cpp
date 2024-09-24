
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

#define N 3030
#define MOD 998244353
#define INF 1000000007 
__attribute__((optimize("Ofast,unroll-loops"),target("avx,avx2,fma")))

vc<int> edges[N];
int datas[N];
int parent[N];
pii ans[N];
int res[N]; // residual
bool used[N];

int find_r(int idx){
    return parent[idx]=(parent[idx]==idx?idx:find_r(parent[idx]));
}

void Solve(){
    int n;
    cin>>n;
    rng(i,0,n-1) edges[i].clear();
    rng(i,0,n-1) cin>>datas[i];
    rng(i,0,n-1) parent[i]=i;
    fill(used,used+n,0); // union됐으면 혼동을 위해 하나는 지워주자.

    gnr(k,n-1,1){
        // k th operation에서는 k의 배수를 이을 수 있음.
        // union-find는 당연히 쓸 거 같긴 한데
        fill(res,res+n,-1);
        rng(i,0,n-1){
            if(!used[i]){
                int temp=datas[i]%k;
                if(res[temp]==-1) res[temp]=i;
                else{
                    ans[k]={i,res[temp]};
                    used[i]=1;
                    break;
                }
            }
        }
    }
    cout<<"YES\n";
    rng(i,1,n-1){
        cout<<ans[i].fi+1<<' '<<ans[i].se+1<<'\n';
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

