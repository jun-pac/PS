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

ll yak[100000];
ll prime[10];
ll cnt[10];

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
        // 2 3 5 7 11 13 17 19 23 29
        // yak Ã¤¿ì±â
        int cc=0;
        sort(yak,yak+cc);
        reverse(yak,yak+cc);
        ll dev=-1;
        while(int i=0; i<cc; i++){
            if((a/yak[i]+1)*yak[i]<=c){
                dev=(a/yak[i]+1)*yak[i];
                break;
            }
        }
        bool flag=false;
        
        ll r=num/GCD(num,dev);
        if((b/r+1)*r<=d){
            flag=true;
            cout<<dev<<' '<<(b/r+1)*r<<endl;
        }
        if(!flag) cout<<-1<<' '<<-1<<endl;
    }
    return 0;
}