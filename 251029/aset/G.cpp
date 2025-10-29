#include <bits/stdc++.h>
using namespace std;

#define rng(i,a,b) for(int i=int(a); i<=int(b); i++)
#define fi first
#define se second
#define N 20000
#define INF 1000000007
#define pb push_back

typedef long long ll;
template<class t> using vc = vector<t>; 
using pii = pair<int,int>;
using pll = pair<ll,ll>;

pii idx2pos[N];
map<pii, int> pos2idx;
vc<pii> rows[N], cols[N];
bool rowv[N], colv[N];
int dist[N];
pii dir[4];
priority_queue<pair<int,pii>> q;

void fillrow(int idx, int d){
        // cout<<"ro "<<idx<<' '<<d<<" \n";

    for(pii temp: rows[idx]){
        int ti=temp.se;
        pii pos=idx2pos[ti];
        if(dist[ti]>d){
            dist[ti]=d;
            q.push({-d,pos});
        }
    }
    rowv[idx]=1;
}

void fillcol(int idx, int d){
    // cout<<"co "<<idx<<' '<<d<<" \n";
    for(pii temp: cols[idx]){
        int ti=temp.se;
        pii pos=idx2pos[ti];
        if(dist[ti]>d){
            dist[ti]=d;
            q.push({-d,pos});
        }
    }
    colv[idx]=1;
}

void Solve(){
    int n,m,k;
    cin>>n>>m>>k;
    rng(i,0,k-1){
        int a,b;
        cin>>a>>b;
        a--, b--;
        pos2idx[{a,b}]=i+1;
        idx2pos[i+1]={a,b};

        rows[a].pb({b,i+1});
        cols[b].pb({a,i+1});
    }

    fill(dist,dist+k+1,INF);
    fill(rowv,rowv+n,0);
    fill(colv,colv+m,0);
    q.push({0,{0,0}});    
    dist[1]=0;

    while(!q.empty()){
        pii pos=q.top().se;
        int curd=-q.top().fi;
        int curidx=pos2idx[pos];
        // cout<<"pos "<<pos.fi<<' '<<pos.se<<' '<<curidx<<' '<<dist[curidx]<<'\n';
        assert(curidx<N);
        q.pop();
        if(curd>dist[curidx]) continue;
        
        rng(t,0,3){
            int ni=pos.fi+dir[t].fi;
            int nj=pos.se+dir[t].se;
            int idx=pos2idx[{ni,nj}];
            if(idx!=0 && dist[idx]>dist[curidx]){
                dist[idx]=dist[curidx];
                q.push({-dist[idx],{ni,nj}});
            }
        }
        rng(i,-2,2){
            if(pos.fi+i>=0 && pos.fi+i<n && !rowv[pos.fi+i]) fillrow(pos.fi+i,dist[curidx]+1);
        }
        rng(j,-2,2){
            if(pos.se+j>=0 && pos.se+j<m && !colv[pos.se+j]) fillcol(pos.se+j,dist[curidx]+1);
        }
    }
    
    pii tar={n-1,m-1};
    int taridx=pos2idx[tar];
    if(taridx!=0){
        if(dist[taridx]==INF) cout<<-1<<'\n';
        else cout<<dist[taridx]<<'\n';
    }
    else{
        int mn=INF;
        for(pii temp: rows[n-1]){
            mn=min(mn,dist[temp.se]+1);
        }
        if(n-2>=0){
            for(pii temp: rows[n-2]){
                mn=min(mn,dist[temp.se]+1);
            }
        }
        for(pii temp: cols[m-1]){
            mn=min(mn,dist[temp.se]+1);
        }
        if(m-2>=0){
            for(pii temp: cols[m-2]){
                mn=min(mn,dist[temp.se]+1);
            }
        }
        cout<<(mn==INF?-1:mn)<<'\n';
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t=1;
    // cin>>t;
    dir[0]={0,-1};
    dir[1]={0,1};
    dir[2]={1,0};
    dir[3]={-1,0};

    while(t--) Solve();
}

// cout<<fixed;
// cout.precision(12);
