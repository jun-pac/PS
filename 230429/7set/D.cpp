// 
//./D<test

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

ll fibo[50];

bool check(ll nx, ll ny, ll x, ll y){
    // nx<ny
    if(nx==1) return true;
    if(ny-nx-1 < y && y < nx) return false;
    if(ny-nx-1 >= y) return check(ny-nx, nx, y, x);
    else return check(ny-nx, nx, ny-1-y, x);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    fibo[0]=1;
    fibo[1]=1;
    for(int i=2; i<=45; i++) fibo[i]=fibo[i-1]+fibo[i-2];
    while(t--){
        ll n,x,y;
        cin>>n>>x>>y;
        // 1<=x<=fibo[n], 1<=y<=fibo[n+1]
        x--, y--;
        cout<<(check(fibo[n], fibo[n+1], x,y)?"YES":"NO")<<endl;
    }
    return 0;
}