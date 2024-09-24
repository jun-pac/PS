
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second

#define N 30030

bool visited[N];
vector<pair<int,int>> edges[N]; // {next, dist}

void network_communication_route(int n, int m, vector<vector<int>> raw_edges) {
    // Building adjacency list
    for(int i=0; i<n; i++) edges[i].clear();
    for(int i=0; i<m; i++){
        edges[raw_edges[i][0]].push_back({raw_edges[i][1],raw_edges[i][2]});
        edges[raw_edges[i][1]].push_back({raw_edges[i][0],raw_edges[i][2]});
    }

    // MST algorithm
    int mn=0;
    priority_queue<pair<int,pair<int,int>>> pq; // {-dist, {idx,next}}
    fill(visited,visited+n,0);
    pq.push({0,{-1,0}});
    vector<pair<int,int>> ans;
    while(!pq.empty()){
        auto temp=pq.top();
        int pred=temp.se.fi;
        int cur=temp.se.se;
        int d=-temp.fi;
        pq.pop();
        if(visited[cur]) continue;
        visited[cur]=1;
        mn+=d;
        if(pred!=-1) ans.push_back({pred,cur});
        for(auto ed : edges[cur]){
            if(!visited[ed.fi]) pq.push({-ed.se,{cur,ed.fi}});
        }
    }
    cout<<mn<<'\n';
    for(int i=0; i<n-1; i++) cout<<ans[i].fi<<' '<<ans[i].se<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int raw_edges[100][3];
    int n,m;
    cin>>n>>m;
    int a,b;
    cin>>a>>b;
    for(int i=0; i<m; i++){
        cin>>raw_edges[i][0]>>raw_edges[i][1]>>raw_edges[i][2];
    }

    for(int i=0; i<n; i++) edges[i].clear();
    for(int i=0; i<m; i++){
        edges[raw_edges[i][0]].push_back({raw_edges[i][1],raw_edges[i][2]});
        edges[raw_edges[i][1]].push_back({raw_edges[i][0],raw_edges[i][2]});
    }

    // MST algorithm
    int mn=0;
    priority_queue<pair<int,pair<int,int>>> pq; // {-dist, {idx,next}}
    fill(visited,visited+n,0);
    pq.push({0,{-1,0}});
    vector<pair<int,int>> ans;
    while(!pq.empty()){
        auto temp=pq.top();
        int pred=temp.se.fi;
        int cur=temp.se.se;
        int d=-temp.fi;
        pq.pop();
        if(visited[cur]) continue;
        visited[cur]=1;
        mn+=d;
        if(pred!=-1) ans.push_back({pred,cur});
        for(auto ed : edges[cur]){
            if(!visited[ed.fi]) pq.push({-ed.se,{cur,ed.fi}});
        }
    }
    cout<<mn<<'\n';
    for(int i=0; i<n-1; i++) cout<<ans[i].fi<<' '<<ans[i].se<<'\n';
    return 0;
}

