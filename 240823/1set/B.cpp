
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
int res[N];

void Solve(){
    bool flag=1;
    // 처음과 마지막을 제외하고 0은 하나만 존재할 수 없다.
    int n;
    cin>>n;
    rng(i,0,n-2) cin>>datas[i];
    fill(res,res+n,0);
    rng(k,0,29){
        int cur=1;
        int prev;
        rng(i,0,n-1){
            if(i==0){
                cur=(datas[i]&(1<<k)?1:0);
                res[i]+=(cur<<k);
                prev=cur;
            }
            else if(i<n-1){
                cur=((datas[i]&(1<<k))||(datas[i-1]&(1<<k))?1:0);
                if(cur==1 && prev==1 && !(datas[i-1]&(1<<k))){
                    cout<<-1<<'\n';
                    return;
                }
                res[i]+=(cur<<k);
                prev=cur;
            }
            if(i==n-1){
                cur=((datas[n-2]&(1<<k))?1:0);
                res[i]+=(cur<<k);
            }
        }
    }
    rng(i,0,n-1) cout<<res[i]<<' ';
    cout<<'\n';
    // cout<<"debug : ";
    // rng(i,0,n-2) cout<<(res[i]&res[i+1])<<' ';
    // cout<<'\n';
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

