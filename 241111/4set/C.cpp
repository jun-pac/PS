
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

#define N 3030
#define MOD 998244353
#define INF 1000000007 

string mp[N];
char res[N][N];

void Solve(){
    int n;
    cin>>n;
    rng(i,0,n-1){
        cin>>mp[i];
    }
    rng(i,0,n-1){
        rng(j,0,n-1){
            int lev=min(min(i,n-1-i),min(j,n-1-j));
            if(lev%4==0){
                res[j][n-1-i]=mp[i][j];
            }
            else if(lev%4==1){
                res[n-1-i][n-1-j]=mp[i][j];
            }
            else if(lev%4==2){
                res[n-1-j][i]=mp[i][j];
            }
            else res[i][j]=mp[i][j];
        }        
    }
    rng(i,0,n-1){
        rng(j,0,n-1) cout<<res[i][j];
        cout<<'\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    //cin>>t;
    while(t--){
        Solve();
    }
    return 0;
}

