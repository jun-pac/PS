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

ll a[200], b[200];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,m,k;
        cin>>n>>m>>k;
        for(int i=0; i<n; i++) cin>>a[i];
        for(int i=0; i<m; i++) cin>>b[i];
        ll last_mn=-1, last_mx=-1;
        for(int i=0; i<k; i++){
            sort(a,a+n);
            sort(b,b+m);
            if(i%2==0){
                ll mn=a[0], mx=b[m-1];
                if(a[0]<b[m-1]) swap(a[0],b[m-1]);
                else{
                    mn=-2, mx=-2;
                }
                if(mn==last_mn && mx==last_mx && k%2!=i%2){
                    break;
                }
                last_mn=mn, last_mx=mx;
            }    
            else{
                ll mn=b[0], mx=a[n-1];
                if(mn<mx) swap(b[0],a[n-1]);
                else{
                    mn=-2, mx=-2;
                }
                if(mn==last_mn && mx==last_mx && k%2!=i%2){
                    break;
                }
                last_mn=mn, last_mx=mx;   
            }
        }
        ll sum=0;
        for(int i=0; i<n; i++) sum+=a[i];
        cout<<sum<<endl;
    }
    return 0;
}