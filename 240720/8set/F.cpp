
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

#define N 1000030
#define MOD 998244353
#define INF 1000000007 

int datas[N];

void Solve(){
    int k;
    cin>>k;
    rng(i,0,k-1){
        int n;
        cin>>n;
        datas[i]=n;
        rng(j,0,n-2){
            int a;
            cin>>a; // Not really an important information
        }
    }
    sort(datas,datas+k,0);
    int res=datas[k-1];
    int mx=0;
    while((1<<mx)<=datas[k-1]) mx++;
    mx--; // (1<<mx)<=datas[k-1] 을 만족함 => MSB임.

    gnr(i,k-2,0){
        int cur=0;
        gnr(m,mx,0){
            if(res&(1<<m)) continue; // 필요가없음
            if(cur+(1<<m)<=datas[i]){
                cur+=(1<<m);
            }
        }
        res=(res|cur);
    }
    cout<<res<<'\n';
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

