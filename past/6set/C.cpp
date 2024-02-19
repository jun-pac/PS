// 
//./C<test.txt

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

int datas[200000];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int zero_cnt=0, p_cnt=0, m_cnt=0;
        for(int i=0; i<n; i++){
            cin>>datas[i];
            if(datas[i]>0) p_cnt++;
            else if(datas[i]<0) m_cnt++;
            else zero_cnt++;
        }
        //cout<<p_cnt<<' '<<m_cnt<<' '<<zero_cnt<<endl;
        sort(datas,datas+n);
        if(p_cnt>=3 || m_cnt>=3) cout<<"NO"<<endl;
        else if(zero_cnt>0){
            //cout<<datas[0]<<' '<<datas[n-1]<<endl;
            if(p_cnt==1 && m_cnt==1 && datas[0]+datas[n-1]==0) cout<<"YES"<<endl;
            else if((p_cnt==0 && m_cnt==1) || (p_cnt==1 && m_cnt==0) || (p_cnt==0 && m_cnt==0)) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
        else if(n==3){
            int sum=0;
            for(int i=0; i<n; i++) sum+=datas[i];
            if(sum==datas[0] || sum==datas[1] || sum==datas[2]) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
        else{
            int sum=0;
            for(int i=0; i<n; i++) sum+=datas[i];
            bool flag=true;
            for(int i=0; i<n; i++){
                sum=sum-datas[i];
                if(!(sum==datas[0] || sum==datas[1] || sum==datas[2] || sum==datas[3])) flag=false;
                sum=sum+datas[i];
            }
            if(flag) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
    return 0;
}