
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
random_device rd; 
mt19937 gen(rd());
uniform_int_distribution<> dist(0, INF); // random integer from [0, INF] // dist(gen)

pii datas[N];
int score[N];
int cnt[N];
int cumcnt[N];

class node{
public:
    // Do something!
    node(){}
    //node(int val){this->val=val;}
    node operator+(node b){
        node result;
        result.val=min(val,b.val); // Modify
        return result;
    }
    int val=0, lazy_val=0;
};

class lazy_seg{
public:
	node seg[1<<20];
	
	lazy_seg(){}
	//lazy_seg(int n){}
	
	void build_seg(int idx, int l, int r){
		if(l==r){
			seg[idx].val=cumcnt[l]-l-1; // seg[idx].val=datas[l];
			seg[idx].lazy_val=0;
		}
		else{
			int mid=(l+r)>>1;
			build_seg(2*idx,l,mid);
			build_seg(2*idx+1,mid+1,r);
			seg[idx]=(seg[2*idx]+seg[2*idx+1]);
		}
	}
	
	void update_down(int idx, int l, int r){
		if(l==r) return;
		int mid=(l+r)>>1;
		seg[2*idx].val+=seg[idx].lazy_val;
		seg[2*idx].lazy_val+=seg[idx].lazy_val;
		seg[2*idx+1].val+=seg[idx].lazy_val;
		seg[2*idx+1].lazy_val+=seg[idx].lazy_val;
		seg[idx].lazy_val=0;
	}
	
	void update_seg(int idx, int l, int r, int t_l, int t_r, int val){
		update_down(idx, l, r);
		if(t_l<=l && r<=t_r){
			seg[idx].val+=val;
			seg[idx].lazy_val+=val;
			return;
		}
		int mid=(l+r)>>1;
		if(t_l<=mid) update_seg(2*idx,l,mid,t_l,t_r,val);
		if(t_r>mid) update_seg(2*idx+1,mid+1,r,t_l,t_r,val);
		seg[idx]=(seg[2*idx]+seg[2*idx+1]);
	}
	
	node find_seg(int idx, int l, int r, int t_l, int t_r){
		update_down(idx, l, r);
		if(t_l<=l && r<=t_r){
			return seg[idx];
		}
		node result;
		int mid=(l+r)>>1;
		if(t_l<=mid) result=(result+find_seg(2*idx,l,mid,t_l,t_r));
		if(t_r>mid) result=(result+find_seg(2*idx+1,mid+1,r,t_l,t_r));
		return result;
	}
};

lazy_seg s;


void Solve(){
    int ac,dr;
    cin>>ac>>dr;

    int n,q;
    cin>>n;
    rng(i,0,n-1) cin>>datas[i].fi;
    rng(i,0,n-1) cin>>datas[i].se;
    rng(i,0,n-1){
        score[i]=max(0,datas[i].fi-ac)+max(0,datas[i].se-dr);
        // cout<<"sc "<<score[i]<<'\n';
        if(score[i]<n) cnt[score[i]]++;
    }
    rng(i,0,n-1) cumcnt[i]=(i==0?0:cumcnt[i-1])+cnt[i];
    // rng(i,0,n-1) cout<<"cum "<<cumcnt[i]<<'\n';
    s.build_seg(1,0,n-1);

    cin>>q;
    rng(i,0,q-1){
        int idx,a,d;
        cin>>idx>>a>>d;
        idx--;
        int newscore = max(0,a-ac)+max(0,d-dr);
        if(score[idx]<n) s.update_seg(1,0,n-1,score[idx],n-1,-1), cnt[score[idx]]--;
        score[idx]=newscore;
        if(score[idx]<n) s.update_seg(1,0,n-1,score[idx],n-1,1), cnt[score[idx]]++;

        if(cnt[0]==0){
            cout<<0<<'\n';
        }
        else{
            int l=0, r=n-1;
            while(l<r){
                int mid=(l+r+1)>>1;
                auto temp=s.find_seg(1,0,n-1,0,mid);
                if(temp.val>=0) l=mid;
                else r=mid-1;
            }
            cout<<l+1<<'\n';
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    // cin>>t;
    while(t--){
        Solve();
    }
    return 0;
}

