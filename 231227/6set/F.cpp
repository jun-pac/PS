
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
vc<int> child[N];
int sz[N];

int sz_DFS(int idx){
    sz[idx]=1;
    for(auto next : child[idx]){
        sz[idx]+=sz_DFS(next);
    }
    return sz[idx];
}

int DFS(int idx){
    if(child[idx].size()==0) return 0;
    vc<int> temp;
    for(auto next : child[idx]){
        temp.pb(sz[next]);
    }
    sort(all(temp));
    reverse(all(temp));
    int sum=sz[idx]-1;
    if(temp[0]>sum/2){
        int mxidx=0;
        for(int i=0; i<child[idx].size(); i++) if(sz[child[idx][i]]==temp[0]) mxidx=child[idx][i];
        return sum-temp[0]+min((2*temp[0]-sum)/2,DFS(mxidx));
    }   
    else{
        return sum/2;
    }
}

void Solve(){
    int n,p;
    cin>>n;
    rng(i,0,n-1) child[i].clear();
    rng(i,0,n-2){
        cin>>p;
        p--;
        child[p].pb(i+1);
    }
    sz_DFS(0);
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

