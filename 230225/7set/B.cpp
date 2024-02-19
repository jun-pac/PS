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
        ll x,y;
        cin>>x>>y;
        cout<<2*(x-y)<<endl;
        for(int i=y; i<=x; i++){
            cout<<i<<' ';
        }
        for(int i=x-1; i>y; i--){
            cout<<i<<' ';
        }
        cout<<endl;
    }
    return 0;
}