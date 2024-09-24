
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
//__attribute__((optimize("Ofast,unroll-loops"),target("avx,avx2,fma")))
array<int,3> qs[N]; // {k, i, idx}
int datas[N];
bool ans[N];


class cntsegtree{
public:	
	int seg[1<<19];
	int info;
	cntsegtree(){}
	cntsegtree(int n){}
	
	void build_seg(int idx, int l, int r){
		if(l==r){
			seg[idx]=1;
			return;
		}
		int mid=(l+r)>>1;
		build_seg(2*idx,l,mid);
		build_seg(2*idx+1,mid+1,r);
		seg[idx]=(seg[2*idx]+seg[2*idx+1]); // Modify
	}

	void update_seg(int idx, int l, int r, int t_idx, int val){
		if(l==r){
			seg[idx]=val; // Modify
			return;
		}
		int mid=(l+r)>>1;
		if(t_idx<=mid) update_seg(2*idx,l,mid,t_idx, val);
		else update_seg(2*idx+1,mid+1,r,t_idx, val);
		seg[idx]=(seg[2*idx]+seg[2*idx+1]); // Modify
	}

	int find_seg(int idx, int l, int r, int t_l, int t_r){
		if(t_l<=l && r<=t_r) return seg[idx];
		int mid=(l+r)>>1, ans=0;
		if(t_l<=mid) ans=(ans+find_seg(2*idx,l,mid,t_l,t_r)); // Modify
		if(t_r>mid) ans=(ans+find_seg(2*idx+1,mid+1,r,t_l,t_r)); // Modify
		return ans;
	}
};

class mnsegtree{
public:	
	pii seg[1<<19];
	int info;
	mnsegtree(){}
	mnsegtree(int n){}
	
	void build_seg(int idx, int l, int r){
		if(l==r){
			seg[idx]={datas[l],l};
			return;
		}
		int mid=(l+r)>>1;
		build_seg(2*idx,l,mid);
		build_seg(2*idx+1,mid+1,r);
		seg[idx]=(seg[2*idx].fi<seg[2*idx+1].fi?seg[2*idx]:seg[2*idx+1]); 
	}

	void update_seg(int idx, int l, int r, int t_idx, int val){
		if(l==r){
			seg[idx]={val,l}; // Modify
			return;
		}
		int mid=(l+r)>>1;
		if(t_idx<=mid) update_seg(2*idx,l,mid,t_idx, val);
		else update_seg(2*idx+1,mid+1,r,t_idx, val);
		seg[idx]=(seg[2*idx].fi<seg[2*idx+1].fi?seg[2*idx]:seg[2*idx+1]); 
	}

	pii find_seg(int idx, int l, int r, int t_l, int t_r){
		if(t_l<=l && r<=t_r) return seg[idx];
		int mid=(l+r)>>1;
        pii ans={INF,-1};
		if(t_l<=mid){
            pii temp=find_seg(2*idx,l,mid,t_l,t_r);
            ans=(ans.fi<temp.fi?ans:temp); // Modify
        }
		if(t_r>mid){
            pii temp=find_seg(2*idx+1,mid+1,r,t_l,t_r);
            ans=(ans.fi<temp.fi?ans:temp); // Modify
        }
		return ans;
	}
};

cntsegtree cntseg;
mnsegtree mnseg;

void Solve(){
    int n,q;
    cin>>n>>q;
    rng(i,0,n-1) cin>>datas[i]; // level of monsters
    rng(i,0,q-1) cin>>qs[i][1]>>qs[i][0];
    rng(i,0,q-1) qs[i][1]--;
    rng(i,0,q-1) qs[i][2]=i;
    sort(qs,qs+q);
    reverse(qs,qs+q);
    //rng(i,0,q-1) cout<<qs[i][0]<<' '<<qs[i][1]<<' '<<qs[i][2]<<'\n';

    cntseg.build_seg(1,0,n-1);
    mnseg.build_seg(1,0,n-1);

    int qidx=0;

    gnr(k,n,1){
        if(q==qidx || qs[qidx][0]!=k) continue;
        
        int cur=0; // 현재위치
        int lev=1; // 현재 level.
        // lev보다 작은 건 다 죽이고 가는게 인지상정임
        while(cur<min(qs[qidx][1]+1,n)){
            //cout<<"K CUR LEV "<<k<<' '<<cur<<' '<<lev<<'\n';
            while(true){
                // lev보다 작은 게 있으면 안된다.
                pii temp=mnseg.find_seg(1,0,n-1,cur,n-1);
                if(temp.fi>=lev) break;
                mnseg.update_seg(1,0,n-1,temp.se,INF);
                cntseg.update_seg(1,0,n-1,temp.se,0);
            }
            // 이제 이분탐색으로 개수가 k개가 되는 가장 마지막 원소를 찾는거지
            if(cntseg.find_seg(1,0,n-1,cur,n-1)<=k) break;
            int l=cur;
            int r=n-1;
            while(l<r){
                int mid=(l+r+1)>>1;
                if(cntseg.find_seg(1,0,n-1,cur,mid)<=k) l=mid;
                else r=mid-1;
            }
            cur=l+1;
            lev++;
        }

        while(qidx<q && qs[qidx][0]>=k){
            // 사실은 cntseg에 아직 남아있는 놈이면 싸웠다는 거죠
            ans[qs[qidx][2]]=(cntseg.find_seg(1,0,n-1,qs[qidx][1],qs[qidx][1])==1);
            qidx++;
        }
    }
    rng(i,0,q-1) cout<<(ans[i]?"YES\n":"NO\n");
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

