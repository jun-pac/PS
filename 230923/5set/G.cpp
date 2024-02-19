// 
//./E<test

#include <bits/stdc++.h>
//#define endl '\n'
#define cediv(a,b) ((a)%(b)==0?((a)/(b)):((a)/(b))+1)
#define fi first
#define se second
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;

template<typename T>
inline T umax(T &u, T v){return u = max(u, v);}
template<typename T>
inline T umin(T &u, T v){return u = min(u, v);}

#define INF 10000000000000007LL

priority_queue<pair<ll,ll>> pq;
ll min_dist[200020];
vector<int> edges[200020], r_edges[200020];
int in_deg[200020], datas[200020];
pair<ll,ll> start[200020];
bool visited[200020];
int cnt;
int order[200020], out[200020];

void DFS(int idx){
    if(visited[idx]) return;
    visited[idx]=true;
    for(auto next : edges[idx]){
        if(!visited[next]) DFS(next);
    }
    order[cnt++]=idx;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        while(!pq.empty()) pq.pop();
        
        ll n,m,k;
        cin>>n>>m>>k;
        for(int i=0; i<n; i++) edges[i].clear();
        for(int i=0; i<n; i++) r_edges[i].clear();
        int a,b;
        fill(in_deg,in_deg+n,0);
        for(int i=0; i<n; i++){
            cin>>datas[i];
        }
        int scnt=0;
        for(int i=0; i<m; i++){
            cin>>a>>b;
            a--, b--;
            in_deg[b]++;
            edges[a].push_back(b);
            r_edges[b].push_back(a);
        }
        fill(visited,visited+n,false);
        cnt=0;
        for(int i=0; i<n; i++){
            if(!visited[i]) DFS(i);
        }

        
        reverse(order,order+n);
        for(int i=0; i<n; i++) out[order[i]]=i;

        fill(min_dist,min_dist+n,INF);
        for(int i=0; i<n; i++){
            if(in_deg[i]==0){
                min_dist[i]=datas[i];
                start[scnt++]={datas[i],i};
            }
        }
        sort(start,start+scnt);
        
        ll mx=0,st=start[0].fi;
        ll res=INF;
        for(int i=0; i<n; i++){
            int idx=order[i];
            if(min_dist[idx]==INF){
                //cout<<"d ? "<<endl;
                ll temp_mx=0;
                for(auto prev : r_edges[idx]){
                    //cout<<idx<<' '<<prev<<' '<<min_dist[prev]<<endl;
                    temp_mx=max(temp_mx,min_dist[prev]+(datas[idx]<datas[prev]?k:0)+datas[idx]-datas[prev]);
                }
                min_dist[idx]=temp_mx;
            }
            //cout<<"dnei "<<min_dist[idx]<<endl;
            mx=max(min_dist[idx],mx);
        }
        res=mx-st;
        
        for(int i=1; i<scnt; i++){
            st=start[i].fi;
            pq.push({-out[start[i-1].se],start[i-1].fi+k});
            //cout<<"i "<<i<<endl;
            while(!pq.empty()){
                auto cur=pq.top();
                pq.pop();
                int idx=order[-cur.fi];
                //cout<<"cur idx "<<idx<<endl;
                if(min_dist[idx]>=cur.se) continue;
                min_dist[idx]=cur.se;
                mx=max(mx,cur.se);
                for(auto next : edges[idx]){
                    // if(out[next]>=cur.fi){
                    //     cout<<next<<' '<<idx<<' '<<out[next]<<' '<<cur.fi<<"fuck"<<endl;
                    //     return 0;
                    // }
                    pq.push({-out[next], min_dist[idx]+(datas[next]<datas[idx]?k:0)+datas[next]-datas[idx]});
                }
            }
            //cout<<"test "<<i<<' '<<mx<<' '<<st<<endl;
            res=min(res,mx-st);
        }
        
    
        cout<<res<<endl;
    }
    return 0;
}