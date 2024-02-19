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

int a[200], b[200];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n, mx=0, mmx=0;
        cin>>n;
        for(int i=0; i<n; i++) cin>>a[i];
        for(int i=0; i<n; i++) cin>>b[i];
        for(int i=0; i<n; i++){
            mx=max(mx,a[i]);
            mx=max(mx,b[i]);
            mmx=max(mmx,min(a[i],b[i]));
        }
        if(max(a[n-1],b[n-1])>=mx && min(a[n-1],b[n-1])>=mmx) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}