
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
#define INF 1000000000000000000 
// random_device rd; 
// mt19937 gen(rd());
// uniform_int_distribution<> dist(0, INF); // random integer from [0, INF] // dist(gen)

array<ll,3> datas[N];
vc<ll> c11, c10, c01;
ll s11[N], s10[N], s01[N], ss10[N], ss01[N];

void Solve(){
    int n;
    cin>>n;
    rng(i,0,n-1) cin>>datas[i][1]; // cost,a,b
    rng(i,0,n-1) cin>>datas[i][2];
    rng(i,0,n-1) cin>>datas[i][0];
    rng(i,0,n-1){
        if(datas[i][1]==1 && datas[i][2]==1) c11.pb(datas[i][0]);
        else if(datas[i][1]==1 && datas[i][2]==0) c10.pb(datas[i][0]);
        else if(datas[i][1]==0 && datas[i][2]==1) c01.pb(datas[i][0]);
    }
    sort(all(c11));
    sort(all(c10));
    sort(all(c01));
    reverse(all(c11));
    reverse(all(c10));
    reverse(all(c01));

    int n11=c11.size(), n10=c10.size(), n01=c01.size();
    // cout<<"n11 n10 n01 : "<<n11<<' '<<n10<<' '<<n01<<'\n';
    

    rng(i,0,n11-1) s11[i]=(i==0?0:s11[i-1])+c11[i];
    rng(i,0,n10-1) s10[i]=(i==0?0:s10[i-1])+c10[i];
    rng(i,0,n01-1) s01[i]=(i==0?0:s01[i-1])+c01[i];
    rng(i,0,n10-1) ss10[i]=(i==0?0:ss10[i-1])+i*c10[i];
    rng(i,0,n01-1) ss01[i]=(i==0?0:ss01[i-1])+(i+1)*c01[i];
    
    // rng(i,0,n11-1) cout<<s11[i]<<'\n';
    // cout<<'\n';

    ll mn=INF;
    ll cur11=0, cur10=0, cur01=0;
    rng(k,0,n11){
        // k개를 1->0 0->1한다면
        ll num=n10+n01+2*k;// total operations
        if(k==0){
            cur11=num*((0==n11)?0:s11[n11-1]);
            cur10=ss10[n10-1];
            cur01=ss01[n01-1];
        }
        
        else{
            cur11+=-(num-2)*(s11[n11-1]-(k==1?0:s11[k-2]))+num*(s11[n11-1]-s11[k-1]);
            ll l=0, r=n10-1;
            if(n10==0||c10[0]<=c11[k-1]) l=-1;
            else{
                while(l<r){
                    ll mid=(l+r+1)>>1;
                    if(c10[mid]>c11[k-1]) l=mid;
                    else r=mid-1; 
                }
            }
            cur11+=(l+1+k-1)*c11[k-1];
            cur10+=(n10==0?0:s10[n10-1])-(l==-1?0:s10[l]);


            l=0, r=n01-1;
            if(n01==0||c01[0]<=c11[k-1]) l=-1;
            else{
                while(l<r){
                    ll mid=(l+r+1)>>1;
                    if(c01[mid]>c11[k-1]) l=mid;
                    else r=mid-1; 
                }
            }
            cur11+=(l+1+k)*c11[k-1];
            cur01+=(n01==0?0:s01[n01-1])-(l==-1?0:s01[l]);
        }

        mn=min(mn,cur11+cur10+cur01);

        // cout<<"K : "<<k<<' '<<cur11<<' '<<cur10<<' '<<cur01<<'\n';
    }
    cout<<mn<<'\n';
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

