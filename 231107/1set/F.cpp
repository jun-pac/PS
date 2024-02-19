// 
//./F<test

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

#define N 200020
int h[N], a[N];
pair<int,pair<int,int>> datas[N];
pair<ll,ll> ai[N];
int mxa[N];
bool use[N];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0; i<n; i++) cin>>h[i];
        for(int i=0; i<n; i++) cin>>a[i];
        for(int i=0; i<n; i++){
            datas[i]={h[i],{a[i],i}};
        }
        sort(datas,datas+n);
        fill(use,use+n,0);
        for(int i=n-1; i>=0; i--){
            if(datas[i].se.fi>(i==n-1?0:mxa[i+1])) use[i]=true;
            mxa[i]=(i==n-1?datas[i].se.fi:max(mxa[i+1],datas[i].se.fi));
        }
        int cnt=0;
        for(int i=0; i<n; i++){
            if(use[i]){
                datas[cnt++]=datas[i];
            }
        }
        for(int i=0; i<cnt; i++){
            ai[i]={(ll)datas[i].fi*datas[i].se.fi,datas[i].se.se};
        }
        sort(ai,ai+n);
        reverse(ai,ai+n);
        for(int i=1; i<200020; i++){
            int mx=0, mn=0; 
            while(true){

            }
        }
    }
    return 0;
}