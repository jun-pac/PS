
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

ll datas[N];
ll sdatas[N];
ll ssum[N];
int pos[N];

ll n,m,k,lim;
bool check(ll x, ll add){
    // x제외, x+add
    // lim-add개를 더해서 x+add보다 큰 것을 m개 이상 만들 수 있는가?
    int num_big=n-(upper_bound(sdatas,sdatas+n,x+add)-sdatas); // 현재 x+add보다 큰 것의 개수
    if(num_big>=m) return 1;
    int xpos=upper_bound(sdatas,sdatas+n,x+add)-sdatas-1; // x+add이하인 가장 우측좌표
    int r=xpos;
    int l=xpos-(m-num_big)+1;
    if(l==0 || sdatas[l-1]>=x){
        // 하나의 x를 남겨놓고 다 쓴다.
        ll mn=(x+add+1)*(r-l+1)-(ssum[r]-(l==0?0:ssum[l-1]));
        if(mn>lim-add) return 0;
        else return 1;
    }
    else{ 
        l--;
        ll mn=(x+add+1)*(r-l+1)-(ssum[r]-(l==0?0:ssum[l-1]))-(add+1);
        if(mn>lim-add) return 0;
        else return 1;

    }
    
}


void Solve(){   
    cin>>n>>m>>k;
    rng(i,0,n-1){
        cin>>datas[i];
        sdatas[i]=datas[i];
    }
    if(n==m){
        rng(i,0,n-1) cout<<0<<' ';
        cout<<endl;
        return;
    }
    sort(sdatas,sdatas+n);
    rng(i,0,n-1) ssum[i]=(i==0?0:ssum[i-1])+sdatas[i];
    lim=k-ssum[n-1];
    //cout<<"lim "<<lim<<'\n';
    rng(i,0,n-1){
        // datas[i]+left보다 큰게 m개 이상이면 fail
        int num_big=n-(upper_bound(sdatas,sdatas+n,datas[i]+lim)-sdatas);
        if(num_big>=m){
            cout<<-1<<' ';
            continue;
        }

        ll l=0, r=lim;
        while(l<r){
            ll mid=(l+r)>>1;
            if(check(datas[i],mid)) l=mid+1;
            else r=mid;
        }
        cout<<l<<' ';
    }
    cout<<'\n';
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

