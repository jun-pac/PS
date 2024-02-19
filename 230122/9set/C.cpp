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

int cnt[26];
int cnt_left[26];
pair<int,int> cnt_pair[26];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;

        // 개수의 절댓값의 차이 / 2
        fill(cnt, cnt+26, 0);
        for(int i=0; i<n; i++) cnt[s[i]-'a']++;
        for(int i=0; i<26; i++) cnt_pair[i]={cnt[i],i};
        sort(cnt_pair, cnt_pair+26);
        reverse(cnt_pair, cnt_pair+26);

        int min_num=0, min_res=10000000;
        for(int k=1; k<=26; k++){
            if(n%k!=0) continue;
            int temp=0;
            for(int i=0; i<k; i++) temp+=abs(cnt_pair[i].fi-n/k);
            for(int i=k; i<26; i++) temp+=cnt_pair[i].fi;

            //cout<<"de "<<k<<' '<<temp<<endl;

            temp=temp/2;
            if(temp<min_res){
                min_res=temp;
                min_num=k;
            }
        }

        cout<<min_res<<endl;
        fill(cnt_left,cnt_left+26,0);
        for(int i=0; i<min_num; i++){
            cnt_left[cnt_pair[i].se]=n/min_num;
        }
        for(int i=0; i<26; i++) cnt_left[i]-=cnt[i];

        int left_cur=0;
        while(left_cur<26 && cnt_left[left_cur]<=0) left_cur++;
        for(int i=0; i<n; i++){
            if(cnt_left[s[i]-'a']<0){
                cnt_left[s[i]-'a']++;
                s[i]=left_cur+'a';
                //cout<<s[i]<<" before minus : "<<cnt_left[left_cur]<<endl;
                cnt_left[left_cur]--;
                
                while(left_cur<26 && cnt_left[left_cur]<=0) left_cur++;
            }
        }
        //for(int i=0; i<26; i++) cout<<cnt_left[i]<<' ';
        //cout<<endl;
        cout<<s<<endl;
    }
    return 0;
}