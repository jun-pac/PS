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

#define INF 100000000
priority_queue<int> posst;
string s;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        cin>>s;
        int q=s.size();
        bool flag=true;
        int num=0, mn_imp=INF;
        while(!posst.empty()) posst.pop();
        posst.push(0); // num으로 들어간다.

        for(int i=0; i<q; i++){
            if(s[i]=='+'){
                num++;
                while(posst.top()>=num) posst.pop();
                if(num==1) posst.push(num);
            }
            else if(s[i]=='-'){
                num--;
                if(mn_imp>num) mn_imp=INF;
            }
            else if(s[i]=='0'){
                if(num<=1 || posst.top()>=num){
                    flag=false;
                    break;
                }
                if(mn_imp==INF) mn_imp=num;
            }
            else{
                if(mn_imp<=num){
                    flag=false;
                    break;
                }
                posst.push(num);
            }
        }
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}