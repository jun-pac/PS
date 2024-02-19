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

#define MOD 998244353;
int divs[1000010]; // 약수의 개수
ll ssum;
ll DP[1000010];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin>>n;
    fill(divs,divs+n+1,1);
    for(int i=2; i<=n; i++){
        for(int j=1; i*j<=n; j++) divs[i*j]++;
    }
    DP[1]=1;
    ssum=1;
    for(int i=2; i<=n; i++){
        DP[i]=(ssum+divs[i])%MOD;
        ssum=(ssum+DP[i])%MOD;
    }
    cout<<DP[n]<<endl;
    return 0;
}