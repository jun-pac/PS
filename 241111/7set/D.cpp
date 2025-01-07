
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
#define MOD 1000000007
#define INF 1000000007 
random_device rd; 
mt19937 gen(rd());
uniform_int_distribution<> dist(0, INF); // random integer from [0, INF] // dist(gen)

ll datas[N];
ll cnt[N], sum[N];
ll p2[6000000];

bool comp(int a, pll b){
    // datas[a] < datas[b.fi]*2^b.se ÀÌ¸י true
    if(b.se>=30) return 1;
    else return (datas[a] < (datas[b.fi]<<(b.se)));
}

void Solve(){
    ll n;
    cin>>n;
    rng(i,0,n-1) cin>>datas[i];
    rng(i,0,n-1){
        int temp=0;
        // cout<<"d "<<datas[i]<<'\n';
        ll val=datas[i];
        while(val%2==0){
            val/=2;
            temp++;
        }
        datas[i]=val;
        cnt[i]=temp;
        sum[i]=(i==0?0:sum[i-1])+cnt[i];
    }
    stack<pll> st; // {idx,2_num}
    ll last=0;
    rng(i,0,n-1){
        ll k=cnt[i];
        while(!st.empty()){
            pll temp=st.top();
            if(comp(temp.fi,{i,k})){
                st.pop();
                last=(last-datas[temp.fi]*p2[temp.se]+datas[temp.fi])%MOD;
                k+=temp.se;
            }
            else break;
        }
        if(k>0) st.push({i,k});
        last=(last+datas[i]*p2[k])%MOD;
        cout<<(last%MOD+MOD)%MOD<<' ';
    }
    cout<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    cin>>t;
    p2[0]=1;
    rng(i,1,6000000-1) p2[i]=(p2[i-1]*2)%MOD;
    while(t--){
        Solve();
    }
    return 0;
}

