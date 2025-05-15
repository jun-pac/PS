
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
// random_device rd; 
// mt19937 gen(rd());
// uniform_int_distribution<> dist(0, INF); // random integer from [0, INF] // dist(gen)

map<pii,int> mp;

void Solve(){
    int n,r,c;
    cin>>n>>r>>c;
    int cr=0, cc=0;
    string s;
    cin>>s;
    mp[{cr,cc}]=1;
    rng(i,0,n-1){
        if(s[i]=='N'){
            cr++;
        }
        else if(s[i]=='S'){
            cr--;
        }
        else if(s[i]=='W'){
            cc++;
        }
        else if(s[i]=='E'){
            cc--;
        }
        mp[{cr,cc}]=1;
        // cout<<"de "<<r+cr<<' '<<c+cc<<' '<<mp[{r+cr, c+cc}]<<'\n';
        if(mp[{r+cr, c+cc}]==1) cout<<1;
        else cout<<0;
    }
    cout<<'\n';
    
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

