
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define cediv(a,b) ((a)%(b)==0?((a)/(b)):((a)/(b))+1)
#define rng(i,a,b) for(int i=int(a);i<=int(b);i++)
#define pb push_back
template<class t> using vc=vector<t>;
typedef long long ll;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

#define N 100010
#define MOD 998244353
#define INF 1000000007 
random_device rd; 
mt19937 gen(rd());
uniform_int_distribution<> dist(0, INF); 

ll datas[N]; // �߿䵵
vc<pll> edges[N]; // {next, level}
ll sum;
ll n;
bool visited[N];

ll DFS(int idx, ll lev){
    visited[idx]=1;
    ll res=datas[idx];
    for(auto temp : edges[idx]){
        if(!visited[temp.fi] && temp.se<=lev) res+=DFS(temp.fi,lev);
    }
    return res;
}

ll mx_comp(ll lev){
    ll mx=0;
    fill(visited,visited+n,0);
    rng(i,0,n-1){
        if(!visited[i]) mx=max(mx,DFS(i,lev));
    }
    return mx;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll m,d;
    cin>>n>>m>>d;
    rng(i,0,n-1) edges[i].clear();
    rng(i,0,n-1) cin>>datas[i];
    sum=0;
    rng(i,0,n-1) sum+=datas[i];
    rng(i,0,m-1){
        ll a,b,c;
        cin>>a>>b>>c;
        a--, b--;
        edges[a].pb({b,c});
        edges[b].pb({a,c});
    }
    int q;
    cin>>q;
    rng(i,0,q-1){
        ll aa,a,b,c;
        cin>>aa;
        if(aa==1){
            cin>>a>>b>>c;
            a--, b--;
            edges[a].pb({b,c});
            edges[b].pb({a,c});
        }
        else if(aa==2){
            cin>>b>>c;
            b--;
            sum+=c-datas[b];
            datas[b]=c;
        }
        else if(aa==3){
            cin>>c;
            d=c;
        }
        else{
            if(sum<d){
                cout<<-2<<'\n';
                continue;
            }
            ll l=0, r=100000000;
            while(l<r){
                ll mid=(l+r)>>1;
                if(mx_comp(mid)>=d) r=mid;
                else l=mid+1;
            }
            if(r==100000000) cout<<-2<<'\n';
            else if(l==0) cout<<-1<<'\n';
            else cout<<l<<'\n';
        }
    }
    return 0;
}

