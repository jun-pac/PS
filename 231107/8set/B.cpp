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

int datas[2000];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0; i<2*n; i++) cin>>datas[i];
        sort(datas,datas+2*n);
        cout<<datas[n-1]-datas[0]+datas[2*n-1]-datas[n]<<endl;
        for(int i=0; i<n; i++) cout<<datas[i]<<' '<<datas[i+n]<<endl;
    }
    return 0;
}