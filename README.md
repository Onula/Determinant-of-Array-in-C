# ------------Determinant-of-Array-in-C------------
# About det() function
<p>1. Takes the size of array and the array(det(int s, double array[s][s])</p>
<p>2. Returns the determinant of array( in this code returns double value )</p>

# About functions in det()
<p>◻️s2() function is for 2 x 2 array</p>
<p>◻️s3() function is for 3 x 3 array</p>
<p>for n x n array with n > 3 there are the following functions</p> 
  <p>&emsp;◻️checkElements() function is because if all elements of some row or column is all 0 the determinant of array is 0(det=0)</p>
  <p>&emsp;◻️checkRowsColumns() function is because if 2-rows or 2-columns is same, the determinant of array is 0 (det=0)</p>
  <p>&emsp;◻️GaussianElimination() function is performed if the above expressions does not returned TRUE (or does not apply) and perform the Gaussian Elimination to find the determinant array </p>
  <p>&emsp;◻️CheckAndSwap() function is inside the GaussianElimination() function because if some element of diagonal is 0 needs to swap the ij row with another whose the element is different from 0 (!=0) in ij-column  AND changing the sign of determinant if swap.</p>
