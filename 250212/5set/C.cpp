
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
    ll n;
    cin>>n;
    if(n==6){
        cout<<"1 1 2 3 1 2\n";
    }
    else if(n==12){
        cout<<"1 1 2 3 1 2 4 4 5 6 4 5\n";
    }
    else if(n==7){
        cout<<"1 1 2 1 3 2 2\n";
    }
    else if(8<=n && n<12){
        cout<<"1 1 3 2 1 3 2 2 ";
        rng(i,8,n-1) cout<<i+1<<' ';
        cout<<'\n';
    }
    else if(12<n && n<16){
        cout<<"1 1 3 2 1 3 2 2 4 4 5 4 5 ";
        rng(i,13,n-1) cout<<i+1<<' ';
        cout<<'\n';
    }
    else{
        int k=n/8;
        rng(i,0,k-1){
            int s=3*i+1;
            cout<<s<<' '<<s<<' '<<s+2<<' '<<s+1<<' '<<s<<' '<<s+2<<' '<<s+1<<' '<<s+1<<' ';
        }
        rng(i,8*k,n-1){
            cout<<i+1<<' ';
        }
        cout<<'\n';
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

