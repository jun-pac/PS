
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

int x[N], datas[N];
// vc<int> edges[N];
// bool is_c[N];
// int depth[N];
// // 일단 scc를 묶고 생각해보는건 어떰?
// bool in[N], out[N];
// int ccnt=0; // cycle cnt
// int cycle_num[N];
// vc<int> cycle_idx[N]; // ccnt로 접근하면 각 cycle의 노드를 순서대로 알려준다.
// int inv_cidx[N]; // 위의 것의 inverse를 알려준다.
// int ans[N];

// bool DFS(int idx){
//     in[idx]=1;
//     bool is_cycle=0;
//     for(auto next : edges[idx]){
//         if(!in[next]) is_cycle=is_cycle|DFS(next);
//         else if(in[next] && !out[next]){
//             // cycle의 증거임.
//             ccnt++;
//             is_cycle=1;
//         }
//     }
//     out[idx]=1;
//     is_c[idx]=is_cycle;
//     if(is_cycle){
//         cycle_num[idx]=ccnt;
//         inv_cidx[idx]=cycle_idx[ccnt].size();
//         cycle_idx[ccnt].push_back(idx);
//     }
//     return is_cycle;
// }

// void Solve(){
//     ll n,k;
//     cin>>n>>k;
//     rng(i,0,n-1){
//         cin>>x[i];
//         x[i]--;
//         edges[x[i]].pb(i);
//     }
//     rng(i,0,n-1) cin>>datas[i];
//     ccnt=-1;
//     rng(i,0,n-1) if(!in[i]) DFS(i);


//     rng(i,0,n-1){
//         if(is_c[i]){
//             int cnum=cycle_num[i];
//             int pos=inv_cidx[i]; // cycle에서 너의 idx
//             ans[i]=datas[cycle_idx[cnum][(pos+k)%((int)cycle_idx[cnum].size())]];
//             //cout<<ans[i]<<' ';
//         }
//         //else cout<<'-'<<' ';
//     }
    
// }

int parent[61][N];
int ans[N];

void Solve(){
    ll n,k;
    cin>>n>>k;
    rng(i,0,n-1){
        cin>>x[i];
        x[i]--;
    }
    rng(i,0,n-1) cin>>datas[i];
    rng(t,0,60){
        if(t==0) rng(i,0,n) parent[t][i]=x[i];
        else{
            rng(i,0,n-1) parent[t][i]=parent[t-1][parent[t-1][i]];
        }
    }
    rng(i,0,n-1) ans[i]=i;
    gnr(t,60,0){
        if((1LL<<t)<=k){
            rng(i,0,n-1) ans[i]=parent[t][ans[i]];
            k-=(1LL<<t);
        }
    }    
    rng(i,0,n-1) cout<<datas[ans[i]]<<' ';
    cout<<'\n';

}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    //cin>>t;
    while(t--){
        Solve();
    }
    return 0;
}

