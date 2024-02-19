// 
//./A<test.txt

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

int datas[100];
char ans[100];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,m,a;
        cin>>n>>m;
        for(int i=0; i<n; i++){
            cin>>a;
            a--;
            datas[i]=min(a,m-1-a);
        }
        sort(datas,datas+n);
        fill(ans,ans+m,'B');
        for(int i=0; i<n; i++){
            if(ans[datas[i]]=='B') ans[datas[i]]='A';
            else ans[m-1-datas[i]]='A';
        }
        for(int i=0; i<m; i++) cout<<ans[i];
        cout<<endl;
    }
    return 0;
}