
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
__attribute__((optimize("Ofast,unroll-loops"),target("avx,avx2,fma")))

#define N 300030
#define MOD 998244353
#define INF 1000000007 

string s, af;

void Solve(){
    cin>>s;
    bool flag=1;
    int n=s.size();
    int idx=-1;
    rng(i,0,n-1){
        if(s[i]=='@'){
            idx=i;
            break;
        }
        if(!('a'<=s[i] && s[i]<='z')){
            flag=0;
            break;
        }
    }
    if(!(2<=idx && idx<=4) || !flag || n-idx!=9){
        cout<<"no\n";
    }
    else{
        rng(i,1,8){
            if(s[idx+i]!=af[i-1]){
                flag=0;
                break;
            }
        }
        if(flag) cout<<"yes\n";
        else cout<<"no\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    //cin>>t;
    af="odoo.com";
    while(t--){
        Solve();
    }
    return 0;
}

