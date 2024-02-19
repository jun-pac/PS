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
        int a,b;
        cin>>a>>b;
        a=abs(a), b=abs(b);
        if(a==b) cout<<a+b<<endl;
        else{
            if(a<b) swap(a,b); // a>b
            int res=b+a;
            res+=a-b-1;
            cout<<res<<endl;
        }
    }
    return 0;
}