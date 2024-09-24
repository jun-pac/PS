
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

pii datas[302];
int ys[302];
int DP[302][302][302]; // [minimum alive][minimum del][maximum unresolved death]. 
// mx unresolved death == n �� ���� ���ٴ� ��. ���������� �� ��츸 ������� �Ѵ�.

// minimum del �̻󿡴� ������ �� �� ����
// maximum unresolved death �̻󿡴� ���� �ϳ��� del�� �ϰ� (���)�־�� ��
// minimum alive �̻󿡴� ������ del�� �� �� ���� 

// minimum del > maximum unresolved�� �����ؾ��Ѵٴ� ���.
// minimum alive > maximum unresolved death �̾�� ��

int mx[302][302], mn[302][302];

void Solve(){
    int n;
    cin>>n;
    rng(i,0,n-1){
        int x,y;
        cin>>x>>y;
        x--, y--; 
        datas[i]={x,y};
        ys[x]=y;
    }
    if(n==1){
        cout<<1<<'\n';
        return;
    }
    rng(i,0,n-1){
        mx[i][i]=ys[i];
        mn[i][i]=ys[i];
        rng(j,i+1,n-1){
            mx[i][j]=max(mx[i][j-1],ys[j]);
            mx[i][j]=min(mx[i][j-1],ys[j]);
        }
    }
    // ���Ÿ� ������ ���� �׳� ������� �� ���̾ƿ��� ���� ������ ���?
    // �ϳ���� �밢���������� �ִ���? �� �߿��Ѱ� �ƴ�?
    
    // 0��°�� �׾���
    DP[n][n][ys[0]]=1;

    // 0��°�� ��ư�� ������.
    DP[ys[0]][ys[0]][n]=1; // 0�̻󿡴� ������ ��ư�� ������ �Ѵٴ� ���ε� ��� unresolved death�� ������ ��ؾ��ϴ��� �𸣰ڳ�
    
    // 0��°�� ��ư�� �ȴ�����, ��� ��쿡�� ��ư�� ������ �Ͱ� �̰� �ٸ� ��쿡�� ī��Ʈ�� �����ش�.
    if(!mx[1][n-1]<ys[0]){
        DP[ys[0]][n][n]=1;
    }
    // if((i==n-1 && mn[0][i-1]>ys[i]) || (mn[0][i-1]>ys[i] && mx[i+1][n-1]<ys[i]))

    // [minimum alive][minimum del][maximum unresolved death]. 
    rng(i,1,n-1){
        stack<array<int,4>> st;
        // i,ys[i]���� del�� �ϴ� ���
        // mndel, mnalive > ys[i]�� �͸� ��ȿ�ϸ�,
        // mxunresolve < ys[i]�� ��� ���� �ذ�ȴ�.

        // �׾��� ���
        // mndel�� ys[i]���� ������ death, �׷��� ������ unresolved�� �ȴ�.
        // mnalive�� �̺��� ���� �� �ִ�.
        // 
    }

    // ���������� unresolved death�� ���� �͸� ����Ѵ�. 
    ll res=0;

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

