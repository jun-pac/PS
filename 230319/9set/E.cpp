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

bool ori_edges[20][20];
vector<int> edges[20];
bool visited[20];
int n, tar;
int dest[20];

bool DFS(int idx, int depth, int s){
    if(idx==s && depth!=0){
        if(depth==tar-1) return true;
        else return false;
    }
    for(auto i : edges[idx]){
        if(visited[i]){
            dest[idx]=i;
            bool temp=DFS(i,depth+1,s);
            if(temp) return true;
        }
    }
    return false;
}

bool check(int idx){
    // idx is an encoding
    fill(visited,visited+n,0);
    int s=-1;
    tar=0;
    for(int j=0; j<n; j++){
        if((1<<j)&idx){
            visited[j]=1;
            if(s==-1) s=j;
            tar++;
        }
    }
    if(tar==1) return true;
    return DFS(s,0,s);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int m,a,b;
    cin>>n>>m;
    for(int i=0; i<m; i++){
        cin>>a>>b;
        a--, b--;
        ori_edges[a][b]=ori_edges[b][a]=1;
        edges[a].pb(b);
        edges[b].pb(a);
    }
    int ans=0;
    for(int i=1; i<=(1<<n); i++){
        // 1인 비트가 LOOP임.
        fill(visited,visited+n,0);
        for(int j=0; j<n; j++){
            if(((1<<j)&i)==0){
                for(auto k : edges[j]) visited[k]=1;
            }
        }
        bool flag=true;
        for(int j=0; j<n; j++){
            if((1<<j)&i){
                if(!visited[j]){
                    flag=false;
                    break;
                }
            }
        }
        if(flag){
            // check(cycle)...?
            flag=check(i);
            if(!flag) continue;
            for(int j=0; j<n; j++){
                if((1<<j)&i){
                    cout<<dest[j]+1<<' ';
                }
                else{
                    for(auto k : edges[j]){
                        if((1<<k)&i){
                            cout<<k+1<<' ';
                            break;
                        }
                    }
                }
            }   
        }
    }


    return 0;
}