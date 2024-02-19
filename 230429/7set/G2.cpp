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

#define INF 1000000007

int cnt[20020];
int seg[20020]; // basically store cnt
int datas[20020];
ll DP[5005];
//ll ssum[5005];
int cls[5005]; // ���� ���� cls

// ���Ҹ� ã���� disable�� ���� ���ָ� �� �� ����
void update_seg(int idx, int l, int r, int t_idx, int val){
    if(l==r){
        seg[idx]+=val;
        return;
    }
    int mid=(l+r)>>1;
    if(t_idx<=mid) update_seg(2*idx,l,mid,t_idx,val);
    else update_seg(2*idx+1,mid+1,r,t_idx,val);
    seg[idx]=max(seg[2*idx],seg[2*idx+1]);
}

int find_seg(int idx, int l, int r, int t_l, int t_r){
    if(t_l<=l && r<=t_r) return seg[idx];
    int mid=(l+r)>>1, ans=0;
    if(t_l<=mid) ans=max(ans,find_seg(2*idx,l,mid,t_l,t_r));
    if(t_r>mid) ans=max(ans,find_seg(2*idx+1,mid+1,r,t_l,t_r));
    return ans;
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        for(int i=0; i<n; i++){
            int cc;
            cin>>cc;
            datas[i]=cc-1;
            // datas[i] : i�� color
        }
        fill(seg,seg+4*n,0);
        fill(DP,DP+n,0); // DP�� �������� ��´�.
        
        // ssum[i]�� i����(i����)�� DP�߿��� i�� class�� ���� �ֵ��� ���� ����
        int l=0; // [l,r]������ ���캸�� ��
        int cur_cls=0;
        for(int i=0; i<n; i++){
            //update_seg(1,0,n-1,datas[i],1); 
            while(l<i){
                //update_seg(1,0,n-1,datas[l],-1);
                cnt[datas[l]]++;
                if(cnt[datas[i]]>=k) l++;
                else{
                    //update_seg(1,0,n-1,datas[l],1);
                    cnt[datas[l]]--;
                    break;
                }
            }
            // [l,i]�� k�� �̻��� ��� ����. (cls==0�� �� ����)
            if(seg[1]<k) cls[i]=0;
            else cls[i]=(l==0?1:cls[l-1]+1);
            
            int temp_l=l;
            if(cls[i]==0) DP[i]=1;
            else if(cls[i]==1){

            }
            else{
                while(l>=0 && cls[temp_l]==cls[l]){
                    // DP[i]+=DP[l-1]*(([temp_l, i]������ datas[i]�� ����)C(k))
                }
            }
            

            cout<<"i l cls DP ssum seg[1] : "<<i<<' '<<l<<' '<<cls[i]<<' '<<DP[i]<<' '<<ssum[i]<<' '<<seg[1]<<endl;
        }
        cout<<(cls[n-1]==0?1:ssum[n-1]%INF)<<endl;
    }
    return 0;
}