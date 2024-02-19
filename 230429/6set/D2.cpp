// 
//./D<test

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


int ans[100010];
vector<int> edges[100010];
int mx_dist[100010];
int mx_idx, mx_depth;

void DFS(int idx, int p=-1, int d=0){
    mx_dist[idx]=max(mx_dist[idx],d);
    if(mx_depth<d){
        mx_idx=idx;
        mx_depth=d;
    }
    for(auto next : edges[idx]){
        if(next!=p) DFS(next,idx,d+1);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin>>n;
    for(int i=0; i<n; i++) edges[i].clear();
    for(int i=0; i<n-1; i++){
        int a,b;
        cin>>a>>b;
        a--, b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    
    fill(mx_dist, mx_dist+n, 0);
    mx_depth=-1;
    DFS(0,-1,0);
    mx_depth=-1;
    DFS(mx_idx,-1,0);
    DFS(mx_idx,-1,0);
    
    sort(mx_dist,mx_dist+n);
    reverse(mx_dist,mx_dist+n);
    int cnt=0;
    for(int i=n; i>0; i--){
        while(cnt<n && mx_dist[cnt]>=i) cnt++;
        ans[i-1]=n-cnt+1;
    }
    for(int i=0; i<n; i++) cout<<min(ans[i],n)<<' ';
    cout<<endl;
    return 0;
}