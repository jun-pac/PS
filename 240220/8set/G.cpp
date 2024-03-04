
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

ll st[N], inc[N];
ll mod;
vc<int> edges[N]; // {idx, dist}
ll min_dist[N];

void dijkstra(int s){
    priority_queue<pair<long long,long long>> pq;
    fill(min_dist,min_dist+N,-1);
	pq.push({0,s});
    while(!pq.empty()){
		long long dist=-pq.top().first, idx=pq.top().second;
		pq.pop();
		if(min_dist[idx]!=-1) continue;
		min_dist[idx]=dist;
		for(int i=0; i<edges[idx].size(); i++){
			ll next=edges[idx][i];
            ll n_dist=dist; 
            // ���⿡�� dist�� �� ó���ϸ� �Ǵ� �� �ƴѰ�?
            // dist�̻��� ���� t��, st[idx]-st[next]===t*(inc[next]-inc[idx]) mod
            // st[idx]-st[next]-dist*(inc[next]-inc[idx]) === (t-dist) * (inc[next]-inc[idx]) mod
            // �̷��� �ؼ� ���� t+1�� ������ �Ǵ±���
            // �ٵ� mod�� �Ҽ��� �͵� �ƴ϶� �̰� �׿������߿� �ּҸ� ��� ������..?
            // �׷� ����� ������ �ֱ���
            // 
			if(min_dist[next]==-1) pq.push({-n_dist,next});
		}
	}
}

void Solve(){
    int n,m; // h is total height
    cin>>n>>m>>mod;
    rng(i,0,n-1) cin>>st[i]; // height at start
    rng(i,0,m-1){
        int a,b;
        cin>>a>>b;
        a--, b--;
        edges[a].pb(b);
        edges[b].pb(a);
    }
    cout<<
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

