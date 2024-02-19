
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
typedef long long ll;
#define N 300030

ll boss[N], pay[N], lead[N];
priority_queue<ll> DP[N]; // pop out biggest payment in the subtree.
ll sum[N]; // sum of the pay in current subtree
vector<int> child[N]; // idx에 연결된 child들
ll m;

ll DFS(int idx){
    ll mx=0;
    sum[idx]=0;
    for(auto next : child[idx]){
        mx=max(mx,DFS(next));
        sum[idx]+=sum[next];
        if(DP[next].size() > DP[idx].size()) swap(DP[idx],DP[next]);
    }
    DP[idx].push(pay[idx]);
    sum[idx]+=pay[idx];
    for(auto next : child[idx]){
        while(!DP[next].empty()) DP[idx].push(DP[next].top()), DP[next].pop();
    }
    while(sum[idx]>m){
        assert(!DP[idx].empty()); // For debug
        sum[idx]-=DP[idx].top();
        DP[idx].pop();
    }
    mx=max(mx,lead[idx]*((ll)DP[idx].size()));
    return mx;
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin>>n>>m;
    for(int i=0; i<n; i++){
        cin>>boss[i]>>pay[i]>>lead[i];
        boss[i]--;
        if(boss[i]!=-1){
            child[boss[i]].pb(i);
        }
    }
    cout<<DFS(0)<<'\n';
    return 0;
}

