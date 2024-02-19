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

int parent[5001];
vector<int> child[5001];
ll sub_sz[5001];
ll cnt;
bool DP[5001], temp[5001];

ll sz_DFS(int idx){
    ll sz=1;
    for(auto next:child[idx]){
        sz+=sz_DFS(next);
    }
    return sub_sz[idx]=sz;
}

void DFS(int idx){
    ll sz=sub_sz[idx]-1;
    if(sz==0) return;
    fill(DP,DP+sz+1,0);
    DP[0]=1;
    for(int i=0; i<child[idx].size(); i++){
        int next=child[idx][i];
        int tt=sub_sz[next];
        for(int j=sz-tt; j>=0; j--){
            if(DP[j]) DP[j+tt]=1;
        }
    }
    //cout<<idx+1<<" | ";
    //for(int j=0; j<sz+1; j++) cout<<DP[j]<<' ';
    //cout<<endl;
    int mid1=sz/2, mid2=(sz+1)/2;
    while(mid1>=0 && !DP[mid1]) mid1--;
    while(mid2<=sz && !DP[mid2]) mid2++;
    cnt+=max((mid1)*(sz-mid1),(mid2)*(sz-mid2));
    for(auto next:child[idx]){
        DFS(next);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,p;
    cin>>n;
    parent[0]=-1;
    for(int i=1; i<n; i++){
        cin>>p;
        p--;
        parent[i]=p;
        child[p].push_back(i);
    }
    sz_DFS(0);
    cnt=0;
    DFS(0);
    cout<<cnt<<endl;
    return 0;
}