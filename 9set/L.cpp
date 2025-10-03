
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

int n;
pll datas[N]; // cur, need
ll minpsum[N];


bool check(ll num){
    ll mx=-INF;
    ll msum=0, psum=0;
    priority_queue<ll> pr; // -p, min heap
    gnr(i,n-1,2*num){
        pr.push(-datas[i].se);
    }
    minpsum[n-2*num]=0;
    gnr(i,2*num-1,num){
        pr.push(-datas[i].se);
        psum-=pr.top();
        pr.pop();
        minpsum[n-i]=psum;
    }

    // m part
    priority_queue<ll> mq; // -(m+p)
    rng(i,0,num-1){
        msum+=datas[i].fi;
        mq.push(-(datas[i].fi+datas[i].se));
    }


    mx=max(mx,msum-minpsum[n-num]);
    rng(i, num, 2*num-1){
        msum+=datas[i].fi;
        mq.push(-(datas[i].fi+datas[i].se));
        ll temp=-mq.top();
        mq.pop();
        msum-=temp;

        mx=max(mx,msum-minpsum[n-(i+1)]);
    }

    return mx>=0;    

}

void Solve(){
    cin>>n;
    rng(i,0,n-1) cin>>datas[i].fi; // m_i
    rng(i,0,n-1) cin>>datas[i].se; // p_i
    sort(datas, datas+n);
    reverse(datas, datas+n);

    ll l=0, r=n/2;
    while(l<r){
        ll mid=(l+r+1)>>1;
        if(check(mid)) l=mid;
        else r=mid-1;
    }
    cout<<l<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    // cin>>t;
    while(t--){
        Solve();
    }
    return 0;
}

