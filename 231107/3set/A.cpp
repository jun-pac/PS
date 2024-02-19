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
#define N 100010
pair<ll,ll> datas[N];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        ll n,p;
        cin>>n>>p;
        for(int i=0; i<n; i++) cin>>datas[i].se;
        for(int i=0; i<n; i++) cin>>datas[i].fi;
        sort(datas,datas+n);
        int cur=0, left=datas[0].se;
        ll res=p;
        for(int i=1; i<n; i++){
            if(left==0 && cur!=i-1){
                cur++;
                left=datas[cur].se;
            }
            if(datas[cur].fi<p && left>0){
                left--;
                res+=datas[cur].fi;
            }
            else res+=p;
        }
        cout<<res<<endl;
    }

    return 0;
}