
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
    fill(cnt,cnt+n+1,0);
    rng(i,0,n-1) cin>>datas[i];
    rng(i,0,n-1) cnt[datas[i]]++;
    int val=INF;
    rng(i,0,n) if(cnt[i]==0){
        val=i;
        break;
    }
    //cout<<"val "<<val<<'\n';
    // 0~val-1을 잡을 수 있는 두 개의 구분된 영역이 존재해야 함.
    fill(cnt,cnt+n+1,0);
    int under_cnt=0, temp=0; // val이하의 값
    rng(i,0,n-1){
        if(datas[i]<val && cnt[datas[i]]==0){
            under_cnt++;
        }
        cnt[datas[i]]++;
        if(under_cnt==val){
            temp=i;
            break;
        }
    }
    //cout<<"temp "<<temp<<'\n';
    
    under_cnt=0;
    fill(cnt,cnt+n+1,0);
    rng(i,temp+1,n-1){
        if(datas[i]<val && cnt[datas[i]]==0){
            under_cnt++;
        }
        cnt[datas[i]]++;
    }
    if(under_cnt!=val) cout<<"-1\n";
    else{
        cout<<2<<'\n';
        cout<<1<<' '<<temp+1<<'\n';
        cout<<temp+2<<' '<<n<<'\n';
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

