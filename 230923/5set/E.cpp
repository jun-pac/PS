// 
//./E<test

#include <bits/stdc++.h>
#define endl '\n'
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
vector<int> edges[200020];
int in_deg[200020], datas[200020];
pair<ll,ll> start[200020];
int visited[200020];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        while(!pq.empty()) pq.pop();
        
        ll n,m,k;
        cin>>n>>m>>k;
        for(int i=0; i<n; i++) edges[i].clear();
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
        }
        fill(min_dist, min_dist+n, INF);
        for(int i=0; i<n; i++){
            if(in_deg[i]==0){
                min_dist[i]=datas[i];
                pq.push({-datas[i],i});
                start[scnt++]={datas[i],i};
            }
        }
        sort(start,start+scnt);

        ll res=INF;
        ll mx=0;
        //ll ft=-1;
        ll st=start[0].fi;

        fill(visited,visited+n,-1);
        while(!pq.empty()){
            auto cur=pq.top();
            pq.pop();
            if(visited[cur.se]==0) continue;
            visited[cur.se]=0;
            //if(min_dist[cur.se]<-cur.fi) continue;
            min_dist[cur.se]=-cur.fi;
            mx=max(mx,-cur.fi);
            for(auto next : edges[cur.se]){
                if(visited[next]!=0){
                    ll dist=(datas[next]<datas[cur.se]?k:0)+datas[next]-datas[cur.se];
                    pq.push({-(dist-cur.fi),next});
                }
            }
        }
        res=min(res,mx-st);

        for(int i=1; i<scnt; i++){
            st=start[i].fi;
            if(i!=0) pq.push({-(start[i-1].fi+k),start[i-1].se});
            while(!pq.empty()){
                auto cur=pq.top();
                pq.pop();
                if(visited[i]==i) continue;
                visited[i]=i;
                if(min_dist[cur.se]>=-cur.fi) continue;

                min_dist[cur.se]=-cur.fi;
                mx=max(mx,-cur.fi);
                for(auto next : edges[cur.se]){
                    if(visited[next]!=i){
                        ll dist=(datas[next]<datas[cur.se]?k:0)+datas[next]-datas[cur.se];
                        pq.push({-(dist-cur.fi),next});
                    }
                }
            }
            res=min(res,mx-st);
        }
            
        cout<<res<<endl;
    }
    return 0;
}