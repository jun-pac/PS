// 
//./D<test.txt

#include <bits/stdc++.h>
#define endl '\n'
#define cediv(a,b) ((a)%(b)==0?((a)/(b)):((a)/(b))+1)
#define fi first
#define se second
#define pb push_back
#define MOD 998244353

using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;

template<typename T>
inline T umax(T &u, T v){return u = max(u, v);}
template<typename T>
inline T umin(T &u, T v){return u = min(u, v);}

int datas[100000];
bool visited[100000];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,m,k,a;
        cin>>n>>m>>k;
        for(int i=0; i<k; i++){
            cin>>a;
            datas[i]=a-1;
        }
        bool flag=true;
        int cri=n*m-3;
        fill(visited, visited+k, false);
        
        int cur=0;
        int staged=0;
        for(int i=0; i<k; i++){
            int tar=k-1-i;
            if(!visited[tar]){
                while(cur<k && datas[cur]!=tar){
                    visited[datas[cur]]=true;
                    cur++;
                    staged++;
                }
                visited[tar]=true;
                cur++;
                staged++;
            }

            //cout<<"tar:"<<tar+1<<' '<<"cur:"<<cur<<' '<<"staged:"<<staged<<endl;

            if(staged>cri){
                flag=false;
                break;
            }
            staged--;
        }

        if(flag) cout<<"YA"<<endl;
        else cout<<"TIDAK"<<endl;
    }
    return 0;
}