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

unordered_map<string,int> um;
string s_arr[100000];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        um.clear();
        for(int i=0; i<n; i++){
            cin>>s_arr[i];
            um[s_arr[i]]=1;
        }
        for(int i=0; i<n; i++){
            bool flag=false;
            for(int j=1; j<s_arr[i].size(); j++){
                if(um[s_arr[i].substr(0,j)]==1 && um[s_arr[i].substr(j,(int)s_arr[i].size()-j)]==1){
                    flag=true;
                    break;
                }
            }
            cout<<flag;
        }
        cout<<endl;
    }
    return 0;
}