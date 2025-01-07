
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


void Solve(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    vc<int> cnt;
    int last=0;
    rng(i,1,n-1){
        if(s[i]!=s[i-1]){
            cnt.pb(i-last);
            last=i;
        }
    }
    cnt.pb(n-last);

    if(s[0]=='1'){
        rng(i,0,2*k-4){
            rng(j,0,cnt[i]-1) cout<<(i%2==0?'1':'0');
        }
        rng(j,0,cnt[2*k-2]-1) cout<<'1';
        rng(j,0,cnt[2*k-3]-1) cout<<'0';
        rng(i,2*k-1,(int)cnt.size()-1){
            rng(j,0,cnt[i]-1) cout<<(i%2==0?'1':'0');
        }
    }
    else{
        rng(i,0,2*k-3){
            rng(j,0,cnt[i]-1) cout<<(i%2==1?'1':'0');
        }
        rng(j,0,cnt[2*k-1]-1) cout<<'1';
        rng(j,0,cnt[2*k-2]-1) cout<<'0';
        rng(i,2*k,(int)cnt.size()-1){
            rng(j,0,cnt[i]-1) cout<<(i%2==1?'1':'0');
        }
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

