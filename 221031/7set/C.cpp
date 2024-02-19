// 
//./C<test.txt

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

ll datas[200000];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0; i<n; i++) cin>>datas[i];
        sort(datas,datas+n);
        ll res=0;
        for(int i=0; i<n-2; i++){
            umax(res, datas[i+1]+datas[n-1]-2*datas[i]);
        }
        reverse(datas,datas+n);
        for(int i=0; i<n-2; i++){
            umax(res, -(datas[i+1]+datas[n-1]-2*datas[i]));
        }
        cout<<res<<endl;
    }
    return 0;
}