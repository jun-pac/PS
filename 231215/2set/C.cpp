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
        int n,m,k;
        cin>>n>>m>>k;
        if(k<n+m-2) cout<<"NO"<<'\n';
        else if(k%2!=(n+m)%2) cout<<"NO"<<'\n';
        else if(n==1 || m==1){
            if(k!=max(n-1,m-1)) cout<<"NO"<<'\n';
            else if(n==1){
                cout<<"YES"<<'\n';
                for(int j=0; j<m-1; j++) cout<<(j%2==0?'R':'B')<<' ';
                cout<<'\n';
            }
            else{
                cout<<"YES"<<'\n';
                for(int i=0; i<n-1; i++) cout<<(i%2==0?'R':'B')<<'\n';
            }
        }
        else{
            if((k-(n-1+m-1))%4==2){
                if(n==2 && m==2){
                    cout<<"NO"<<'\n';
                }
                else if(m==2){
                    cout<<"YES"<<'\n';
                    for(int i=0; i<n; i++){
                        for(int j=0; j<m-1; j++){
                            if(j==0 && i<=1) cout<<'R'<<' ';
                            else cout<<((j+n)%2==0?'B':'R')<<' ';
                        }
                        cout<<'\n';
                    }
                    for(int i=0; i<n-1; i++){
                        for(int j=0; j<m; j++){
                            if(j==1 && i==0) cout<<'B'<<' ';
                            else cout<<(i%2==0?'R':'B')<<' ';
                        }
                        cout<<'\n';
                    }
                }
                else{
                    cout<<"YES"<<'\n';
                    for(int i=0; i<n; i++){
                        for(int j=0; j<m-1; j++){
                            if(i==1 && j==0) cout<<'B'<<' ';
                            else cout<<(j%2==0?'R':'B')<<' ';
                        }
                        cout<<'\n';
                    }
                    for(int i=0; i<n-1; i++){
                        for(int j=0; j<m; j++){
                            if(i==0 && j<=1) cout<<'R'<<' ';
                            else cout<<((i+m)%2==0?'B':'R')<<' ';
                        }
                        cout<<'\n';
                    }
                }
            }
            else{
                cout<<"YES"<<'\n';
                for(int i=0; i<n; i++){
                    for(int j=0; j<m-1; j++){
                        cout<<(j%2==0?'R':'B')<<' ';
                    }
                    cout<<'\n';
                }
                for(int i=0; i<n-1; i++){
                    for(int j=0; j<m; j++){
                        cout<<(j==m-1?((i+m)%2==0?'B':'R'):'B')<<' ';
                    }
                    cout<<'\n';
                }
            }
        }
    }
    return 0;
}