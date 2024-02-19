
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
string a,b;
vc<pii> seqa, seqb, invb;

string reduce(){ // return은 reduce되는 1의 개수임.
    string res=0;
    int n=a.size();
    rng(i,0,n-1) res+=(a[i]==1);
    int k=n-1;
    while(k>0 && a[k]==0) k--;
    int zero=n-1-k;
    
}

void inv_reduce(){

}

void fit_num1(){
        
}

void Solve(){
    cin>>a>>b;    
    seqa.clear();
    seqb.clear();
    reduce(); // process a compression
    inv_reduce();
    if()
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

