
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
#define INF 10000000000007 

// 어떤 포인트들이 있을거고 그건 많아봐야 n개일거기 때문에 small to large가 될 것이다.

ll datas[5005];
vc<int> edges[5005];
map<ll,ll> mp[5005];
ll offset[5005];
// 나를 최소 어디까지 올려야 하는지,
// 그게 얼마나 돈이 필요한 일인지   
// 거기보다 더 올리기 위해서는 구간별로 얼마를 지불해야 하는지

pll DFS(int idx, int p){
    if(idx!=0 && edges[idx].size()==1){
        mp[idx][1]=INF; // 추가된 부분에 대해서만 따지면 되는 듯 하다
        //cout<<"here "<<mp[idx].size()<<'\n';
        return {datas[idx],0};
    }
    ll largest_idx=-1;
    ll val_sum=0, cost_sum=0;

    for(int i=0; i<edges[idx].size(); i++){
        int next = edges[idx][i];
        if(next==p) continue;
        auto temp=DFS(next,idx);
        val_sum+=temp.fi;
        cost_sum+=temp.se;

        if(largest_idx==-1 || mp[next].size()>mp[largest_idx].size()) largest_idx=next;
    }
    swap(mp[idx],mp[largest_idx]);
    offset[idx]=offset[largest_idx]+1; // 이건 그냥 모든 k에 +1을 해주는 개념임
    // cout<<"largest "<<idx<<' '<<largest_idx<<' '<<mp[idx].size()<<' '<<mp[largest_idx].size()<<'\n';
    
    for(auto next : edges[idx]){
        if(next==p || next==largest_idx) continue;
        for(auto [k,v] : mp[next]){
            // k+1+offset[next]가 실제 value
            // k+1+offset[next]-offset[idx]를 해줘야 하는 것이죠
            if(v!=0) mp[idx][k+1+offset[next]-offset[idx]]+=v;
            //if(mp[idx][k+1+offset[next]-offset[idx]]>INF) mp[idx][k+1+offset[next]-offset[idx]]=INF;
        }
        //mp[next].clear(); // To save memory. small-to-large setting에서는 필요 없긴 하다.
    }

    if(val_sum<=datas[idx]){
        ll left=datas[idx]-val_sum;
        ll cost=0;
        //cout<<mp[idx].size()<<'\n';
        for(auto [k,v] : mp[idx]){
            if(v>=left){
                //cout<<"add "<<idx<<' '<<left<<' '<<k+offset[idx]-1<<'\n';
                cost+=left*(k+offset[idx]-1);
                mp[idx][k]-=left;
                left=0;
                break;
            }
            else{
                cost+=v*(k+offset[idx]-1);
                left-=v;
                mp[idx][k]=0;
            }
        }
        return {datas[idx],cost_sum+cost}; // datas[idx]-val_sum만큼 이미 올림
    }
    else{
        // datas[idx] < val_sum 인 상황으로 별 반응이 필요가 없음
        mp[idx][1-offset[idx]]+=val_sum-datas[idx];
        return {datas[idx],cost_sum};
    }
}

void Solve(){
    int n;
    cin>>n;
    rng(i,0,n-1) edges[i].clear();
    rng(i,0,n-1) mp[i].clear();
    rng(i,0,n-1) cin>>datas[i];
    fill(offset,offset+n,0);

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

