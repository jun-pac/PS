
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

// leaf <=> {leaf,leaf} > {neigh,neigh} for all neighbor. But how to find neighbor?
// {i,i}+{j,j}=2*{i,j}+n*weight_ij
// i기준으로 {i,i}->{i,j}가장 감소분이 적은 j는 neighbor가 확실하긴 한데, 나머지는 알 수 없음.
// weight_ij*(number of j's subtree, if i is root)
// {i,i}중에 가장 큰 것은 leaf임은 확실하다. 나머지는 보장되지 않는다. -> l
// leaf가 확실한 l의 부모를 찾아보자.{l,j}중 l제외하고 가장 큰 게 부모겠죠 -> p
// 그럼 w_lp는 위의 식으로 구할 수 있음.

// p부터는 여러개의 neighbor가 있을 수 있다는 게 문제다.
// {l,x}와 {p,x}의 관계를 생각. 임의의 x에 대해 이건 단지 w_lp만큼만 작을 뿐이다.
// 이것도 이제 가장 적게 감소한 녀석은 연결돼 있는 건 맞음. 연결이 여러개거나 찾은 점으로 다시 돌아올 때
// 그리고 연결이 더 없는 leaf를 만나도 이게 leaf인지 모르고 min을 연결해버릴수도 있어서 안됨.
// i--x--y라면 iy<ix, iy<xy 이지만 x--i--y라면 xy<ix, xy<iy, i--y--x이면 ix<iy, ix<xy
// iy와 xy의 관계로 y의 위치를 알 수 있네요

// i와 연결된 녀석을 찾는 방법은, 어떤 y에 대해서, 모든 x가 (xy<ix && xy<iy) || (ix<iy && ix<xy)
// 2등이 여러개면 안되는거?

// 컴포넌트를 늘리는 풀이를 생각할 때, 어떤 컴포넌트에서 한쪽 끝을 가지는 가장 큰 애는 연결돼있지 않나

ll datas[2020][2020];
bool visited[N];
priority_queue<array<ll,3>> pq;
vc<array<ll,3>> ans;

void Solve(){
    ll n;
    cin>>n;
    rng(i,0,n-1){
        rng(j,0,i){
            cin>>datas[i][j];
            if(j!=i) datas[j][i]=datas[i][j];
        }
    }
    int cnt=0;
    int idx=0;
    visited[0]=1;
    rng(i,1,n-1) pq.push({datas[i][0],0,i});
    while(cnt<n-1){
        while(!pq.empty() && (visited[pq.top()[1]] && visited[pq.top()[2]])) pq.pop();
        assert(!pq.empty());
        auto temp=pq.top();
        ll i=temp[1],j=temp[2],w=datas[i][i]+datas[j][j]-2*datas[i][j];
        w/=n;
        if(!visited[i]){
            visited[i]=1;
            rng(k,0,n-1) if(!visited[k]) pq.push({datas[i][k],i,k}); 
        }
        else if(!visited[j]){
            visited[j]=1;
            rng(k,0,n-1) if(!visited[k]) pq.push({datas[j][k],j,k}); 
        }
        ans.pb({i+1,j+1,w});
        cnt++;
    }
    rng(i,0,(int)ans.size()-1) cout<<ans[i][0]<<' '<<ans[i][1]<<' '<<ans[i][2]<<'\n';
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

