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

int ans[101];
int datas[101];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        fill(ans,ans+n,0);   
        int sum=0;
        for(int i=0; i<n; i++){
            cin>>datas[i];
            sum+=datas[i];
        }
        if(sum!=n-1 || datas[0]!=0){
            cout<<"NO"<<endl;
            continue;
        }
        bool flag=true;
        int van=0;
        int cur_sum=0;
        for(int i=n-1; i>0; i--){
            if(datas[i]!=0){
                cur_sum+=datas[i];
                ans[n-cur_sum]=i+1;
                van+=datas[i]-1;
            }
            else{
                if(van==0){
                    flag=false;
                    break;
                }
                van--;
            }
        }
        if(!flag) cout<<"NO"<<endl;
        else{
            int cur=0;
            for(int i=0; i<n; i++){
                while(cur<n && ans[cur]!=0) cur++;
                if(datas[i]==0){
                    ans[cur]=i+1;
                }
            }
            cout<<"YES"<<endl;
            for(int i=0; i<n; i++) cout<<ans[i]<<' ';
            cout<<endl;
        }
    }
    return 0;
}