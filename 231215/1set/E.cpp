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

#define N 400041
int a[200020], b[200200];
#define INF 1000000007

int datas[N];
int DP[N];

int LIS(int datas[], int n){
    fill(DP,DP+n,INF);
    int mx=0;
    // 단조증가면(즉, 같아도 되면) upper_bound를 쓰고, 그렇지 않으면 lower_bound
    for(int i=0; i<n; i++){
        int idx=lower_bound(DP,DP+n,datas[i])-DP;
        DP[idx]=datas[i];
        mx=max(mx,idx+1);
    }
    return mx;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        for(int i=0; i<n; i++) cin>>a[i];
        for(int i=0; i<m; i++) cin>>b[i];
        sort(b,b+m);
        reverse(b,b+m);
        for(int i=0; i<m; i++){

        }

    }
    return 0;
}