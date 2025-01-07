
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

int p[N], res[N];
int loop_num[N];
bool visited[N];

void DFS(int idx, vc<int> &con){
    visited[idx]=1;
    con.push_back(idx);
    if(!visited[p[idx]]){
        DFS(p[idx],con);
    }
}

void Solve(){
    ll n,k;
    cin>>n>>k;
    rng(i,0,n-1) cin>>p[i];
    rng(i,0,n-1) p[i]--;
    ll numm=min(20LL,k);
    k-=numm;
    rng(t,0,numm-1){
        rng(i,0,n-1) res[i]=p[p[i]]; // 짝수사이클 제거
        rng(i,0,n-1) p[i]=res[i];
    }
    if(k==0){
        rng(i,0,n-1) cout<<p[i]+1<<' ';
        return;
    }
    rng(i,0,n-1) res[i]=p[i];

    rng(i,0,n-1){
        if(!visited[i]){
            vc<int> temp;
            DFS(i,temp);
            ll num=temp.size();
            if(num==1) continue;
            ll mul=0, teee=1;
            rng(j,0,num){
                teee=(teee*2)%num;
                mul++;
                if(teee==1) break;
            }
            //cout<<"ch "<<mul<<' '<<num-1<<'\n';
            ll curk=k%(mul);
            if(curk==0) continue;
            ll mv=1;
            rng(t,0,curk-1){
                mv=mv*2;
                mv=mv%num;
            }
            //cout<<num<<' '<<k<<' '<<curk<<' '<<mv<<'\n';
            // 모든 값을 mv만큼 이동
            int curi=i, cnt=0;
            res[curi]=temp[mv];
            curi=p[curi];
            cnt++;
            while(curi!=i){
                res[curi]=temp[(cnt+mv)%num];
                curi=p[curi];
                cnt++;
            }
        }

    }
    rng(i,0,n-1) cout<<res[i]+1<<' ';
    cout<<'\n';
    
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

