
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

ll datas[N];
ll n;

ll val(ll idx, ll k){
    // k���� ������ �ϰ� �� ���� idx��°
    //cout<<"visit "<<idx<<' '<<k<<endl;
    if(k==0) return idx+1;
    // if(idx>=datas[n-1]+1-n){
    //     return idx+1+k*n;
    // }
    ll l=0, r=n+idx;
    // �⺻������ idx'�� idx���� ū ���̳�
    // idx�տ� �󸶳� ���Ű� ���ִ����� �Ǵ��ϰ�, 
    while(l<r){
        ll mid=(l+r)>>1;
        // mid���ٸ� �󸶳� ���Ű� ���ְڴ°�?
        // datas�� �� ��ġ�� �ָ�... �� ������ �������� �����ؾ���
        int pos=upper_bound(datas,datas+n,mid)-datas-1;
        if(mid-pos-1>=idx) r=mid;
        else l=mid+1;
    }
    return val(l,k-1);
}

void Solve(){
    int k;
    cin>>n>>k;
    rng(i,0,n-1) cin>>datas[i];
    rng(i,0,n-1) datas[i]--;
    cout<<val(0,k)<<'\n';
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

