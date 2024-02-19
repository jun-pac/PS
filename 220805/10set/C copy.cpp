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

ll datas[100];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0; i<n; i++){
            cin>>datas[i];
        }
        ll mx=abs(datas[0]), mx_idx=0;
        for(int i=0; i<n; i++){
            if(mx<abs(datas[i])){
                mx_idx=i;
                mx=abs(datas[i]);
            }
        }
        if(n==1) cout<<0<<endl;
        else if(mx==0) cout<<0<<endl;
        else if(datas[mx_idx]>0){
            cout<<2*n-1<<endl;
            cout<<n<<' '<<mx_idx+1<<endl;
            cout<<n<<' '<<mx_idx+1<<endl;
            cout<<n<<' '<<n<<endl;
            for(int i=1; i<n-1; i++){
                cout<<i+1<<' '<<n<<endl;
                cout<<n<<' '<<n<<endl;
            }
        }
        else{
            cout<<2*n-1<<endl;
            cout<<1<<' '<<mx_idx+1<<endl;
            cout<<1<<' '<<mx_idx+1<<endl;
            cout<<1<<' '<<1<<endl;
            for(int i=n-2; i>0; i--){
                cout<<i+1<<' '<<1<<endl;
                cout<<1<<' '<<1<<endl;
            }
        }
    }
    return 0;
}