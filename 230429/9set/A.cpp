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

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        int res=4;
        res=min(4,min(n,m));
        if(x1==1 || x1==n || x2==1 || x2==n) res=min(res,3);
        if(y1==1 || y1==m || y2==1 || y2==m) res=min(res,3);
        if((x1==1 || x1==n) && (y1==1 || y1==m)) res=min(res,2);
        if((x2==1 || x2==n) && (y2==1 || y2==m)) res=min(res,2);
        cout<<res<<endl;
    }
    return 0;
}