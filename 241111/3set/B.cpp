
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

int datas[N];
int cnt[N];

void Solve(){
    int n,x;
    cin>>n>>x;
    rng(i,0,n-1) cin>>datas[i];
    sort(datas,datas+n);
    fill(cnt,cnt+n,0);
    rng(i,0,n-1){
        if(datas[i]<n) cnt[datas[i]]++;
    }
    
    if(x>=n){
        rng(i,0,n-1){
            if(cnt[i]==0){
                cout<<i<<'\n';
                return;
            }
        }
        cout<<n<<'\n';
        return;
    }

    // 0부터 n까지 돌다가 공동이 있을 때, 나를 채울 수 있는 최대의 앞의 원소부터
    // 근데 x도 굉장히 클 수 있다.
    // x가 n이상이면 아무런 의미가 없다.

    // 0,1,...,k까지를 채워서 최대한 k+1을 크게 만들 수 있는가?
    fill(cnt,cnt+n,0);
    int idx=0;
    rng(i,0,n-1){
        while(idx<n && datas[idx]<=i){
            cnt[datas[idx]%x]++;
            idx++;
        }
        if(cnt[i%x]==0){
            cout<<i<<'\n';
            return;
        }
        cnt[i%x]--;
    } 
    cout<<n<<'\n';
    
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

