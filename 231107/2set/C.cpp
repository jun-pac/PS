// 
//./C<test

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

ll datas[200010], sum[200010];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0; i<n; i++) cin>>datas[i];
        for(int i=0; i<n; i++) sum[i]=(i==0?0:sum[i-1])+(datas[i]>0?datas[i]:0);
        ll res=0; 
        int cur=0;
        for(cur=0; cur<n; cur++){
            if(cur%2==0 && datas[cur]>0) break;
        }
        res=sum[n-1]-(cur==0?0:sum[cur-1]);
        ll mx=0;
        if(cur!=0 && n>=2) mx=max(mx,sum[cur-1]-(datas[1]>0?datas[1]:0));
        for(int i=0; i<cur; i+=2){
            mx=max(mx,datas[i]+sum[cur-1]-sum[i]);
        }
        cout<<res+mx<<endl;
    }
    return 0;
}