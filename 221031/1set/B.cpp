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
        cout<<n<<endl;
        for(int i=0; i<n; i++){
            if(i==0) for(int j=0; j<n; j++) cout<<j+1<<' ';
            else if(i==1){
                cout<<2<<' '<<1<<' ';
                for(int j=2; j<n; j++) cout<<j+1<<' ';
            }
            else{
                for(int j=0; j<i; j++) cout<<j+2<<' ';
                cout<<1<<' ';
                for(int j=i+1; j<n; j++) cout<<j+1<<' ';
            }
            cout<<endl;
        }
    }
    return 0;
}