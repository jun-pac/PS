
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

vc<int> edges[N]; 
vc<int> subset[20];
bool visited[20];
bool last[20];
int state[20];

void DFS(int st, int idx){
    visited[idx]=1;
    subset[st].pb(idx);
    for(int next : edges[idx]){
        if(!visited[next]) DFS(st, next);
    }
}

int n;
bool check(){
    // cout<<"check"<<endl;
    // rng(i,0,n-1) cout<<last[i]<<' '; cout<<endl;
    bool res=1;
    fill(state,state+n,0);
    fill(visited,visited+n,0);
    rng(i,0,n-1){
        //cout<<"idx "<<i<<' '<<last[i]<<' '<<state[i]<<'\n';
        if(last[i]!=state[i]%2){
            if(visited[i]){
                return false;
            }
            for(auto next : subset[i]){
                //cout<<"visit "<<i<<' '<<next<<endl;
                if(next<i && !visited[next]){
                    return false;
                }
                else if(next >= i){
                    if(visited[next]) continue;
                    visited[next]=1;
                    int k=1;
                    while((next+1)*k<=n){
                        state[(next+1)*k-1]++;
                        k++;
                    }
                }
            }
        }
    }

    // rng(i,0,n-1) cout<<state[i]%2<<' '; cout<<'\n';
    int cnt=0;
    rng(i,0,n-1) if(visited[i]) cnt++;
    cout<<cnt<<'\n';
    rng(i,0,n-1) if(visited[i]) cout<<i+1<<' ';
    cout<<'\n';
    // fill(state,state+n,0);
    // rng(i,0,n-1){
    //     if(visited[i]){
    //         int k=1;
    //         while(k*(i+1)<=n){
    //             state[k*(i+1)-1]++;
    //             k++;
    //         }
    //     }
    // }
    //rng(i,0,n-1) cout<<state[i]%2<<' '; cout<<'\n';
    return true;
}

void Solve(){
    int m,a,b;
    cin>>n>>m;
    rng(i,0,n-1) edges[i].clear();
    rng(i,0,m-1){
        cin>>a>>b;
        a--, b--;
        edges[a].pb(b);
    }
    if(n>=20){
        cout<<n<<'\n';
        rng(i,0,n-1) cout<<i+1<<' '; cout<<"\n";
        return;
    }
    rng(i,0,n-1) subset[i].clear();
    rng(i,0,n-1){
        fill(visited,visited+n,0);
        DFS(i,i);
        sort(all(subset[i]));
        //cout<<i<<' '<<" subset : ";
        //rng(j,0,(int)subset[i].size()-1) cout<<subset[i][j]<<' '; cout<<'\n';
    }
    fill(last,last+n,0);
    if(n>=15){
        rng(i,0,n-1){
            last[i]=1;
            rng(j,i+1,n-1){
                last[j]=1;
                rng(k,j+1,n-1){
                    last[k]=1;
                    if(check()){
                        return;
                    }
                    last[k]=0;
                }
                last[j]=0;
            }
            last[i]=0;
        }
    }
    if(n>=10){
        rng(i,0,n-1){
            last[i]=1;
            rng(j,i+1,n-1){
                last[j]=1;
                if(check()){
                    return;
                }
                last[j]=0;
            }
            last[i]=0;
        }
    }
    if(n>=5){
        rng(i,0,n-1){
            last[i]=1;
            if(check()){
                return;
            }
            last[i]=0;
        }
    }
    cout<<-1<<'\n';
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

