
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

int A[1000][1000];
int B[1000][1000];
int btemp[1000][1000], rowsum[1000], colsum[1000];
bool visited[1000][1000];

void Solve(){
    int n,m;
    cin>>n>>m;
    rng(i,0,n-1){
        rng(j,0,m-1) cin>>A[i][j];
    }
    rng(i,0,n-1){
        rng(j,0,m-1) cin>>B[i][j];
    }
    rng(k,0,29){
        // subproblem
        // B를 역으로 제거해나가는 아이디어인데
        rng(i,0,n-1) fill(visited[i],visited[i]+m,0);
        rng(i,0,n-1){
            rng(j,0,m-1) btemp[i][j]=((B[i][j]&(1<<k))?1:0);
        }
        rng(i,0,n-1){ // rowsum
            int temp=0;
            rng(j,0,m-1) temp+=btemp[i][j];
            rowsum[i]=temp;
        }
        rng(j,0,m-1){
            int temp=0;
            rng(i,0,n-1) temp+=btemp[i][j];
            colsum[j]=temp;
        }
        int rowsum_tar=0, colsum_tar=n;
        stack<int> rowhit, colhit;
        rng(i,0,n-1) if(rowsum_tar==rowsum[i]) rowhit.push(i);
        rng(j,0,m-1) if(colsum_tar==colsum[j]) colhit.push(j);
        while(!rowhit.empty() || !colhit.empty()){
            while(!rowhit.empty()){
                int r=rowhit.top();
                rowsum[r]=-INF;
                rng(j,0,m-1) visited[r][j]=1;
                rowhit.pop();
                colsum_tar--;
            }
            while(!colhit.empty()){
                int c=colhit.top();
                colsum[c]=-INF;
                rng(i,0,n-1) visited[i][c]=1;
                colhit.pop();
                rowsum_tar++;
            }
            rng(i,0,n-1) if(rowsum_tar==rowsum[i]) rowhit.push(i);
            rng(j,0,m-1) if(colsum_tar==colsum[j]) colhit.push(j);
        }
        rng(i,0,n-1){
            rng(j,0,m-1){
                if(!visited[i][j]){
                    if(btemp[i][j] && !(A[i][j]&(1<<k))){
                        cout<<"No\n";
                        return;
                    }
                    if(!btemp[i][j] && (A[i][j]&(1<<k))){
                        cout<<"No\n";
                        return;
                    }
                }
            }
        }
    }
    cout<<"Yes\n";
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

