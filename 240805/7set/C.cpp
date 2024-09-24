
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

vector<int> edges[1005];
int n;
int nums[1005];

vector<pair<double, double>> ans;

void run_dfs(int cur, int par, double bef_y){
    double cur_x, cur_y, par_x;

    if(par == -1){
        cur_x = 0.0;
        cur_y = 0.0;
    }else{
        cur_x = (double)nums[cur] / 10000.0;
        par_x = (double)nums[par] / 10000.0;
        cur_y = bef_y + sqrt((double)1.0 - (cur_x - par_x) * (cur_x - par_x));
    }
    ans[cur].first = cur_x;
    ans[cur].second = cur_y;
    for(int k: edges[cur]){
        if(k == par) continue;
        run_dfs(k, cur, cur_y);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin>>n;
    ans.resize(n);
    for(int i=0;i<n-1;i++){
        int a, b;
        cin>>a>>b;
        --a; --b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    int cnt = 0;
    queue<pair<int, int>> Q;
    Q.push({0, -1});
    while(!Q.empty()){
        auto pa = Q.front();
        int cur = pa.first;
        int par = pa.second;
        Q.pop();
        nums[cur] = cnt;
        cnt++;
        for(int k: edges[cur]){
            if(k==par) continue;
            Q.push({k, cur});
        }
    }
    run_dfs(0, -1, 0.0);
    cout<<setprecision(15);
    for(int i=0;i<n;i++){
        cout<<ans[i].first<<' '<<ans[i].second<<'\n';
    }

    
    
    return 0;
}

