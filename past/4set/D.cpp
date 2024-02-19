// 
//./D<test.txt

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

bool alltj; // 모든 cnt가 두 역할을 하고 있음
bool check[200000], visited[200000];
int cnt;
vector<int> edges[200000];
int up_cnts[200000];

bool DFS(int idx){
    if(visited[idx]) return false;
    visited[idx] = true;
    if(edges[idx].size()==1){
        check[idx]=true;
        cnt++;
        return false;
    }
    else if(edges[idx].size()==2){
        bool temp=false;
        int next=(visited[edges[idx][0]]?edges[idx][1]:edges[idx][0]);
        temp=DFS(next);
        if(temp || !check[next]){
            check[idx]=true;
            cnt++;
            return false;
        }
        return true;
    }
    else{
        bool temp=false;
        int up_cnt=0;
        for(int i=0; i<edges[idx].size(); i++){
            int next=edges[idx][i];
            if(!visited[next]){
                if(DFS(next)){
                    up_cnt++;
                    temp=true;
                }
            }
        }
        if(temp){
            check[idx]=true;
            cnt++;
        }
        up_cnts[idx]=up_cnt;
        return false;
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,a,b;
        cin>>n;
        for(int i=0;i<n;i++) edges[i].clear();
        fill(visited,visited+n,false);
        fill(check,check+n,true);
        for(int i=0; i<n-1; i++){
            cin>>a>>b;
            a--, b--;
            edges[a].push_back(b);
            edges[b].push_back(a);
        }
        int max_degree=0,mx_idx;
        for(int i=0; i<n; i++){
            if(max_degree<(int)edges[i].size()){
                max_degree=(int)edges[i].size();
                mx_idx=i;
            }
        }
        if(n==1){
            cout<<0<<endl;
        }
        if(max_degree<2){
            cout<<(n+1)/2<<endl;
            continue;
        }
        cnt=0;
        DFS(mx_idx);
        alltj=true;
        for(int i=0; i<n; i++){
            if(check[i]){
                bool temp=true;
                for(int j=0; j<edges[i].size(); j++){
                    int next=edges[i][j];
                    if(edges[next].size()>=3){
                        if(up_cnts[next]==1) alltj=false;
                    }
                    else if(edges[next].size()==1){
                        if(edges[edges[next][0]].size()>=4) alltj=false;
                    }
                }
            }
        }
        if(alltj) cout<<cnt<<endl;
        else cout<<cnt-1<<endl;
    }
    return 0;
}