
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

#define N 3030
#define MOD 998244353
#define INF 1000000007 

pll ba[N];

void Solve(){
    ll n,tot;
    cin>>n>>tot; // maximum total time

    rng(i,0,n-1) cin>>ba[i].se>>ba[i].fi; // b, a
    sort(ba,ba+n);

    ll res=0;
    rng(i,0,n-1) if(ba[i].se<=tot) res=1;
    rng(i,0,n-1){
        priority_queue<ll> in, out;
        ll sum=0;
        rng(j,i+1,n-1){
            // i,j는 확실히 가지고 있고,j와 i가 끝을 담당. 나머지에 대해서는 b는 중요하지 않다.
            ll offset=ba[i].se+ba[j].se+ba[j].fi-ba[i].fi;
            if(j!=i+1) out.push(-ba[j-1].se); // 지금 이용할 a            
            while(!in.empty() && -out.top()<in.top()){
                ll a=-out.top();
                out.pop();
                ll b=in.top();
                in.pop();
                sum-=b-a;
                out.push(-b);
                in.push(a);
            } 
            while(!out.empty() && -out.top()+offset+sum<=tot){
                sum+=-out.top();
                in.push(-out.top());
                out.pop();
            }
            //cout<<"goit "<<i<<' '<<j<<' '<<sum<<' '<<2+k<<'\n';

            if(offset+sum<=tot) res=max(res,(ll)2+(ll)in.size());
        }
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

