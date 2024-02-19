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
        int n,k;
        cin>>n>>k;
        int l,r;
        bool lf=0,rf=0;
        for(int i=0; i<n; i++){
            cin>>l>>r;
            if(l==k) lf=1;
            if(r==k) rf=1;
        }
        if(lf&&rf) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}