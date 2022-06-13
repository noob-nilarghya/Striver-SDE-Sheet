bool isValid(int matrix[9][9], int row, int col, int num){
    // Check row
    for(int i=0; i<9; i++){
        if(matrix[row][i]==num){ return false; }
    }
    // check col
    for(int i=0; i<9; i++){
        if(matrix[i][col]==num){ return false; }
    }
    // check box
    if(row>=0 && row<=2 && col>=0 && col<=2){ // box 1
        for(int i=0; i<=2; i++){
            for(int j=0; j<=2; j++){
                if(row != i && col != j && matrix[i][j]==num){ return false; }
            }
        }
    }
    if(row>=3 && row<=5 && col>=0 && col<=2){ // box 2
        for(int i=3; i<=5; i++){
            for(int j=0; j<=2; j++){
                if(row != i && col != j && matrix[i][j]==num){ return false; }
            }
        }
    }
    if(row>=6 && row<=8 && col>=0 && col<=2){ // box 3
        for(int i=6; i<=8; i++){
            for(int j=0; j<=2; j++){
                if(row != i && col != j && matrix[i][j]==num){ return false; }
            }
        }
    }
    if(row>=0 && row<=2 && col>=3 && col<=5){ // box 4
        for(int i=0; i<=2; i++){
            for(int j=3; j<=5; j++){
                if(row != i && col != j && matrix[i][j]==num){ return false; }
            }
        }
    }
    if(row>=3 && row<=5 && col>=3 && col<=5){ // box 5
        for(int i=3; i<=5; i++){
            for(int j=3; j<=5; j++){
                if(row != i && col != j && matrix[i][j]==num){ return false; }
            }
        }
    }
    if(row>=6 && row<=8 && col>=3 && col<=5){ // box 6
        for(int i=6; i<=8; i++){
            for(int j=3; j<=5; j++){
                if(row != i && col != j && matrix[i][j]==num){ return false; }
            }
        }
    }
    if(row>=0 && row<=2 && col>=6 && col<=8){ // box 7
        for(int i=0; i<=2; i++){
            for(int j=6; j<=8; j++){
                if(row != i && col != j && matrix[i][j]==num){ return false; }
            }
        }
    }
    if(row>=3 && row<=5 && col>=6 && col<=8){ // box 8
        for(int i=3; i<=5; i++){
            for(int j=6; j<=8; j++){
                if(row != i && col != j && matrix[i][j]==num){ return false; }
            }
        }
    }
    if(row>=6 && row<=8 && col>=6 && col<=8){ // box 9
        for(int i=6; i<=8; i++){
            for(int j=6; j<=8; j++){
                if(row != i && col != j && matrix[i][j]==num){ return false; }
            }
        }
    }
    return true;
}
bool isItSudoku(int matrix[9][9]) {
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            if(matrix[i][j]==0){
                // Try out all possibilities
                for(int num=1; num<=9; num++){
                    if(isValid(matrix, i, j, num)==true){
                        matrix[i][j]=num;
                        bool a=isItSudoku(matrix);
                        if(a==true){ return true; }
                        matrix[i][j]=0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}
