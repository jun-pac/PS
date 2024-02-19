
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
#define INF 1000000007 

string s;
ll sum[3][N];
ll n;

inline ll sumk(ll k){
    ll m=k/3;
    if(k%3==0) return m*(m+1)/2*3;
    if(k%3==1) return m*(m+1)+(m+1)*(m+2)/2;
    if(k%3==2) return m*(m+1)/2+(m+1)*(m+2);
}

ll calc(int a, int b){
    // a , ... , b 00은 없음이 보장됨.
    // 양끝이 1임이 보장
    //cout<<"frag "; cout<<a<<' '<<b<<'\n';
    //cout<<"string "; rng(i,a,b) cout<<s[i]; cout<<'\n';
    rng(i,a,b) sum[0][i]=(i-3<a?0:sum[0][i-3])+(i%3==0 && s[i]=='0'); 
    rng(i,a,b) sum[1][i]=(i-3<a?0:sum[1][i-3])+(i%3==1 && s[i]=='0'); 
    rng(i,a,b) sum[2][i]=(i-3<a?0:sum[2][i-3])+(i%3==2 && s[i]=='0'); 

    ll len=(b-a+1);
    ll res=cediv(len,3)*((a+1)*(n-b)-1);
    rng(i,a+1,b-1){
        if(s[i]=='1'){
            res=(res+cediv(b-i+1,3)*(a)+cediv(i-a+1,3)*(n-b-1));
        }
        else{
            res=(res+cediv(b-i,3)*(a)+cediv(i-a,3)*(n-b-1));
        }
    }
    cout<<"res : "<<res<<'\n';
    ll inner=0;
    rng(i,a,b){
        if(s[i]=='1'){
            inner+=sumk(b-i+1)-(sum[i%3][b]-sum[i%3][i]); // i로부터 3k+1의 개수에 있는 zero의 개수
        }
        else{
            //inner=sumk(b-i); // 개수가 3k일 때, 3k+1일 때(언제나 -1), 3k+2일 때 (거기 0있누)
            inner+=sumk(b-i+1);
            inner-=(b-i)/3+1;
            inner-=(sum[(i+1)%3][b]-sum[(i+1)%3][i]);
        }
    }
    cout<<"inner : "<<inner<<'\n';
    //assert(inner%2==0);
    return res+inner;

}

void Solve(){
    cin>>n;
    cin>>s;
    ll res=0;
    bool gflag=0;
    int last=-1;
    rng(i,0,n-1){
        if(gflag && i<n-1 && s[i]=='0' && s[i+1]=='0'){
            gflag=0;
            res=(res+calc(last,i-1));
        }
        else if(!gflag && s[i]=='1'){
            gflag=1;
            last=i;
        }
    }
    if(gflag) res=(res+calc(last,n-1-(s[n-1]=='0'?1:0)));
    cout<<res<<'\n';

    // res=0;
    // //rng(i,0,10) s[i]='0';
    // rng(i,14,n-1){
    //     rng(j,i,n-1){
    //         int last=-100; // 마지막 체크한부분
    //         rng(k,i,j){
    //             if(s[k]=='1' && last<k-1){
    //                 res++;
    //                 last=k+1;
    //             }
    //         }
    //     }
    // }
    // cout<<res<<'\n';

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

