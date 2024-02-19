// 
//./A<test

#include <bits/stdc++.h>
//#define endl '\n'
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

// 뭔가 tree DP를 하면서, subtree에서 너의 값이 l일때 max, r일때 max를 구해서 관리하면 어떤가요
// 합치는 데 복잡도가 얼마죠 => 각각 독립적으로 선택하면 되는거죠

vector<int> edges[200000];
pair<ll,ll> bound[200000];
pair<ll,ll> DP[200000];

ll DFS(int idx, int p){
    ll l_val=0, r_val=0;
    for(int i=0; i<edges[idx].size(); i++){
        int next=edges[idx][i];
        if(next==p) continue;
        DFS(next,idx);
        l_val+=max(DP[next].fi+abs(bound[next].fi-bound[idx].fi), DP[next].se+abs(bound[next].se-bound[idx].fi));
        r_val+=max(DP[next].fi+abs(bound[next].fi-bound[idx].se), DP[next].se+abs(bound[next].se-bound[idx].se));
    }
    DP[idx]={l_val,r_val};
    return max(l_val,r_val);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,a,b;
        cin>>n;
        for(int i=0; i<n; i++) edges[i].clear();
        for(int i=0; i<n; i++) cin>>bound[i].fi>>bound[i].se;
        for(int i=0; i<n-1; i++){
            cin>>a>>b;
            a--, b--;
            edges[a].push_back(b);
            edges[b].push_back(a);
        }
        ll res=DFS(0,-1);
        cout<<res<<endl;
    }
    return 0;
}