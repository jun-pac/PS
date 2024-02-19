// 
//./E<test

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

#define MOD 1000000007
ll datas[8196];
ll temp[3000];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin>>n;
    for(int i=0; i<n; i++) cin>>datas[i];
    ll res=0;
    sort(datas,datas+n);
    for(int i=0; i<n-1; i++){
        
        int l=0, r=0;
        int cnt=0;
        
        while(cnt<n-i){
            cout<<"B : "<<l<<' '<<r<<endl;
            if(l+1>=r) temp[cnt]=datas[l]+datas[++r];
            else if(r==n-i) temp[cnt]=datas[++l]+datas[r];
            else if(datas[l+1]-datas[l] > datas[r+1]-datas[r]) temp[cnt]=datas[l]+datas[++r];
            else temp[cnt]=datas[++l]+datas[r];
            cout<<"R : "<<l<<' '<<r<<endl;
            cnt++;
        }
        
        cout<<i<<" th stage"<<endl;
        for(int j=0; j<n-i; j++) cout<<temp[j]<<' ';
        cout<<endl;
        for(int j=0; j<n-i; j++) datas[j]=temp[j]%MOD;
    }
    cout<<datas[0]<<endl;
    return 0;
}