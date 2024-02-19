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

int A[200020], B[200020];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        for(int i=0; i<n; i++) cin>>A[i];
        for(int i=0; i<m; i++) cin>>B[i];
        int res1=A[0], res2=B[0], mn, mx;
        for(int i=1; i<n; i++) res1=res1^A[i];
        for(int i=1; i<m; i++) res2=res2|B[i];
        if(n%2==0){
            mx=res1;
            res1=A[0]|res2;
            for(int i=1; i<n; i++) res1=res1^(A[i]|res2);
            mn=res1;
            cout<<mn<<' '<<mx<<endl;
        }
        else{
            cout<<res1<<' '<<(res1|res2)<<endl;
        }
    }
    return 0;
}