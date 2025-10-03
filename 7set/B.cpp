
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

#define N 400030
#define MOD 998244353
#define INF 1000000007 
random_device rd; 
mt19937 gen(rd());
uniform_int_distribution<> dist(0, INF); // random integer from [0, INF] // dist(gen)

int ans[N];

void Solve(){
    int n;
    cin>>n;
    if(n<=3){
        if(n==2){
            cout<<"1 2 1 2\n";
        }
        else if(n==3){
            cout<<"1 3 1 2 3 2\n";
        }
        else{
            cout<<"1 1\n";
        }
    }
    else if(n%2==0){
        // easy
        rng(i,1,n/2-1){
            ans[n/2+i] = i*2+1;
            ans[n/2+i-(i*2+1)] = i*2+1;
        }
        ans[n/2-1]=n;
        ans[n/2+n-1]=n;
        ans[n/2]=1;
        ans[2*n-1]=1;

        // cout<<n/2+n-1<<' '<<ans[n/2+n-1]<<'\n';
        rng(i,0,n/2-2){
            ans[2*n-n/2+i] = i*2+2;
            ans[2*n-n/2+i-(i*2+2)] = i*2+2;
        }
                // cout<<n/2+n-1<<' '<<ans[n/2+n-1]<<'\n';

        rng(i,0,2*n-1) cout<<ans[i]<<' ';
        cout<<'\n';
    }
    else{
        rng(i,1,n/2){
            ans[n/2-i] = i*2+1;
            ans[n/2-i+i*2+1] = i*2+1;
        }
        ans[n/2+1]=n-1;
        ans[n/2+n]=n-1;
        ans[n/2]=1;
        ans[2*n-1]=1;

        rng(i,0,n/2-2){
            ans[2*n-n/2+1+i-1] = i*2+2;
            ans[2*n-n/2-1-i-1] = i*2+2;
        }
        rng(i,0,2*n-1) cout<<ans[i]<<' ';
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

