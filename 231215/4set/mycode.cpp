#include <iostream>
using namespace std;
#define rng(i,a,b) for(int i=int(a);i<=int(b);i++)
#define rep(i,b) rng(i,0,b-1)
#define gnr(i,b,a) for(int i=int(b);i>=int(a);i--)
#define per(i,b) gnr(i,b-1,0)

typedef long long ll;
 

#define INF (1e16)

inline ll get_error(int l, int r, ll* sum){
   int mid=(l+r)>>1;
   if((r-l+1)%2==0) return sum[r]-2*sum[mid]+(l==0?0:sum[l-1]);
   else return sum[r]-sum[mid]-(mid==0?0:sum[mid-1])+(l==0?0:sum[l-1]);
}

void Solve(){
   int n,g; // 각각 원소의 개수, 그룹의 개수
   cin>>n>>g; 
   int* scores = new int[n];
   ll** DP = new ll*[g];
    for(int i = 0; i < g; i++) DP[i] = new ll[n];
    ll* sum = new ll[n];
    rng(i,0,n-1) cin>>scores[i];
    rng(i,0,n-1){
            int mn=scores[i], mnidx=i;
            rng(j,i+1,n-1) if(scores[j]<mn) mn=scores[j], mnidx=j;
            swap(scores[i],scores[mnidx]);
    }
    rng(i,0,n-1) sum[i]=(i==0?0:sum[i-1])+scores[i];

    rng(j,0,n-1) DP[0][j]=get_error(0,j,sum);
    rng(i,1,g-1){
        rng(j,i,n-1){
            ll mn=INF;
            rng(k,i,j){
                mn=min(mn,DP[i-1][k-1]+get_error(k,j,sum));
            }
            DP[i][j]=mn;
            // DP[i][j]=max{DP[i-1][j-1]+geterror(j,j), ... DP[i-1][i-1]+geterror(i,j)}
        }
    }
   cout<<"Minimum error = "<<DP[g-1][n-1]<<'\n';
}

int main(){
   ios_base::sync_with_stdio(false); cin.tie(NULL);
    int TC=1;
    while(TC--){
        Solve();
    }
}