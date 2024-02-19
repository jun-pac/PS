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

ll a[200020];
ll b[200020];
ll mn[200020];
ll mx[200020];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0; i<n; i++) cin>>a[i];
        for(int i=0; i<n; i++) cin>>b[i];
        ll sum=0;
        for(int i=0; i<n; i++) sum+=abs(a[i]-b[i]);
        for(int i=0; i<n; i++){
            mn[i]=min(a[i],b[i]);
            mx[i]=max(a[i],b[i]);
        }
        sort(mn,mn+n);
        sort(mx,mx+n);
        if(mn[n-1]>mx[0]) cout<<sum+2*(mn[n-1]-mx[0])<<endl;
        else cout<<sum<<'\n';
    }
    return 0;
}