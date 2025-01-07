
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

ll datas[N]; // a, ratings of participants
ll diff[N]; // b, difficulty

void Solve(){
    int n,m;
    cin>>n>>m;
    rng(i,0,n-1) cin>>datas[i];
    rng(i,0,m-1) cin>>diff[i];
    ll kel=datas[0];
    sort(datas,datas+n);
    // ���ʿ� ������ ���ϴ� �ֵ鸸 �߿���. 
    int num=n-(upper_bound(datas,datas+n,kel)-datas);
    rng(i,0,num-1) datas[i]=datas[n-num+i];
    // ������ ���ϴ� �� num�� ��������

    sort(diff,diff+m);
    int diffnum=m-(upper_bound(diff,diff+m,kel)-diff);
    reverse(diff+m-diffnum, diff+m);

    // �̰͵� ���� ��Ǫ�� ����� diffnum���� �߿��ϴ�
    // cout<<"kel, num, diffnum "<<kel<<' '<<num<<' '<<diffnum<<'\n';
    rng(k,1,m){
        ll left=m%k; // ����� left���� �Ⱦ�����
        if(left>=diffnum){
            // ���� ��� ������ Ǯ �� ���� ����
            cout<<m/k<<' ';
            continue;
        }
        ll cur=diffnum-left;
        // ���� ��Ǫ�� cur���� ����� ��. ū ������ ���´ٸ� �� ���� 
        ll res=0;
        while(cur>0){
            ll val=diff[m-diffnum+cur-1];
            assert(val>kel);
            res+=num-(lower_bound(datas, datas+num, val)-datas)+1; // val�� [datas, datas+num-1]�� ������ Ǯ �� �ִٸ�. ������ �������
            // 
            //cout<<"debug "<<k<<' '<<left<<' '<<cur<<' '<<val<<' '<< num-(lower_bound(datas, datas+num, val)-datas)<<'\n';
            cur-=k;
        }
        cout<<res+(m-diffnum)/k<<' ';
        // ������ log n ���⵵�� �� ���̴�
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

