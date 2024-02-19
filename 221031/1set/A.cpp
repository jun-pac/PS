// 
//./A<test.txt

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
        int n,res=0;
        cin>>n;
        if(n>=3){
            res+=(n-3)/3;
            n=n-res*3;
        }
        if(n==1) res+=2;
        if(n==2) res+=1;
        if(n==3) res+=1;
        if(n==4) res+=2;
        if(n==5) res+=2;
        cout<<res<<endl;
    }
    return 0;
}