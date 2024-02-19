// 
//./B<test

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

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> ans;
        int cnt=0;
        bool flag=true;
        if(n%2==0) flag=false;
        while(flag && n!=1){
            cnt++;
            if(cnt>40) break;
            if(((n-1)/2)%2!=0){
                ans.push_back(2);
                n=(n-1)/2;
            }
            else if(((n+1)/2)%2!=0){
                ans.push_back(1);
                n=(n+1)/2;
            }
            else{
                flag=false;
                break;
            }
        }
        if(!flag || n!=1){
            cout<<-1<<endl;
        }
        else{
            reverse(ans.begin(),ans.end());
            cout<<cnt<<endl;
            for(int i=0; i<ans.size(); i++){
                cout<<ans[i]<<' ';
            }
            cout<<endl;  
        }
    }
    return 0;
}