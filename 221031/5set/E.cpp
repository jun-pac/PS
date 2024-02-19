// 
//./E<test.txt

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

int prime[100010];
bool pt[100010];

ll GCD(ll a, ll b){
    if(a<b) swap(a,b);
    if(a%b==0) return b;
    else return GCD(b,a%b);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        ll a,b,c,d,num;
        cin>>a>>b>>c>>d;
        num=a*b;
        bool flag=false;
        for(int i=a+1; i<=c; i++){
            ll r=num/GCD(num,i);
            if((b/r+1)*r<=d){
                flag=true;
                cout<<i<<' '<<(b/r+1)*r<<endl;
                break;
            }
        }
        if(!flag) cout<<-1<<' '<<-1<<endl;
    }
    return 0;
}