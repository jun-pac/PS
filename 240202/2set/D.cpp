
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

bool is_prime(int num){
    rng(i,2,min(num-1,(int)sqrt(num)+1)){
        if(num%i==0) return false;
    }
    return true;
}

void Solve(){
    //rng(i,2,20) cout<<i<<' '<<is_prime(i)<<'\n';
    int n;
    cin>>n;
    if(is_prime(n)){
        cout<<n<<'\n';
        rng(i,0,n-1) cout<<i+1<<' '<<(i+1)%n+1<<'\n';
        return;
    }
    if(is_prime(n+1)){
        cout<<n+1<<'\n';
        rng(i,0,n-1) cout<<i+1<<' '<<(i+1)%n+1<<'\n';
        cout<<1<<' '<<3<<'\n';
        return;
    }
    
    rng(i,n+2,2*n-3){
        if(is_prime(i) && !(i==2*n-3 && n%2==1)){
            cout<<i<<'\n';
            rng(j,0,n-3) cout<<j+1<<' '<<(j+1)%(n-2)+1<<'\n';
            // 남은건 i - n + 2
            int left=i-n+2; // 4이상
            if(left%2==1){
                left--;
                cout<<n-1<<' '<<n<<'\n';
                int one=2;
                while(one<=left){
                    if(is_prime(one) && is_prime(left+2-one)) break;
                    one++;
                }
                rng(j,0,one-2) cout<<j+1<<' '<<n-1<<'\n';
                rng(j,one-1,left-1) cout<<j+1<<' '<<n<<'\n';
                return;
            }
            int one=2;
            while(one<=left-2){
                if(is_prime(one) && is_prime(left-one)) break;
                one++;
            }
            rng(j,0,one-1) cout<<j+1<<' '<<n-1<<'\n';
            rng(j,one,left-1) cout<<j+1<<' '<<n<<'\n';
            return;
        }
    }
    assert(false);
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

