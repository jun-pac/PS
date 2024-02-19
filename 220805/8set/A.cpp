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

ll a[100];
ll b[100];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<m;i++)cin>>b[i];
        ll suma=0, sumb=0;
        for(int i=0; i<n; i++) suma+=a[i];
        for(int i=0; i<m; i++) sumb+=b[i];
        if(suma==sumb) cout<<"Draw"<<endl;
        else if(suma>sumb) cout<<"Tsondu"<<endl;
        else cout<<"Tenzing"<<endl;
    }
    return 0;
}