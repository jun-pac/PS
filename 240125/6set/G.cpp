
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
// i�������� {i,i}->{i,j}���� ���Һ��� ���� j�� neighbor�� Ȯ���ϱ� �ѵ�, �������� �� �� ����.
// weight_ij*(number of j's subtree, if i is root)
// {i,i}�߿� ���� ū ���� leaf���� Ȯ���ϴ�. �������� ������� �ʴ´�. -> l
// leaf�� Ȯ���� l�� �θ� ã�ƺ���.{l,j}�� l�����ϰ� ���� ū �� �θ���� -> p
// �׷� w_lp�� ���� ������ ���� �� ����.

// p���ʹ� �������� neighbor�� ���� �� �ִٴ� �� ������.
// {l,x}�� {p,x}�� ���踦 ����. ������ x�� ���� �̰� ���� w_lp��ŭ�� ���� ���̴�.
// �̰͵� ���� ���� ���� ������ �༮�� ����� �ִ� �� ����. ������ �������ų� ã�� ������ �ٽ� ���ƿ� ��
// �׸��� ������ �� ���� leaf�� ������ �̰� leaf���� �𸣰� min�� �����ع������� �־ �ȵ�.
// i--x--y��� iy<ix, iy<xy ������ x--i--y��� xy<ix, xy<iy, i--y--x�̸� ix<iy, ix<xy
// iy�� xy�� ����� y�� ��ġ�� �� �� �ֳ׿�

// i�� ����� �༮�� ã�� �����, � y�� ���ؼ�, ��� x�� (xy<ix && xy<iy) || (ix<iy && ix<xy)
// 2���� �������� �ȵǴ°�?

// ������Ʈ�� �ø��� Ǯ�̸� ������ ��, � ������Ʈ���� ���� ���� ������ ���� ū �ִ� ��������� �ʳ�

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

