
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

int cols[N];
int colcnt[N]; // 각 color의 
int outcnt[N]; // m개의 박스영역 바깥에 있는... 색별 박스의 개수
vc<int> cpos[N]; // 각각의 color들이 어느 위치에서 나오는지. 근데 2n임
pii box[N];
int offset[N];

int sum,k;

void Solve(){
    int n,m;
    cin>>n>>m>>k;
    rng(i,0,n-1){
        cin>>cols[i];
        cols[i]--;
        colcnt[cols[i]]++;
        cpos[cols[i]].pb(i);
    }
    int tot_box=0;
    rng(i,0,n-1){
        int sz=cpos[i].size();
        tot_box+=cediv(sz,k);
        rng(j,0,sz-1) cpos[i].pb(cpos[i][j]);
    }
    if(tot_box<=m){
        rng(i,0,n-1) cout<<n<<'\n';
        return;
    }

    sum=0;
    int bcnt=0;
    rng(i,0,n-1){
        int sz=colcnt[i];
        rng(j,0,cediv(sz,k)-1){
            box[bcnt++]={cpos[i][j*k],i};
        }
    }
    sort(box,box+bcnt);
    
    int mpos=box[m].fi;
    rng(i,m,bcnt-1){
        outcnt[box[i].se]++;
    }

    cout<<n+0-mpos<<'\n';
    
    rng(t,1,n-1){
        // t번 left cyclic shift를 하고 문제를 풀라는 것
        int fcol=cols[t-1]; // 맨 앞의 컬러
        int l=0, r=cediv(colcnt[fcol],k)-1;
        //if(cpos[fcol][offset[fcol]]>=mpos) 는 맨 앞에 있는 원소도 m out에 속한다는 거니 불가능
        while(l<r){
            int mid=(l+r+1)>>1;
            if(cpos[fcol][mid*k+offset[fcol]]<mpos) l=mid;
            else r=mid-1;
        }
        offset[fcol]++;
        if(cpos[fcol][l*k+offset[fcol]]>=mpos){
            int newmpos=mpos+1;
            while(newmpos<min(2*n,mpos+k)-1){
                if(cols[mpos%n]==cols[newmpos%n]) newmpos++;
                else break;
            }
            mpos=newmpos;
        }
        cout<<n+t-mpos<<'\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    while(t--){
        Solve();
    }
    return 0;
}

