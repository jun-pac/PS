
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
// random_device rd; 
// mt19937 gen(rd());
// uniform_int_distribution<> dist(0, INF); // random integer from [0, INF] // dist(gen)

ll datas[N];
ll sum[N];
ll n,s,d;

bool check(ll tar){
    // 내부sum
    if(tar<=d){
        gnr(r,n-1,0){
            if(sum[r-1]<tar) break;
            else if(sum[r-1]==tar) return 1;
            ll temp=sum[r-1]-tar; // 해당하는 값이 존재해야 함.
            if((*lower_bound(sum,sum+r,temp))==temp) return 1;
        }
    }
    // n-1포함
    gnr(l,n-1,0){
        ll lsum=sum[n-1]-(l==0?0:sum[l-1]);
        if(lsum>tar) break;
        else if(lsum==tar) return 1;
        ll temp=tar-lsum;
        auto pos=lower_bound(sum,sum+n,temp);
        if(pos!=(sum+n) && (*pos)==temp) return 1;
    }
    return 0;
}

void Solve(){
    cin>>n>>s;
    rng(i,0,n-1) cin>>datas[i];
    rng(i,0,n-1) sum[i]=(i==0?0:sum[i-1])+datas[i];
    d=sum[n-1];
    if(s<d){
        ll tar=s;
        cout<<(check(tar)?"Yes":"No")<<'\n';
    }
    else{
        ll tar=s%d;
        cout<<(check(tar)||check(tar+d)?"Yes":"No")<<'\n';
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

