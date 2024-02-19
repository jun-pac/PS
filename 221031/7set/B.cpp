// 
//./B<test.txt

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

ll a[200000], b[200000];
ll bigside[200000];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        ll res=0;
        ll ssum=0;
        for(int i=0; i<n; i++){
            cin>>a[i]>>b[i];
            ssum+=a[i]+b[i];
            bigside[i]=max(a[i],b[i]);
        }
        ssum*=2;
        sort(bigside, bigside+n);
        for(int i=0; i<n-1; i++){
            ssum-=2*bigside[i];
        }
        cout<<ssum<<endl;
    }
    return 0;
}