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

#define INF 1000000007
vector<pair<int,int>> edges[250000];
ll DP[11][250000]; // DP[k][i*m+j]�� [i][j]���� '����'�ؼ� k hop��ŭ �̵��ϰ� �� �ڿ� ��򰡿� �������� �� �� �ּ��� �Ÿ�


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll n,m,k,w;
    cin>>n>>m>>k;
    
    for(int i=0; i<n*m; i++) edges[i].clear();
    for(int i=0; i<n*m; i++) edges[i].reserve(4);
    for(int i=0; i<n; i++){
        for(int j=0; j<m-1; j++){
            cin>>w;
            edges[i*m+j].push_back({i*m+j+1,w});
            edges[i*m+j+1].push_back({i*m+j,w});
        }
    }
    for(int i=0; i<n-1; i++){
        for(int j=0; j<m; j++){
            cin>>w;
            edges[i*m+j].push_back({(i+1)*m+j,w});
            edges[(i+1)*m+j].push_back({i*m+j,w});
        }
    }

    if(k%2==1){
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cout<<-1<<' ';
            }
            cout<<endl;
        }
        return 0;
    }

    fill(DP[0],DP[0]+n*m,0);
    for(int r=1; r<=k/2; r++){
        for(int idx=0; idx<n*m; idx++){
            // r hop������ ��Ȳ
            DP[r][idx]=INF;
            for(int j=0; j<edges[idx].size(); j++){
                int next=edges[idx][j].first;
                DP[r][idx]=min(DP[r][idx],DP[r-1][next]+edges[idx][j].second);
            }
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++) cout<<DP[k/2][i*m+j]*2<<' ';
        cout<<endl;
    }
    return 0;
}