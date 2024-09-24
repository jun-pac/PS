
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
#define M 200000
#define MOD 998244353
#define INF 1000000007 
__attribute__((optimize("Ofast,unroll-loops"),target("avx,avx2,fma")))

pii datas[N];
set<pii> pp[N];

array<int,3> ccheck(int n, int d){
    rng(i,0,n-1) pp[datas[i].fi+datas[i].se+M].insert({datas[i].fi,i});
    int a=0,b=0,c=0;

    rng(i,0,n-1){
        pii aa={datas[i].fi,i};
        auto btemp=pp[datas[i].fi+datas[i].se+M].lower_bound({datas[i].fi+d/2,-1});
        if(btemp==pp[datas[i].fi+datas[i].se+M].end() || (btemp->fi)!=aa.fi+d/2) continue;
        pii bb=*btemp;
        int gap=bb.fi-aa.fi;
        assert(gap==d/2);
        
        int idx=datas[i].fi+datas[i].se+2*gap+M;
        if(idx<N && pp[idx].size()>=1){
            // bb이상의 가장 작은 놈이 bb+gap이하여야..
            auto temp=pp[idx].lower_bound({bb.fi,-1});
            if(temp!=pp[idx].end() && (temp->fi)<=bb.fi+gap){
                a=aa.se+1, b=bb.se+1, c=(temp->se)+1;
            }
        }
        idx=datas[i].fi+datas[i].se-2*gap+M;
        if(idx>=0 && pp[idx].size()>=1){
            // aa-gap이상의 가장 작은 놈이 aa이하여야..
            auto temp=pp[idx].lower_bound({aa.fi-gap,-1});
            if(temp!=pp[idx].end() && (temp->fi)<=aa.fi){
                a=aa.se+1, b=bb.se+1, c=(temp->se)+1;
            }
        }
    }

    rng(i,0,n-1) pp[datas[i].fi+datas[i].se+M].clear();
    return {a,b,c};    
}

void Solve(){
    int n,d;
    cin>>n>>d;
    rng(i,0,n-1){
        cin>>datas[i].fi>>datas[i].se;
    }
    auto res=ccheck(n,d);
    if(res[0]!=0){
        cout<<res[0]<<' '<<res[1]<<' '<<res[2]<<'\n';
        return;
    }
    rng(i,0,n-1){
        datas[i].se=-datas[i].se;
    }
    res=ccheck(n,d);
    cout<<res[0]<<' '<<res[1]<<' '<<res[2]<<'\n';
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

