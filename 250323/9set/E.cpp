
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

vc<pll> edges[N];
array<ll,3> es[N];
int visited[N];
ll DP[N];

// void DFS(int idx, ll val){
//     DP[idx]=val;
//     for(auto temp: edges[idx]){
//         if(DP[temp.fi]==-1){
//             DFS(temp.fi,temp.se^val);
//         }
//     }
// }

ll cnt;
vc<pll> tar;

ll DFS2(int idx, ll pos, int val){
    if(visited[idx]) return 0;
    visited[idx]=1;
    tar.pb({idx,val});
    cnt++;
    ll res=val; 
    for(auto temp: edges[idx]){
        if(!visited[temp.fi]){
            if(temp.se&pos) res+=DFS2(temp.fi,pos,1-val);
            else res+=DFS2(temp.fi,pos,val);
        }
    }
    return res;
}

void Solve(){
    int n,m;
    cin>>n>>m;
    rng(i,0,m-1){
        ll a,b,z;
        cin>>a>>b>>z;
        a--, b--;
        edges[a].pb({b,z});
        edges[b].pb({a,z});
        es[i]={a,b,z};
    }
    // loop는 모두 0의 값을 가져야.
    // 0인 loop는 하나의 edges를 제거.

    // loop가 없다면 forest라는 것인데, 아니 여기서 sum을 어떻게 줄이냐고
    // fill(DP,DP+n,-1);

    // rng(i,0,n-1) if(DP[i]==-1){
    //     DFS(i,0);
    // }
    // rng(i,0,m-1) if(DP[es[i][0]]^DP[es[i][1]]!=es[i][2]){
    //     cout<<"WHERE? "<<es[i][0]<<' '<<es[i][1]<<' '<<es[i][2]<<' '<<DP[es[i][0]]<<' '<<DP[es[i][1]]<<'\n';
    //     cout<<-1<<'\n';
    //     return;
    // }
    // 일단 가능은 함. 이제 자릿수별로 optimal을 찾는다.

    fill(DP,DP+n,0);
    ll res=0;
    rng(k,0,30){
        ll pos=(1LL<<k);
        fill(visited,visited+n,0);

        rng(i,0,n-1){
            cnt=0;
            tar.clear();
            if(!visited[i]){
                ll temp=DFS2(i,pos,0);
                res+=pos*min(temp,cnt-temp);
                if(temp<=cnt-temp){
                    for(auto tt: tar){
                        DP[tt.fi]+=pos*(tt.se);
                    }
                }
                else{
                    for(auto tt: tar){
                        DP[tt.fi]+=pos*(1-tt.se);
                    }
                }
            }
        }
    }

    rng(i,0,m-1) if((DP[es[i][0]]^DP[es[i][1]])!=es[i][2]){
        // cout<<"WHERE? "<<es[i][0]<<' '<<es[i][1]<<' '<<es[i][2]<<' '<<DP[es[i][0]]<<' '<<DP[es[i][1]]<<'\n';
        cout<<-1<<'\n';
        return;
    }

    rng(i,0,n-1) cout<<DP[i]<<' ';
    
    
    // cout<<'\n';
    // cout<<res<<'\n';
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

