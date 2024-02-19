// 
//./D<test

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

int datas[1000];   
int dels[1000]; //idxÀÓ

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s;
    cin>>s;
    int n=s.size();
    for(int i=0; i<n; i++) cin>>datas[i];
    int d; // deleteÇÒ °Í
    cin>>d;
    for(int i=0; i<d; i++) cin>>dels[i];
    for(int i=0; i<n; i++) dels[i]--;
    string adds;
    cin>>adds;
    sort(adds.begin(), adds.end());
    
    return 0;
}