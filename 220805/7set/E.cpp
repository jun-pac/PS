// 
//./E<test

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

bool state[100010];
pair<int,int> interval[100010];
int qs[100010];
int seg[1<<18];
int n,m;

void build_seg(int idx, int l, int r){
    if(l==r){
        seg[idx]=state[l];
        return;
    }
    int mid=(l+r)>>1;
    build_seg(2*idx,l,mid);
    build_seg(2*idx+1,mid+1,r);
    seg[idx]=seg[2*idx]+seg[2*idx+1]; // Some other operation
}

int find_seg(int idx, int l, int r, int t_l, int t_r){
    if(t_l<=l && r<=t_r) return seg[idx];
    int mid=(l+r)>>1, ans=0;
    if(t_l<=mid) ans+=find_seg(2*idx,l,mid,t_l,t_r);
    if(t_r>mid) ans+=find_seg(2*idx+1,mid+1,r,t_l,t_r);
    return ans;
}

bool check(int idx){
    // [0, idx]의 쿼리를 수행
    fill(state,state+n,0);
    for(int i=0; i<=idx; i++){
        state[qs[i]]=true;
    }
    build_seg(1,0,n-1);
    bool res=0;
    for(int i=0; i<m; i++){
        int a=interval[i].fi;
        int b=interval[i].se;
        if(find_seg(1,0,n-1,a,b)*2>b-a+1) return true;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int q,a,b;
        cin>>n>>m;
        for(int i=0; i<m; i++){
            cin>>a>>b;
            interval[i].fi=a-1, interval[i].se=b-1;
        }

        cin>>q;
        for(int i=0; i<q; i++) cin>>qs[i];
        for(int i=0; i<q; i++) qs[i]--;
        
        if(!check(q-1)) cout<<-1<<endl;
        else{
            int l=0, r=q-1;
            while(l!=r){
                int mid=(l+r)>>1;
                if(check(mid)) r=mid;
                else l=mid+1;
            }
            cout<<l+1<<endl;
        }
    }
    return 0;
}