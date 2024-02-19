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


#define MOD 1000000007 
int as[200002], bs[200002];


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0; i<n; i++) cin>>as[i];
        for(int i=0; i<n; i++) cin>>bs[i];
        sort(bs,bs+n);
        sort(as,as+n);
        ll res=1;
        for(int i=0; i<n; i++){
            int idx=lower_bound(bs,bs+n,as[i])-bs;
            ll temp=(idx-i<=0?0:idx-i);
            res=(res*temp)%MOD;
        }
        cout<<res<<endl;
    }
    return 0;
}