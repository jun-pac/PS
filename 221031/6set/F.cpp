// 
//./E<test.txt

#include <bits/stdc++.h>
#define endl '\n'
#define cediv(a,b) ((a)%(b)==0?((a)/(b)):((a)/(b))+1)
#define fi first
#define se second
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;

template<typename T>
inline T umax(T &u, T v){return u = max(u, v);}
template<typename T>
inline T umin(T &u, T v){return u = min(u, v);}

#define INF 1000000007

class lazy_seg{
public:
	int seg[1<<20];
	
	lazy_seg(){
        fill(seg,seg+(1<<20),-1);
    }
	
	void update_down(int idx, int l, int r){
		if(l==r) return;
		int mid=(l+r)>>1;
		// seg[2*idx], seg[2*idx+1]
        
		umax(seg[2*idx],seg[idx]);
        umax(seg[2*idx+1],seg[idx]);
		// seg[idx]의 lazy_val초기화
		seg[idx]=-1;
	}
	
	void update_seg(int idx, int l, int r, int t_l, int t_r, int val){
		update_down(idx, l, r);
		if(t_l<=l && r<=t_r){
			seg[idx]=val;
			return;
		}
		int mid=(l+r)>>1;
		if(t_l<=mid) update_seg(2*idx,l,mid,t_l,t_r,val);
		if(t_r>mid) update_seg(2*idx+1,mid+1,r,t_l,t_r,val);
	}
	
	int find_seg(int idx, int l, int r, int t_l, int t_r){
		if(t_l<=l && r<=t_r){
			return seg[idx];
		}
        update_down(idx, l, r);
		int result=seg[idx];
		int mid=(l+r)>>1;
		if(t_l<=mid) umax(result,find_seg(2*idx,l,mid,t_l,t_r));
		if(t_r>mid) umax(result,find_seg(2*idx+1,mid+1,r,t_l,t_r));
		return result;
	}
};

lazy_seg s;
#define MOD 998244353
#define N 300030
ll power[N]; // 3^i
ll res[N]; // (2/3)^i 3^(n-1)
pair<int,int> datas[N];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, mx=0;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>datas[i].fi>>datas[i].se;
        umax(mx,datas[i].se);
        s.update_seg(1,0,mx-1,datas[i].fi,datas[i].se,i);
    }

    mx++;
    cout<<"seg ";
    for(int i=0;i<mx;i++) cout<<s.find_seg(1,0,mx-1,i,i)<<' ';
    cout<<endl;
    ll mul=1;
    for(int i=0; i<n; i++){
        power[i]=mul;
        mul=(mul*3)%MOD;
    }
    mul=1;
    //cout<<"res"<<endl;
    for(int i=0; i<n; i++){
        res[i]=(mul*power[n-1-i])%MOD;
        mul=(mul*2)%MOD;
        //cout<<res[i]<<' ';
    }
    //cout<<endl;
    ll ans=0;
    for(int i=0; i<mx; i++){
        int last=s.find_seg(1,0,mx-1,i,i);
        cout<<"last : "<<last<<endl;
        if(last==-1){
            //nothing happens
            cout<<"val "<<0<<endl;
        }
        else if(last==0){
            // 1*(2/3)^(n-1)*3^(n-1)
            ans=(ans+res[n-1])%MOD;
            cout<<"val "<<res[n-1]<<endl;
        }
        else{
            // (2/3)^(n-last) * 3^(n-1)
            ans=(ans+res[n-last])%MOD;
            cout<<"val "<<res[n-last]<<endl;
        }
    }

    cout<<ans<<endl;
    return 0;
}