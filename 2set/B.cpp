
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
map<int,int> cnt;
int nums[N];

void Solve(){
    int n,k;
    cin>>n>>k;
    rng(i,0,n-1) cin>>datas[i];
    cnt.clear();
    rng(i,0,n-1) cnt[datas[i]]++;
    int temp=0;
    auto cur=cnt.begin();
    while(cur!=cnt.end()){
        nums[temp++]=(cur->se);
        cur=next(cur);
    }
    sort(nums,nums+temp);
    // cout<<"temp "<<temp<<'\n';
    // rng(i,0,temp-1) cout<<nums[i]<<'\n';
    int tot=0;
    int idx=0;
    while(idx<temp){
        if(tot+nums[idx]<=k){
            tot+=nums[idx];
            idx++;
            // cout<<"what "<<tot<<' '<<k<<' '<<idx<<' '<<temp<<'\n';
        }
        else break;
    }
    cout<<max(1,temp-idx)<<'\n';
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

