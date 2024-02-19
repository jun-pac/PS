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

ll a[300020], b[300030];


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0; i<n; i++) cin>>a[i];
        for(int i=0; i<n; i++) cin>>b[i];
        ll suma=0, sumb=0;
        sort(a,a+n);
        sort(b,b+n);
        for(int i=0; i<n; i++) suma+=a[i];
        for(int i=0; i<n; i++) sumb+=b[i];
        cout<<min(suma+n*b[0],sumb+n*a[0])<<endl;
        
    }
    return 0;
}