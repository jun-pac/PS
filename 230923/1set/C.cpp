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

ll datas[1004];
ll sum[1004];


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        ll n, k, mx=0;
        cin>>n>>k;
        for(int i=0; i<n; i++){
            cin>>datas[i];
            sum[i]=(i==0?0:sum[i-1])+i+datas[i];
        }
        for(int i=0; i<n; i++){
            ll temp=datas[i];
            for(int j=i; j<n; j++) temp=max(temp,datas[j]+j-i);
            ll l=datas[i], r=temp;
            while(l<r){
                ll mid=(l+r+1)>>1;
                ll sum_temp=0;
                ll cur=mid;
                for(int j=i; j<n; j++){
                    if(cur<=datas[j]) break;
                    sum_temp+=cur-datas[j];
                    cur--;
                }
                if(sum_temp<=k) l=mid;
                else r=mid-1;
            }
            //cout<<"debug "<<i<<' '<<l<<endl;
            mx=max(mx,l);
        }
        cout<<mx<<endl;
    }
    return 0;
}