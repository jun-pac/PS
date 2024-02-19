// 
//./C<test

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

ll a[200020], b[200020];
ll seg[800080]; // l 인덱스로는 그냥 b_i들의 개수를 담는다.
ll bsum[200020];
ll res[200020];

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

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0; i<n; i++){
            cin>>a[i];
        }
        for(int i=0; i<n; i++){
            cin>>b[i];
        }
        bsum[0]=b[0];
        for(int i=1; i<n; i++) bsum[i]=bsum[i-1]+b[i];
        
        fill(seg,seg+4*n,0);
        fill(res,res+n,0);

        /*cout<<"Bs : ";
        for(int i=0; i<n; i++) cout<<bsum[i]<<' ';
        cout<<endl;
        */

        for(int i=0; i<n; i++){
            int fill_idx;// [i, fill_idx]까지는 1씩 더해지고, 나머지가 fill_idx+1에 들어감
            ll a_tar=(i==0?0:bsum[i-1])+a[i];
            fill_idx=upper_bound(bsum,bsum+n,a_tar)-bsum;
            fill_idx--;
            if(fill_idx>=i) update_seg(1,0,n-1,i,fill_idx,1);
            //cout<<i<<' '<<a_tar<<' '<<" fill "<<fill_idx<<" left over : ";

            if(fill_idx!=n-1){
                res[fill_idx+1]+=a_tar-(fill_idx==-1?0:bsum[fill_idx]);
                //cout<<a_tar-(fill_idx==-1?0:bsum[fill_idx]);
            }
            //cout<<endl;
            
        }
        for(int i=0; i<n; i++) res[i]+=b[i]*find_seg(1,0,n-1,i);
        for(int i=0; i<n; i++) cout<<res[i]<<' ';
        cout<<endl; 
    }
    return 0;
}