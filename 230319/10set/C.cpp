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

ll datas[400009];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0; i<2*n; i++) cin>>datas[i];
        sort(datas,datas+2*n);
        ll sum=0, sum1=0, mx;
        for(int i=0; i<2*n; i++) sum1+=abs(datas[i]);
        if(n==1) cout<<datas[1]-datas[0]<<endl;
        else if(n==2){
            mx=sum1;
            ll temp=0;
            for(int i=0; i<2*n; i++) temp+=abs(datas[i]-2);
            mx=min(mx,temp);

            temp=0;
            for(int i=0; i<2*n; i++) temp+=abs(datas[i]+1);
            for(int i=0; i<2*n; i++) mx=min(mx,temp-abs(datas[i]+1)+abs(datas[i]-n));
            cout<<mx<<endl;
        }
        else if(n%2==0){
            mx=sum1;
            ll temp=0;
            for(int i=0; i<2*n; i++) temp+=abs(datas[i]+1);
            mx=min(mx,temp-abs(datas[2*n-1]+1)+abs(datas[2*n-1]-n));
            cout<<mx<<endl;
        }
        else cout<<sum1<<endl;
    }
    return 0;
}