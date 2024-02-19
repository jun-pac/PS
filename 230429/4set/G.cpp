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
        bool flag=true; 
        int sum=0, mn=0, mx=0;
        for(int i=0; i<n; i++){
            cin>>datas[i];
        }
        for(int i=0; i<n; i++){
            if(datas[i]!=0){
                if(sum!=i-1){
                    flag=false;
                    break;
                }
            }
            sum+=datas[i];
            if(sum<i){
                flag=false;
                break;
            }
            if(i==0) ans[i]=0;
            else{
                if(datas[i]!=0) ans[i]=++mx;
                else ans[i]=--mn;
            }
        }
        if(sum!=n-1) flag=false;
        if(!flag) cout<<"NO"<<endl;
        else{
            for(int i=0; i<n; i++) cout<<ans[i]-mn+1<<' ';
            cout<<endl;
        }
    }
    return 0;
}