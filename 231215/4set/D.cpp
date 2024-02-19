
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
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

int DP[2][100][2500]; // 현재까지의 0의 개수, 현재까지의 01의 개수

void Solve(){
    string s;
    cin>>s;
    int n=s.size();
    int cnt0=0;
    rng(i,0,n-1) if(s[i]=='0') cnt0++;
    if(cnt0>n/2) rng(i,0,n-1) s[i]=('0'+'1'-s[i]); 
    if(cnt0>n/2) cnt0=n-cnt0;
    // cnt0는 언제나 50이하

    DP[0][0][0]=(s[0]=='1'?0:1);
    DP[0][1][0]=(s[0]=='0'?0:1);
    rng(i,1,n-1){
        //cout<<"idx : "<<i<<'\n';
        rng(num0,0,min(cnt0,i+1)){
            rng(num01,0,num0*(i+1-num0)){
                DP[i%2][num0][num01]=19721121;
                if(num01>=num0) DP[i%2][num0][num01]=min(DP[i%2][num0][num01],DP[(i+1)%2][num0][num01-num0]+(s[i]=='1'?0:1));
                if(num0>=0 && num01<=(num0-1)*(i+1-num0)) DP[i%2][num0][num01]=min(DP[i%2][num0][num01],DP[(i+1)%2][num0-1][num01]+(s[i]=='0'?0:1));
                //cout<<num0<<' '<<num01<<" : "<<DP[i%2][num0][num01]<<'\n';
            }
        }
    }
    //cout<<cnt0<<' '<<s<<'\n';
    //cout<<n*(n-1)/2<<' '<<cnt0*(cnt0-1)/2<<' '<<(n-cnt0)*(n-cnt0-1)/2<<' '<<(n*(n-1)/2-cnt0*(cnt0-1)/2-(n-cnt0)*(n-cnt0-1)/2)/2<<'\n';
    cout<<DP[(n+1)%2][cnt0][(n*(n-1)/2-cnt0*(cnt0-1)/2-(n-cnt0)*(n-cnt0-1)/2)/2]/2<<'\n';
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

