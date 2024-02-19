
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
vc<int> vals[N];
priority_queue<pii> pq; // {last idx, val}

void Solve(){
    int n;
    cin>>n;
    rng(i,0,n) vals[i].clear();
    rng(i,0,n-1) cin>>datas[i];
    while(!pq.empty()) pq.pop();


    rng(i,0,n-1){
        assert(datas[i]>0);
        assert(datas[i]<=n);
        vals[datas[i]].pb(i);
    }
    rng(i,1,n){
        if((int)vals[i].size()>0){
            pq.push({*prev(vals[i].end()),i});
            //cout<<"ts "<<i<<' '<<*prev(vals[i].end())<<'\n';
            //rng(j,0,vals[i].size()-1) cout<<vals[i][j]<<' ';
            //cout<<'\n';
        }
    }
    

    int prevval=INF;
    
    while(!pq.empty()){
        int lpos=pq.top().fi;
        int val=pq.top().se;
        int fpos=vals[val][0];
        assert(vals[val].size()>0);
        int num=vals[val].size();
        if(val<prevval && lpos-fpos+1==num){
            pq.pop();
            prevval=val;
        }
        else break;
    }
    cout<<pq.size()<<'\n';
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

