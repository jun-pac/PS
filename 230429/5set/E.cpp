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

vector<int> edges[200020];
int datas[200020];
int visited[200020];
bool zero_visited[200020];
priority_queue<pair<int,int>> pq;
int cnt;

void check_DFS(int idx){
    visited[idx]=true;
    cnt++;
    for(auto next : edges[idx]){
        if(!visited[next]) check_DFS(next);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,m;   
        cin>>n>>m;
        for(int i=0; i<n; i++) edges[i].clear();
        for(int i=0; i<n; i++) cin>>datas[i];
        int a,b;
        for(int i=0; i<m; i++){
            cin>>a>>b;
            a--, b--;
            edges[a].push_back(b);
            edges[b].push_back(a);
        }
        int zero_idx=-1;
        for(int i=0; i<n; i++) if(datas[i]==0){
            zero_idx=i;
            break;
        }
        cnt=0;
        fill(visited,visited+n,false);
        check_DFS(0);
        if(zero_idx==-1 || cnt!=n){
            cout<<"NO"<<endl;
            continue;
        }
        
        // À¯»ç dijkstra
        bool flag=false;
        fill(visited,visited+n,0);
        fill(zero_visited,zero_visited+n,false);
        for(int i=0; i<n; i++){
            if(datas[i]==0 && !zero_visited[i]){
                while(!pq.empty()) pq.pop();
                pq.push({-datas[i],i});
                int cur_cnt=0;
                int visit_cnt=i+1;
                while(!pq.empty()){
                    int idx=pq.top().se;
                    int val=-pq.top().fi;
                    pq.pop();
                    if(visited[idx]==visit_cnt) continue;
                    visited[idx]=visit_cnt;
                    if(val==0) zero_visited[idx]=true;
                    if(val>cur_cnt) break;

                    cur_cnt++;
                    for(auto next:edges[idx]){
                        if(visited[next]!=visit_cnt) pq.push({-datas[next],next});
                    }
                }
                //cout<<"start from "<<i<<' '<<cur_cnt<<endl;
                if(cur_cnt==n){
                    flag=true;
                    break;
                }
            }
        }
        cout<<(flag?"YES":"NO")<<endl;
    }
    return 0;
}