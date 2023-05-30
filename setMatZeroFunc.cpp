void setZeroes(vector<vector<int>>& matrix) {
        vector<int> row;
        vector<int> col;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(matrix[i][j]==0){
                    row.push_back(i);
                    col.push_back(j);
                }
            }
        }
        if(matrix.size()==1 && row.size()!=0){
            for(int i=0;i<matrix.size();i++){
                for(int j=0;j<matrix[i].size();j++){
                    
                        matrix[i][j]=0;
                    
                }
            }            
        }
        else if(matrix[0].size()==1 && col.size()!=0){
            for(int i=0;i<matrix.size();i++){
                for(int j=0;j<matrix[i].size();j++){
                    
                        matrix[i][j]=0;
                    
                }
            } 
        }
        else{
        for(int i=0;i<row.size();i++){
            int r=row[i];
            for(int j=0;j<matrix[r].size();j++){
                matrix[r][j]=0;
            }
        }
        for(int i=0;i<col.size();i++){
            int c=col[i];
            for(int j=0;j<matrix.size();j++){
                matrix[j][c]=0;
            }
        }
        }
    }