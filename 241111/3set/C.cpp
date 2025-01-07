
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

int aa[N], bb[N];
int inv_aa[N];
int aa_flag[N]; // midx[aa[i]]<=midx[aa[i+1]]인 경우 flag=0
int flagsum;
int midx[N];
set<int> allidx[N];

void Solve(){
    int n,m,q;
    cin>>n>>m>>q;
    rng(i,0,n-1){
        cin>>aa[i];
        aa[i]--;
        inv_aa[aa[i]]=i;
    }
    rng(i,0,n-1) allidx[i].clear();

    rng(i,0,m-1){
        cin>>bb[i];
        bb[i]--;
        allidx[bb[i]].insert(i);
    }
    rng(i,0,n-1){
        if(allidx[i].size()==0) midx[i]=INF;
        else midx[i]=(*allidx[i].begin());
    }

    flagsum=0;
    rng(i,0,n-2){
        if(midx[aa[i]]<=midx[aa[i+1]]) aa_flag[i]=0;
        else aa_flag[i]=1;
        flagsum+=aa_flag[i];
        // INF를 제외하고는 같을 수 없기 때문에 <=로 충분하다.
        // midx[aa[i]]==0같은 조건은 flagsum==0이면 알아서 만족하는 것.
    }
    aa_flag[n-1]=0; // 언제나. 신경쓸필요 없음.

    cout<<(flagsum==0?"YA\n":"TIDAK\n");
    rng(i,0,q-1){
        int idx,t;
        cin>>idx>>t;
        idx--, t--;
        int pastnum=bb[idx];

        allidx[pastnum].erase(idx);
        midx[pastnum]=(allidx[pastnum].size()==0?INF:(*allidx[pastnum].begin()));

        allidx[t].insert(idx);
        midx[t]=(allidx[t].size()==0?INF:(*allidx[t].begin()));

        bb[idx]=t;
        
        // inv_aa[pastnum], inv_aa[pastnum]-1 update
        int k=inv_aa[pastnum];
        if(k!=n-1 && k!=-1){
            int pflag=aa_flag[k];
            aa_flag[k]=(midx[aa[k]]<=midx[aa[k+1]]?0:1);
            flagsum+=aa_flag[k]-pflag;
        }
        k=inv_aa[pastnum]-1;
        if(k!=n-1 && k!=-1){
            int pflag=aa_flag[k];
            aa_flag[k]=(midx[aa[k]]<=midx[aa[k+1]]?0:1);
            flagsum+=aa_flag[k]-pflag;
        }
        // inv_aa[t], inv_aa[t]-1 update
        k=inv_aa[t];
        if(k!=n-1 && k!=-1){
            int pflag=aa_flag[k];
            aa_flag[k]=(midx[aa[k]]<=midx[aa[k+1]]?0:1);
            flagsum+=aa_flag[k]-pflag;
        }
        k=inv_aa[t]-1;
        if(k!=n-1 && k!=-1){
            int pflag=aa_flag[k];
            aa_flag[k]=(midx[aa[k]]<=midx[aa[k+1]]?0:1);
            flagsum+=aa_flag[k]-pflag;
        }
        cout<<(flagsum==0?"YA\n":"TIDAK\n");
    }
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

