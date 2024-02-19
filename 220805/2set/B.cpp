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

int datas[200020];
ll ssum[200020];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        for(int i=0; i<n; i++) cin>>datas[i];
        sort(datas,datas+n);
        for(int i=0; i<n; i++) ssum[i]=(i==0?datas[i]:datas[i]+ssum[i-1]);
        
        ll mx=0;
        for(int i=0; i<=k; i++){
            // i는 앞에서 제거하는 개수
            mx=max(mx,ssum[n-1-(k-i)]-(k==0?0:ssum[2*i-1]));
            //cout<<"debug : "<<i<<' '<<ssum[n-1-(k-i)]<<' '<<(k==0?0:ssum[2*k-1])<<endl;
        }
        cout<<mx<<endl;
    }
    return 0;
}