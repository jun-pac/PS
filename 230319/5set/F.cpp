// 
//./F<test

#include <bits/stdc++.h>
#define endl '\n'
#define cediv(a,b) ((a)%(b)==0?((a)/(b)):((a)/(b))+1)
#define fi first
#define se second
#define pb push_back

using namespace std;

typedef long long ll;

int cnt[200000][26];
unordered_map<int,int> mn[26]; // 각각은 i번째 원소가 없음이 확실한 애들을 넣는다. 
string s;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>s;
        for(int j=0; j<s.size(); j++){
            cnt[i][s[j]-'a']++;
        }
        int temp=0;
        for(int j=0; j<26; j++){
            if(cnt[i][j]%2!=0) temp+=(1<<j);
        }
        for(int j=0; j<26; j++){
            if(cnt[i][j]==0) mn[j][temp]=mn[j][temp]+1;
        }
    }

    ll res=0;
    for(int i=0; i<n; i++){
        int temp=0;
        for(int j=0; j<26; j++) if(cnt[i][j]%2==0) temp+=(1<<j);

        for(int j=0; j<26; j++){
            if(cnt[i][j]==0){
                res=res+mn[j][temp-(1<<j)];
            }
        }
    }
    cout<<res/2<<endl;

    return 0;
}