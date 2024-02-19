
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

#define N 200030
#define MOD 998244353
#define INF 1000000007 

// 어떤 simple path도 XOR값이 0이면 안 됨
// XOR{ A --- LCA --- B } == 0 <=> XOR{ROOT --- A} == XOR{ROOT --- B} 는 아니네 
// XOR{ROOT --- A} ^ LCA ^ XOR{ROOT --- B} ==0 가 맞다 
// 아 바꾸는 값은 제한이 없었네ㅋㅋㅋ


int datas[N];
vc<int> edges[N];
int xval[N];
set<int> DP[N];
int res;

void DFS1(int idx, int p, int cur){
    xval[idx]=cur^datas[idx];
    for(auto next : edges[idx]){
        if(next==p) continue;
        DFS1(next,idx,xval[idx]);
    }
}

bool DFS2(int idx, int p){
    vc<int> child;
    for(auto next : edges[idx]){
        if(next==p) continue;
        if(DFS2(next,idx)) child.pb(next);
    }
    for(auto ch : child){
        if(DP[ch].size()>DP[idx].size()) swap(DP[idx],DP[ch]);
    }
    bool flag=1;
    for(auto ch : child){
        for(auto val : DP[ch]){
            if(DP[idx].find(val^datas[idx])!=DP[idx].end()){
                flag=0;
                break;
            }
        }
        for(auto val : DP[ch]){
            DP[idx].insert(val);
        }
    }
    if(DP[idx].find(xval[idx]^datas[idx])!=DP[idx].end()) flag=0;
    DP[idx].insert(xval[idx]);
    if(!flag){
        res++;
        return 0;
    }
    return 1;
}

void Solve(){
    int n,a,b;
    cin>>n;
    rng(i,0,n-1) cin>>datas[i];
    rng(i,0,n-2){
        cin>>a>>b;
        a--, b--;
        edges[a].pb(b);
        edges[b].pb(a);
    }
    DFS1(0,-1,0);
    DFS2(0,-1);
    cout<<res<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    while(t--){
        Solve();
    }
    return 0;
}

