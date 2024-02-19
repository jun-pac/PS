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

string s;
int st[200000];
int datas[200000];
int st_cnt;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cin>>s;
        int o_f=false;
        int o_idx=0;
        int sum=0;
        for(int i=0; i<n; i++){
            if(s[i]=='1'){
                sum++;
                o_idx=i;
                o_f=true;
            }
        }
        if(!o_f){
            cout<<"NO"<<endl;
            continue;
        }
        if(sum%2==1){
            cout<<"NO"<<endl;
            continue;
        }
        st_cnt=0;
        cout<<"YES"<<endl;
        //cout<<"O"<<o_idx<<endl;
        // o_idx
        for(int i=o_idx+1; i<n; i++) datas[i-o_idx-1]=i;
        for(int i=0; i<o_idx; i++) datas[i+n-o_idx-1]=i;
        for(int i=0; i<n-1; i++){
            if(i!=0){
                cout<<st[st_cnt-1]+1<<' '<<datas[i]+1<<endl;
                st_cnt--;
            }
            if((i==0&&s[datas[i]]=='1')||(i!=0&&s[datas[i]]=='0')){
                //cout<<"h"<<endl;
                st[st_cnt]=datas[i];
                st_cnt++;
            }
            if(st_cnt==0){
                //cout<<"h"<<endl;
                //cout<<"h"<<endl;
                st[st_cnt]=datas[i];
                st_cnt++;
                st[st_cnt]=datas[i];
                st_cnt++;
            }
        }
        cout<<o_idx+1<<' '<<st[st_cnt-1]+1<<endl;
    }
    return 0;
}