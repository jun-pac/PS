
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define cediv(a,b) ((a)%(b)==0?((a)/(b)):((a)/(b))+1)
#define rng(i,a,b) for(int i=int(a);i<=int(b);i++)
#define gnr(i,b,a) for(int i=int(b);i>=int(a);i--)
typedef long long ll;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

#define N 300030
#define MOD 998244353
#define INF 1000000007 

string x[100], y[100], z[100];
// (i,j,k)가 있으면, x[i][j], y[j][k], z[k][i]에 나타난다고 WLOG생각할 수 있을 듯

void Solve(int tt){
    int n;
    cin>>n;
    // 사실 지금 불가능한 경우는 1이 있는데, 
    // 반드시 0이어야 할 부분을 전부 1로 체크하고, 근데 어떤 1은 전부 1인 아이들을 지난다.    
    rng(i,0,n-1) cin>>x[i];
    rng(i,0,n-1) cin>>y[i];
    rng(i,0,n-1) cin>>z[i];
    rng(i,0,n-1) rng(j,i+1,n-1) swap(x[i][j],x[j][i]);
    rng(i,0,n-1) rng(j,i+1,n-1) swap(y[i][j],y[j][i]);
    rng(i,0,n-1) rng(j,i+1,n-1) swap(z[i][j],z[j][i]);
    rng(i,0,n/2-1) swap(x[i],x[n-1-i]);
    rng(i,0,n/2-1) swap(y[i],y[n-1-i]);
    rng(i,0,n/2-1) swap(z[i],z[n-1-i]);


    rng(i,0,n-1){
        rng(j,0,n-1){
            if(x[i][j]=='0') continue;
            bool flag=0;
            rng(k,0,n-1){
                if(y[j][k]!='0' && z[k][i]!='0'){
                    flag=1;
                    break;
                }
            }
            if(!flag){
                cout<<"No\n";
                return;
            }
        }
    }
    rng(j,0,n-1){
        rng(k,0,n-1){
            if(y[j][k]=='0') continue;
            bool flag=0;
            rng(i,0,n-1){
                if(x[i][j]!='0' && z[k][i]!='0'){
                    flag=1;
                    break;
                }
            }
            if(!flag){
                cout<<"No\n";
                return;
            }
        }
    }
    rng(k,0,n-1){
        rng(i,0,n-1){
            if(z[k][i]=='0') continue;
            bool flag=0;
            rng(j,0,n-1){
                if(y[j][k]!='0' && x[i][j]!='0'){
                    flag=1;
                    break;
                }
            }
            if(!flag){
                cout<<"No\n";
                return;
            }
        }
    }
    cout<<"Yes\n";
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    // cin>>t;
    rng(tt,0,t-1){
        Solve(tt);
    }
    return 0;
}

