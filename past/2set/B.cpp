// 
//./B<test.txt

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

int datas[100090];
int res[100000];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0; i<n; i++) cin>>datas[i];
        bool flag=true;
        int last=datas[0];
        int idx=0;
        for(int i=1; i<n; i++){
            if(datas[i]==last){
                res[i]=i-1;
            }
            else{
                if(i-idx==1){
                    flag=false;
                    break;
                }
                res[idx]=i-1;
                last=datas[i];
                idx=i;
            }
        }
        if(idx==n-1) flag=false;
        else{
            res[idx]=n-1;
        } 
        if(flag){
            for(int i=0; i<n; i++){
                cout<<res[i]+1<<' ';
            }
            cout<<endl;
        }
        else cout<<-1<<endl;
    }
    return 0;
}