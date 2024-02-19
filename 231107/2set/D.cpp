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

int datas[200030];
vector<int> edges[200020];
ll ans[200010];
int sub_sz[200020];
ll cost1[200020], cost0[200020];
int mul;
bool visited[200020];

void DFS1(int idx){
    visited[idx]=true;
    sub_sz[idx]=1;
    cost0[idx]=0;
    cost1[idx]=0;
    for(auto next : edges[idx]){
        if(!visited[next]){
            DFS1(next);
            sub_sz[idx]+=sub_sz[next];
            cost0[idx]+=cost0[next];
            cost1[idx]+=cost1[next];
        }
    }
    if(datas[idx]&mul) cost0[idx]=cost1[idx]+sub_sz[idx]; // *mul;는 DFS2에서 하는 걸로
    else cost1[idx]=cost0[idx]+sub_sz[idx];
}

void DFS2(int idx, int p){
    // 현위치에서 값을 계산하는 곳
    ans[idx]+=((datas[idx]&mul)?cost1[idx]:cost0[idx])*mul;
    ll last_sub_sz=sub_sz[idx];
    ll last_cost0=cost0[idx];
    ll last_cost1=cost1[idx];

    // 다음으로 주권을 넘기는 곳
    // 매번 초기화를 해야 함에 주의.
    for(auto next : edges[idx]){
        if(next==p) continue;
        sub_sz[idx]=last_sub_sz-sub_sz[next];
        if(datas[idx]&mul){
            cost1[idx]=last_cost1-cost1[next];
            cost0[idx]=cost1[idx]+sub_sz[idx];
        }
        else{
            cost0[idx]=last_cost0-cost0[next];
            cost1[idx]=cost0[idx]+sub_sz[idx];
        }

        sub_sz[next]+=sub_sz[idx];
        if(datas[next]&mul){
            cost1[next]+=cost1[idx];
            cost0[next]+=sub_sz[next];
        }
        else{
            cost0[next]+=cost0[idx];
            cost1[next]+=sub_sz[next];
        }
        DFS2(next,idx);
        //sub_sz[next]-=sub_sz[idx];
        //cost0[next]-=((datas[next]&mul)?cost1[idx]:cost0[idx]);
        //cost1[next]-=((datas[next]&mul)?cost1[idx]:cost0[idx]);
    }
    //sub_sz[idx]=last_sub_sz;
    //cost0[idx]=last_cost0;
    //cost1[idx]=last_cost1;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,u,v;
        cin>>n;
        for(int i=0; i<n; i++) edges[i].clear();
        for(int i=0; i<n; i++) cin>>datas[i]; 
        for(int i=0; i<n-1; i++){
            cin>>u>>v;
            u--, v--;
            edges[u].push_back(v);
            edges[v].push_back(u);
        }
        mul=1;
        fill(ans,ans+n,0);
        while(mul<(1<<20)){
            fill(visited,visited+n,0);
            DFS1(0);
            DFS2(0,-1);
            //if(mul==1){ cout<<"temp "; for(int i=0; i<n; i++) cout<<ans[i]<<' '; cout<<endl;}
            mul<<=1;
        }
        for(int i=0; i<n; i++) cout<<ans[i]<<' ';
        cout<<endl;
    }
    return 0;
}