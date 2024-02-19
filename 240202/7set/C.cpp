
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
int cur_mat[N]; // ���� tar�� idx�� ��� datas[idx]�� �Ǵ���?

void Solve(){
    int n,m;
    cin>>n>>m;
    cin>>datas>>tar;
    // subseq�� �������� ������ �Ǵµ� ���� �ָ�?
    // �ִ��� ������ DP�� �ϰ� �ϳ��� �ڷ� ������
    // LCS�� �ƴ϶� tar�� �������ֱ���
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
        // k���� ������ �о���̴� ����. k�� <-> �������� �Ÿ��� ������ ���? ����
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

