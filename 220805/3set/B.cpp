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


int datas[200020];

int gcd(int x, int y){
    if(x<y) swap(x,y);
    if(y==0) return x;
    if(x%y==0) return y;
    return gcd(y,x%y);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0; i<n; i++) cin>>datas[i];

        int res=datas[0]-1;
        bool nonzero=(res!=0?true:false);
        for(int i=1; i<n; i++){
            int cur=abs(datas[i]-i-1);
            //cout<<"das "<<cur<<endl;
            if(!nonzero && cur!=0){
                nonzero=true;
                res=cur;
            }
            if(nonzero && cur!=0) res=gcd(res,cur);
        }
        if(!nonzero) cout<<n-1<<endl;
        else cout<<res<<endl;

    }
    return 0;
}