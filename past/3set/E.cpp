// 
//./E<test.txt

#include <bits/stdc++.h>
#define endl '\n'
#define cediv(a,b) ((a)%(b)==0?((a)/(b)):((a)/(b))+1)
#define fi first
#define se second
#define pb push_back
#define INF 10000000
using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;

template<typename T>
inline T umax(T &u, T v){return u = max(u, v);}
template<typename T>
inline T umin(T &u, T v){return u = min(u, v);}

vector<int> edges[200000];
vector<int> r_edges[200000];
int dist[200000]; // 처음에는 INF로 채워짐
bool inQ[200000];
queue<int> q;
vector<int> s_edges[200000];
int mn_hord[200000];

inline int get_dist(int idx, int n_val){
    int nn=edges[idx].size();
    if(n_val<mn_hord[idx]){
        mn_hord[idx]=n_val;
        return n_val+nn;
    }
    
    vector<int> temp(nn);
    for(int i=0; i<nn; i++){
        temp[i]=dist[edges[idx][i]]+1;
    }
    sort(temp.begin(),temp.end());
    int mn=INF;
    for(int i=0; i<nn; i++){
        if(mn>temp[i]+nn-i-1){
            mn=temp[i]+nn-i-1;
            mn_hord[idx]=temp[i]-i;
        }
    }
    return mn;
    
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,m,a,b;
    cin>>n>>m;
    for(int i=0;i<n;i++) edges[i].clear();
    for(int i=0;i<n;i++) r_edges[i].clear();
    for(int i=0;i<n;i++) s_edges[i].clear();
    for(int i=0; i<m; i++){
        cin>>a>>b;
        a--; b--;
        edges[a].push_back(b);
        r_edges[b].push_back(a);
        s_edges[a].push_back(INF);
    }

    fill(dist,dist+n,INF);
    while(!q.empty()) q.pop();
    fill(inQ,inQ+n,false);
    fill(mn_hord,mn_hord+n,INF);
    q.push(n-1);
    inQ[n-1]=true;
    dist[n-1]=0;
    while(!q.empty()){
        int idx=q.front();
        q.pop();
        inQ[idx]=false;
        for(int i=0; i<r_edges[idx].size(); i++){
            int next=r_edges[idx][i];
            int tt=get_dist(next,dist[idx]);
            if(tt<dist[next]){
                dist[next]=tt;
                if(!inQ[next]){
                    inQ[next]=true;
                    q.push(next);
                }
            }
        }
    }
    cout<<dist[0]<<endl;
    return 0;
}