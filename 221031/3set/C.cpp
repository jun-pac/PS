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

int rt[200000];
bool l_flag[200000];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    string s;
    cin>>t;
    while(t--){
        int n;
        cin>>n>>s;
        fill(l_flag,l_flag+2*n,false);
        int cnt=0, res=n;
        for(int i=0; i<2*n; i++){
            if(s[i]=='(') cnt++;
            else{
                l_flag[cnt]=false;
                cnt--;
                if(l_flag[cnt]) res--;
                l_flag[cnt]=true;
            }
        }
        cout<<res<<endl;
    }
    return 0;
}