
// #include <bits/stdc++.h>
// using namespace std;
// #define fi first
// #define se second
// #define cediv(a,b) ((a)%(b)==0?((a)/(b)):((a)/(b))+1)
// #define rng(i,a,b) for(int i=int(a);i<=int(b);i++)
// #define rep(i,b) rng(i,0,b-1)  
// #define gnr(i,b,a) for(int i=int(b);i>=int(a);i--)
// #define per(i,b) gnr(i,b-1,0)
// #define pb push_back
// #define eb emplace_back
// #define bg begin()
// #define ed end()
// #define all(x) x.bg,x.ed
// #define si(x) int(x.size())
// template<class t> using vc=vector<t>;
// template<class t> using vvc=vc<vc<t>>;
// typedef long long ll;
// using pii=pair<int,int>;
// using vi=vc<int>;
// using uint=unsigned;
// using ull=unsigned long long;
// using pil=pair<int,ll>;
// using pli=pair<ll,int>;
// using pll=pair<ll,ll>;
// using t3=tuple<int,int,int>;

// #define N 300030
// #define MOD 998244353
// #define INF 1000000007 
// random_device rd; 
// mt19937 gen(rd());
// uniform_int_distribution<> dist(0, INF); // random integer from [0, INF] // dist(gen)

// pii datas[N];
// vc<pii> byrow[N], bycol[N];
// int n,m,k;
// map<pii,int> idxp;
// long long min_dist[N];

// void dijkstra(int s){
//     priority_queue<pair<long long,long long>> pq;
//     fill(min_dist,min_dist+10001,-1);
// 	pq.push({0,s});
//     while(!pq.empty()){
//         int i=datas[s-1].fi, j=datas[s-1].se;

// 		long long dist=-pq.top().first, idx=pq.top().second;
// 		pq.pop();
// 		if(min_dist[idx]!=-1) continue;
// 		min_dist[idx]=dist;
//         // neighbor check
//         if(idxp[{i,j+1}]!=0) 
// 		for(int i=0; i<edges[idx].size(); i++){
// 			long long next=edges[idx][i].first, n_dist=dist+edges[idx][i].second;
// 			if(min_dist[next]==-1) pq.push({-n_dist,next});
// 		}
// 	}
// }



// void Solve(){
//     cin>>n>>m>>k;
//     rng(i,0,k-1){
//         int r,c;
//         cin>>r>>c;
//         r--, c--;
//         byrow[r].pb({c,i});
//         bycol[c].pb({r,i});
//         idxp[{r,c}]=i+1;
//     }
//     idxp[{n-1,m-1}]=k+1;

//     dijkstra(1);
    
// }

// int main(){
//     ios_base::sync_with_stdio(false); cin.tie(NULL);
//     int t=1;
//     cin>>t;
//     while(t--){
//         Solve();
//     }
//     return 0;
// }

