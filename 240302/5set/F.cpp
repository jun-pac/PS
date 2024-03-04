
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
using pii=pair<int,int>;

#define N 200020

array<int,5> cnt[N];
int sum[N];
pii s_cnt[N]; 

void Solve(){
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        for(int j=0; j<s.size(); j++) cnt[i][s[j]-'a']++; 
        sum[i]=s.size();
    }

    int res=0;
    for(int i=0; i<5; i++){
        //cout<<"char "<<(char)('a'+i)<<'\n';
        // a,b,c,d,e각각이 max가 되는 경우를 나눠서 생각한다.
        // s_cnt[j]={(j번째 주머니에서 i+'a'의 개수)-(j번째 주머니에서 i+'a'가 아닌 개수), (j번째 주머니에서 i+'a'의 개수)}
        for(int j=0; j<n; j++) s_cnt[j]={cnt[j][i]*2-sum[j],cnt[j][i]};
        sort(s_cnt,s_cnt+n);
        reverse(s_cnt,s_cnt+n);
        int cur=0, num_s=0, num_tot=0;
        while(cur<n){
            num_s+=s_cnt[cur].se;
            num_tot+=-s_cnt[cur].fi+2*s_cnt[cur].se;
            if(num_s*2<=num_tot) break;
            cur++;
        }
        res=max(res,cur);
    }
    cout<<res<<'\n';

}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    while(t--){
        Solve();
    }
    return 0;
}

