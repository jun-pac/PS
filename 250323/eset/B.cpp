
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

int a[N];
int b[N];
int parent[N];
set<int> baset[N]; // ������ b�� ���� aset. a�� idx�� ������ ����ϴ�.
priority_queue<pii> pq; // -dist, bidx // min dist�� ã�ƾ� �ϹǷ�. ���� dist��� ������ �ǹ̰� ����.

int find_root(int idx){
    if(idx==parent[idx]) return idx;
    return parent[idx]=find_root(parent[idx]);
}

int get_last_a(int bidx){
    if(baset[bidx].upper_bound(bidx)==baset[bidx].begin()) return (*prev(baset[bidx].end()));
    else return (*prev(baset[bidx].upper_bound(bidx)));
}

void Solve(){
    int n,k;
    cin>>n>>k;
    assert(k==0);
    rng(i,0,n-1) cin>>a[i];
    rng(i,0,n-1) cin>>b[i];
    rng(i,0,n-1) parent[i]=i; // b parent
    rng(i,0,n-1) baset[i].clear();
    while(!pq.empty()) pq.pop();

    rng(i,0,n-1){
        if(a[i]!=0){
            baset[i].insert(i);
            pq.push({-0,i}); // dist�� b idx�� ��� ����ϴ�.
        }
    }
    int mx=0;

    while(!pq.empty()){
        pii temp=pq.top();
        int dist=-temp.fi;
        int bidx=temp.se;
        assert(bidx==find_root(bidx));
        pq.pop();

        int aidx=get_last_a(bidx);
        // baset[bidx]���� bidx������ �� �� ���� ū ��.
        // bidx���� ū ���� ���ʿ� bidx+1�� ������ ���� �ʳ�?

        mx=max(mx,dist);
        if(a[aidx]<=b[bidx]){
            baset[bidx].erase(aidx);
            if(a[aidx]<b[bidx] && baset[bidx].size()!=0){
                int naidx=get_last_a(bidx);
                pq.push({-(bidx-naidx+(bidx-naidx<0?n:0)),bidx});
            }
        }
        if(a[aidx]>=b[bidx]){
            // baset[bidx]�� ��� ���Ҹ� baset[(bidx+1)%n]���� �ű�. small to large���.
            // ���� baset[(bidx+1)%n]�� ���Ұ� �����ٸ� pq update
            int next_root=find_root((bidx+1)%n);
            if(next_root==bidx){
                cout<<mx+1<<'\n';
                return;
            }
            // assert(next_root!=bidx);

            int next_size=baset[next_root].size();
            if(next_size<baset[bidx].size()){
                swap(baset[next_root],baset[bidx]);
            }
            for(auto k: baset[bidx]) baset[next_root].insert(k);
            if(next_size==0 && baset[next_root].size()!=0){ // ���� 0�̾����� pq�� ���ο� �� �־��� �ʿ䰡 ����
                int naidx=get_last_a(next_root);
                pq.push({-(next_root-naidx+(next_root-naidx<0?n:0)),next_root});
            }
            baset[bidx].clear();
            parent[bidx]=next_root;            
        }
        int v=min(a[aidx],b[bidx]);
        a[aidx]-=v;
        b[bidx]-=v;
    }
    cout<<mx+1<<'\n';
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

