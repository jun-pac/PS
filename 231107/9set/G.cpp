// 
//./E<test

#include <bits/stdc++.h>
#define endl '\n'
#define cediv(a,b) ((a)%(b)==0?((a)/(b)):((a)/(b))+1)
#define fi first
#define se second
#define pb push_back


using namespace std;
using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;

template<typename T>
inline T umax(T &u, T v){return u = max(u, v);}
template<typename T>
inline T umin(T &u, T v){return u = min(u, v);}


const int MAXN = 1020000;
const ll inf = 1000000000000; 
ll  arr[MAXN]; 

int f(int l, int r, ll m, ll M){
    if(l>r) return 0; 
    if(l==r){
        return arr[l]>=m && arr[l]<=M;
    }
    int mid = (l+r)>>1; 
    int add_  = 0; 
    if(arr[mid]>=m && arr[mid]<=M) add_ =  1; 
    return add_ + f(mid+1,r,max(m,(ll)arr[mid]),M) + f(l,mid-1,m,min(M,(ll)arr[mid]));  
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    ll n,m,a,c,x0; 
    cin >> n >> m >> a >> c >> x0; 
    //printf("1");
    arr[0] = x0; 
    // ax + c(mod m) 
    for(int i=1;i<=n;i++) {
        ll  t =  (a*arr[i-1] + c)%m; 
        arr[i] = t;
        //cout << arr[i];
    }
    cout << f(1,n,-1,inf); 

    return 0;
}