
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
int datas[N];
int cnt[N];


void Solve(){
    int n;
    cin>>n;
    fill(cnt,cnt+n+2,0);
    rng(i,0,n-1) cin>>datas[i];
    rng(i,0,n-1) cnt[datas[i]]++;
    int one=0;
    bool flag=1;
    rng(i,0,n-1){
        if(cnt[i]==0){
            cout<<i<<'\n';
            flag=0;
            break;
        }
        else if(cnt[i]==1){
            if(one==0) one++;
            else{
                flag=0;
                cout<<i<<'\n';
                break;
            }
        }
    }
    if(flag) cout<<n<<'\n';
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

