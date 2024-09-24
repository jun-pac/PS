
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
//__attribute__((optimize("Ofast,unroll-loops"),target("avx,avx2,fma")))

#define N 300030
#define MOD 998244353
#define INF 1000000007 

vc<int> edges[N];
bool is_n[N]; // nut의 존재여부
int vacan[N];

int cnt=0;

void pre_DFS(int idx, int p){
    int val=0;
    for(auto next : edges[idx]){
        if(next==p) continue;
        pre_DFS(next,idx);
        if(!is_n[next]) val++;
    }
    vacan[idx]=val;
}

void DFS(int idx, int p, int md){
    cnt++;
    if(md==0){
        // is_n[idx]==0일 뿐만 아니라, 그 위에서도 끌고 내려온 게 없는 것.
        for(auto next : edges[idx]){
            if(next==p) continue;
            if(is_n[next] && vacan[next]!=0) DFS(next,idx,1);
            if(!is_n[next]) DFS(next,idx,0); 
        }
    }
    else{
        if(vacan[idx]>=2){
            for(auto next : edges[idx]){
                if(next==p) continue;
                if(is_n[next] && vacan[next]!=0) DFS(next,idx,1);
                if(!is_n[next]) DFS(next,idx,0); 
            }
        }
        else{
            for(auto next : edges[idx]){
                if(next==p) continue;
                if(vacan[next]>0) DFS(next,idx,1);
            }
        }
    }
}

void Solve(int tt){
    // 밀면서 가는 전략은 좋은 전략이 아니고,
    // 암튼 각 점이 도달가능한지만 잘 체크해주면 되는거잖아
    int n,m;
    cin>>n>>m;
    rng(i,0,n-2){
        int a,b;
        cin>>a>>b;
        a--, b--;
        edges[a].pb(b);
        edges[b].pb(a);
    }
    rng(i,0,m-1){
        int a;
        cin>>a;
        is_n[a-1]=1;
    } 
    pre_DFS(0,-1);
    DFS(0,-1,0);
    cout<<cnt<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    // cin>>t;
    rng(tt,0,t-1){
        Solve(tt);
    }
    return 0;
}

