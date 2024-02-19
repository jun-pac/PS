// 
//./C<test

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

#define N 200020
int datas[N];
vector<int> edges[N];
bool visited[N];
bool state[N]; // 1이면 반드시 살아야 하는 것.
int sz[N];

int DFS_ring(int idx, bool st){
    if(visited[idx]) return state[idx]==st;
    visited[idx]=true;
    state[idx]=st;
    for(int i=0; i<edges[idx].size(); i++) if(!visited[edges[idx][i]]){
        return DFS_ring(edges[idx][i],!st)+1;
    }
    return 1;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin>>n;
    for(int i=0; i<n; i++) cin>>datas[i];
    for(int i=0; i<n; i++) datas[i]--;
    bool flag=true;
    for(int i=0; i<n; i++){
        edges[datas[i]].push_back(i);
    }
    for(int i=0; i<n; i++) sz[i]=edges[i].size();
    // for(int i=0; i<n; i++) cout<<sz[i]<<endl;
    for(int i=0; i<n; i++){
        if(edges[i].size()==1 && edges[i][0]==i){
            cout<<-1<<endl;
            return 0;
        }
    }

    queue<int> q;
    for(int i=0; i<n; i++){
        if(sz[i]==0) q.push(i);
    }
    while(!q.empty()){
        int idx=q.front();
        q.pop();
        //cout<<idx<<endl;
        if(visited[idx]){
            if(!state[idx]){
                cout<<-1<<endl;
                return 0;
            }
        }
        visited[idx]=true;
        state[idx]=true;
        // datas[idx]로 관심사를 이동
        if(visited[datas[idx]]){
            if(state[datas[idx]]){
                cout<<-1<<endl;
                return 0;
            }
            continue;
        }
        
        visited[datas[idx]]=true;
        state[datas[idx]]=false;
        if(!visited[datas[datas[idx]]]) sz[datas[datas[idx]]]--;
        if(!visited[datas[datas[idx]]] && sz[datas[datas[idx]]]==0) q.push(datas[datas[idx]]);
        if(!visited[datas[datas[idx]]] && sz[datas[datas[idx]]]==1 && datas[datas[idx]]==datas[datas[datas[idx]]]){
            cout<<-1<<endl;
            return 0;
        }
    }
    //for(int i=0; i<n; i++) cout<<visited[i]<<' '; cout<<endl;
    for(int i=0; i<n; i++){
        if(!visited[i]){
            if(DFS_ring(i,true)%2==1){
                cout<<-1<<endl;
                return 0;
            }
        }
    }
    int resnum=0;
    for(int i=0; i<n; i++) if(state[i]) resnum++;
    cout<<resnum<<endl;
    for(int i=0; i<n; i++) if(state[i]) cout<<datas[i]+1<<' ';
    cout<<endl;

    return 0;
}