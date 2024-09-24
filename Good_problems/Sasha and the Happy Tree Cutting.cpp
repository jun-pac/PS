
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

#define N 100030
#define MOD 998244353
#define INF 1000000007 

vc<int> edges[N];
int parent[N], depth[N];
vc<int> r_edges[N];
vc<int> groups, cgroups; 
int DP[(1<<20)];

void DFS1(int idx, int p, int d){
    parent[idx]=p;
    depth[idx]=d;
    for(int next : edges[idx]){
        if(next!=p) DFS1(next,idx,d+1);
    }
}

inline int bitnums(int num){
    int res=0;
    while(num!=0){
        if(num%2==1) res++;
        num>>=1;
    }
    return res;
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
    DFS1(0,-1,0);
    // rng(i,0,n-1) cout<<"p "<<i+1<<' '<<parent[i]<<endl;
    // rng(i,0,n-1) cout<<"d "<<i+1<<' '<<depth[i]<<endl;
    int q;
    cin>>q;
    rng(i,0,n-1) r_edges[i].clear(); 
    rng(i,0,q-1){
        int a,b;
        cin>>a>>b;
        a--, b--;
        while(a!=b){
            if(depth[a]>depth[b]){
                //cout<<"in "<<a<<' '<<i<<'\n';
                r_edges[a].pb(i);
                a=parent[a];
                assert(a!=-1);
            }
            else{
                //cout<<"in "<<b<<' '<<i<<'\n';
                r_edges[b].pb(i);
                b=parent[b];
                assert(b!=-1);
            }
        }
    }

    // 답은 최대 20개
    rng(i,0,(1<<q)-1){
        DP[i]=bitnums(i);
    }
    groups.clear();
    cgroups.clear();
    rng(i,0,n-1){
        int temp=0;
        for(int j=0; j<(int)r_edges[i].size(); j++){
            //cout<<"rredge "<<i+1<<' '<<r_edges[i][j]+1<<'\n';
            temp+=(1<<r_edges[i][j]); 
        }
        //cout<<"temp "<<i<<' '<<temp<<'\n';
        if(temp!=0) groups.pb(temp);
    }
    // Anyway the most important thing in this problem is, there are only O(k) number of different temp
    // <=> If we compress the tree based on different coverage, than number of nodes are bound on O(k)
    sort(all(groups));
    rng(i,0,(int)groups.size()-1) if(i==0 || groups[i]!=groups[i-1]) cgroups.pb(groups[i]);
    int sz=cgroups.size();
    assert(sz<=3*q);
    //rng(i,0,sz-1) cout<<"group "<<cgroups[i]<<'\n';
    rng(i,0,(1<<q)-1){
        rng(j,0,sz-1){
            int temp=(cgroups[j]&i);
            DP[i]=min(DP[i],DP[i-temp]+1);
        }
    }
    cout<<DP[(1<<q)-1]<<'\n';
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

