
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

map<ll,ll> DP[N]; // ���� ��� {color, num} -> violation�� ���ϰ� ���� �� �ִ� ������
int datas[N];
int n;
vc<int> edges[N];
ll res;

void DFS(int idx, int p){
    for(auto next:edges[idx]){
        if(next==p) continue;
        DFS(next,idx);
        res=(res+DP[next][datas[idx]])%MOD;
        if(DP[next].size()>DP[idx].size()) swap(DP[next], DP[idx]);
    }
    if(idx!=0 && edges[idx].size()==1){ // leaf
        DP[idx][datas[idx]]=1;
        return;
    }

    //cout<<"IDX "<<idx+1<<'\n';
    for(auto next : edges[idx]){
        if(next==p) continue;
        //cout<<"NXT "<<next+1<<'\n';
        for(auto [col,val] : DP[next]){
            //cout<<"next's "<<col<<' '<<val<<'\n';
            if(DP[idx][col]==0){
                DP[idx][col]=val;
            }
            else{
                ll ori=DP[idx][col];
                DP[idx][col]=((ori+1)*(val+1)-1)%MOD;
                res=(res+ori*val)%MOD;
            }
        }
    }
    DP[idx][datas[idx]]++; // �ϳ��� �ִ� ���� �߰����� combination�� ������ ����. res�� ������ �̹� ���
    // for(auto [col,val] : DP[idx]){
    //     cout<<"["<<col<<' '<<val<<"] ";
    // }
    // cout<<'\n';
    // ���� ������ ���̽��� ��� idx�� �������� Ȧ�� ���������� �ʴ� ���̴�.
    // �ٵ� �̰� 2�� �̻��� �̴� ������ ������ �־��� �ٵ� �� �� �ִ°ɷ� �̷��� �ص� �Ǵ°�?
    // �ᱹ ������ ���ϴ� ���� ������ �����ٺ��� violation (�θ� �ڼհ��迡�� �� �� ����)���� 1�� �̻� �̴� combination��
    // �̰� �� ���ؾ� �ϴ� �� �´�. 
    // 1�� �̻��� �̴°Ŵ� �˰ڳ�
    // (1�� �̻� + 1)*(1�� �̻� + 1)* ... *()�� �ϸ� ��� �Ǵ°���
    // �׷��� �������� �� ������ 1�� (sum)(1�� �̻�)���� �� �ö󰡸� �ȵǴ� ��. 
    // �̰� �׳� map�� ���� �ϳ�
    // �׶��׶� merge�� �ϴ� ����� ����?
}

void Solve(){
    cin>>n;
    rng(i,0,n-1) cin>>datas[i];
    rng(i,0,n-2){
        int a,b;
        cin>>a>>b;
        a--, b--;
        edges[a].pb(b), edges[b].pb(a);
    }
    res=0;
    DFS(0,-1);
    cout<<((res+n)%MOD+MOD)%MOD<<'\n';
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

