// 
//./B<test

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

int ans[400000];
priority_queue<pair<int,int>> pq;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        ll n,k,a;
        cin>>n>>k;
        for(int i=0; i<n; i++){
            cin>>a;
            if(a>k) pq.push({a%k+2*k,-i});
            else pq.push({a%k+k,-i});
        }
        int cnt=0;
        while(!pq.empty()){
            auto tt=pq.top();
            pq.pop();
            if(tt.fi<=k) ans[cnt++]=-tt.se+1;
            else pq.push({tt.fi-k,tt.se});
        }
        for(int i=0; i<n; i++) cout<<ans[i]<<' ';
        cout<<endl;
    }
    return 0;
}