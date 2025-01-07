
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

int datas[N];
stack<int> st;
vc<int> getout;
vc<int> getin;

void Solve(){
    int n;
    cin>>n;
    rng(i,0,n-1){
        cin>>datas[i];
    }
    getin.clear();
    getout.clear();
    // ���� �͵��� lexio-�� �ּҰ� �ǵ��� k���� �����ϴ� ����� ã�� ������
    // k<n��. ���������� ���� ���� ���Ұ� ����.
    // 1���� �����ϴ� �����, �տ��� ���� ���ʷ�, �̰� ���ָ� �� �۾�����? �� ���̸� �ٷ� �ڷ� �ѱ�� ��. 
    // O(n)���� �� �۾��� ���� �� ����
    while(!st.empty()) st.pop();
    rng(i,0,n-1){
        while(!st.empty() && st.top() > datas[i]){
            getout.pb(st.top());
            st.pop();
        }
        st.push(datas[i]);
    }
    sort(all(getout));
    if(getout.empty()){
        // ���ʺ��� ��������
        while(!st.empty()){
            getin.pb(st.top());
            st.pop();
        }
        sort(all(getin));
        rng(i,0,(int)getin.size()-1) cout<<getin[i]<<' ';
        rng(i,0,(int)getout.size()-1) cout<<getout[i]+1<<' ';
        cout<<'\n';
        return;
    }
    while(!st.empty() && st.top()>getout[0]+1){
        getout.pb(st.top());
        st.pop();   
    }
    while(!st.empty()){
        getin.pb(st.top());
        st.pop();
    }
    sort(all(getin));
    sort(all(getout));
    rng(i,0,(int)getin.size()-1) cout<<getin[i]<<' ';
    rng(i,0,(int)getout.size()-1) cout<<getout[i]+1<<' ';
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

