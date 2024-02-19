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

ll datas[200000];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        ll sum=0;
        ll mx=-1, mx_idx=-1;
        for(int i=0; i<n; i++){
            cin>>datas[i];
            if(mx<datas[i]){
                mx=datas[i];
                mx_idx=i;
            }
        }
        if(n==2){
            sum=max(datas[0]+datas[1], 2*abs(datas[0]-datas[1]));
        }
        else if(mx_idx==1 && n-1-mx_idx==1){
            sum=max(3*datas[0], 3*datas[2]);
            sum=max(sum, 3*abs(datas[0]-abs(datas[1]-datas[2])));
            sum=max(sum, 3*abs(datas[2]-abs(datas[1]-datas[0])));
            sum=max(sum, 3*abs(datas[2]-datas[0]));
            sum=max(sum, datas[0]+datas[1]+datas[2]);
            sum=max(sum, datas[0]+2*abs(datas[1]-datas[2]));
            sum=max(sum, datas[2]+2*abs(datas[1]-datas[0]));
            sum=max(sum, 2*abs(datas[0]-abs(datas[1]-datas[2]))+abs(datas[1]-datas[2]));
            sum=max(sum, 3*(abs(datas[0]-abs(datas[1]-datas[2]))-abs(datas[1]-datas[2])));
            sum=max(sum, 2*abs(datas[2]-abs(datas[1]-datas[0]))+abs(datas[1]-datas[0]));
            sum=max(sum, 3*(abs(datas[2]-abs(datas[1]-datas[0]))-abs(datas[1]-datas[0])));
        }
        else{
            sum=mx*n;
        }
        cout<<sum<<endl;
    }
    return 0;
}