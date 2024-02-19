// 
//./G<test.txt

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

ll datas[200000];

class node{
public:
    // Do something!
    node(){}
    node operator+(node b){
        node result;
        result.val=val+b.val;
        return result;
    }
    ll val=0, lazy_val=0; //lazy_val은 1/2연산의 개수
};

class lazy_seg{
public:
	node seg[1<<18];
	
	lazy_seg(){}
	
	void build_seg(int idx, int l, int r){
		if(l==r){
			seg[idx].val=datas[l];
		}
		else{
			int mid=(l+r)>>1;
			build_seg(2*idx,l,mid);
			build_seg(2*idx+1,mid+1,r);
			seg[idx]=seg[2*idx]+seg[2*idx+1];
		}
	}
	
	void update_down(int idx, int l, int r){
		if(l==r || seg[idx].lazy_val==0) return;
		int mid=(l+r)>>1;
        ll di=seg[idx].lazy_val;
        if(di>=30){
            seg[2*idx].val=0; seg[2*idx].lazy_val+=di;
            seg[2*idx+1].val=0; seg[2*idx+1].lazy_val+=di;
        }
        else{
            seg[2*idx].val/=(1<<di); seg[2*idx].lazy_val+=di;
            seg[2*idx+1].val/=(1<<di); seg[2*idx+1].lazy_val+=di;
        }
        seg[idx].lazy_val=0;
	}
	
	void update_seg(int idx, int l, int r, int t_l, int t_r, int val){
		if(t_l<=l && r<=t_r){
			seg[idx].val=seg[idx].val/2;
            seg[idx].lazy_val++;
			return;
		}
		update_down(idx, l, r);
		int mid=(l+r)>>1;
		if(t_l<=mid) update_seg(2*idx,l,mid,t_l,t_r,val);
		if(t_r>mid) update_seg(2*idx+1,mid+1,r,t_l,t_r,val);
		seg[idx]=seg[2*idx]+seg[2*idx+1];
	}
	
	ll find_seg(int idx, int l, int r, int t_l, int t_r){
		if(t_l<=l && r<=t_r){
			return seg[idx].val;
		}
		update_down(idx, l, r);
		ll result=0;
		int mid=(l+r)>>1;
		if(t_l<=mid) result=result+find_seg(2*idx,l,mid,t_l,t_r);
		if(t_r>mid) result=result+find_seg(2*idx+1,mid+1,r,t_l,t_r);
		return result;
	}
};

lazy_seg s;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        ll n,k,sum=0;
        cin>>n>>k;
        for(int i=0; i<n; i++) cin>>datas[i];
        for(int i=0; i<n; i++) sum+=datas[i];
        s.build_seg(1,0,n-1);
        ll mx=-n*k+s.find_seg(1,0,n-1,0,n-1);
        //cout<<"sum : "<<sum<<' '<<s.find_seg(1,0,n-1,0,n-1)<<endl;
        for(int i=1; i<=n; i++){
            // i는 badcoin의 개수
            s.update_seg(1,0,n-1,n-i,n-1,1);
            //cout<<"sum : "<<s.find_seg(1,0,n-1,0,n-1)<<endl;
            for(int j=0; j<n; j++) cout<<s.find_seg(1,0,n-1,j,j)<<' ';
            cout<<endl;
            ll temp=-(n-i)*k+s.find_seg(1,0,n-1,0,n-1);
            if(i!=n) cout<<"bad "<<i<<' '<<temp<<' '<<s.find_seg(1,0,n-1,0,n-i-1)<<' '<<s.find_seg(1,0,n-1,n-i,n-1)<<' '<<s.find_seg(1,0,n-1,0,n-1)<<endl;
            umax(mx,temp);
        }
        cout<<mx<<endl;
    }
    return 0;
}

/*
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        ll n,k,sum=0;
        cin>>n>>k;
        for(int i=0; i<n; i++) cin>>datas[i];
        for(int i=0; i<n; i++) sum+=datas[i];
        s.build_seg(1,0,n-1);
        ll mx=-n*k+s.find_seg(1,0,n-1,0,n-1);
        //cout<<"sum : "<<sum<<' '<<s.find_seg(1,0,n-1,0,n-1)<<endl;
        for(int i=1; i<=n; i++){
            // i는 badcoin의 개수
            sum-=datas[n-i];
            //cout<<"sum : "<<s.find_seg(1,0,n-1,0,n-1)<<endl;
            ll temp=-(n-i)*k+sum;
            for(int j=n-i; j<n; j++) temp+=datas[j]/(1<<(j-n+i+1)); 
            //cout<<"bad "<<i<<' '<<temp<<' '<<s.find_seg(1,0,n-1,0,n-1)<<endl;
            umax(mx,temp);
        }
        cout<<mx<<endl;
    }
    return 0;
}
*/