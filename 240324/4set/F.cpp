
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

void prt(int l, int r){
    int n=r-l+1;
    if(n%2==0){
        rng(i,r-n/2+1,r) cout<<i<<' ';
        rng(i,l,l+n/2-1) cout<<i<<' ';
    }   
    else{
        rng(i,r-n/2,r-1) cout<<i<<' ';
        cout<<r<<' ';
        rng(i,l,l+n/2-1) cout<<i<<' ';
    }
}

void Solve(){
    int n,k;
    cin>>n>>k;
    int q=cediv(n,k);
    int cur=0;
    while(cur<n){
        prt(cur+1,min(cur+k,n));
        cur+=k;
    }
    cout<<'\n';
    cout<<q<<'\n';
    cur=0;
    int cnt=1;
    while(cur<n){
        rng(i,cur,min(cur+k-1,n-1)) cout<<cnt<<' ';
        cnt++;
        cur+=k;
    }
    cout<<'\n';

}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    // prt(1,6); cout<<endl;
    // prt(1,7); cout<<endl;
    // prt(3,8); cout<<endl;

    int t=1;
    cin>>t;
    while(t--){
        Solve();
    }
    return 0;
}

