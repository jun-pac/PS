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

#define N 100010
int a[N], b[N], c[N];


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n>>x;
        for(int i=0; i<n; i++) cin>>a[i];
        for(int i=0; i<n; i++) cin>>b[i];
        for(int i=0; i<n; i++) cin>>c[i];
        int res=0;
        //bool flag=false;
        //if(res==x) flag=true;
        for(int i=0; i<n; i++){
            if((res|a[i])-((res|a[i])&x)!=0) break;
            res=(res|a[i]);
        }
        //cout<<"a fin "<<res<<endl;
        for(int i=0; i<n; i++){
            if((res|b[i])-((res|b[i])&x)!=0) break;
            res=(res|b[i]);
        }
        //cout<<"b fin "<<res<<endl;
        for(int i=0; i<n; i++){
            if((res|c[i])-((res|c[i])&x)!=0) break;
            res=(res|c[i]);
        }
        //cout<<res<<endl;
        if(res==x) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}