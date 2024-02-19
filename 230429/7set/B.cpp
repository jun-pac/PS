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

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        ll n,x1,y1,x2,y2;
        cin>>n>>x1>>y1>>x2>>y2;
        x1*=2;
        x2*=2;
        y1*=2;
        y2*=2;
        ll s1=max(abs(x1-(n+1)),abs(y1-(n+1)));
        ll s2=max(abs(x2-(n+1)),abs(y2-(n+1)));
        cout<<abs(s1-s2)/2<<endl;
    }
    return 0;
}