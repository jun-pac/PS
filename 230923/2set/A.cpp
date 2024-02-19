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

int datas[2000];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,mx=0,mn=1000000007;
        cin>>n;
        for(int i=0; i<n; i++){
            cin>>datas[i];
            mx=max(mx,datas[i]);
            mn=min(mn,datas[i]);
        }
        if(mx==mn) cout<<-1<<endl;
        else{
            int cnt=0;
            for(int i=0; i<n; i++) if(datas[i]==mx) cnt++;
            cout<<n-cnt<<' '<<cnt<<endl;
            for(int i=0; i<n; i++) if(datas[i]!=mx) cout<<datas[i]<<' ';
            cout<<endl;
            for(int i=0; i<n; i++) if(datas[i]==mx) cout<<datas[i]<<' ';
            cout<<endl;
        }
    }
    return 0;
}