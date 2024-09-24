
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
__attribute__((optimize("Ofast,unroll-loops"),target("avx,avx2,fma")))

int datas[N]; // Company number    
vc<pii> edges[N];
priority_queue<pair<ll,pii>> pq;
int parent[N];
set<pll> st[N]; // small to large DP;
ll ans[N]; 

int find(int idx){
	if(idx==parent[idx]) return idx;
	return parent[idx]=find(parent[idx]);
}
void c_union(int a, int b, ll val){
	a=find(a), b=find(b);
	if(st[a].size()<st[b].size()) swap(a,b);
    parent[b]=a;
    for(auto temp=st[b].begin(); temp!=st[b].end(); temp=next(temp)){
        auto stemp=st[a].lower_bound({temp->fi,-1});
        if(stemp!=st[a].end() && stemp->fi==temp->fi){
            ans[temp->fi]+=(ll)val*(temp->se)*(stemp->se);
            pll aa={stemp->fi, temp->se+stemp->se};
            st[a].erase(stemp);
            st[a].insert(aa);
        }
        else{
            st[a].insert({temp->fi,temp->se});
        }

    }
}

void Solve(){
    int n,k,m;
    cin>>n>>k>>m;
    rng(i,0,n-1){
        int x;
        cin>>x;
        datas[i]=x-1;
    }
    fill(ans,ans+k,0);
    rng(i,0,m-1){
        int a,b,w;
        cin>>a>>b>>w; // w is capa of edge
        a--, b--;
        edges[a].pb({b,w});
        edges[b].pb({a,w});
        pq.push({w,{a,b}});
    }
    rng(i,0,n-1) parent[i]=i;
    rng(i,0,n-1){
        st[i].insert({datas[i],1});
    }
    while(!pq.empty()){
        auto temp=pq.top();
        pq.pop();
        int a=temp.se.fi;
        int b=temp.se.se;
        if(find(a)==find(b)) continue;
        //cout<<"visi "<<a<<' '<<b<<' '<<-temp.fi<<'\n';
        c_union(a,b,temp.fi); // ans를 여기서 업데이트 해주지
        //cout<<"ans "<<ans[0]<<' '<<ans[1]<<'\n';
    }
    rng(i,0,k-1) cout<<ans[i]<<'\n';
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

