
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
//__attribute__((optimize("Ofast,unroll-loops"),target("avx,avx2,fma")))

#define N 300030
#define MOD 998244353
#define INF 1000000007 
int ori[1000];
int aa[1000];
int bb[1000];

void Solve(){
    string a,b;
    int n,m;
    cin>>n>>m; // n<m
    cin>>a; // n
    cin>>b; // m
    rng(i,0,n-1) aa[i]=a[i]-'a';
    rng(i,0,m-1) bb[i]=b[i]-'a';

    fill(ori,ori+n,-1);
    rng(i,m-n,m-1){
        ori[i]=aa[i-(m-n)];
        //cout<<ori[i]<<'\n';
    }

    gnr(i,m-n-1,0){
        ori[i]=(bb[i+n]-ori[i+n]+26*10)%26;
        //cout<<ori[i]<<'\n';
    }
    rng(i,0,m-1) cout<<(char)(ori[i]+'a');
    cout<<'\n';

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

