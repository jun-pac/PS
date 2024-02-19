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

int datas[200030];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0; i<n; i++){
            cin>>datas[i];
        }
        sort(datas,datas+n);
        if(!(datas[0]==datas[1] && datas[1]==0)){
            cout<<0<<endl;
        }
        else{
            priority_queue<pair<int,int>> left;
            int mx=0;
            left.push({-0,1});
            left.push({-0,1});
            for(int i=2; i<n; i++) left.push({datas[i],2});
            while(!left.empty()){
                pair<int,int> temp=left.top();
                left.pop();
                int sm=-temp.fi;
                while(!left.empty() && sm+(-left.top().fi)<mx+1) left.pop();
                if(sm+(-left.top().fi)==mx+1){
                    mx++;
                    pair<int,int> temp2=left.top();
                    left.pop();
                    if()
                }
            }
            for(int i=2; i<n; i++){
                int cur=datas[i];
                while(!left.empty() && left.top().fi+cur>mx+1) left.pop();
                if(left.empty()) break;
                if(left.top().fi+cur!=mx+1){
                    left.push({cur,2});
                }
                else{
                    mx++;
                    pair<int,int> temp=left.top();
                    left.pop();
                    if(temp.se==2){
                        left.push({temp.fi,1});
                        left.push({cur,1});
                    }
                    else left.push({cur,1});
                }
            }
            cout<<mx+1<<endl;
        }
    }
    return 0;
}