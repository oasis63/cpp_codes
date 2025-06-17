int Solution::bulbs(vector<int> &A) {
     int n = A.size();

    int press = 0;
    
    for(int i = 0;i<n;i++){
        if(press%2 == 0){ // state back to initial state
            if(A[i] == 0){ // need to turn on the button 
                press++;   
            }
        }else{  // state has changed
            if(A[i] == 1){
                press++;
            }
        }
    }
    
    return press;
}
