rng(i,0,nx){
        rng(k,0,2){
            array<int,3> temp={0,0,0};
            if(k==mp[datas[0][i]]) continue;
            temp[mp[datas[0][i]]]-=(i!=0 && datas[0][i-1]==datas[0][i])+(i!=nx && datas[0][i+1]==datas[0][i]);
            temp[k]+=(i!=0 && datas[0][i-1]==invmp[k])+(i!=nx && datas[0][i+1]==invmp[k]);
            if(x_mod.find(temp)==x_mod.end()) x_mod.insert(temp);
        }
    }