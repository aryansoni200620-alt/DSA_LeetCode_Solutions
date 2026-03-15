
char* convert(char* s, int numRows) {
    int len = strlen(s);

   
    if (numRows <= 1 || len <= numRows) {
        return s;
    }

    
    char** rows = (char**)malloc(numRows * sizeof(char*));
    int* rowIdx = (int*)calloc(numRows, sizeof(int));
    for (int i = 0; i < numRows; i++) {
        rows[i] = (char*)malloc((len + 1) * sizeof(char));
    }

    int currentRow = 0;
    bool goingDown = false;

    for (int i = 0; i < len; i++) {
        rows[currentRow][rowIdx[currentRow]++] = s[i];

        
        if (currentRow == 0 || currentRow == numRows - 1) {
            goingDown = !goingDown;
        }

       
        currentRow += goingDown ? 1 : -1;
    }

    
    char* result = (char*)malloc((len + 1) * sizeof(char));
    int k = 0;
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < rowIdx[i]; j++) {
            result[k++] = rows[i][j];
        }
        free(rows[i]); 
    }
    result[k] = '\0';

    free(rows);
    free(rowIdx);

    return result;
}
