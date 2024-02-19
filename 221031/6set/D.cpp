// 
//./D<test.txt

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
int n;

string get_s(int shift){
    string temp=s;
    for(int i=0; i<n-shift; i++){
        if(s[i]=='1') temp[i+shift]='1';
    }
    return temp;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin>>n;
    cin>>s;
    int leadone=0;
    int leadzero=0; // after leadone
    int nextone=0;
    int ones, zeros;
    while(leadone<n && s[leadone]=='0') leadone++;
    leadzero=leadone;
    while(leadzero<n && s[leadzero]=='1') leadzero++;
    ones=leadzero-leadone;
    //cout<<"d "<<leadone<<" "<<ones<<endl;
    if(leadone==n){
        cout<<0<<endl;
    }
    else{
        string mxstr=s;
        string temp;
        for(int i=1; i<=ones; i++){
            temp=get_s(i);
            /*if(mxstr.compare(temp)<0){
                mxstr=temp;
            }*/
            //cout<<"temp "<<temp<<endl;
            if(mxstr<temp){
                mxstr=temp;
            }
        }
        int i=0;
        while(mxstr[i]=='0') i++;
        for(;i<n; i++) cout<<mxstr[i];
        cout<<endl;
    }
    return 0;
}