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

int a[100], b[100];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        ll sum=0;
        for(int i=0; i<n; i++){
            cin>>a[i];
            sum+=a[i];
        }   
        for(int i=0; i<m; i++){
            cin>>b[i];
            int mn=1000000007;
            int mn_idx;
            for(int j=0; j<n; j++){
                if(a[j]<mn){
                    mn=a[j];
                    mn_idx=j;
                }
            }
            sum+=(b[i]-mn);
            a[mn_idx]=b[i];
        }
        cout<<sum<<endl;
    }
    return 0;
}