
#include <bits/stdc++.h>
using namespace std;
#define rng(i,a,b) for(int i=int(a);i<=int(b);i++)
typedef long long ll;
#define MOD 998244353

ll DP[2501][2501];

void Solve(){    
    int n,k;
    cin>>n>>k;
    rng(tot,1,n){
        rng(last,0,min(tot-1,k-1)){
            ll res=0;
            rng(u,0,k-1-last){
                int temp=(last+1)*(u+1);
                if(tot>temp) res=(res+DP[tot-temp][u])%MOD;
                else if(tot==temp) res++;
                else break;
            }
            DP[tot][last]=res%MOD;
        }
    }
    ll res=0;
    rng(last,0,min(n-1,k-1)) res=(res+DP[n][last])%MOD;
    cout<<(res+MOD)%MOD<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--){
        Solve();
    }
    return 0;
}

