// 
//./C<test

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

pair<ll,ll> datas[1000010];
int a[1000010];
int b[1000010];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        ll n, sa, sb;
        cin>>n>>sa>>sb;
        ll aa;
        for(int i=0; i<n; i++){
            cin>>aa;
            datas[i]={aa,i};
        }
        sort(datas,datas+n);
        reverse(datas,datas+n);
        ll na=0, nb=0;
        for(int i=0; i<n; i++){
            if(sa*(na+1)<sb*(nb+1)){
                a[na++]=datas[i].se+1;
            }
            else{
                b[nb++]=datas[i].se+1;
            }
        }
        cout<<na<<' ';
        for(int i=0; i<na; i++) cout<<a[i]<<' ';
        cout<<endl;
        cout<<nb<<' ';
        for(int i=0; i<nb; i++) cout<<b[i]<<' ';
        cout<<endl;
    }
    return 0;
}