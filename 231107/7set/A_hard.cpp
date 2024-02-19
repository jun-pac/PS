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

int oria[100010], aa[100010], bb[100010];

ll solve(int a0, int n){
    for(int i=0; i<n-1; i++) aa[i+1]=oria[i+1];
    aa[0]=a0;
    sort(aa,aa+n);
    sort(bb,bb+n);

    int l=0, r=n;
    while(l<r){
        int mid=(l+r+1)/2;
        bool flag=true;
        for(int i=0; i<mid; i++){
            if(aa[i]>=bb[n-mid+i]){
                flag=false;
                break;
            }
        }
        if(!flag) r=mid-1;
        else l=mid;
    }
    return n-l;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        for(int i=0; i<n-1; i++) cin>>oria[i+1];
        for(int i=0; i<n; i++) cin>>bb[i];
        ll fans=solve(1,n);
        ll l=2, r=m;
        if(solve(m,n)!=fans){
            while(l!=r){
                int mid=(l+r)/2;
                if(solve(mid,n)==fans) l=mid+1;
                else r=mid;
            }
            cout<<fans*m+m-r+1<<endl;
        }
        else cout<<fans*m<<endl;
    }
    return 0;
}