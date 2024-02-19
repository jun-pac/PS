
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
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

string s;
int child[N][2];

int DFS(int idx){
    // min fix num
    if(child[idx][0]==-1 && child[idx][1]==-1) return 0;
    int vall=INF, valr=INF;
    if(child[idx][0]!=-1) vall=DFS(child[idx][0]);
    if(child[idx][1]!=-1) valr=DFS(child[idx][1]);
    return (s[idx]=='U'?1:0)+min((s[idx]=='R'?1:0)+vall,(s[idx]=='L'?1:0)+valr);
}

void Solve(){
    int n,a,b;
    cin>>n;
    cin>>s;
    rng(i,0,n-1){
        cin>>a>>b;
        a--, b--;
        child[i][0]=a;
        child[i][1]=b;
    }
    cout<<DFS(0)<<'\n';
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

