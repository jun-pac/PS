
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

ll sum[26][N];
ll n, sz;

pll nextidx(ll idx1, ll idx2, ll k, int c){
    // idx1번째의 S의 idx2번째 위치부터 search가 가능함.
    ll resi=(n-1-idx1)*sum[c][sz-1]+(sum[c][sz-1]-(idx2==0?0:sum[c][idx2-1]));
    if(resi>k) return {-1,-1};
    //else return {idx1+()} 

}


void Solve(){
    string s, t;
    cin>>n;
    cin>>s;
    cin>>t;
    // s의 sum
    sz=s.size();
    rng(i,0,25){
        rng(j,0,(int)s.size()-1){
            sum[i][j]=(j==0?0:sum[i][j-1])+((s[j]-'a')==i);
        }
    }
    ll l=0,r=n*(ll)s.size();
    while(l<r){
        ll k=(l+r+1)>>1;
        bool flag=1;
        ll last1=0, last2=0;
        rng(i,0,(int)t.size()-1){
            pll res=nextidx(last1,last2,k,t[i]-'a');
            if(res.fi==-1 || res.fi>=n){
                flag=0;
                break;
            }
            last1=res.fi+(last2+1==s.size());
            last2=(res.se+1==s.size()?0:res.se+1);
        }
        if(flag) l=k;
        else r=k-1;
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

