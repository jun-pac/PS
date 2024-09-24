
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
string s;
ll datas[200];
void Solve(){
    ll n;
    cin>>n;
    cin>>s;
    rng(i,0,n-1) datas[i]=s[i]-'0';
    bool flag=1;
    rng(i,0,n-1) if(datas[i]==0) flag=0;
    if(n==2){
        cout<<datas[0]*10+datas[1]<<'\n';
        return;
    }
    if(n==3){
        ll mn=99999;
        mn=min(mn,datas[0]+datas[1]*10+datas[2]);
        mn=min(mn,datas[0]*(datas[1]*10+datas[2]));
        mn=min(mn,datas[2]+datas[0]*10+datas[1]);
        mn=min(mn,datas[2]*(datas[0]*10+datas[1]));
        cout<<mn<<'\n';
        return;
    }
    if(n>=4 && !flag){
        cout<<0<<'\n';
        return;
    }   
    
    ll res=9999999;
    rng(i,0,n-2){
        // i, i+1РЬ Че
        ll temp=datas[i]*10+datas[i+1];
        rng(j,0,n-1){
            if(j!=i && j!=i+1 && datas[j]!=1){
                temp+=datas[j];
            }
        }
        res=min(res,temp);
    }
    cout<<res<<'\n';
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

