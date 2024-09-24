
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

#define N 400030
#define MOD 998244353
#define INF 1000000007 
random_device rd; 
mt19937 gen(rd());
uniform_int_distribution<> dist(0, INF); // random integer from [0, INF] // dist(gen)

ll datas[N];
ll sum[N];
ll k,n;
int st_idx[N]; // 어떤 i에서 시작했는지
int last_idx[N]; // 해당 st_idx에서 last_idx가 뭐였는지

bool check(ll val){
    // 모든 조각이 val이상이 되도록.
    // i==0일때 시작하는 scheme을 해서 k-1이상이 나올때만 의미가 있음
    fill(st_idx,st_idx+2*n,-1);
    int num=0;
    int curidx=-1;
    st_idx[curidx]=0;
    while(curidx<0+n){
        if(sum[0+n]-(curidx==-1?0:sum[curidx]) < val) break;
        num++;
        int l=curidx, r=0+n;
        while(l<r){
            int mid=(l+r)>>1;
            if(sum[mid]-(curidx==-1?0:sum[curidx])>=val) r=mid;
            else l=mid+1;
        }
        curidx=l;
        st_idx[curidx]=0;
    }
    last_idx[0]=curidx;
    if(num>=k) return 1;
    if(num<k-1) return 0;

    rng(i,1,n-1){
        if(sum[i]>=k) break;
        num=0;
        curidx=i-1;
        st_idx[curidx]=i;
        while(curidx<i+n){
            if(sum[i+n]-(curidx==-1?0:sum[curidx]) < val) break;
            num++;
            int l=curidx, r=i+n;
            while(l<r){
                int mid=(l+r)>>1;
                if(sum[mid]-(curidx==-1?0:sum[curidx])>=val) r=mid;
                else l=mid+1;
            }
            curidx=l;
            if(st_idx[curidx]!=-1){
                int lidx=last_idx[st_idx[curidx]];   
                if(sum[i+n]-sum[lidx]>=val) return 1;
                else last_idx[i]=lidx;    
            }
            st_idx[curidx]=i;
        }

        if(num>=k) return 1;
        last_idx[i]=curidx;
    }   

    return 0; 
}

void Solve(){    
    cin>>k>>n;
    rng(i,0,n-1) cin>>datas[i];
    rng(i,0,n-1) sum[i]=(i==0?0:sum[i-1])+datas[i];
    rng(i,0,n-1) sum[i+n]=sum[i+n-1]+datas[i];

    ll l=1, r=sum[n-1];
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
    //cin>>t;
    while(t--){
        Solve();
    }
    return 0;
}

