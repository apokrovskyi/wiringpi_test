bool* int_to_binary(int i, int length){
    bool* result = new bool[length];
    for(;length>0;length--){
        result[length-1]=i&1;
        i/=2;
    }
    
    return res;
}
