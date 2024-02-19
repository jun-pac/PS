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

string s;
ll datas[200000];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cin>>s;
        for(int i=0; i<n; i++){
            cin>>datas[i];
        }
        int left=-1;
        ll res=0;
        ll sum_temp=0;
        ll min_temp=100000;
        for(int i=0; i<n; i++){
            if(s[i]=='1'){
                if(left==-1){
                    left=i;
                    if(i!=0) min_temp=datas[i-1];
                    if(i!=0) sum_temp+=datas[i-1];
                }
                sum_temp+=datas[i];
                umin(min_temp,datas[i]);
            }
            else{
                if(left!=-1){
                    if(left==0){
                        res+=sum_temp;
                    }
                    else{
                        res+=sum_temp-min_temp;
                    }
                    sum_temp=0;
                    min_temp=100000;
                    left=-1;
                }
            }
        }

        if(left!=-1 && left==0){
            res+=sum_temp;
        }
        if(left!=-1 && left!=0){
            res+=sum_temp-min_temp;
        }

        cout<<res<<endl;
    }
    return 0;
}