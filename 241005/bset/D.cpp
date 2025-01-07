
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

int datas[N];
int n;
ll sum[N];
int mx=0;

ll calc(ll a, ll b){
    ll cur=0;
    if(a>b) return cur;
    if((b-a+1)%2==0){
        cur=sum[b]-(a<=0?0:sum[a-1]);
    }
    else{
        cur=max(sum[b]-sum[a],sum[b-1]-(a<=0?0:sum[a-1]));
    }
    return cur;
}

ll get_mx(int mn){
    // mn이상만 사용가능
    int last=-1;
    bool flag=0;
    ll wo_mx=0;
    ll mx_gain=-INF; // mx를 보유해서 발생하는 최대의 gain (mx를 더하는 것을 포함)
    rng(i,0,n-1){
        if(datas[i]<mn){
            if(flag){
                // [l,i-1]
                int a=last, b=i-1;
                flag=0;
                ll cur=calc(a,b);
                wo_mx+=cur;
                // mx를 강제적으로 보유한다고 하면 어찌되는가?
                rng(j,a,b){
                    if(datas[j]==mx){
                        // [last,j-2], [j+2,i-1] 을 생각하자
                        mx_gain=max(mx_gain,calc(a,j-2)+calc(j+2,b)+mx);
                    }
                }
            }
        }
        else{
            if(!flag){
                flag=1;
                last=i;
            }
        }
    }
    if(flag){
        int a=last, b=n-1;
        flag=0;
        ll cur=calc(a,b);
        wo_mx+=cur;
        // mx를 강제적으로 보유한다고 하면 어찌되는가?
        rng(j,a,b){
            if(datas[j]==mx){
                // [last,j-2], [j+2,i-1] 을 생각하자
                mx_gain=max(mx_gain,calc(a,j-2)+calc(j+2,b)+mx);
            }
        }
    }
    return wo_mx+max(0LL,mx_gain);
}



long long ternary(long long s, long long e){
    while(3<=e-s){
        long long l=(s+s+e)/3, r=(s+e+e)/3;
        if(get_mx(l)<get_mx(r)) s=l;
        else e=r;
    }
    long long mx=0, res;
    for(long long i=s; i<=e; i++){
        long long temp=get_mx(i);
        if(mx<temp) mx=temp, res=i;
    }
    return res;
}



void Solve(){
    cin>>n;
    rng(i,0,n-1) cin>>datas[i];
    sum[0]=datas[0];
    sum[1]=datas[1];
    rng(i,2,n-1) sum[i]=sum[i-2]+datas[i];
    mx=0;
    rng(i,0,n-1) mx=max(mx,datas[i]);
    cout<<ternary(0,mx)<<endl;
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

