// 
//./B<test

#include <bits/stdc++.h>
#define endl '\n'
#define cediv(a,b) ((a)%(b)==0?((a)/(b)):((a)/(b))+1)
#define fi first
#define se second
#define pb push_back

using namespace std;

typedef long long ll;


#define N 5050
vector<pair<ll,pair<ll,ll>>> ori_edges[1000]; // {angle, {next, t}}
vector<pair<ll,ll>> edges[N]; // num, length
const ll NUM=1000;
ll min_dist[N];
ll st[5];
#define INF 100000000

void dijkstra(ll s, bool start_zero=true){
    priority_queue<pair<ll,ll>> pq;
    fill(min_dist,min_dist+N,INF);
	if(start_zero) for(ll i=0; i<5; i++) pq.push({0,s*5+i});
    else pq.push({0,s});
    while(!pq.empty()){
		ll dist=-pq.top().first, idx=pq.top().second;
		pq.pop();
		if(min_dist[idx]!=INF) continue;
		min_dist[idx]=dist;
		for(ll i=0; i<edges[idx].size(); i++){
			ll next=edges[idx][i].first, n_dist=dist+edges[idx][i].second;
			if(min_dist[next]==INF) pq.push({-n_dist,next});
		}
	}
}



int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll n,d,al,ar;
    ll m, next, t, angle; // t°¡ distance
    cin>>n>>d>>al>>ar;
    d--;
    for(ll i=0; i<n; i++){
        cin>>m;
        for(ll j=0; j<m; j++){
            cin>>next>>t>>angle;
            next--;
            ori_edges[i].push_back({angle,{next,t}});
        }
        sort(ori_edges[i].begin(),ori_edges[i].end());
    }
    
    for(ll i=0; i<n; i++){
        if(i==0){
            for(ll j=0; j<ori_edges[i].size(); j++){
                auto cur=ori_edges[i][j];
                ll next=cur.se.fi;
                ll kout;
                for(kout=0; kout<ori_edges[next].size(); kout++){
                    if(ori_edges[next][kout].se.fi==i) break;
                }
                for(ll kin=0; kin<ori_edges[i].size(); kin++){
                    edges[i*5+kin].push_back({next*5+kout,cur.se.se});
                }     
            }
            continue;
        }
        for(ll j=0; j<ori_edges[i].size(); j++){
            auto cur=ori_edges[i][j];
            ll next=cur.se.fi;
            ll kout;
            for(kout=0; kout<ori_edges[next].size(); kout++){
                if(ori_edges[next][kout].se.fi==i) break;
            }
            for(ll kin=0; kin<ori_edges[i].size(); kin++){
                ll in_angle=ori_edges[i][kin].fi+180;
                ll out_angle=cur.fi;
                if((out_angle-in_angle+1080)%360<=180 && (out_angle-in_angle+1080)%360<=al){
                    edges[i*5+kin].push_back({next*5+kout,cur.se.se});
                }
                else if((in_angle-out_angle+1080)%360<=180 && (in_angle-out_angle+1080)%360<=ar){
                    edges[i*5+kin].push_back({next*5+kout,cur.se.se});
                }
            }     
        }
    }

    for(ll i=0; i<5*n; i++){
        for(auto e : edges[i]){
            //cout<<i<<' '<<e.fi<<' '<<e.se<<endl;
        }
    }

    ll ans=INF;
    dijkstra(0,true);
    for(ll i=0; i<5; i++) st[i]=min_dist[5*d+i];
    for(ll i=0; i<5; i++){
        dijkstra(5*d+i,false);
        ll min_ts=INF;
        for(ll j=0; j<5; j++) min_ts=min(min_ts,min_dist[j]);
        ans=min(ans,min_ts+st[i]);
    }
    
    if(ans>=INF) cout<<"impossible"<<endl;
    else cout<<ans<<endl;
    return 0;
}