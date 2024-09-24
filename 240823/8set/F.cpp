
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

pii datas[N];
int DP[1000][101]; // n���� �Ἥ k�� ������� ����. ���� target�� ���� �ʰ�.
// �׶��� �ּ� cost�ΰŰ�. action�� 2���� �ۿ� ���°Ű�
// �̰� �� ���ĵ� �ʿ䰡 ����. �׳� minimum�̶�
// 1����� ������ �ʿ�.

void Solve(){
    int n,k;
    cin>>n>>k;
    int s=0;
    rng(i,0,n-1){
        int a,b;
        cin>>a>>b;        
        if(a>b) swap(a,b);
        datas[i].fi=a, datas[i].se=b;
        s+=a+b;
    }
    if(s<k){
        cout<<-1<<'\n';
        return;
    }

    int mn=INF;
    rng(t,0,n-1){
        // t�� ���� final�� ���ؼ� �� ���̴ϴ�
        // �ٵ� t�� ��ä���� ���� �͵� ���ǻ� ������ �սô�.
        fill(DP[0],DP[0]+k+1,INF); // �ּҰ��̴� INF
        DP[0][0]=0;
        rng(i,0,n-1){
            int a=datas[i].fi, b=datas[i].se;
            if(i==t){
                if(i==0) continue;
                else rng(j,0,k) DP[i][j]=DP[i-1][j];
            }
            else{
                if(i!=0){
                    rng(j,0,k) DP[i][j]=DP[i-1][j];
                    rng(j,0,k-a-b) DP[i][j+a+b]=min(DP[i-1][j]+a*b,DP[i][j+a+b]);
                }
                else if(a+b<=k) DP[i][a+b]=a*b;
            }
        }
        int a=datas[t].fi, b=datas[t].se;
        if(a+b<=k) mn=min(mn,DP[n-1][k-a-b]+a*b);
        rng(i,max(0,k-(a+b-1)),k){
            int togo=k-i;
            if(togo<=b-a) mn=min(mn,DP[n-1][i]+togo*a);
            else mn=min(mn,DP[n-1][i]+a*b-((a+b-togo)/2)*((a+b-togo+1)/2));
        }
    }
    cout<<mn<<'\n';
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

