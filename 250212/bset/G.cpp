
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define cediv(a,b) ((a)%(b)==0?((a)/(b)):((a)/(b))+1)
#define rng(i,a,b) for(int i=int(a);i<=int(b);i++)
#define rep(i,b) rng(i,0,b-1)  
#define gnr(i,b,a) for(int i=int(b);i>=int(a);i--)
#define per(i,b) gnr(i,b-1,0)
#define pb push_back
#define eb emplace_back
#define bg begin()
#define ed end()
#define all(x) x.bg,x.ed
#define si(x) int(x.size())
template<class t> using vc=vector<t>;
template<class t> using vvc=vc<vc<t>>;
typedef long long ll;
using pii=pair<int,int>;
using vi=vc<int>;
using uint=unsigned;
using ull=unsigned long long;
using pil=pair<int,ll>;
using pli=pair<ll,int>;
using pll=pair<ll,ll>;
using t3=tuple<int,int,int>;

#define N 300030
#define MOD 998244353
#define INF 1000000007 

ll DP[110][11][11]; // 가장 앞 위치, 개수임. 사실 DP에는 위치만 중요함.
string s;
ll close_pos[11][26];

void Solve(){
    int n,m;
    cin>>n>>m;
    cin>>s;
    rng(i,0,n-1){
        rng(j,0,25){
            close_pos[i][j]=n; // 없으면 n
            rng(ii,i,n-1){
                if(s[ii]==j+'a'){
                    close_pos[i][j]=ii;
                    break;
                }
            }
        }
    }
    rng(j,0,25){
        if(close_pos[0][j]==n) DP[0][0][0]+=1;
        else DP[0][close_pos[0][j]][1]+=1;
    }
    
    rng(i,1,m-1){
        rng(j,0,n){
            rng(k,0,25){

            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    // cin>>t;
    while(t--){
        Solve();
    }
    return 0;
}

