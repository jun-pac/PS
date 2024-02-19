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

vector<int> datas[100];
vector<int> rdatas[100];
int cnt[100];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n;
        fill(cnt,cnt+55,0);
        for(int i=0; i<55; i++) rdatas[i].clear();
        for(int i=0; i<n; i++) datas[i].clear();
        for(int i=0; i<n; i++){
            int k;
            cin>>k;
            for(int j=0; j<k; j++){
                cin>>x;
                x--;
                datas[i].push_back(x);
                rdatas[x].push_back(i);
                cnt[x]++;
            }
        }
        // 어떻게 0으로 만들 수 있을까
        int mx=0;
        //for(int i=0; i<6; i++) cout<<cnt[i]<<' '; cout<<endl;
        for(int i=0; i<50; i++){
            if(rdatas[i].size()==0) continue;
            for(auto j:rdatas[i]){
                for(auto k:datas[j]){
                    cnt[k]--;
                }
            }
            //for(int j=0; j<6; j++) cout<<cnt[j]<<' '; cout<<endl;
            int temp=0;
            for(int j=0; j<50; j++) if(cnt[j]!=0) temp++;
            mx=max(mx,temp);
            for(auto j:rdatas[i]){
                for(auto k:datas[j]){
                    cnt[k]++;
                }
            }
        }
        cout<<mx<<endl;
        
    }
    return 0;
}