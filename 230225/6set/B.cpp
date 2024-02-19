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
        ll n;
        cin>>n;
        ll temp=n;
        vector<int> nums;
        while(temp!=0){
            nums.push_back(temp%10);
            temp=temp/10;
        }
        ll res=0;
        ll mul=1;
        bool flag=true;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]%2==0) res+=mul*(nums[i]/2);
            else{
                if(flag) res+=mul*(nums[i]/2+1);
                else res+=mul*(nums[i]/2);
                flag=!flag;
            }
            mul=mul*10;
        }
        cout<<res<<' '<<n-res<<endl;
    }
    return 0;
}