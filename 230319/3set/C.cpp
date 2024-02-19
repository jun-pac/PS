// 
//./C<test

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

#define MOD 998244353

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        ll l,r;
        cin>>l>>r;
        ll temp=l;
        ll cnt=0;
        while(temp<=r){
            temp*=2;
            cnt++;
        }
        //cout<<cnt<<endl;
        
        ll l_mx=r;
        for(int i=0; i<cnt-1; i++) l_mx/=2;
        ll nums=l_mx-l+1;
        if(cnt!=1){
            ll tri_mx=r;
            tri_mx/=3;
            for(int i=0; i<cnt-2; i++) tri_mx/=2;
            if(tri_mx>=l) nums+=(tri_mx-l+1)*(cnt-1);
        }
        cout<<cnt<<' '<<nums%MOD<<endl;
        

    }
    return 0;
}