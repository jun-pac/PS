// 
//./D<test

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

ll datas[200002];
ll ssum[200002];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        ll n,q;
        cin>>n>>q;
        for(int i=0; i<n; i++) cin>>datas[i];
        for(int i=0; i<n; i++){
            ssum[i]=(i==0?datas[0]:datas[i]+ssum[i-1]);
        }
        ll l,r,k;
        for(int i=0; i<q; i++){
            cin>>l>>r>>k;
            l--, r--;
            ll res=ssum[n-1]-(ssum[r]-(l==0?0:ssum[l-1]))+k*(r-l+1);
            if(res%2==0) cout<<"NO"<<endl;
            else cout<<"YES"<<endl;
        }
    }
    return 0;
}