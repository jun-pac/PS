// 
//./D<test

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

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin>>n>>s;
    int cnt=0;
    vector<long long> ans;
    for(long long i=1; i<=(1LL<<n); i++){
        int temp=i;
        //cout<<"init : "<<i<<endl;
        int total=(1LL<<n);
        bool flag=true;
        for(int j=0; j<n; j++){
            if(s[j]=='1'){
                //cout<<"hello"<<endl;
                temp=temp/2;
                //cout<<temp<<' ';
                if(temp==0){
                    flag=false;
                    break;
                }
                total/=2;
            }
            else{
                temp=(total-temp+1);
                temp=temp/2;
                //cout<<temp<<' ';
                if(temp==0){
                    flag=false;
                    break;
                }
                total/=2;
                temp=total-temp+1;
            }
        }
        //cout<<endl;
        if(flag) ans.push_back(i);
    }
    for(int i=0; i<ans.size(); i++){
        if(i!=ans.size()-1) cout<<ans[i]<<' ';
        if(i==ans.size()-1) cout<<ans[i];
    }
    return 0;
}