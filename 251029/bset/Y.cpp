
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
random_device rd; 
mt19937 gen(rd());
uniform_int_distribution<> dist(0, INF); // random integer from [0, INF] // dist(gen)

 
void Solve(){
    double p1=1, p2=0;
    ll n;
    cin>>n;
    if(n==1){
        cout<<100<<' '<<0<<'\n';
    }
    else if(n==2){
        cout<<0<<' '<<100<<'\n';
    }
    else{
        rng(i,0,min(100000LL,n-2)-1){
            double cur=(p1+p2)/2;
            p1=p2;
            p2=cur;
            // cout<<p1<<' '<<p2<<'\n';
            // if(abs(p1-p2)<0.00000001){
            //     cout<<"break "<<n<<' '<<p1<<' '<<p2<<endl;
            //     break;
            // }
        }
        cout<<fixed;
        cout.precision(12);
        cout<<p2*100<<' '<<100-p2*100<<'\n';
    }

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

