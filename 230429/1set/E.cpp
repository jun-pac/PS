// 
//./E<test

#include <bits/stdc++.h>
//#define endl '\n'
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

ll datas[200003], ssum[200003];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0; i<n; i++) cin>>datas[i];
        for(int i=0; i<n; i++) ssum[i]=(i==0?datas[i]:datas[i]+ssum[i-1]);

        ll l=1, r=n, res;
        while(l<r){
            int mid=(l+r)>>1;
            cout<<"? "<<mid-l+1<<' ';
            for(int i=l; i<=mid; i++) cout<<i<<' ';
            cout<<endl;
            cin>>res;
            if(res==ssum[mid-1]-(l==1?0:ssum[l-1-1])){
                l=mid+1;
            }
            else{
                r=mid;
            }
        }
        cout<<"! "<<l<<endl;
    }
    return 0;
}