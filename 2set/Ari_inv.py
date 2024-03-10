

MOD=1000000007
MAX_DIGIT=62

def ari_inv(num):
    res=1
    mult=num
    for i in range(0,MAX_DIGIT):
        if((MOD-2)&(2**i)):
            res=(res*mult)%MOD
        mult=(mult*mult)%MOD
    return res