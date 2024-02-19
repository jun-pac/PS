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
        int n,k;
        cin>>n>>k;
        if(k%2==1){
            cout<<"YES"<<endl;
            for(int i=0; i<n/2; i++) cout<<2*i+1<<' '<<2*i+2<<endl;
        }
        else if(k%4==2){
            cout<<"YES"<<endl;
            for(int i=0; i<n/2; i++){
                if(i%2==0) cout<<2*i+2<<' '<<2*i+1<<endl;
                else cout<<2*i+1<<' '<<2*i+2<<endl;
            }
        }
        else cout<<"NO"<<endl;
    }
    return 0;
}