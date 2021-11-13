

string stringShift(string s, vector<vector<int>>& shift) {
    int len = s.length();
    string str = s + s;
    // string ans;
    int n = shift.size();
    for(int i=0;i<n;i++){
        int type = shift[i][0];
        int step = shift[i][1];
        step %= len;
        
        if(type == 1){ // right shift
            step = len - step;
        }
        
        str = str.substr(step,len);
        s=str;
        // cout<<str<<endl;
        str = str + str;
    }
    
    return s;
    
}
