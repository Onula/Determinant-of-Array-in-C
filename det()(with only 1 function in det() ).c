//by Onula
//This code returns the determinant of the array

/*__________________________________PIECE OF MAIN.C CODE_______________________________________________________    
#include <stdio.h>

void read_array( int s, double array[s][s]);
void copyarray(int s, double cpyarray[s][s], double array[s][s]);

double det(int s, double array[s][s]);
void CheckAndSwap( int s, int ij,  int *sign, double array[s][s]);

//Where array also means matrix
int main(){
	
	//Read the size of array
	int s;
    printf("The size of array: ");
    scanf("%d", &s);

    //Read the elements of array
    double array[s][s];
    read_array(s, array); // Arguments: (int s(size), float array[s][s] ) 
    
    //If you do not want the array[s][s] to change to use it elsewhere for any reason 
	//you can coppy the elements in array[s][s] to another array.There the coppied arrray is cpyarray[s][s]].	
	//But if you dont need the (original) array[s][s] to use it elsewhere you can skip (delete) this part(piece, function) from this code 
	//and change the argument cpyarray to array in the call part of the det() function in printf().
	//So it will be printf("\ndet(array) is: %ld", det(s, array) ); 
    double cpyarray[s][s];
	copyarray(s, cpyarray, array);
    
    //Call the det() function 
	double determinant = det(s,array);  
    
	//Print the determinant of array[s][s]
	printf("\ndet(array) is: %lf", determinant);
}

//READ ARRAY
void read_array(int s, double array[s][s]){
    int i,j;
    printf("\n Give the array (To change rows press ENTER )(To change columns press SPACE): \n");

    //read the array
    for(i=0; i<s; i++){
       printf("row%d < ", i+1);
       for(j=0; j<s; j++)
          scanf("\n%lf", &array[i][j]);
    }
}

//Copying the array[s][s] to cpyarray[s][s]
void copyarray(int s, double cpyarray[s][s], double array[s][s]){
	int i,j;
	for(i=0; i<s; i++){
		for(j=0; j<s; j++){
			cpyarray[i][j] = array[i][j];
		}
	}	
}
__________________________________END OF PIECE OF MAIN.C CODE______________________________________________________*/ 

//FIND DETERMINANT
double det(int s, double array[s][s]){
   	double d1,d2,d3,d4,d5,d6;//Diagonals for s==2( Leibniz formula) or s==3 (Sarrus formula)
   
    
	if(s == 2){//2x2 array (Leibniz formula)
        //Main diagonal
        d1 = array[0][0] * array[1][1];
        //Anti diagonal or secondary diagonal
        d2 = array[0][1] * array[1][0];
        return(d1 - d2);
    }
    else if(s == 3){//3x3 array (Sarrus formula)
        //Consider that the first two columns are copied next to the table.
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
    else{//(s > 3) 
    
		d1 = 1;//Main diagonal
        int ij;//Index for the elemnts of main diagonal
		int i, j; 
		int k, l;//For the loop of Gaussian Elimination
        double a;//dividend
        int sign = 1;
        
        //Check if all elements of some row or column is all 0 before the Gaussian Elimination, because if at least one whole row or column is 0 the determinant is 0
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
		
		//Check if some rows or columns is all same before the Gaussian Elimination, because if they exist the determinant is 0 ( det(array) = 0 )
		int sameElementsR;
		int sameElementsC;
		for(i=0; i<s-1; i++){    
			for(j=i+1; j<s; j++){
				 
				sameElementsR = 0; //The number of same elements of i-row with j-row
				if( array[i][i] == array[j][i] ){//If No.i element of diagonal is equal with the No.i element of j-row, maybe the i-row = j-row 
					for(k=0; k<s; k++){
						//Compare the i-row with j-row if they are same
						if( (sameElementsR != -1) && (array[i][k] == array[j][k]) ) sameElementsR += 1;
					    else break;
					}
					if(sameElementsR == s) return 0; //It means that i-row = j-row
				}
				
				sameElementsC = 0; // The number of same elements of i-column with j-column
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
		
		
		//Finding the determinant of array[][] with Gaussian Elimination making the array upper triangular
        for(ij=0; ij<(s - 1); ij++){
        	
			if(array[ij][ij] == 0){// If the elemnt of diagonal is 0 needs to swap the ij row with another that the element is !=0 in ij-column
        		CheckAndSwap(s, ij, &sign, array);
			}
			
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
            d1 = d1 * array[i][i];
        }
        
        return sign * d1; //This multiplication is done so that the determinant gets the right sign
    }
}

/* SWAP the ij-row  (if the element array[ij][ij]==0) with the row that the element in ij-column  is different from 0 (!=0).
   CHANGE the sign of result(determinant) if swap.                                                                         */
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



