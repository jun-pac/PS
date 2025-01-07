
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

set<int> datas[N];
vc<pll> es;

void Solve(){
    ll n,m;
    es.clear();
    cin>>n>>m;
    rng(i,0,n-1){
        int num;
        cin>>num;
        datas[i].clear();
        rng(j,0,num-1){
            int a;
            cin>>a;
            datas[i].insert(a);
        }
        int k=0;
        while(datas[i].find(k)!=datas[i].end()){
            k++;
        }
        // 지금의 k가 처음으로 없는
        int a=k;
        //cout<<"whaat "<<a<<'\n';
        if(datas[i].find(k+1)==datas[i].end()) es.pb({a,-(a+1)});
        else{
            k++;
            while(datas[i].find(k)!=datas[i].end()){
                k++;
            }
            int b=k;
            //cout<<"hehe "<<b<<'\n';
            es.pb({a,-b});
        }
    }
    sort(all(es));
    reverse(all(es));
    ll res=0;
    ll cur=m;
    ll mx=0;
    rng(i,0,n-1) mx=max(mx,-es[i].se);
    // if(cur>es[0].fi){
    //     // 얘들은 그냥 냅둬야 함.
    //     res+=((es[0].fi+1+cur)*(cur-es[0].fi))/2;
    //     cur=es[0].fi;
    // }
    // rng(i,0,n-1){
    //     if(es[i].fi>=cur) mx=max(mx,-es[i].se);
    //     else{
    //         ll idx=es[i].fi;
    //         //[idx+1,cur]의 영역을 mx로
    //         res+=mx*(cur-idx);
    //         cur=idx;
    //         mx=max(mx,-es[i].se);
    //     }
    // }
    //cout<<mx<<' '<<m<<'\n';
    if(m>mx){
        res=((m+mx+1)*(m-mx))/2;
        res+=mx*(1+mx);
    }
    else res=mx*(m+1);
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

