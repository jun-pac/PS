
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
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

#define N 500030
#define MOD 998244353
#define INF 1000000007 

ll DP[N][2];
vc<int> edges[N];
ll datas[N];
bool visited[N];
ll res;

ll DFS(int idx, bool is_root){
    visited[idx]=1;
    int n=edges[idx].size();
    vc<ll> vals; // ���� �ֺ��� n���� ����
    // n==1�� ���� ���� ó��
    // DP[idx]�� idx�� root��� �����Ͽ� �ִ��� ��.
    // ���� compress�Ǵ��� �������� �ٸ� ����� compression�� ������ �� ��ħ.
    // idx�� leaf-out�� �� �ƴϱ� ������ ������ �� ����.
    // ���� 0�ϼ��� �ְ��
    // �� �θ� ����� ��, �׾��� �� ������ ���
    // �θ� �״´ٰ� �ϸ� �̰� ����.

    res=max(res,datas[idx]);
    for(auto next : edges[idx]){
        if(!visited[idx]){
            vals.pb(DFS(next,0));
        }
    }
    sort(all(vals));
    int pcnt=0; // child�߿� 0�̻��̸� 
    ll psum=0;
    rng(i,0,(int)vals.size()-1){
        if(vals[i]>=0) pcnt++;
        if(vals[i]>=0) psum+=vals[i];
    }
    rng(i,0,(int)vals.size()-1){
        
    }

    // Managing deleted parent
    // End case itself
    // Just maximize internally
    ll res=psum+datas[idx];
    if(pcnt==2){

    }
    


    // Managing DP[idx]
    if(!is_root){
        
    }
    else{
        // ���ʿ� �߰��Ǵ� node�� ����
    }
}

void Solve(){
    int n;
    cin>>n;
    rng(i,0,n-1){
        cin>>datas[i];
    }
    rng(i,0,n-1) edges[i].clear();
    int a,b;
    rng(i,0,n-2){
        cin>>a>>b;
        a--, b--;
        edges[a].pb(b);
        edges[b].pb(a);
    }
    
    int rt;
    rng(i,0,n-1){
        if(edges[i].size()==1){
            rt=i;
            break;
        }
    }
    // root�� �� ��ü�� leaf��
    res=0;
    DFS(rt,1);
    cout<<res<<'\n';
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

