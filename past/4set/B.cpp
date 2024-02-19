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
        int n,a,mmx=1000000007,jmx=1000000007;
        int midx,jidx;
        cin>>n;
        bool flag=false;
        for(int i=0; i<n; i++){
            cin>>a;
            if(i%2==0 && a<mmx){
                mmx=a;
                midx=i;
            }
            else if(i%2==1 && a<jmx){
                jmx=a;
                jidx=i;
            }
        }
        if(n%2==1){
            cout<<"Mike"<<endl;
        }
        else{
            if(mmx>jmx) cout<<"Mike"<<endl;
            else if(jmx>mmx) cout<<"Joe"<<endl;
            else{
                if(midx>jidx) cout<<"Mike"<<endl;
                else cout<<"Joe"<<endl;
            }
        }
    }    
    return 0;
}