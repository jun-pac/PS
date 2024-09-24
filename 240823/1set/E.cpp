
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

vc<int> edges[N];
pii es[N];
int dist[N];

void Solve(){
    int n,m;
    cin>>n>>m;
    rng(i,0,n-1) edges[i].clear();
    rng(i,0,m-1){
        int a,b;
        cin>>a>>b;
        a--, b--;
        edges[a].pb(b);
        edges[b].pb(a);
        es[i]={a,b};
    }
    fill(dist,dist+n,-1);
    queue<pii> q;
    q.push({0,0});
    while(!q.empty()){
        int idx=q.front().fi;
        int d=q.front().se;
        q.pop();
        if(dist[idx]!=-1) continue;
        dist[idx]=d;
        for(auto next : edges[idx]){
            if(dist[next]==-1) q.push({next,d+1});
        }
    } 
    bool flag=1;
    rng(i,0,m-1){
        if(dist[es[i].fi]%2==dist[es[i].se]%2) flag=0;
    }

    queue<int> on, en;
    rng(i,0,n-1){
        if(dist[i]%2==0) en.push(i);
        else on.push(i);
    }
    if(flag){
        // B∞° ¿Ã±Ë
        cout<<"Bob"<<endl;
        rng(i,0,n-1){
            int c1, c2;
            cin>>c1>>c2;
            if(c1>c2) swap(c1,c2);
            if(c2==3){
                if(c1==1){
                    if(on.size()==0){
                        int idx=en.front();
                        en.pop();
                        cout<<idx+1<<' '<<c2<<endl;
                    }
                    else{
                        int idx=on.front();
                        on.pop();
                        cout<<idx+1<<' '<<c1<<endl;
                    }
                }
                else{
                    if(en.size()==0){
                        int idx=on.front();
                        on.pop();
                        cout<<idx+1<<' '<<c2<<endl;
                    }
                    else{
                        int idx=en.front();
                        en.pop();
                        cout<<idx+1<<' '<<c1<<endl;
                    }
                }
            }
            else if(on.size()==0){
                int idx=en.front();
                en.pop();
                cout<<idx+1<<' '<<c2<<endl;
            }
            else{
                int idx=on.front();
                on.pop();
                cout<<idx+1<<' '<<c1<<endl;
            }
        }
    }
    else{
        cout<<"Alice"<<endl;
        rng(i,0,n-1){
            cout<<1<<' '<<2<<endl;
            int r1, r2;
            cin>>r1>>r2;
        }
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

