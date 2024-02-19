// 
//./D<test

#include <bits/stdc++.h>
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

int solve(int l, int r){
    if(l==r) return l;
    if(l+1==r){
        cout<<"? "<<l+1<<' '<<r+1<<endl;
        int res;
        cin>>res;
        if(res==1) return l;
        else return r;
    }
    int mid=(l+r)>>1;
    int lmx=solve(l,mid);
    int rmx=solve(mid+1,r);
    cout<<"? "<<l+1<<' '<<rmx<<endl;
    int res1, res2;
    cin>>res1;
    cout<<"? "<<l+1<<' '<<rmx+1<<endl;
    cin>>res2;
    if(res2==res1) return rmx;
    else return lmx;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int res=solve(0,n-1);
        cout<<"! "<<res+1<<endl;
    }
    return 0;
}