
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

#define N 400030
#define MOD 998244353
#define INF 1000000007 

int datas[N]; // 2*n����
int tot_cnt[N];
int cur_cnt[N];
void Solve(){
    int n,m,k;
    cin>>n>>m>>k;
    rng(i,0,n-1){
        cin>>datas[i];
        datas[i]--;
        tot_cnt[datas[i]]++;
    }
    rng(i,0,n-1) datas[i+n]=datas[i];
    // We can maintain the duration [l,r].
    // But what is r? is that starting point of mth bucket?
    // �´�. �׷��� r�������� �� ��ȿ�ϰ� ī��Ʈ�Ǵ� �����̰�,/
    // r���� ������ �ְ� l+n���ٴ� ���� ������ �� ���� ��ȿ���ϼ��� �ְ� �ƴҼ��� �ִµ�
    // �츮�� � color�� ����� ������Ʈ �� �� min(tot_cnt[color], cediv(cur_cnt[color],k)*k)�� �ϸ� �ȴ�
    // ������ �츮�� full block�� �����ָ� �� �� �ƴϴ���?

    int r=0;
    int num_box=1;
    int ans=min(tot_cnt[datas[0]],cediv(1,k)*k);
    cur_cnt[datas[0]]++;
    rng(l,0,n-1){
        while(l+n-1>r && num_box-cediv(cur_cnt[datas[r+1]],k)+cediv(cur_cnt[datas[r+1]]+1,k)<=m){
            num_box=num_box-cediv(cur_cnt[datas[r+1]],k)+cediv(cur_cnt[datas[r+1]]+1,k);
            ans=ans-min(tot_cnt[datas[r+1]],cediv(cur_cnt[datas[r+1]],k)*k);
            ans=ans+min(tot_cnt[datas[r+1]],cediv(cur_cnt[datas[r+1]]+1,k)*k);
            cur_cnt[datas[r+1]]++;
            r++;
        }
        cout<<ans<<'\n';
        num_box=num_box-cediv(cur_cnt[datas[l]],k)+cediv(cur_cnt[datas[l]]-1,k);
        //cout<<cur_cnt[datas[l]]<<' '<<cediv(cur_cnt[datas[l]],k)<<' '<<cediv(cur_cnt[datas[l]]-1,k)<<'\n';
        //assert(cediv(cur_cnt[datas[l]],k)>=cediv(cur_cnt[datas[l]]-1,k));
        ans=ans-min(tot_cnt[datas[l]],cediv(cur_cnt[datas[l]],k)*k);
        ans=ans+min(tot_cnt[datas[l]],cediv(cur_cnt[datas[l]]-1,k)*k);
        cur_cnt[datas[l]]--;
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

