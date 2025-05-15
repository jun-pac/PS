
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
// random_device rd; 
// mt19937 gen(rd());
// uniform_int_distribution<> dist(0, INF); // random integer from [0, INF] // dist(gen)

string s;
int ans[N]; // 'o'면 1, '.'이면 2, 상관없으면 0

void Solve(){
    int n,k;
    cin>>n>>k;
    cin>>s;
    
    // 일단 정해진 것은 정해진 것임.
    int ocnt=0;
    vc<int> vacancy;
    int mx=0;
    int last=-1;
    rng(i,0,n-1){
        if(s[i]=='o'){
            ans[i]=1;
            ocnt++;
            if(last!=-1) mx+=(i-last+1)/2;
            last=-1;
        }
        if(s[i]=='.'){
            ans[i]=2;
            if(last!=-1) mx+=(i-last+1)/2;
            last=-1;
        }
        if(s[i]=='?'){
            if((i!=0 && s[i-1]=='o') || (i!=n-1 && s[i+1]=='o')){
                ans[i]=2;
                if(last!=-1) mx+=(i-last+1)/2;
                last=-1;
            }
            else{
                // 진정한 ?
                ans[i]=0;
                if(last==-1) last=i;
            }
        }
    }
    if(last!=-1) mx+=(n-last+1)/2;
    last=-1;

    // rng(i,0,n-1){
    //     if(ans[i]==0) cout<<'?';
    //     if(ans[i]==1) cout<<'o';
    //     if(ans[i]==2) cout<<'.';        
    // }
    // cout<<'\n';

    // cout<<ocnt<<' '<<k<<' '<<mx<<'\n';


    last=-1;
    if(mx==(k-ocnt)){
        rng(i,0,n-1){
            if(ans[i]!=0){
                // 짝수길이는 ?으로 냅두는 게 맞음.
                if(last!=-1){
                    if((i-last)%2==1){
                        rng(kk,0,i-last-1){
                            if(kk%2==0) ans[kk+last]=1;
                            else ans[kk+last]=2;
                        }
                    }
                    last=-1;
                }
            }
            else{
                if(last==-1) last=i;
            }
        }
        if(last!=-1){
            if((n-last)%2==1){
                rng(kk,0,n-last-1){
                    if(kk%2==0) ans[kk+last]=1;
                    else ans[kk+last]=2;
                }
            }
            last=-1;
        }
    }
    if(k==ocnt){
        rng(i,0,n-1){
            if(ans[i]==0) ans[i]=2;
        }
    }
 

    rng(i,0,n-1){
        if(ans[i]==0) cout<<'?';
        if(ans[i]==1) cout<<'o';
        if(ans[i]==2) cout<<'.';        
    }
    cout<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    // cin>>t;
    while(t--){
        Solve();
    }
    return 0;
}

