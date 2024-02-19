
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

string s;


using namespace std;
class segtree{
public:	
	int mx[1<<19];
    int mn[1<<19]; 
	segtree(){}
	
	void build_seg(int idx, int l, int r){
		if(l==r){
			mx[idx]=(s[l]=='('?1:-1)+(s[l+1]=='('?1:-1);
            mn[idx]=(s[l]=='('?1:-1)+(s[l+1]=='('?1:-1);
			return;
		}
		int mid=(l+r)>>1;
		build_seg(2*idx,l,mid);
		build_seg(2*idx+1,mid+1,r);
    	mx[idx]=max(mx[2*idx],mx[2*idx+1]);
        mn[idx]=min(mn[2*idx],mn[2*idx+1]);
	}

	void update_seg(int idx, int l, int r, int t_idx, int val){
		if(l==r){
            mx[idx]=mx[idx]+val;
			mn[idx]=mn[idx]+val; // Modify
			return;
		}
		int mid=(l+r)>>1;
		if(t_idx<=mid) update_seg(2*idx,l,mid,t_idx, val);
		else update_seg(2*idx+1,mid+1,r,t_idx, val);
		mx[idx]=max(mx[2*idx],mx[2*idx+1]);
        mn[idx]=min(mn[2*idx],mn[2*idx+1]);
	}

	pii find_seg(int idx, int l, int r, int t_l, int t_r){
		if(t_l<=l && r<=t_r) return {mx[idx],mn[idx]};
		int mid=(l+r)>>1, mx=-100, mn=100;
		if(t_l<=mid){
            auto res=find_seg(2*idx,l,mid,t_l,t_r);
            mx=max(mx,res.fi);
            mn=min(mn,res.se);
        }
		if(t_r>mid){
            auto res=find_seg(2*idx+1,mid+1,r,t_l,t_r);
            mx=max(mx,res.fi);
            mn=min(mn,res.se);
        }
		return {mx,mn};
	}
};

segtree seg;

// ()( )) ... 이건 언제나 안됨
// ()()()()()
// ()()(( ... ))()()() 이런 형태만 일단 가능하네요
// ((()()))() 이런것도 됨. ((()() 는 안됨
// ((와 ))는 둘 다 존재하거나, 아예 없거나.


void Solve(){
    int n,m,x;
    cin>>n>>m;
    cin>>s;
    // valid until first (( appears // Here, valid means, 'Not fail'
    // valid from last )) appears.
    // parity condition holds
    // if sum is larger, Only last )) should work
    // if sum is smaller i.e. string has more ')'. Only first (( should work  

    if(n%2==1){
        rng(i,0,m-1){
            cin>>x;
            cout<<"NO\n";
        }
        return;
    }
    seg.build_seg(1,0,n-2); // 총 길이가 n-1임에 주의.

    rng(i,0,m-1){
        cin>>x;
        x--;
        // 앞 seq가 valid할 경우에 바뀐 부분에 대해서 sanity check를 하는 건 어렵지않음
        // 앞 seq가 invalid할 경우?
        // seg + binary로 매번 새로 ((, ))위치를 결정할 수 있어야 함.
        // 그리고 앞뒤에 ()로만 이뤄져있음을 확인할 수 있어야 함.
        // 이후의 2개원소의 합을 관리하는 seg는 어떰?
        if(x!=n-1) seg.update_seg(1,0,n-2,x,(s[x]=='('?-2:2));
        if(x!=0) seg.update_seg(1,0,n-2,x-1,(s[x]=='('?-2:2));
        s[x]=('('+')')-s[x];
        //cout<<"prt "<<s<<'\n';
        if(s[0]==')' || s[n-1]=='('){
            cout<<"NO\n";
            continue;
        }
        auto tot=seg.find_seg(1,0,n-2,0,n-2);
        if(tot.fi==0 && tot.se==0){
            cout<<"YES\n";
        }
        else if((tot.fi==2 && tot.se!=-2) || (tot.fi!=2 && tot.se==-2)){
            cout<<"NO\n";
        }
        else{
            int leftend, rightend; // ((와 ))위 앞인덱스의 위치임
            int l=0, r=n-2;
            while(l<r){
                int mid=(l+r)>>1;
                if(seg.find_seg(1,0,n-2,0,mid).fi==2) r=mid;
                else l=mid+1;
            }
            leftend=l;
            l=0, r=n-2;
            while(l<r){
                int mid=(l+r+1)>>1;
                if(seg.find_seg(1,0,n-2,mid,n-2).se==-2) l=mid;
                else r=mid-1;
            }
            rightend=l;
            //cout<<"l r "<<leftend<<' '<<rightend<<'\n';
            if(seg.find_seg(1,0,n-2,0,leftend).se==-2 || seg.find_seg(1,0,n-2,rightend,n-2).fi==2){
                cout<<"NO\n";
            }
            else if(leftend+1<rightend){ // 앞에서 ()()()반복은 당연히 만족되는 듯?
                cout<<"YES\n";
            }
            else cout<<"NO\n";
        }
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

