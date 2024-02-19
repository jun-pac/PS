// 
//./C<test

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

int res[100010];
bool visited[100010];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,cnt=0;
        cin>>n;
        fill(visited,visited+n+1,false);
        for(int i=1; i<=n; i++){
            if(visited[i]) continue;
            int temp=i;
            while(temp<=n){
                visited[temp]=true;
                res[cnt++]=temp;
                temp=temp*2;
            }
        }
        for(int i=0; i<cnt; i++) cout<<res[i]<<' ';
        cout<<endl;
    }
    return 0;
}