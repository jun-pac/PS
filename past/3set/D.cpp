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

vector<int> edges[200000];
int visited[200000];
ll mn[200000], mx[200000];
int cnt;

ll DFS(int idx){
    visited[idx]=true;
    if(idx!=0 && edges[idx].size()==1){
        cnt++;
        return mx[idx];
    }
    ll sub_mx=0;
    for(int i=0; i<edges[idx].size(); i++){
        int next=edges[idx][i];
        if(!visited[next]) sub_mx+=DFS(next);
    }
    if(sub_mx<mn[idx]){
        cnt++;
        return mx[idx];
    }
    else{
        return min(mx[idx],sub_mx);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a,b;
        for(int i=1; i<n; i++){
            cin>>a;
            a--;
            edges[a].push_back(i);
            edges[i].push_back(a);
        }
        for(int i=0; i<n; i++){
            cin>>mn[i]>>mx[i];
        }
        cnt=0;
        fill(visited,visited+n,false);
        DFS(0);
        cout<<cnt<<endl;
        for(int i=0; i<n; i++){
            edges[i].clear();
        }
    }
    return 0;
}