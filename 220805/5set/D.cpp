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

pair<ll,ll> datas[200020];
unordered_map<ll,ll> mp[200020];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        for(int i=1; i<n+1; i++) mp[i].clear();
        for(int i=0; i<n; i++) cin>>datas[i].fi;  
        for(int i=0; i<n; i++) cin>>datas[i].se;
        for(int i=0; i<n; i++) mp[datas[i].fi][datas[i].se]=mp[datas[i].fi][datas[i].se]+1;
        sort(datas,datas+n);
        ll sq=400;
        ll res=0;
        ll last=0;
        ll del=0;
        // a[i]<sq인 경우는 한 번에 구해버립니다
        for(int i=0; i<n; i++){
            // {a,b} = {j,a*j-b}
            if(datas[i].fi*datas[i].fi==datas[i].se+datas[i].se) del++;
            ll s=max(1LL,cediv(1+datas[i].se,datas[i].fi));
            ll e=min(min(n,sq),(n+datas[i].se)/datas[i].fi);
            ll cur_sum=datas[i].fi*s-datas[i].se;
            ll p=datas[i].fi;
            for(int j=s; j<=e; j++){
                res=res+mp[j][cur_sum];
                cur_sum=cur_sum+p;
            }
        }
        
        int ss=0;
        while(ss<n && datas[ss].fi<=sq) ss++;
        for(int i=ss; i<n; i++){
            if(i!=0 && datas[i].fi==datas[i-1].fi && datas[i].se==datas[i-1].se){
                res+=last;
                continue;
            }
            last=0;
            ll s=max(1LL,cediv(1+datas[i].se,datas[i].fi));
            ll e=min(n,(n+datas[i].se)/datas[i].fi);
            ll cur_sum=datas[i].fi*s-datas[i].se;
            ll p=datas[i].fi;
            for(ll j=s; j<=e; j++){
                // a값은 j이고, b값은 datas[i].fi*j-datas[i].se인 개수
                last=last+mp[j][cur_sum];
                cur_sum=cur_sum+p;
            }
            res=res+last;
        }
        cout<<(res-del)/2<<endl;
    }
    return 0;
}