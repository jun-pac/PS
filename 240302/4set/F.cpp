
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

// This type is more appropriate when finding max, min value in the range.
// For adding total number, plz check bottom code



double y_prob[N], y_sum[N], y_end[N], y_end_sum[N];
double x_prob[N], x_sum[N];

void Solve(){
    int n,l,d; // l<=n, d<=n
    cin>>n>>l>>d;
    y_prob[0]=1;
    y_sum[0]=1;
    rng(i,1,l+d-1){
        int l_end=max(0,i-d);
        int r_end=min(l-1,i-1);
        assert(r_end>=l_end);
        y_prob[i]=(y_sum[r_end]-(l_end==0?0:y_sum[l_end-1]))/d; // sum(max(0,i-d), min(l-1,i-1))/d
        y_sum[i]=y_sum[i-1]+y_prob[i];
    }
    double temp=0;
    rng(i,l,l+d-1){
        y_end[i]=temp;
        temp+=y_prob[i];
    }
    rng(i,l+d,n) y_end[i]=1;
    rng(i,0,n) y_end_sum[i]=(i==0?0:y_end_sum[i-1])+y_end[i];

    x_sum[0]=1;
    x_prob[0]=1;
    rng(i,1,n){
        int l_end=max(0,i-d);
        int r_end=min(n-d,i-1);
        assert(r_end>=l_end);
        x_prob[i]=(x_sum[r_end]-(l_end==0?0:x_sum[l_end-1]))/d; // sum(max(0,i-d), min(l-1,i-1))/d
        x_sum[i]=x_sum[i-1]+x_prob[i];
    }

    double res=0;
    rng(i,n-d+1,n){
        res+=y_end[i]*x_prob[i];
    }
    double ans=res;
    rng(thres,n-d,n-1){ // thres까지는 다시 돌린다. 즉 thres가 나올 수 없는 것
        // thres를 분산하는 처리를 해준다. modify
        res-=y_end[thres]*x_prob[thres];
        res+=(y_end_sum[n]-y_end_sum[thres])*x_prob[thres]/d; // 어차피 동일 확률로 갈 것이다.
        ans=max(ans,res);
    }
    cout<<fixed;
    cout.precision(12);
    cout<<ans;
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

