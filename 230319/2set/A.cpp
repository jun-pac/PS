// 
//./A<test

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

int ans[50010];
bool visited[100020];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,m,a;
        cin>>n>>m;
        int cnt=0;
        fill(ans,ans+n,-1);
        fill(visited,visited+n+m,0);
        for(int i=0; i<m; i++){
            cin>>a;
            a--;
            if(!visited[a-n]){
                if(cnt<n) ans[n-1-cnt]=i+1;
                cnt++;
                visited[a-n]=1;
            }
        }
        for(int i=0; i<n; i++) cout<<ans[i]<<' ';
        cout<<endl;

    }
    return 0;
}