
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
string a, b;
int suma[26][N];
int sumb[26][N];

void Solve(){
    int n,q;
    cin>>n>>q;
    cin>>a;
    cin>>b;
    rng(k,0,25){
        rng(i,0,n-1) suma[k][i]=(i==0?0:suma[k][i-1])+(a[i]=='a'+k?1:0);
    }
    rng(k,0,25){
        rng(i,0,n-1) sumb[k][i]=(i==0?0:sumb[k][i-1])+(b[i]=='a'+k?1:0);
    }
    rng(i,0,q-1){
        int l,r;
        cin>>l>>r;
        l--, r--;
        int cnt=0;
        rng(k,0,25){
            cnt+=abs(suma[k][r]-(l==0?0:suma[k][l-1])-(sumb[k][r]-(l==0?0:sumb[k][l-1])));
        }
        cout<<cnt/2<<'\n';
    }
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

