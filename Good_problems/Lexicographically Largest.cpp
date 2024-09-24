
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
#define INF 1000300007 

int datas[N];
set<int> ans, cand; // candidate for 
pii dur[N]; // {last, first}

// �������ϸ� set���� ��θ� �� �� �˾ƾ� �Ѵ�.

void Solve(){
    int n;
    cin>>n;
    ans.clear();
    cand.clear(); cand.insert(-INF);

    rng(i,0,n-1) cin>>datas[i];
    rng(i,0,n-1) dur[i]={datas[i]+1,datas[i]+i+1};
    sort(dur,dur+n);
    gnr(i,n-1,0){
        int r=dur[i].se;
        int l=dur[i].fi;
        // {i,r}���� ���� ��ĭ�� ã�� �� ��ǥ
        cand.insert(r); // �ߺ��Ǹ� �˾Ƽ� ó�����ٵ� set�̶�
        auto it=prev(cand.upper_bound(r));
        assert(*it<=r);
        while(it!=cand.begin() && *it>=l){
            int val=*it;
            it=prev(it);
            cand.erase(val);
            //cout<<"val "<<val<<'\n';
            if(ans.find(val)==ans.end()){ // ����
                ans.insert(val);
                cand.insert(val-1);
                //cout<<"insert "<<val<<'\n';
                break;
            }
        }
    }
    //cout<<ans.size()<<' '<<cand.size()<<'\n';
    for(auto it=ans.end(); it!=ans.begin(); it=prev(it)){ // ū ������� ���
        cout<<*(prev(it))<<' ';
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

