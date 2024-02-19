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

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        bool flag=false;
        for(int i=0; i<=n; i++){
            if(i*(i-1) + (n-i)*(n-i-1) == 2*k){
                cout<<"YES"<<endl;
                for(int j=0; j<i; j++) cout<<1<<' ';
                for(int j=0; j<n-i; j++) cout<<-1<<' ';
                cout<<endl;
                flag=true;
                break;
            }
        }
        if(!flag) cout<<"NO"<<endl;
    }
    return 0;
}