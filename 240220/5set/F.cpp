
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

#define N 500030
#define MOD 998244353
#define INF 1000000007 

int datas[N];
int pos[N]; // �ʱ⿡ ���� i�� ����ִ���?
ll DP[N];

class lazy_cnt_tree{
public:
	lazy_cnt_tree(){}
	int seg[1<<20]; // ���� offset�� ������
	void build_seg(int idx, int l, int r){
		if(l==r){
			seg[idx]=0;
			return;
		}
		int mid=(l+r)>>1;
		build_seg(2*idx,l,mid);
		build_seg(2*idx+1,mid+1,r);
		seg[idx]=0; // For multiple use
	}
	void update_seg(int idx, int l, int r, int t_l, int t_r, long long val){
		if(t_l<=l && r<=t_r){
			seg[idx]+=val;
			return;
		}
		int mid=(l+r)>>1;
		if(t_l<=mid) update_seg(2*idx,l,mid,t_l,t_r,val);
		if(t_r>mid) update_seg(2*idx+1,mid+1,r,t_l,t_r,val);
	}

	long long find_seg(int idx, int l, int r, int t_idx){
		if(l==r) return seg[idx];
		long long res=seg[idx];
		int mid=(l+r)>>1;
		if(t_idx<=mid) res=res+find_seg(2*idx,l,mid,t_idx);
		if(t_idx>mid) res=res+find_seg(2*idx+1,mid+1,r,t_idx);
		return res;
	}
};

lazy_cnt_tree lct;

void Solve(){
    int n;
    cin>>n;
    rng(i,0,n-1) cin>>datas[i];
    rng(i,0,n-1){
        datas[i]--;
        pos[datas[i]]=i;
    }
    lct.build_seg(1,0,n-1);
    ll res=0;
    // DP[i]�� ���� i���� makeup�ϴµ� ��� �����.
    DP[0]=pos[0];
    rng(i,1,n-1){
        // seg���� 0~i-2�� invalid
        // ���� i-1�� �ϰ� ������Ʈ�ϰ� �ٽ� i�� ����
        ll posii=pos[i-1]+lct.find_seg(1,0,n-1,pos[i-1]); // i-1�� ��ġ�� ã�´�.
        ll posi=pos[i]+lct.find_seg(1,0,n-1,pos[i]); // i�� ��ġ�� ã�´�.
        DP[i]=abs(i-posii)+abs(i-1-posi)+(i==1?0:DP[i-2]);
        
        // posii�� �ϴ� i-1�� �ű���.
        lct.update_seg(1,0,n-1,0,pos[i-1],1);

        posi=pos[i]+lct.find_seg(1,0,n-1,pos[i]);
        DP[i]=min(DP[i],abs(i-posi)+DP[i-1]);
        // i�ڸ��� i�� ���� DP[i-1]���� �̿��ϴ� ����� �ְ�,
        // i�ڸ��� i-1�� ���� i-1�ڸ��� i�� ���� DP[i-2]�� ȣ���� �� �ִ�.
        //cout<<"DP "<<i<<' '<<DP[i]<<'\n';
    }

    if(n!=2) cout<<min(DP[n-1],DP[n-2])<<'\n';
    else cout<<DP[n-1]<<'\n';

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

