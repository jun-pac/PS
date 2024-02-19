
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

pii datas[N];
int s_r[N], s_l[N];
int mx[1000010];
int DP[1000010];
int sorted_l[N];
set<pii> reserve;

void Solve(){
    int n,m;
    cin>>n>>m;
    rng(i,0,m-1) cin>>datas[i].se>>datas[i].fi;
    rng(i,0,m-1) sorted_l[i]=datas[i].se;
    sort(sorted_l,sorted_l+m);
    sort(datas,datas+m);
    fill(mx,mx+n+1,0);
    reserve.clear();
    rng(i,0,m-1){
        s_r[i]=datas[i].fi; // 오름차순
        s_l[i]=datas[i].se;
        reserve.insert({s_l[i],s_r[i]});
    }

    int curm=0;
    rng(i,1,n){
        //int l=s_l[i], r=s_r[i]; // r만 increasing
        //cout<<"lr "<<l<<' '<<r<<'\n';
        int pre_mx=0;
        auto temp=reserve.begin();

        if(temp==reserve.end()) pre_mx=0;
        else{

            pii last=*reserve.begin();
            //cout<<"last "<<last.fi<<'\n';
            pre_mx=(last.fi==0?0:mx[last.fi-1]);            
        }
        int largenum=m-(upper_bound(sorted_l,sorted_l+m,i)-sorted_l);
        int cur_num=m-curm-largenum;
        
        //assert(cur_num>=1);
        // r보다 큰 것 : 
        DP[i]=cur_num+pre_mx;
        mx[i]=max(DP[i],(i==0?0:mx[i-1]));
        while(curm<m && s_r[curm]<=i){
            reserve.erase({s_l[curm],s_r[curm]});
            curm++;
        }

        //cout<<"i premx, curnum, mx, large : "<<i<<' '<<pre_mx<<' '<<cur_num<<' '<<mx[i]<<' '<<largenum<<'\n';

    }
    int res=0;
    //rng(i,0,m-1) res=max(res,mx[i]); 
    cout<<mx[n]<<'\n';
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

