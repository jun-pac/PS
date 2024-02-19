// 
//./B<test.txt

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
        int n;
        cin>>n;
        if(n==1) cout<<1<<endl;
        else if(n==2) cout<<"1 2"<<endl;
        else if(n==3) cout<<"3 1 2"<<endl;
        else if(n%3==1){
            for(int i=0; i<n/3-1; i++){
                cout<<3*i+3<<' '<<3*i+2<<' '<<3*i+1<<' ';
            }
            cout<<3*(n/3-1)+2<<' '<<3*(n/3-1)+1<<' '<<n-1<<' '<<n<<endl;
        }
        else if(n%3==2){
            for(int i=0; i<n; i++) cout<<i+1<<' ';
            cout<<endl;
        }
        else{
            for(int i=0; i<n-4; i++) cout<<i+2<<' ';
            cout<<n-1<<' '<<1<<' '<<n-2<<' '<<n<<endl;
        }
    }
    return 0;
}