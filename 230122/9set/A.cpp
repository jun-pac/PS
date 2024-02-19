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
        int w,d,h,a,b,f,g;
        cin>>w>>d>>h;
        cin>>a>>b>>f>>g;
        int res=h;
        int t1=min(a+f,2*w-a-f)+abs(g-b);
        int t2=min(b+g,2*d-b-g)+abs(a-f);
        res=res+min(t1,t2);
        cout<<res<<endl;
    }
    return 0;
}