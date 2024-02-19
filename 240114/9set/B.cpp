
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

void Solve(){
    ll n,k;
    cin>>n>>k;
    // 2^18>200000
    // k>40ÀÌ¸י
    if(k>38){
        cout<<(n==0)<<'\n';
        return;
    }
    int cnt=0;
    rng(i,1,n){
        int last=n;
        int cur=i;
        bool flag=1;
        rng(i,0,k-3){
            int temp=last-cur;
            if(!(temp>=0 && temp<=cur)){
                flag=0;
                break;
            }
            last=cur;
            cur=temp;
        }
        if(flag){
            cnt++;
            //cout<<cur<<' '<<last<<'\n';
        }
    }
    cout<<cnt<<'\n';
}

// 0 1 1 2 3 5 8 13 21 35
//   1   2   4   8   16

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--){
        Solve();
    }
    return 0;
}

