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

ll datas[1000];
ll MOD=1000000007;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        ll amul=1;
        ll mul=1;
        for(int i=0; i<n; i++){
            cin>>datas[i];
        }
        for(int i=0; i<n; i++){
            amul=(amul*datas[i])%MOD;
        }
        bool flag=false;
        for(int i=0; i<n; i++){
            mul=(mul*datas[i])%MOD;
            if((mul*mul)%MOD==amul){
                cout<<i+1<<endl;
                flag=true;
                break;
            }
        }
        if(!flag) cout<<-1<<endl;
    }
    return 0;
}