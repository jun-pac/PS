
#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
#define N 200020

bool visited[N];
queue<pii> q;

int main(){
    int n,k;
    cin>>n>>k;
    q.push({n,0});
    while(!q.empty()){
        int idx=q.front().first, d=q.front().second;
        q.pop();
        if(idx==k){
            cout<<d;
            break;
        }
        if(visited[idx]) continue;
        visited[idx]=true;
        if(idx-1>=0 && !visited[idx-1]) q.push({idx-1,d+1});
        if(idx+1<N && !visited[idx+1]) q.push({idx+1,d+1});
        if(2*idx<N && !visited[2*idx]) q.push({2*idx,d+1});
    }
}