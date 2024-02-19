
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

int datas[N];
int unidata[N];

void Solve(){
    int n;
    cin>>n;
    rng(i,0,n-1) cin>>datas[i];
    sort(datas,datas+n);
    int cnt=0;
    int last=-1;
    rng(i,0,n-1){
        if(datas[i]!=last) unidata[cnt++]=datas[i];
        last=datas[i];
    }
    last=-1;
    int mx=1;


    // cout<<"uni : ";
    // rng(i,0,cnt-1) cout<<unidata[i]<<' '; cout<<'\n';

    rng(i,0,n-1){
        if(datas[i]==last) continue;
        last=datas[i];
        int temp=i;
        //while(i+1<n && datas[i+1]==last) i++;
        //int cur_cnt=i-temp+1; // i가 마지막 last값을 가지는 원소로 수렴함.
        // 이제 [last-n,last-1]에 속하는 원소의 개수를 구할 차례임
        int num=upper_bound(unidata,unidata+cnt,last)-lower_bound(unidata,unidata+cnt,last-n+1);
        mx=max(mx,num);
        // cout<<"i "<<i<<' '<<datas[i]<<' '<<cur_cnt<<' '<<num<<'\n';
    }
    assert(mx<=n);
    cout<<mx<<'\n';
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

