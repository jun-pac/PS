
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
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

void Solve(){
    int n,k,x;
    cin>>n>>k>>x;
    if(x==1){
        if(n==1) cout<<"NO"<<'\n';
        else{
            if(n%2==0 && k<=1){
                cout<<"NO"<<'\n';
                return;
            }
            else if(n%2==1 && k<=2){
                cout<<"NO"<<'\n';
                return;
            }
            cout<<"YES"<<'\n';
            cout<<(n/2)<<'\n';
            if(n%2==0) rng(i,0,n/2-1) cout<<2<<' ';
            else rng(i,0,n/2-1) cout<<(i==n/2-1?3:2)<<' ';
            cout<<'\n';
        }
    }
    else{
        cout<<"YES\n";
        cout<<n<<'\n';
        rng(i,0,n-1) cout<<1<<' '; cout<<'\n';
    }
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

