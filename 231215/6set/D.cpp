
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
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

int datas[N], d2[N];
ll DP[N]; // DP는 아니긴 함 : i를 만들기 위해 필요한 최소한의 연산
ll qs[N];
int LScut[21][N]; // 각각 앞 뒤에서 cut
ll MSsum[21]; // 뒤에서 i개는 0으로 처리한 상태에서의 합
void Solve(){
    int n,q;
    cin>>n>>q;
    rng(i,0,n-1) cin>>datas[i];
    rng(i,0,n-1) d2[i]=datas[i];
    sort(datas,datas+n); // datas[n-1]이 된다면 -> 
    // 그게 아니면 이전값들 다 돌려보면 되는거 아님?
    int def=datas[0];
    ll sum=0;
    rng(i,0,n-1) sum+=datas[i];
    rng(i,0,n-1) def=def&datas[i]; // default값
    fill(LScut[0],LScut[0]+n,0);
    MSsum[0]=sum;

    rng(i,1,20){
        // 뒤에서 i개만 자르는 것
        MSsum[i]=MSsum[i-1];
        int cur=(1<<(i-1));
        rng(j,0,n-1){
            LScut[i][j]=LScut[i-1][j]+((d2[j]%2)<<(i-1));
            MSsum[i]-=((d2[j]%2)<<(i-1));
            d2[j]/=2;
        }    
    }

    rng(i,0,q-1) cin>>qs[i];

    rng(k,1,20){
        // k자리의 숫자임
        rng(i,(k==1?0:(1<<(k-1))),(1<<k)-1){
            // k자리에 해당하는 i들
            
        }
    }
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

