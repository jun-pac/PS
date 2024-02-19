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

pair<ll,ll> datas[100000];
ll res[100000];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        ll a,b;
        for(int i=0; i<n; i++){
            cin>>a;
            datas[i]={a,i+1};
        }
        sort(datas,datas+n);
        res[0]=0;
        for(int i=1; i<n; i++){
            ll temp=datas[i].fi;
            res[i]=(temp/datas[i-1].fi*datas[i-1].fi-temp+datas[i-1].fi)%datas[i-1].fi;
            datas[i].fi=temp+res[i];
        }
        cout<<n<<endl;
        for(int i=0; i<n; i++) cout<<datas[i].se<<' '<<res[i]<<endl;
    }
    
    return 0;
}