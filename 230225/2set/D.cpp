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

int edges[200200];
vector<int> rev_edges[200200];
int visited[200200];
bool is_cycle[200200];
int subsz[200200];
int cycle_num;
int path_num;
int last;
int n;

bool DFS(int idx, int visitnum){
    visited[idx]=visitnum;
    last=idx;
    path_num++;
    if(0<=edges[idx] && edges[idx]<n){
        int next=edges[idx];
        if(visited[next]==-1){
            is_cycle[idx]=DFS(next, visitnum);
            return is_cycle[idx];
        }
        else if(visited[next]==visitnum){
            is_cycle[idx]=true;
            return true;
        }
        else{
            is_cycle[idx]=is_cycle[next];
            return is_cycle[idx];
        }
    }
    is_cycle[idx]=false;
    return false;
}


int rev_DFS(int idx){
    subsz[idx]=1;
    for(int i=0; i<rev_edges[idx].size(); i++){
        int next=rev_edges[idx][i];
        int temp=rev_DFS(next);
        subsz[idx]+=temp;
    }
    return subsz[idx];
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){ 
        cin>>n;
        for(int i=0; i<n; i++){
            cin>>edges[i];
            edges[i]+=i;
        }
        for(int i=0; i<n; i++) rev_edges[i].clear();
        for(int idx=0; idx<n; idx++){
            if(0<=edges[idx] && edges[idx]<n){
                rev_edges[edges[idx]].push_back(idx);
            }
        }
        cycle_num=0;
        path_num=0;
        fill(visited,visited+n,-1);
        DFS(0,0);
        int real_path=path_num;
        int real_last=last;
        for(int i=1; i<n; i++){
            if(visited[i]==-1) DFS(i,i);
        }
        for(int i=0; i<n; i++){
            if(is_cycle[i]) cycle_num++;
        }

        if(is_cycle[0]){
            //cout<<"is cycle"<<endl;
            cout<<(ll)real_path*((ll)2*n+1-cycle_num)<<endl;
        }
        else{
            //cout<<(ll)n*(2*n+1)-(ll)real_path*cycle_num<<endl;
            fill(subsz,subsz+n,0);
            rev_DFS(real_last);
            int idx=0;
            ll nums=0;
            while(0<=idx && idx<n){
                //cout<<"nums check "<<idx<<' '<<subsz[idx]<<endl;
                nums+=subsz[idx];
                idx=edges[idx];
            }
            //cout<<"no cycle"<<endl;
            //cout<<cycle_num<<' '<<nums<<endl;
            cout<<(ll)n*(2*n+1)-(ll)real_path*cycle_num-nums<<endl;
        }
    }
    return 0;
}