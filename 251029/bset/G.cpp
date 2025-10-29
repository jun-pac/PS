
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
random_device rd; 
mt19937 gen(rd());
uniform_int_distribution<> dist(0, INF); // random integer from [0, INF] // dist(gen)

long long gcd(long long x, long long y){
    if(x<y) swap(x,y);
    if(y==0) return x;
    if(x%y==0) return y;
    return gcd(y,x%y);
}

char ans[101][101];
void Solve(){
    int l,w,n;
    cin>>l>>w>>n;
    if((l*w)%n!=0){
        cout<<"impossible\n";
        return;
    }
    int nl=gcd(n,l);
    int nw=n/nl;
    int al=l/nl;
    assert(w%nw==0);
    int aw=w/nw;
    int cnt=0;
    rng(ii,0,nl-1){
        rng(jj,0,nw-1){
            rng(i,0,al-1){
                rng(j,0,aw-1){
                    ans[ii*al+i][jj*aw+j]=(char)cnt+'A';
                }
            }
            cnt++;
        }
    }

    rng(i,0,l-1){
        rng(j,0,w-1){
            cout<<ans[i][j];
        }
        cout<<'\n';
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

