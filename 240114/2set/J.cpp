
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

ll pos1[N], pos2[N];

void Solve(){
    int n;
    cin>>n;
    rng(i,0,n-1) cin>>pos1[i];
    rng(i,0,n-1) cin>>pos2[i];
    int lmx=0;
    int j=n-1;
    gnr(i,n-1,0){
        // pos1[i]보다 작은 최대의 pos2[i]를 고르는데, two pointer로
        while(j>=0 && pos2[j]>=pos1[i]) j--;
        if(j>=0 && pos2[j]<pos1[i]){
            lmx++;
            j--;
        }
    }    

    int lmn=n;
    j=0;
    rng(i,0,n-1){
        while(j<n && pos2[j]<pos1[i]) j++;
        if(j<n && pos2[j]>pos1[i]) lmn--, j++;
    }
    cout<<lmx-lmn+1<<'\n';
    rng(i,lmn,lmx) cout<<i<<' '; cout<<'\n';
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

