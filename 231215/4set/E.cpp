
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

#define N 50005
#define MOD 998244353
#define INF 1000000007 

string s;
pii qs[N];
int pos_to_idx[N_];
// edges�� ��û���� ���� ���� �־ ������
vc<pii> pos[26][26]; // [a][b]���̿� �� pos // ���⼭ �Ļ��Ǵ� edges�� 50000^2 scale�� ����
// ������ 676���� ����°���
int mindist[26*26][26*26]; // ������ dist�� ���⿡ ���Ե� �ֵ��� �Ÿ��ε�..
int lastpos[26*26]; // lastpos DP;
void Solve(){
    cin>>s;
    int n,q;
    n=s.size();
    cin>>q;
    rng(i,0,q-1){
        cin>>qs[i].fi>>qs[i].se; // s,t�ε� ����� ����.
    }
    rng(i,1,n-1){
        pos_to_idx[i]=(s[i-1]-'a')*26+s[i]-'a';
        pos[s[i-1]-'a'][s[i]-'a'].pb(i);
    }
    rng(i,1,n-1){
        lastpos[pos_to_idx[i]]=i;
        
    }

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

