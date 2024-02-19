
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

string datas,tar;
int cur_mat[N]; // 현재 tar의 idx가 어떻게 datas[idx]로 되는지?

void Solve(){
    int n,m;
    cin>>n>>m;
    cin>>datas>>tar;
    // subseq가 존재함은 보장이 되는데 가장 멀리?
    // 최대한 앞으로 DP를 하고 하나씩 뒤로 보내는
    // LCS가 아니라 tar가 정해져있구나
    int cur=0;
    rng(i,0,m-1){
        while(cur<n && datas[cur]!=tar[i]) cur++;
        cur_mat[i]=cur;
        cur++;
    }
    assert(cur<=n);

    int mx=1;
    cur=n-1;
    gnr(k,m-1,1){
        // k개를 앞으로 밀어붙이는 전략. k개 <-> 나머지의 거리만 따지면 충분? ㅇㅇ
        int ori=cur_mat[k];
        while(cur>=0 && datas[cur]!=tar[k]) cur--;
        cur_mat[k]=cur;
        cur--;
        assert(cur_mat[k]>=ori);
        mx=max(mx,cur_mat[k]-cur_mat[k-1]);
    }
    cout<<mx<<'\n';
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

