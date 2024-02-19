// 
//./A<test

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
 

ll datas[120];
ll gcd(ll a, ll b){
    if(a>b) swap(a,b);
    if(b%a==0) return a;
    else return gcd(a,b%a);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        for(int i=0; i<n; i++){
            cin>>datas[i];
        }
        bool flag=false;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(gcd(datas[j],datas[i])<=2){
                    flag=true;
                    break;
                }
            }
            if(flag) break;
        }
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}