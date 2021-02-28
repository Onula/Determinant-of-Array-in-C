#include <stdio.h>
#include <stdlib.h>
#include "detlib.h"

void read_array( int s, double array[s][s]);
void copyarray(int s, double cpyarray[s][s],  double array[s][s]);

//Where array also means matrix
int main(){
	
	//Read the size of array
	int s;
    printf("The size of array: ");
    scanf("%d", &s);

    //Read the elements of array
    double array[s][s];
    read_array(s, array); // Arguments: (int s(size), long double array[s][s] ) 
    
    /*If you do not want the array[s][s] to change to use it elsewhere for any reason 
	you can coppy the elements in array[s][s] to another array.There the coppied arrray is cpyarray[s][s]].	
	But if you dont need the (original) array[s][s] to use it elsewhere you can skip (delete) this part(piece, function) from this code 
	and change the argument cpyarray to array in the call part of the det() function in printf().
	So it will be printf("\ndet(array) is: %ld", det(s, array) );*/ 
    double cpyarray[s][s];
	copyarray(s, cpyarray, array);
	 	
	//Print the determinant of array[s][s]
	printf("\ndet(array) is: %lf", det(s, array) );//
	
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
