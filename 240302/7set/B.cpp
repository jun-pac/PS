
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

#define N 500030
#define MOD 998244353
#define INF 1000000007 
__attribute__((optimize("Ofast,unroll-loops"),target("avx,avx2,fma")))

string s;
ll rsum[N], lsum[N]; // 왼쪽에서부터 센 >의 개수, 왼쪽에서부터 센 <의 개수
//ll rmul[N], lmul[N]; // >의 곱셈. (우측의 lsum을 곱한 것), <의 곱셈 : 좌측의 rsum을 곱한 것
ll rmuls[N], lmuls[N];

void Solve(){
    int n;
    cin>>n;
    cin>>s;
    rng(i,0,n-1) rsum[i]=(i==0?0:rsum[i-1])+(s[i]=='>');
    rng(i,0,n-1) lsum[i]=(i==0?0:lsum[i-1])+(s[i]=='<');
    rng(i,0,n-1) rmuls[i]=(i==0?0:rmuls[i-1])+(s[i]=='>'?(lsum[n-1]-lsum[i]):0);
    rng(i,0,n-1) lmuls[i]=(i==0?0:lmuls[i-1])+(s[i]=='<'?rsum[i]:0);

    // rng(i,0,n-1) cout<<rsum[i]<<' '; cout<<endl;
    // rng(i,0,n-1) cout<<lsum[i]<<' '; cout<<endl;
    // rng(i,0,n-1) cout<<rmuls[i]<<' '; cout<<endl;
    // rng(i,0,n-1) cout<<lmuls[i]<<' '; cout<<endl;

    int lend=0, rend=0;
    ll lnum,rnum;
    rng(i,0,n-1){
        ll ln=(i==0?0:rsum[i-1]); // 왼쪽에 >의 개수
        ll rn=lsum[n-1]-lsum[i]; // 오른쪽에 <의 개수
        bool rfi=0;
        if(s[i]=='<'){
            if(ln>rn) rfi=1;
            lnum=min(ln,rn+1);
            rnum=min(ln,rn)+1;
            ln=lnum;
            rn=rnum-1;
        }
        else{
            if(ln>=rn) rfi=1;
            rnum=min(ln+1,rn);
            lnum=min(ln,rn)+1;
            ln=lnum-1;
            rn=rnum;
        }
        ll num=lnum+rnum;
        ll tri=(num)*(num+1)/2;
        ll add=0;

        //assert(lsum[rend]-lsum[i]<=rn);
        //assert((i==0?0:rsum[i-1])-(lend==0?0:rsum[lend-1])<=ln);
        rend=max(i,rend);
        lend=min(i,lend);
        while(rend+1<n && lsum[rend+1]-(i==0?0:lsum[i-1])<=rnum) rend++;
        while(lend<i && rsum[i]-(lend==0?0:rsum[lend-1])>lnum) lend++;
        if(rnum==0) lend=i;
        if(lnum==0) rend=i;
        //cout<<"lnum, rnum, lend, rend : "<<lnum<<' '<<rnum<<' '<<lend<<' '<<rend<<'\n';
        add+=(rmuls[rend]-rmuls[i]-(rsum[rend]-rsum[i])*(lsum[n-1]-lsum[rend]))*2;
        add+=((i==0?0:lmuls[i-1])-(lend==0?0:lmuls[lend-1])-((i==0?0:lsum[i-1])-(lend==0?0:lsum[lend-1]))*(lend==0?0:rsum[lend-1]))*2;
        if(rfi) add+=rsum[n-1]-rsum[i];
        else add+=(i==0?0:lsum[i-1]);
        //cout<<"ans : " <<tri+add<<'\n';
        cout<<tri+add<<' ';
    }
    cout<<'\n';
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

