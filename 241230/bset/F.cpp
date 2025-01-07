
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
    int n;
    string s,t;
    cin>>n>>s>>t;
    // cout<<n<<'\n';
    // cout<<s<<' '<<t<<'\n';
    bool flag=1;
    for(int i=0; i<n; i++){
        // cout<<i<<'\n';
        if(i+3<=n-1 && s[i]=='T' && s[i+1]=='I' && s[i+2]=='O' && s[i+3]=='T'){
            if(t[i]=='I' && t[i+1]=='S' && t[i+2]=='C'){
                i=i+2;
            }
            else{
                rng(j,0,2) if(s[i+j]!=t[i+j]) flag=0;   
                i=i+2;
            }
        }
        else{
            if(s[i]!=t[i]){
                flag=0;
                break;
            }
        }
        if(!flag) break;
    }
    cout<<(flag?"Yes\n":"No\n");

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

