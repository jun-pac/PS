
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

// CHT가 아니라 완전히 Convex hull
// 개념상 convexhull을 구하는 문제긴 하지만, 꼭 엄밀하게 모든 convexhull을 구할 필요는 없는 듯.
// 사실 그냥 기하적인 관찰로 풀리는 문제고 꼭 Convex hull이 필요하다고 하기도 애매.

double datas[N], sum[N];
int st[N]; // 여기는 그냥 idx만 
double ans[N];

void Solve(){
    int n;
    cin>>n;
    rng(i,1,n) cin>>datas[i];
    sum[0]=0;
    rng(i,1,n) sum[i]=sum[i-1]+datas[i];
    int scnt=0;
    st[scnt++]=n;
    gnr(i,n,1){
        // ans[i]를 채우는 방법
        // {i-1, sum[i-1]}에서 선을 긋는 방법임.
        while(scnt>1){
            int cur=st[scnt-1]; // {cur, sum[cur]}
            int com=st[scnt-2]; // {com, sum[com]}
            if((sum[com]-sum[i-1])*(cur-(i-1))-(sum[cur]-sum[i-1])*(com-(i-1))<0) break;
            scnt--;
        }
        ans[i]=(sum[st[scnt-1]]-sum[i-1])/(st[scnt-1]-(i-1));
        st[scnt++]=i-1;
    }
    cout<<fixed;
    cout.precision(12);
    rng(i,1,n) cout<<ans[i]<<'\n';
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

