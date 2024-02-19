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

string s;
ll ans[300030];
ll non_zero[300030];

#define MOD 998244353
#define MAX_DIGIT 62

// Remember (ak)*(bk)^(-1) === a*b^(-1) === (ak%P)*(bk%P)^(-1) (mod P)
long long ari_inv(long long num){
    // Calculate num^(MOD-2)
    long long res=1, mult=num;
    for(int i=0; i<MAX_DIGIT; i++){
        if((MOD-2)&(1LL<<i)){
            res=(res*mult)%MOD;
        }
        mult=(mult*mult)%MOD;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    cin>>s;
    int idx;
    char c;
    // ans[0]贸府
    ll res=1;
    for(int i=1; i<n-1; i++){
        if(s[i]=='?') res=res*(i)%MOD;
    }
    non_zero[0]=res;
    if(s[0]=='?') ans[0]=0;
    else ans[0]=non_zero[0];
    
    for(int i=0; i<m; i++){
        cin>>idx>>c;
        idx--;
        char last=s[idx];
        s[idx]=c;

        // ans[i+1]贸府
        if(idx==0) non_zero[i+1]=non_zero[i];
        else{
            non_zero[i+1]=non_zero[i];
            if(last=='?') non_zero[i+1]=non_zero[i+1]*ari_inv(idx)%MOD;
            if(s[idx]=='?') non_zero[i+1]=non_zero[i+1]*(idx)%MOD;
        }
        if(s[0]=='?'){
            //cout<<i<<' '<<"sd"<<endl;
            ans[i+1]=0;
        }
        else{
            //cout<<i<<' '<<"de"<<endl;
            ans[i+1]=non_zero[i+1];
        }
    }
    for(int i=0; i<m+1; i++) cout<<(ans[i]+MOD)%MOD<<endl; 

    return 0;
}