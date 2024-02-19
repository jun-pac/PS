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
        ll n,k,g;
        cin>>n>>k>>g;
        if(n==1){
            cout<<0<<endl;
            continue;
        }
        ll mx=(g%2==0?g/2-1:g/2);
        ll res=mx*(n-1);
        if(mx*n>=k*g){
            cout<<k*g<<endl;
            continue;
        }
        ll last=k*g-res;
        if(last%g>mx){
            cout<<res-(g-last%g)<<endl;
        }
        else{
            cout<<res+ (last%g)<<endl;
        }
    }
    return 0;
}