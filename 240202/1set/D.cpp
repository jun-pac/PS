
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

int datas[5005];
bool dels[5005][5005];  // 짝수고, 한 원소가 과반수만 아니면 지울 수 있다는 걸 귀납적으로 증명가능
ll DP[5005];
int cnt[5005];

void Solve(){
    int n;
    cin>>n;
    rng(i,0,n-1) cin>>datas[i];
    rng(i,0,n-1) datas[i]--;
    rng(i,0,n-1){
        fill(cnt,cnt+n,0);
        int mx=0;
        rng(j,i,n-1){
            // dels[i][j]는 [i,j]를 지울 수 있을 때 1임
            cnt[datas[j]]++;
            mx=max(mx,cnt[datas[j]]);
            dels[i][j]=((j-i+1)%2==0 && 2*mx<=(j-i+1));
        }
    }
    DP[0]=1;
    rng(i,1,n-1){
        DP[i]=-INF;
        if(DP[i-1]>=0 && datas[i]==datas[i-1]) DP[i]=DP[i-1]+1;
        if(dels[0][i-1]) DP[i]=max(DP[i],1LL);
        rng(j,1,i-1){
            // [j,i-1]을 지울 수 있는가임
            if(datas[j-1]==datas[i] && DP[j-1]>=0 && dels[j][i-1]) DP[i]=max(DP[j-1]+1,DP[i]);
        }
    }

    ll res=DP[n-1];
    rng(i,0,n-2) if(dels[i+1][n-1]) res=max(res,DP[i]);
    cout<<(res<0?0:res)<<'\n';
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

