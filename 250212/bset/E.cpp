
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

string s;
int n;

pii DFS(int l, int r){ // {ans, min cost to change ans}
    if(l==r){
        return {s[l]-'0',1};
    }
    int d=(r-l+1)/3;
    int m1=l+d, m2=l+2*d;
    pii t1=DFS(l,m1-1);
    pii t2=DFS(m1,m2-1);
    pii t3=DFS(m2,r);
    int sum=t1.fi+t2.fi+t3.fi;
    int ans=(sum < 2 ? 0:1);
    int cnt=(sum==0 || sum==3 ? 2:1);
    vc<int> temp;
    if(t1.fi==ans) temp.pb(t1.se);
    if(t2.fi==ans) temp.pb(t2.se);
    if(t3.fi==ans) temp.pb(t3.se);
    sort(all(temp));
    int mncost=0;
    rng(i,0,cnt-1) mncost+=temp[i];
    return {ans,mncost};
}

void Solve(){
    int m;
    cin>>m;
    cin>>s;
    int n=1;
    rng(i,0,m-1) n=n*3;
    // cout<<"N "<<n;
    pii temp=DFS(0,n-1);
    cout<<temp.se<<'\n';
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

