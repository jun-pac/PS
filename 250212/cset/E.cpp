
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


int datas[N], tar[N];
int match[N];

void Solve(){
    int n,m;
    cin>>n>>m;
    rng(i,0,n-1){
        rng(j,0,m-1) cin>>datas[i*m+j];
    }
    rng(i,0,n-1){
        rng(j,0,m-1) cin>>tar[i*m+j];
    }
    fill(match,match+n*m,INF);

    
    int idxa=0, idxb=0;
    int res=0;
    int last_match_b=-1;

    while(idxa<n*m && idxb<n*m){
        if(last_match_b==idxb-1){
            if(datas[idxa]==tar[idxb]){
                match[idxa]=idxb;
                last_match_b=idxb;
                idxa++; idxb++;
            }
            else{
                idxb++;
            }
        }
        else{
            if(datas[idxa]!=tar[idxb]) idxb++;
            else{
                // 같다! 근데 이게 매칭이 되는거?
                // [idxa, last_match_b+1] 동안 m으로 나눠떨어진 적이 있는지?
                if(idxa/m != (last_match_b+1)/m || (idxa%m==0)){
                    match[idxa]=idxb;
                    last_match_b=idxb;
                    idxa++;
                    idxb++;
                }
                else{
                    int l=((last_match_b+1)/m)*m;
                    int cnt=0;
                    rng(i,0,idxa-1){
                        if(match[i]<l) cnt++;
                    }
                    cout<<n*m-cnt<<'\n';
                    
                    return;
                }
            }
        }
    }
    int l=n*m;
    if(!(idxa/m != (last_match_b+1)/m || (idxa%m==0))){
        // cout<<"h?";
        l=((last_match_b+1)/m)*m;
    }
    int cnt=0;
    // cout<<last_match_b<<' '<<match[0]<<' '<<l<<'\n';
    rng(i,0,idxa-1){
        if(match[i]<l) cnt++;
    }
    cout<<n*m-cnt<<'\n';
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

