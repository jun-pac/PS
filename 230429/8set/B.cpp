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

ll foo(ll m, ll a, ll b){
    return m-1+(a/m)+(b/m)+(a%m==0?0:1)+(b%m==0?0:1);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        ll a,b;
        cin>>a>>b;
        ll sq=sqrt(a+b);
        ll l=sq-1, r=sq+1;
        ll val=foo(sq,a,b);
        //cout<<sq<<' '<<val<<endl;
        ll ans=val;
        while(l>0){
            ll temp=foo(l,a,b);
            ans=min(ans,temp);
            if(abs(val-temp)>8) break;
            l--;
        }
        while(r<=max(a,b)){
            ll temp=foo(r,a,b);
            ans=min(ans,temp);
            //cout<<"de : "<<r<<' '<<temp<<endl;
            if(abs(val-temp)>8) break;
            r++;
        }
        cout<<ans<<endl;
    }
    return 0;
}