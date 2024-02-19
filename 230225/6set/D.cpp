// 
//./D<test

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

ll pos[10000], r_pos[10000];
ll tpow[10000];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    tpow[0]=1;
    for(int i=1; i<3002; i++){
        tpow[i]=(tpow[i-1]*2)%MOD;
    }
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>pos[i];
        r_pos[n-1-i]=-pos[i];
    }
    ll res=0;
    for(int l=0; l<n; l++){
        for(int r=l+1; r<n; r++){
            ll d, left_num, right_num;
            d=pos[r]-pos[l];
            left_num=n-(upper_bound(r_pos,r_pos+n,-(pos[l]-d))-r_pos); //pos[l]-d보다 작은 점의 개수
            right_num=n-(lower_bound(pos,pos+n,pos[r]+d)-pos); //pos[r]+d이상인 점의 개수
            //cout<<"less than "<<pos[l]-d<<" : "<<left_num<<endl;
            //cout<<"goreq than "<<pos[r]+d<<" : "<<right_num<<endl;
            //cout<<"temp sum : "<<((tpow[left_num+1]-1)*(tpow[right_num+1]-1))%MOD<<"\n\n";
            res=(res+((tpow[left_num])*(tpow[right_num])))%MOD;
        }
    }
    cout<<res<<endl;
    return 0;
}