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

ll datas[100000]; // i th color number

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        ll n,m,k;
        cin>>n>>m>>k;
        for(int i=0; i<m; i++) cin>>datas[i];
        //bool flag=true;
        if(k>m){
            cout<<"NO"<<endl;
            continue;
        }
        if(k==1){
            cout<<"YES"<<endl;
            continue;
        }
        sort(datas,datas+m);
        reverse(datas,datas+m);
        bool flag=true;
        for(int i=0; i<m; i++){
            if((datas[i]-1)*(k-i)+1>n) flag=false;
        }
        if(flag==false){
            cout<<"NO"<<endl;
            continue;
        }
        // somethifn

        cout<<"YES"<<endl;
    }
    return 0;
}