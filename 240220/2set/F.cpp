
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

vc<int> datas[N];
vc<int> edges[N];

int in[N], out[N], cnt;
bool DFS(int idx){
    if(in[idx]!=-1 && out[idx]==-1) return 0;
    else if(in[idx]!=-1) return 1;
    in[idx]=cnt++;
    for(auto next : edges[idx]){
        if(!DFS(next)) return 0;
    }
    out[idx]=cnt++;
    return 1;
}

void Solve(){
    int n,k;
    cin>>n>>k;
    rng(i,0,k-1) datas[i].resize(n);
    rng(i,0,n-1) edges[i].clear();
    rng(i,0,k-1) rng(j,0,n-1) cin>>datas[i][j];
    if(k<=1){
        cout<<"YES\n";
        return;
    }
    rng(i,0,k-1){
        rng(j,2,n-1){
            //cout<<datas[i][j]-1<<' '<<datas[i][j-1]-1<<endl;
            edges[datas[i][j]-1].pb(datas[i][j-1]-1);
        }
    }
    // cycle detection
    fill(in,in+n,-1);
    fill(out,out+n,-1);
    bool flag=1;
    cnt=0;
    rng(i,0,n-1){
        if(in[i]==-1){
            if(!DFS(i)){
                flag=0; break;
            }
        }
    }
    cout<<(flag?"YES\n":"NO\n");
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

