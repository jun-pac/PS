
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

vc<int> edges[N];
string s;
int nleaf, n0, n1, nelse;

void DFS(int idx, int p){
    for(auto next : edges[idx]){
        if(next!=p){
            DFS(next,idx);
        }
    }
    if(idx!=0 && edges[idx].size()==1){
        // leaf
        nleaf++;
        if(s[idx]=='1') n1++;
        if(s[idx]=='0') n0++;
    }
    else if(idx!=0 && s[idx]=='?'){
        nelse++;
    }
}
void Solve(){
    int n;
    cin>>n;
    rng(i,0,n-1) edges[i].clear();
    rng(i,0,n-2){
        int a,b;
        cin>>a>>b;
        a--, b--;
        edges[a].pb(b);
        edges[b].pb(a);
    }
    cin>>s;
    nelse=0;
    nleaf=0, n0=0, n1=0;
    DFS(0,-1);
    if(s[0]=='?'){
        if(n0>n1){
            cout<<n0+(nleaf-n0-n1)/2<<'\n';
        }
        else if(n0<n1){ // 같으면 상관없음
            cout<<n1+(nleaf-n0-n1)/2<<'\n';
        }
        else{
            // 같을 때는 먼저하는게 손해기때문에
            if(nelse%2==0) cout<<n0+(nleaf-n0-n1)/2<<'\n';
            else cout<<n0+(nleaf-n0-n1+1)/2<<'\n';
        }
    }
    else{
        if(s[0]=='0') cout<<n1+(nleaf-n0-n1+1)/2<<'\n';
        else cout<<n0+(nleaf-n0-n1+1)/2<<'\n';
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

