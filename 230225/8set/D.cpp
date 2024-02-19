// 
//./D<test

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

#define INF 10000000000007LL

ll edges[800][800]; // i -> j로 연결하는 간선, 각 값은 edges[i][j]는 i->j의 weight
ll dist[800][800]; // DP[i][j]는 i에서 j로 도달가능한 최소의 거리
ll visited[800];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll n,m,a,b,c;
    cin>>n>>m;
    for(int i=0; i<n; i++) fill(edges[i],edges[i]+n,INF);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>a>>b>>c;
            edges[a][b]=c;
        }
    }      
    // 모든 점들이 ring을 이루고 있는 상황으로 문제 변환 가능. idx와 idx+1을 weight 1인 간선으로 연결 
    //for(int i=0; i<n; i++) edges[i][(i+1)%n]=min(edges[i][(i+1)%n],1);
    // 처음에는 이 간선들을 이용할 수 없으므로 따로 처리해준다.

    // (V^2 + E)V dijkstra
    for(int i=0; i<n; i++) fill(dist[i],dist[i]+n,INF);
    for(int i=0; i<n; i++){
        // Starting from i
        fill(visited,visited+n,0);
        dist[i][i]=0;

        // 처음에 시작 지점에서는 1인 간선을 절대 이용할 수 없다. 그 다음부터는 자유롭게 이용 가능하다.
        for(int idx=0; idx<n; idx++){
            dist[i][idx]=min(INF,edges[i][idx]);
            //cout<<"i idx dist : "<<i<<' '<<idx<<' '<<dist[i][idx]<<endl;
        }

        for(int k=0; k<n-1; k++){
            // 아직까지 방문되지 않은 점 중 dist가 가장 작은 것을 방문하여 그 이웃들을 update
            // idx -> (idx+1)%n 이런 간선은 weight 1을 가진다고 생각할 수 있다.
            ll mn_idx=0, mn=INF; 
            for(int idx=0; idx<n; idx++){
                if(!visited[idx] && dist[i][idx]<mn) mn=dist[i][idx], mn_idx=idx;
            }
            if(visited[mn_idx]) continue;
            visited[mn_idx]=true;
            
            for(int idx=0; idx<n; idx++){
                umin(dist[i][(idx+dist[i][mn_idx])%n],dist[i][mn_idx]+edges[mn_idx][idx]);
            }
            umin(dist[i][(mn_idx+1)%n],dist[i][mn_idx]+1);
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i==j) cout<<0<<' ';
            else cout<<dist[i][j]<<' ';
        }
        cout<<endl;
    }
    
    return 0;
}