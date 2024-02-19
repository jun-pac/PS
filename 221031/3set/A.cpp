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

int datas[10000];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int k;
    cin>>k;
    while(k--){
        int n;
        cin>>n;
        for(int i=0; i<n; i++) cin>>datas[i];
        int res=datas[n-1]-datas[0];
        for(int i=0; i<n-1; i++) umax(res,datas[i]-datas[i+1]);
        int l_min=datas[0];
        for(int i=0; i<n-1; i++) umin(l_min,datas[i]);
        int r_max=datas[n-1];
        for(int i=1; i<n; i++) umax(r_max,datas[i]);
        umax(res,datas[n-1]-l_min);
        umax(res,r_max-datas[0]);
        cout<<res<<endl;
    }
    return 0;
}