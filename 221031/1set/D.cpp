// 
//./D<test.txt

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

#define N 200001
ll MOD=998244353;
ll sums[N]; // mod kºÎºÐÇÕ
ll ans[N];
ll DP_e[N];
ll DP_o[N];

int main(){
    ll n,k;
    scanf("%lld %lld",&n,&k);
    ll ind=k;
    int cnt=0;
    DP_o[0]=1;
    // <= check
    while(ind<n){
        fill(sums,sums+k,0);
        if(cnt%2==0){
            // use DP_e
            for(int i=ind-k; i<=n-k; i++){
                int temp=i%k;
                sums[temp]=(sums[temp]+DP_o[i])%MOD;
                DP_e[i+k]=sums[temp];
            }
            DP_o[0]=0;
            for(int i=ind; i<=n; i++) ans[i]=(ans[i]+DP_e[i])%MOD;
            //cout<<"cur "<<k<<" : ";
            //for(int i=0; i<=n; i++) cout<<DP_e[i]<<' ';
            //cout<<endl;
        }
        else{
            for(int i=ind-k; i<=n-k; i++){
                int temp=i%k;
                sums[temp]=(sums[temp]+DP_e[i])%MOD;
                DP_o[i+k]=sums[temp];
            }
            for(int i=ind; i<=n; i++) ans[i]=(ans[i]+DP_o[i])%MOD;
            //cout<<"cur "<<k<<" : ";
            //for(int i=0; i<=n; i++) cout<<DP_o[i]<<' ';
            //cout<<endl;
        }
        k++;
        cnt++;
        ind=ind+k;
    }
    for(int i=1; i<=n; i++) printf("%lld ",ans[i]);
    return 0;
}