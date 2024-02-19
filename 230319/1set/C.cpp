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

int datas[200020];
int last_change[200020]; // n길이. 각 위치에서 언제 마지막으로 바뀐건지
int pos[200020]; // change position
int val[200020]; // changed value
int nums[400020];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    map<pair<int,int>,int> mp;
    int t;
    cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;
        for(int i=0; i<n; i++){
            cin>>datas[i];
        }
        for(int i=0; i<m; i++){
            cin>>pos[i]>>val[i];
            pos[i]--;
        }
        
        mp.clear();
        fill(last_change,last_change+n,-1);
        for(int i=0; i<m; i++){
            int pp=pos[i], vv=val[i];
            int cur_val=datas[pp];
            mp[{pp,cur_val}]=mp[{pp,cur_val}]+i-last_change[pp];
            //cout<<"in_debug : pp, cur_val, num : "<<pp<<' '<<cur_val<<' '<<mp[{pp,cur_val}]<<' '<<last_change[pp]<<endl;
            datas[pp]=vv;
            last_change[pp]=i;
        }
        for(int i=0; i<n; i++){
            mp[{i,datas[i]}]=mp[{i,datas[i]}]+m-last_change[i];
        }
        fill(nums,nums+n+m+1,0);
        for(auto i = mp.begin() ; i != mp.end() ; i++){
            //cout<<"debug : idx, val, num : "<<(i->fi.fi)<<' '<<(i->fi.se)<<' '<<(i->se)<<endl;
            nums[i->fi.se]+=i->se;
            //temp+=((ll)i->second)*((ll)i->second);
            //i->second=0;
        }
        ll temp=0;
        for(int i=0; i<n+m+1; i++){
            temp+=(ll)nums[i]*(m+1-nums[i]);
        }
        ll res=((ll)n*(m+1)*m)/2+temp/2;
        cout<<res<<endl;
    }
    return 0;
}