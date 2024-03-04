
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
__attribute__((optimize("Ofast,unroll-loops"),target("avx,avx2,fma")))

vc<ll> ans;
bool DFS(ll n, ll m){
    if(n<m) return 0;
    if(n==m) return 1;
    ll numn=0, numm=0;
    ll temp=n;
    string nn;
    while(temp!=0){
        numn++;
        nn.pb(temp%2+'0');
        temp/=2;
    }
    reverse(all(nn));

    string mm;
    temp=m;
    while(temp!=0){
        numm++;
        mm.pb(temp%2+'0');
        temp/=2;
    }
    reverse(all(mm));
    //cout<<"Debug : "<<nn<<' '<<mm<<' '<<numn<<' '<<numm<<'\n';

    // �̰��� ��Ʈ�� ���̱� ������ 1<<(numn-1)���� ���
    if(numn==numm){
        ans.pb(m^n);
        //cout<<"here\n";
        return 1;
    }
    if(n&(1LL<<(numm-1))){
        ll res=(1LL<<(numm))-1;
        ans.pb(n^res); // ���� numm���� ��� 0���� set
        //cout<<"here "<<(n^res)<<' '<<m<<'\n';
        return DFS(res,m);
    }
    // 1�� �� �Ѱ� �����ϸ� ����� ���� 
    ll last=numn-1;
    for(ll i=numn-2; i>=numm; i--){
        if(n&(1LL<<i)){
            last=i;
            break;
        }
    }
    if(last==numn-1){
        return 0;
    }
    // 1�� 2�� �̻��̸� 2��°�� 1���� 111..1�� ������ָ� �ȴ�.
    ll res=m;
    for(ll i=numm; i<=last; i++){
        res+=(1LL<<i);
    }
    ans.pb(n^res);
    return DFS(res,m);
}

void Solve(){
    ll n,m; // n->m
    cin>>n>>m;
    ans.clear();
    if(DFS(n,m)){
        cout<<ans.size()<<'\n';
        cout<<n<<' ';
        ll cur=n;
        rng(i,0,(int)ans.size()-1){
            assert(ans[i]<cur && (ans[i]^cur)<cur);
            cur=cur^ans[i];
            cout<<cur<<' ';
        }
        cout<<'\n';
    }
    else cout<<-1<<'\n';
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

