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

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        if(m==1) cout<<0<<endl;
        else cout<<min(n+1,m)<<endl;

        if(n>=m-1){
            for(int i=0; i<m-1; i++){
                for(int j=0; j<i+1; j++) cout<<m-i-1+j<<' ';
                for(int j=i+1; j<m; j++) cout<<j-i-1<<' ';
                cout<<endl;
            }
            for(int i=m-1; i<n; i++){
                for(int j=0; j<m-1; j++) cout<<j+1<<' '; cout<<0<<endl;
            }
        }
        else{
            for(int i=0; i<n; i++){
                for(int j=0; j<i+1; j++) cout<<n-i+j<<' ';
                for(int j=i+1; j<n+1; j++) cout<<j-i-1<<' ';
                for(int j=n+1; j<m; j++) cout<<j<<' ';
                cout<<endl;
            }            
        }
    }
    return 0;
}