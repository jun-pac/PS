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

ll edges[800][800]; // i -> j�� �����ϴ� ����, �� ���� edges[i][j]�� i->j�� weight
ll dist[800][800]; // DP[i][j]�� i���� j�� ���ް����� �ּ��� �Ÿ�
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
    // ��� ������ ring�� �̷�� �ִ� ��Ȳ���� ���� ��ȯ ����. idx�� idx+1�� weight 1�� �������� ���� 
    //for(int i=0; i<n; i++) edges[i][(i+1)%n]=min(edges[i][(i+1)%n],1);
    // ó������ �� �������� �̿��� �� �����Ƿ� ���� ó�����ش�.

    // (V^2 + E)V dijkstra
    for(int i=0; i<n; i++) fill(dist[i],dist[i]+n,INF);
    for(int i=0; i<n; i++){
        // Starting from i
        fill(visited,visited+n,0);
        dist[i][i]=0;

        // ó���� ���� ���������� 1�� ������ ���� �̿��� �� ����. �� �������ʹ� �����Ӱ� �̿� �����ϴ�.
        for(int idx=0; idx<n; idx++){
            dist[i][idx]=min(INF,edges[i][idx]);
            //cout<<"i idx dist : "<<i<<' '<<idx<<' '<<dist[i][idx]<<endl;
        }

        for(int k=0; k<n-1; k++){
            // �������� �湮���� ���� �� �� dist�� ���� ���� ���� �湮�Ͽ� �� �̿����� update
            // idx -> (idx+1)%n �̷� ������ weight 1�� �����ٰ� ������ �� �ִ�.
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