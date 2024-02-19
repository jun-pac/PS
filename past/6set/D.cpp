// 
//./D<test.txt

#include <bits/stdc++.h>
//#define endl '\n'
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
        int l=0, r=n-1;
        while(l!=r){
            int mid=(l+r)>>1;
            cout<<"? "<<l+1<<' '<<mid+1<<endl;
            int a, cnt=0;
            for(int i=l; i<=mid; i++){
                cin>>a;
                if(l+1<=a && a<=mid+1) cnt++;
            }
            if(cnt%2==1) r=mid;
            else l=mid+1;
        }
        cout<<"! "<<l+1<<endl;
    }
    return 0;
}