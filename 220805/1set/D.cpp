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

vector<int> edges[2002];
bool visited[2002];
queue<pair<int,int>> qq;
int pred[2002];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        for(int i=0; i<n; i++){
            edges[i].clear();
        }
        for(int i=0; i<m; i++){
            int a,b;
            cin>>a>>b;
            a--, b--;
            edges[a].pb(b);
            edges[b].pb(a);
        }
        bool flag=false;
        for(int i=0; i<n; i++){
            if(edges[i].size()<4) continue;
            for(auto next:edges[i]){
                while(!qq.empty()) qq.pop(); // clear queue
                fill(visited,visited+n,0);
                // i에서 시작해서 next로 도착하는 경로를 찾는 BFS. 단, (i, next)라는 경로는 써서는 안됨.
                // 근데 두 개의 노드는 남기는 건 어떻게 보장되느냐? 라고 물어볼 수 있는데, BFS경로에서 depth(i기준 거리)가 1인 노드가 두 번 이상 방문될 수 있는지 생각해보자.

                qq.push({i,-1});
                while(!qq.empty()){
                    auto cur=qq.front();
                    qq.pop();
                    if(visited[cur.fi]) continue;
                    //cout<<"Visit : "<<cur.fi+1<<' '<<"| Last : "<<cur.se+1<<endl;
                    visited[cur.fi]=true;
                    pred[cur.fi]=cur.se;
                    if(cur.fi==next){
                        flag=true;
                        //cout<<"Catch "<<i+1<<' '<<next+1<<endl;
                        break;
                    }
                    for(auto BFS_next:edges[cur.fi]){
                        if(!visited[BFS_next] && !(cur.fi==i && BFS_next==next)) qq.push({BFS_next,cur.fi});
                    }
                }
                if(flag){
                    cout<<"YES"<<endl;
                    //cout<<"DEBUG : "<<last<<' '<<next<<endl;
                    fill(visited,visited+n,0);
                    int last=next;
                    visited[last]=true;
                    int temp_cnt=0;
                    while(pred[last]!=-1){
                        last=pred[last];
                        visited[last]=true;
                        temp_cnt++;
                    }
                    cout<<temp_cnt+3<<endl;

                    last=next;
                    while(pred[last]!=-1){
                        cout<<last+1<<' '<<pred[last]+1<<endl;
                        last=pred[last];
                    }
                    cout<<last+1<<' '<<next+1<<endl;
                    temp_cnt=0;
                    for(auto t_next:edges[i]){
                        if(!visited[t_next]){
                            temp_cnt++;
                            cout<<i+1<<' '<<t_next+1<<endl;
                            if(temp_cnt>=2) break;
                        }
                    }
                    break;
                }
            }
            if(flag) break;
        }
        if(!flag) cout<<"NO"<<endl;
    }
    return 0;
}