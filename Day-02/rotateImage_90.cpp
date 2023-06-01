    //---> Roatate by 90° ----> matrix transpose + reverse

void SWAP(int& a, int& b){
    int temp=a;
    a=b;
    b=temp;
}
    
void rotate(vector<vector<int>>& matrix) {
        
    //Matrix Transpose
    for(int i=0; i<matrix.size(); i++){
        for(int j=i; j<matrix[i].size(); j++){
                
            SWAP(matrix[i][j], matrix[j][i]);                
        }
    }
        
    // Reverse
    for(int i=0; i<matrix.size(); i++){
        int len=matrix[i].size();
        for(int j=0; j<(len/2); j++){
                
            SWAP(matrix[i][j], matrix[i][len-j-1]);
        }
    }
}