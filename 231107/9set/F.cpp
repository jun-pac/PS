// 
//./F<test

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
int datas[20020];
int seg[1<<18];

// 원소를 찾으면 disable도 같이 해주면 될 거 같음
void update_seg(int idx, int l, int r, int t_idx){
    if(l==r){
        seg[idx]=1;
        return;
    }
    int mid=(l+r)>>1;
    if(t_idx<=mid) update_seg(2*idx,l,mid,t_idx);
    else update_seg(2*idx+1,mid+1,r,t_idx);
    seg[idx]=seg[2*idx]+seg[2*idx+1];
}

int find_seg(int idx, int l, int r, int t_l, int t_r){
    if(t_l<=l && r<=t_r) return seg[idx];
    int mid=(l+r)>>1, ans=0;
    if(t_l<=mid) ans+=find_seg(2*idx,l,mid,t_l,t_r);
    if(t_r>mid) ans+=find_seg(2*idx+1,mid+1,r,t_l,t_r);
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>datas[i];
    }
    int cur=0;
    for(int i=0; i<n-1; i++){
        int left=n-i;
        int l=0, r=n-1;
        // tar위치를 제거
        //cout<<"mv "<<datas[cur]<<endl;
        int tar=cur+1-find_seg(1,0,n-1,0,cur)+datas[cur]-1+left;
        
        //cout<<"t "<<tar<<endl;
        tar=(tar-1)%left+1;
        //cout<<"t "<<tar<<endl;
        while(l!=r){
            int mid=(l+r)/2;
            int nums=mid+1-find_seg(1,0,n-1,0,mid);
            if(nums>=tar) r=mid;
            else l=mid+1;
        }
        cur=l;
        //cout<<"del "<<cur+1<<endl;
        update_seg(1,0,n-1,cur);
        // next cur은 여기서 한 칸 더 이동
        left--;
        l=0, r=n-1;
        tar=cur+2-find_seg(1,0,n-1,0,cur)+left;
        tar=(tar-1)%left+1;
        //cout<<"tt "<<tar<<endl;
        while(l!=r){
            int mid=(l+r)/2;
            int nums=mid+1-find_seg(1,0,n-1,0,mid);
            if(nums>=tar) r=mid;
            else l=mid+1;
        }
        cur=l;
        //cout<<"next "<<cur+1<<endl;
    }
    cout<<cur+1<<endl;
    return 0;
}