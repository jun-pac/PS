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

vector<pair<int,int>> edges[250000];
ll ans[250000];

class node{
public:
    node(){}
    node(int st, int e, ll d){
        step=st;
        e_idx=e;
        dist=d;
    }
    int step, e_idx;
    ll dist;
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll n,m,k,w;
    cin>>n>>m>>k;
    // idx = i*m+j
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
    
    priority_queue<pair<ll,pair<int,int>>> pq; // -dist, step, idx
    for(int i=0; i<n*m; i++){
        // 500*500 starting point
        while(!pq.empty()) pq.pop();
        pq.push({0,{0,i}});
        while(!pq.empty()){
            ll dist=-pq.top().fi;
            int step=pq.top().se.fi;
            int idx=pq.top().se.se;
            pq.pop();
            if(step==k/2){
                ans[i]=2*dist;
                break;
            }
            for(int j=0; j<edges[idx].size(); j++){
                int next=edges[idx][j].fi;
                w=edges[idx][j].se;
                pq.push({-(dist+w),{step+1,next}});
            }
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++) cout<<ans[i*m+j]<<' ';
        cout<<endl;
    }
    return 0;
}