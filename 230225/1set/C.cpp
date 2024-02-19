// 
//./C<test

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

int c[10000]; // table capacity
int p[10000]; // preference
int nums[10000];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        for(int i=0; i<n; i++) cin>>p[i];
        for(int i=0; i<m; i++) cin>>c[i];
        fill(nums,nums+n,0);
        for(int i=0; i<n; i++) nums[p[i]-1]++;
        sort(nums,nums+n);
        reverse(nums,nums+n);
        priority_queue<int> pq;
        for(int i=0; i<n; i++){
            if(nums[i]!=0) pq.push(nums[i]);
        }

        sort(c,c+m);
        reverse(c,c+m);
        int res=0, idx=0;
        while(!pq.empty()){
            if(idx>=m) break;
            int temp=pq.top();
            pq.pop();
            res+=min(temp,c[idx]);
            if(temp-min(temp,c[idx])!=0){
                pq.push(temp-min(temp,c[idx]));
            }
            idx++;
        }

        cout<<res<<endl;
    }
    return 0;
}