
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

// 어떤 포인트들이 있을거고 그건 많아봐야 n개일거기 때문에 small to large가 될 것이다.

ll datas[5005];
vc<int> edges[5005];
set<pll> mp[5005]; // {값, 개수}
// 나를 최소 어디까지 올려야 하는지,
// 그게 얼마나 돈이 필요한 일인지
// 거기보다 더 올리기 위해서는 구간별로 얼마를 지불해야 하는지

pll DFS(int idx, int p){
    if(idx!=0 && edges[idx].size()==1){
        mp[idx].insert({1,INF}); // 추가된 부분에 대해서만 따지면 되는 듯 하다
        return {datas[idx],0};
    }
    ll val_sum=0, cost_sum=0;
    for(auto nnext : edges[idx]){
        if(nnext==p) continue;
        auto temp=DFS(nnext,idx);
        val_sum+=temp.fi;
        cost_sum+=temp.se;
        for(auto cur=mp[nnext].begin(); cur!=mp[nnext].end(); cur=next(cur)){
            ll k=cur->fi, v=cur->se;
            if(v==0) continue;
            auto tar=mp[idx].lower_bound({k+1,-1});
            if(tar==mp[idx].end() || tar->fi!=k+1){
                mp[idx].insert({k+1,v});
            }
            else{
                ll tval=tar->se;
                mp[idx].erase(tar);
                mp[idx].insert({k+1,tval+v});
            }
            //if(mp[idx][k+1]>INF) mp[idx][k+1]=INF;
        }
        mp[nnext].clear();
    }

    pll res;
    if(val_sum<=datas[idx]){
        ll left=datas[idx]-val_sum;
        ll cost=0;
        for(auto cur=mp[idx].begin(); cur!=mp[idx].end(); ){
            ll k=cur->fi, v=cur->se;
            if(v>=left){
                cost+=left*(k-1);
                mp[idx].erase(cur);
                if(v-left>0) mp[idx].insert({k,v-left});
                left=0;
                break;
            }
            else{
                cost+=v*(k-1);
                left-=v;
                auto pcur=cur;
                cur=next(cur);
                mp[idx].erase(pcur);
            }
        }
        return {datas[idx],cost_sum+cost}; // datas[idx]-val_sum만큼 이미 올림
    }
    else{
        // datas[idx] < val_sum 인 상황으로 별 반응이 필요가 없음
        mp[idx].insert({1,val_sum-datas[idx]});
        return {datas[idx],cost_sum};
    }
}

void Solve(){
    int n;
    cin>>n;
    rng(i,0,n-1) edges[i].clear();
    rng(i,0,n-1) mp[i].clear();
    rng(i,0,n-1) cin>>datas[i];
    rng(i,0,n-2){
        int a;
        cin>>a;
        a--;
        edges[a].pb(i+1);
        edges[i+1].pb(a);
    }
    cout<<DFS(0,-1).se<<'\n';
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

