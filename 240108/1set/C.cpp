
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

void Solve(){
    int n,m;
    cin>>n>>m;
    int cntm=0;
    int oddm=m;
    while(oddm%2==0){
        cntm++;
        oddm/=2;
    }   
    if(n%oddm!=0){
        cout<<-1<<'\n';
        return;
    }

    int cntn=0, oddn=n;
    while(oddn%2==0){
        cntn++;
        oddn/=2;
    }
    if(cntm<=cntn){
        cout<<0<<'\n';
    }
    else{
        // 이제 oddm* 2^cntn는 마지막에 곱해주고, n=oddn/oddm, m=2^(cntm-cntn)만 생각하면 됩니다.
        // 홀수 * (2^-(cntm-cntn)) 만큼을 원하는데
        // oddn/oddm * 2^(cntm-cntn)개의 조각을 생각해보자. 우리는 각 사람 당 oddn/oddm씩을 가져가면 되는데,
        // 분배가 가능한 선에서 몇 쌍을 결합할 수 있는가? 단, 2^(cntm-cntn)보다 큰 블럭은 불가능
        //cout<<oddn<<' '<<oddm<<' '<<cntn<<' '<<cntm<<'\n';
        ll num=oddn/oddm;
        ll save=0;
        rng(i,0,cntm-cntn-1){
            save+=num/2;
            num=num/2;
        }
        ll res=1;
        rng(i,0,cntm-cntn-1) res=res*2;
        res=res*oddn/oddm;
        res-=oddn/oddm;
        rng(i,0,cntm-cntn-1) save=save*2;
        res-=save;
        rng(i,0,cntn-1) res=res*2;
        res=res*oddm;
        cout<<res<<'\n';
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

