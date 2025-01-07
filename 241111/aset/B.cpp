
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

void Solve(){
    int n,q;
    cin>>n>>q;
    int l=0, r=1;
    ll res=0;
    rng(i,0,q-1){
        char c;
        int tar;
        cin>>c>>tar;
        tar--;
        if(l==tar || r==tar){
            continue;
        }
        if(c=='L'){
            // l만 움직인다
            if(tar<l && l<r){
                res+=(l-tar+n)%n;
            }
            else if(r<tar && tar<l){
                res+=(l-tar+n)%n;
            }
            else if(l<r && r<tar){
                res+=(l-tar+n)%n;
            }
            else{
                res+=(tar-l+n)%n;
            }
            l=tar;
        }
        else{
            if(tar<l && l<r){
                res+=(tar-r+n)%n;
            }
            else if(r<tar && tar<l){
                res+=(tar-r+n)%n;
            }
            else if(l<r && r<tar){
                res+=(tar-r+n)%n;
            }
            else{
                res+=(r-tar+n)%n;
            }
            r=tar;
        }
    }
    cout<<res<<'\n';
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

