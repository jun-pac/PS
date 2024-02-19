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
        string a,b;
        cin>>a>>b;
        bool a_top=1, b_top=1;
        reverse(b.begin(), b.end());
        //cout<<"rb : "<<b<<endl;
        a=a+b;
        //cout<<"ra : "<<a<<endl;
        int l=1,r=n+m-1;
        while(l<m+n && a[l]!=a[l-1]) l++;
        while(r>0 && a[r]!=a[r-1]) r--;
        //cout<<"ds "<<l<<' '<<r<<endl;
        if(l==n+m) cout<<"YES"<<endl;
        else if(l>=r) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}