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


ll gcd(ll a, ll b){
    if(a<b) swap(a,b);
    if(b==0) return a;
    if(a%b==0) return b;
    else return gcd(b,a%b);
}

ll datas[200300];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0; i<n; i++) cin>>datas[i];
        ll sum=0, left=0, right;
        for(int i=0; i<n; i++) sum+=datas[i];
        ll res=0;
        for(int i=0; i<n-1; i++){
            left+=datas[i];
            right=sum-left;
            res=max(res,gcd(left,right));
        } 
        cout<<res<<endl;
    }
    return 0;
}