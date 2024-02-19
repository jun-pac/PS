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

#define N 9
#define INF 1000000007

int h[N];
int h_p[N], h_m[N]; // h[i]+i , h[i]-i
ll r_DP[N], l_DP[N]; 

int seg[4*N]; // 영락없는 min세그

void build_seg(int idx, int l, int r, bool flag){
    if(l==r){
        seg[idx]=(flag?h_p[l]:h_m[l]);
        return;
    }
    int mid=(l+r)>>1;
    build_seg(2*idx,l,mid,flag);
    build_seg(2*idx+1,mid+1,r,flag);
    seg[idx]=min(seg[2*idx],seg[2*idx+1]); // Some other operation
}

int find_seg(int idx, int l, int r, int t_l, int t_r){
    if(t_l<=l && r<=t_r) return seg[idx];
    int mid=(l+r)>>1, ans=INF;
    if(t_l<=mid) ans=min(ans,find_seg(2*idx,l,mid,t_l,t_r));
    if(t_r>mid) ans=min(ans,find_seg(2*idx+1,mid+1,r,t_l,t_r));
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        ll sum=0;
        for(int i=0; i<n; i++){
            cin>>h[i];
            sum+=h[i];
            h_p[i]=h[i]+i;
            h_m[i]=h[i]-i;
        }
        fill(r_DP,r_DP+n,0);
        fill(l_DP,l_DP+n,0);
        // r_DP는 i기준 우측으로 최대한 한 번에 지울 수 있는 양을 의미
        build_seg(1,0,n-1,true);
        r_DP[n-1]=0;
        for(int i=n-2; i>=0; i--){
            int l=i+1,r=n-1; // 뭘 찾나면 i보다 우측에서 i보다 작은 최소의 원소를 찾는다.
            ll last;
            if(find_seg(1,0,n-1,i+1,n-1)>=h_p[i]) last=n-1;
            else{
                while(l<r){
                    int mid=(l+r)>>1;
                    if(find_seg(1,0,n-1,i,mid)<h_p[i]) r=mid;
                    else l=mid+1;
                }
                // 현재 h_p[l]<h_p[i]임
                //cout<<"?"<<endl;
                r_DP[i]=r_DP[l]+h[l];
                last=l-1;
            }
            //cout<<i<<" th r last : "<<last<<endl;
            last=min(last,(ll)h[i]-1+i);
            r_DP[i]+=(((ll)last-i)*(2*h[i]-1+i-last))/2;
        }

        build_seg(1,0,n-1,false);
        l_DP[0]=0;
        for(int i=1; i<n; i++){
            int l=0,r=i-1;
            ll last;
            if(find_seg(1,0,n-1,0,i-1)>=h_m[i]) last=0;
            else{
                while(l<r){
                    int mid=(l+r+1)>>1;
                    if(find_seg(1,0,n-1,mid,i)<h_m[i]) l=mid;
                    else r=mid-1;
                }
                // 현재 h_p[l]<h_p[i]임
                l_DP[i]=l_DP[l]+h[l];
                last=l+1;
            }
            last=max(last,(ll)i-h[i]+1);
            //cout<<i<<" th l last : "<<last<<endl;
            l_DP[i]+=(((ll)i-last)*(2*h[i]-1+last-i))/2;
        }
        
        /*for(int i=0; i<n; i++){
            cout<<"i lDP rDP "<<i<<' '<<l_DP[i]<<" "<<r_DP[i]<<endl;
        }*/
        ll mn=sum;
        for(int i=0; i<n; i++){
            mn=min(mn,sum-(l_DP[i]+r_DP[i]));
        }
        cout<<mn<<endl;
    }
    return 0;
}