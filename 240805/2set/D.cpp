
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
__attribute__((optimize("Ofast,unroll-loops"),target("avx,avx2,fma")))

ll datas[N];

void Solve(){
    // 누적합임 어차피
    int n;
    cin>>n;
    rng(i,0,n-1) cin>>datas[i];
    int flag1=0;
    rng(i,0,n-1) if(datas[i]==1) flag1=1;
    int idx=0;
    if(flag1){
        rng(i,0,n-1){
            if(datas[i]!=1){
                flag1=0;
                idx=i;
            }
            if(!flag1 && datas[i]==1){
                cout<<-1<<'\n';
                return;
            }
        }
        if(flag1){
            cout<<0<<'\n';
            return;
        }
    }
    ll cnt=0;
    ll cur=0;
    rng(i,1,n-1){
        // i-1을 cur번 제곱한 게 최소인 상황임. 
        if(datas[i]==datas[i-1]){
            cnt+=cur;
        }
        else if(datas[i]>datas[i-1]){
            ll prevd=datas[i-1];
            while(datas[i]>=prevd*prevd && cur>0){
                prevd=prevd*prevd;
                cur--;
            }
            cnt+=cur;
        }
        else{
            ll temp=datas[i];
            while(temp<datas[i-1]){
                temp=temp*temp;
                cur++;
            }
            cnt+=cur;
        }
    }
    cout<<cnt<<'\n';

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

