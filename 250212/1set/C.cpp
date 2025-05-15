
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
// random_device rd; 
// mt19937 gen(rd());
// uniform_int_distribution<> dist(0, INF); // random integer from [0, INF] // dist(gen)
ll power_of_ten[20];

ll get_cnt_mx(ll a, ll b, ll k, ll mx){
    // mx digit이하만 가능하다?
    if(k==1){
        return max(0LL,min(b,mx)-a+1);
    }
    ll p10=power_of_ten[k-1];
    ll aa=a/p10;
    ll bb=b/p10;
    if(aa>mx) return 0;
    if(aa==bb){
        return get_cnt_mx(a%p10, b%p10, k-1, mx);
    }
    ll res=get_cnt_mx(a%p10, p10-1, k-1, mx);
    if(bb>mx){
        ll temp=1;
        rng(i,0,k-2) temp*=(mx+1);
        res+=temp*(mx-(aa+1)+1);
    }
    else{
        ll temp=1;
        rng(i,0,k-2) temp*=(mx+1);
        res+=temp*((bb-1)-(aa+1)+1);
        res+=get_cnt_mx(0, b%p10, k-1, mx);
    }
    return res;
}

ll get_cnt(ll a, ll b, ll k){
    // a, b has same digit, k
    // cout<<"debug; "<<a<<' '<<b<<' '<<k<<'\n';
    if(k==1) return b-a+1;
    ll p10=power_of_ten[k-1];
    ll aa=a/p10;
    ll bb=b/p10;
    // cout<<aa<<' '<<bb<<' '<<p10<<'\n';
    if(aa==bb){
        if(aa==1){
            if(a==aa*p10) return 1;
            else return 0;
        }
        else{
            // cout<<"get mx : "<<a%p10<<' '<<b%p10<<' '<<k-1<<' '<<aa-1<<' '<<get_cnt_mx(a%p10, b%p10, k-1, aa-1)<<'\n';
            return get_cnt_mx(a%p10, b%p10, k-1, aa-1);
        }
    }
    else{
        ll res=0;
        if(aa==1){
            if(a==aa*p10) res+=1;
            else res+=0;
        }
        else{
            // cout<<"get mx : "<<a%p10<<' '<<p10-1<<' '<<k-1<<' '<<aa-1<<' '<<get_cnt_mx(a%p10, p10-1, k-1, aa-1)<<'\n';
            res+=get_cnt_mx(a%p10, p10-1, k-1, aa-1);
        }

        rng(i,aa+1,bb-1){
            ll temp=1;
            rng(j,0,k-2) temp=temp*i;
            res+=temp;
        }

        res+=get_cnt_mx(0,b%p10, k-1, bb-1);
        // cout<<"get mx : "<<0<<' '<<b%p10<<' '<<k-1<<' '<<bb-1<<' '<<get_cnt_mx(0,b%p10, k-1, bb-1)<<'\n';
        return res;
    }
}

void Solve(){
    ll a,b;
    cin>>a>>b;
    ll val=10;
    ll k=1;
    ll temp=1;
    rng(i,0,18){
        power_of_ten[i]=temp;
        temp*=10;
    }
    if(a==1000000000000000000LL){
        cout<<1<<'\n';
        return;
    }
    while(val<=a){
        val*=10;
        k++;
    }
    if(val-1>=b){
        cout<<get_cnt(a,b,k);
    }
    else{
        ll res=0;
        while(true){
            res+=get_cnt(a, val-1, k);
            a=val;
            if(val>b/10) break;
            val*=10;
            k++;
        }
        if(a<=b) res+=get_cnt(a,b,k+1);
        cout<<res<<'\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    //cin>>t;
    while(t--){
        Solve();
    }
    return 0;
}

