#include <stdio.h>
#include <stdlib.h>
#include "detlib.h"


double det(int s, double array[s][s]);
double s2(int s, double array[s][s]);//For 2 x 2 array
double s3(int s, double array[s][s]);//For 3 x 3 array
//For n x n array that n > 3
int checkElements(int s, double array[s][s]);//Check if all elements of some row or column is all 0
int checkRowsColumns(int s, double array[s][s]);//Check if some rows or columns is same
double GaussianElimination(int s, double array[s][s]);//If the above expressions are false performing Gaussian Elimination 
    void CheckAndSwap(int s, int ij, int *sign, double array[s][s]);//The function inside the function GaussianElimination()


//FIND DETERMINANT
double det(int s, double array[s][s]){
   
	if(s == 2){//2 x 2 array (Leibniz formula)
        return s2(s, array);
    }
    else if(s == 3){//3 x 3 array (Sarrus formula)
        return s3(s,array);
    }
    else{//s > 3 (s x s array)
    
        //Check if all elements of some row or column is all 0 before the Gaussian Elimination, because if at least one whole row or column is 0 the determinant is 0
        if(checkElements(s, array) == 0 ) return 0;
		
		//Check if some rows or columns is same before the Gaussian Elimination, because if they exist the determinant is 0 ( det(array) = 0 )
		if(checkRowsColumns(s, array) == 0 ) return 0;
	
		//Finding the determinant of array[][] with performing Gaussian Elimination that makes the array upper triangular, if the above expressions are false
        return GaussianElimination(s, array); 
    }
}

// The functions in det() function __________________________________________________________________________________

//If s==2 (2 x 2 array)
double  s2(int s, double array[s][s]){
	//Main diagonal
    double  d1 = array[0][0] * array[1][1];
    
	//Anti diagonal or secondary diagonal
    double  d2 = array[0][1] * array[1][0];
    
	return(d1 - d2);
}

//If s==3(3 x 3 array)
double  s3(int s, double array[s][s]){
	double  d1, d2, d3, d4, d5, d6;//Diagonals
	//Imagine that the first two columns are copied after the sth column of the table and the table is sxs.
	
	//Diagonal north-west to south-east lines
        d1 = array[0][0] * array[1][1] * array[2][2];
        d2 = array[0][1] * array[1][2] * array[2][0];
        d3 = array[0][2] * array[1][0] * array[2][1];
    //Diagonal south-west to north-east lines
        d4 = array[2][0] * array[1][1] * array[0][2];
        d5 = array[2][1] * array[1][2] * array[0][0];
        d6 = array[2][2] * array[1][0] * array[0][1];

    return d1+d2+d3 - d4-d5-d6;
}

//If s>3 check if all elements of some row or column is all 0 before the Gaussian Elimination, because if at least one whole row or column is 0 the determinant is 0
int checkElements(int s, double array[s][s]){
	int i, j;
	for(i=0; i<s; i++){
        int zeroesC = 0; //Zeroes counters of  i-column 
		int zeroesR = 0;//Zeroes counters of i-row  
       	if(array[i][i] != 0) continue; //If the common element of i-row and i-column(or i-diagonal)it's not 0, there is no reason to check the other elements                 
		for(j=0; j<s; j++){
			
   		    //Check for i-column if the j-element is 0
		    if( (zeroesC != -1) && (array[j][i] == 0)) zeroesC += 1	; 
		    else zeroesC = -1;//This means that at least one element is not 0
		    //Check for i-row if the j-element is 0
			if( (zeroesR != -1) && (array[i][j] == 0)) zeroesR += 1	;
			else zeroesR = -1;//This means that at least one element is not 0
				
			if((zeroesC == -1) && (zeroesR == -1)) break;//If at least one element of i-row and j-column it's not zero ,go to the next row and column
				
			if( (zeroesC == s) || (zeroesR == s) ) return 0;// If the elements of i-row or i-column is all 0 the determinant it's 0 	
		}
     }
	 return -1;//It means that dont have column or row that all elements are 0	
}
//If s>3 check if some rows or columns is all same before the Gaussian Elimination, because if they exist the determinant is 0 ( det(array) = 0 )
int checkRowsColumns(int s, double array[s][s]){
	int i, j, k;
	for(i=0; i<s-1; i++){    
		for(j=i+1; j<s; j++){
				 
			int sameElementsR = 0; //The number of same elements of i-row with j-row
			if( array[i][i] == array[j][i] ){//If No.i element of diagonal is equal with the No.i element of j-row, maybe the i-row = j-row 
				for(k=0; k<s; k++){
					//Compare the i-row with j-row if they are same
					if( (sameElementsR != -1) && (array[i][k] == array[j][k]) ) sameElementsR += 1;
					else break;
				}
				if(sameElementsR == s) return 0; //It means that i-row = j-row
			}
				
			int sameElementsC = 0; // The number of same elements of i-column with j-column
			if(array[i][i] == array[i][j]){//If No.i element of diagonal is equal with the No.i element of j-column, maybe the  i-column = j-column
				for(k=0; k<s; k++){
					//Compare the i-column with j-column if they are same
					if(array[k][i] == array[k][j])  sameElementsC += 1;
					else break;
				}
				if(sameElementsC == s) return 0; //It means that i-column = j-column so the determinant is equal to 0	
			}	
		}
	}
	return -1;//It means that any i-column != j-column
	
}
//If s > 3 finding the determinant of array[][] with Gaussian Elimination making the array upper triangular
double  GaussianElimination(int s, double  array[s][s]){
	int ij;//Index for the elemnts of main diagonal
	int k, l, i;//Indexes in for(){} loops
	double d = 1;//The product of the main diagonal
	double a;//dividend
	int sign = 1;

	for(ij=0; ij<(s - 1); ij++){
        	
		if(array[ij][ij] == 0)// If the elemnt of diagonal is 0 needs to swap the ij row with another that the element is !=0 in ij-column
       		CheckAndSwap(s, ij, &sign, array);
				
		//Mathematical operations to zero the elements below the elemnt array[ij][ij] in ij-column
        for(k=ij+1; k<s; k++){  
			a = array[k][ij]; //dividend
			// (k row) = (ij row) * ( -(element of ij-column in k-row) / (elemnt of ij-row and ij-column in diagonal) + (k-row)
            for(l=ij; l<s; l++){
            //If you want to print the mathematical operations delete the slashes(//) below, before printf
			//printf("array[%d][%d] = %f * ( %f/%f ) + %f \n", k, l, array[ij][l], -a, array[ij][ij] , array[k][l]);  
            array[k][l] = array[ij][l] * ( -a / array[ij][ij] ) + array[k][l]; 
            }
        }
    }
          
    //The product of the diagonal gives the determinant 
    for(i=0; i<s; i++){
        d = d * array[i][i];
    }
    
    return sign * d; //This multiplication is done so that the determinant gets the right sign
}

/* SWAP the ij-row  (if the element array[ij][ij]==0) with the row that the element in ij-column  is different from 0 (!=0).
   CHANGE the sign of result(determinant) if swap. */
void CheckAndSwap(int s, int ij, int *sign, double array[s][s]){
	int i,j;
	int row=0;
	double temp;
	
	//check  
	for(i=ij+1; i<s; i++){
	    if(array[i][ij] != 0){
	    	row = i;
	    	break;
		}	
	} 
	
	// when all the elements of the column from ij to s are not 0
	if(row != 0){
		//swap the elements of rows 
	    for(j=ij; j<s; j++){
		    temp = array[ij][j];
		    array[ij][j] = array[row][j];
		    array[row][j] = temp;
	    }
	}
	
    // When swap the rows the sign becomes the opposite 	
	*sign = (*sign) * -1; 
		
}


