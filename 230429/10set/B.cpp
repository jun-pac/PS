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

int gcd(int x, int y){
    if(x<y) swap(x,y);
    if(y==0) return x;
    if(x%y==0) return y;
    return gcd(y,x%y);
}

int datas[200200];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        for(int i=0; i<n; i++){
            cin>>datas[i];
        }
        int r=k;// gcd(n,k); // 이게 1이면 모든 쌍이 가능한 것 
        //cout<<"R "<<r<<endl;
        int cnt=0;
        for(int i=0; i<n; i++){
            if(datas[i]%r!=(i+1)%r) cnt++;
        }
        if(cnt==0) cout<<0<<endl;
        else if(cnt<=2) cout<<1<<endl;
        else cout<<-1<<endl;
    }
    return 0;
}