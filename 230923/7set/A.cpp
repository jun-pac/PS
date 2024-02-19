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

int datas[101];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0; i<n; i++) cin>>datas[i];
        if(n%2==0){
            cout<<2<<endl;
            cout<<1<<' '<<n<<endl;
            cout<<1<<' '<<n<<endl;
        }
        else{
            cout<<4<<endl;
            cout<<1<<' '<<n-1<<endl;
            cout<<1<<' '<<n-1<<endl;
            cout<<n-1<<' '<<n<<endl;
            cout<<n-1<<' '<<n<<endl;
        }
    }
    return 0;
}