
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
#define INF 1000000007 

ll datas[N];
ll mod;
string s;
ll ans[N];

void Solve(){
    int n;
    cin>>n>>mod;
    rng(i,0,n-1) cin>>datas[i];
    cin>>s;
    int l=0, r=n-1;
    rng(i,0,n-2){
        if(s[i]=='L') l++;
        else r--;
    }
    assert(l==r);
    ll res=datas[l];
    ans[0]=res%mod;
    rng(i,1,n-1){
        if(s[n-1-i]=='L'){
            l--;
            res=res*datas[l]%mod;
        }
        else{
            r++;
            res=res*datas[r]%mod;
        }
        ans[i]=res;
    }
    rng(i,0,n-1) cout<<(ans[n-1-i]%mod+mod)%mod<<' '; cout<<'\n';

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

