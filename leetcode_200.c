
#include<stdio.h>
#include<stdlib.h>


// 印出整個 Island
void printIsland(char** grid, int gridSize, int colsize){

	int i,j;
    printf("Island:\n");

	for(i=0;i<gridSize;i++){
    	for(j=0;j<colsize;j++){

    		printf("%c ",grid[i][j]);

    	}
    	printf("\n");
    }

}

void findIsland(char** grid, int gridSize, int colsize, int row, int col){

	// 確保沒有超出範圍
	if(col+1 < colsize){

		// 找右邊一格
		if(grid[row][col + 1] == '1'){

			findIsland(grid, gridSize, colsize, row, col+1);

		}

	}

	// 確保沒有超出範圍
	if(row+1 < gridSize){

		// 找下面一格
		if(grid[row + 1][col] == '1'){

			findIsland(grid, gridSize, colsize, row+1, col);

		}

	}

	//將這一格改成 0 (表示找過了)
	//防止進入無窮迴圈 (進左在進右)
	grid[row][col] = '0';


	// 確保沒有超出範圍
	if(col-1 >= 0){

		// 找左邊一格
		if(grid[row][col - 1] == '1'){

			findIsland(grid, gridSize, colsize, row, col-1);
		}

	}

	if(row-1 >= 0){

		// 找上面一格
		if(grid[row - 1][col] == '1'){

			findIsland(grid, gridSize, colsize, row-1, col);

		}

	}


}

int numIslands(char** grid, int gridSize, int* gridColSize){
    

    if(gridSize == 0)
        return 0;

    int count = 0, i, j, colsize;
    colsize = * gridColSize;

    for(i=0;i<gridSize;i++){
    	for(j=0;j<colsize;j++){

    		if(grid[i][j] == '1'){
    			findIsland(grid, gridSize, colsize, i, j);
    			count = count + 1;
    		}

    	}
    }

    //printf("Count = %d \n",count);
    //printf("colsize = %d\n",colsize);
    //printIsland(grid, gridSize,  colsize);
    
    return count;
}

// Test Island Map

[["1","1","0","0","0"],["1","1","0","0","0"],["0","0","1","0","0"],["0","0","0","1","1"]]

[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]

[["1","0","0","0","0"],["1","0","0","0","0"],["0","1","0","1","0"],["1","1","0","1","0"]]


// 會往上的 case
[["1","0","1","1","1"],["1","0","1","0","1"],["1","1","1","0","1"]]
