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
        int n,m;
        cin>>n>>m;
        if(m%n==0){
            cout<<"YES"<<endl;
            for(int i=0;i<n;i++) cout<<m/n<<' ';
            cout<<endl;
        }
        else if(m<n) cout<<"NO"<<endl;
        else{
            if(n%2==0 && m%2==0){
                cout<<"YES"<<endl;
                for(int i=0;i<n-2;i++) cout<<1<<' ';
                cout<<1+(m-n)/2<<' '<<1+(m-n)/2<<endl;
            }
            else if(n%2==1){
                cout<<"YES"<<endl;
                for(int i=0;i<n-1;i++) cout<<1<<' ';
                cout<<1+(m-n)<<endl;
            }
            else cout<<"NO"<<endl;
        }
    }
    return 0;
}