// 
//./D<test.txt

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

int datas[100000];
pair<int,int> nums[100000]; // ¼ıÀÚ, end_idx
int cnt[100000];
int num_cnt;
int DP[100000];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0; i<n; i++) cin>>datas[i];
        int cur_num=-1;
        int temp_ans=0;
        num_cnt=0;
        for(int i=0; i<n; i++){
            if(i!=0 && datas[i]!=cur_num){
                nums[num_cnt++]={cur_num,i-1};
            }
            cur_num=datas[i];
        }

        nums[num_cnt++]={cur_num,n-1};
        for(int i=0; i<num_cnt; i++) cnt[i]=nums[i].se-(i==0?-1:nums[i-1].se);
        //for(int i=0; i<num_cnt; i++) cout<<"d0 "<<nums[i].fi<<' '<<cnt[i]<<endl;
        for(int i=0; i<num_cnt; i++) if(nums[i].fi!=0) temp_ans+=(cnt[i]+1)/2;
        
        //cout<<"d1 "<<temp_ans<<endl;
        
        DP[0]=DP[1]=0;
        for(int i=2; i<num_cnt; i++){
            DP[i]=DP[i-1];
            if(cnt[i]%2==1 && cnt[i-1]==1){
                bool flag=true;
                int l=i-2;
                while(cnt[l]%2!=1 && l>=0){
                    if(cnt[l+1]==1 && (nums[l].fi^nums[l+2].fi)==nums[l+1].fi){
                        l-=2;
                    }
                    else{
                        flag=false;
                        break;
                    }
                }
                if(l<0) flag=false;
                if(!(cnt[l+1]==1 && (nums[l].fi^nums[l+2].fi)==nums[l+1].fi)) flag=false;
                if(flag) DP[i]=max(DP[i],(l==0?0:DP[l-1])+1);
            }
        }
        for(int i=0; i<num_cnt; i++) cout<<DP[i]<<' ';
        cout<<endl;
        cout<<temp_ans-DP[num_cnt-1]<<endl;
    }
    //cout<<(56^4)<<endl;
    return 0;
}