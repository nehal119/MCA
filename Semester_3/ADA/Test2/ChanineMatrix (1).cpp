#include<iostream>
using namespace std;

Algorithm minMul(d[0:n],P[1:n-1][1:n], n){
2. For i = 1 to n do {M[i, i] = 0; }
3. For diagonal = 1 to n-1 do {
4. For i = 1 to n-diagonal do {
5. j = i + diagonal;
6. M[i, j] = M[i, i] + M[i+1, j] + d[i-1]*d[i]*d[j];
7. P[i, j] = i;
8. For k = i+1 to j-1 do{
9. If((M[i, k] + M[k+1, j] + d[i-1]*d[k]*d[j]) < M[i, j]) then {
10. M[i, j] = M[i, k] + M[k+1, j] + d[i-1]*d[k]*d[j];
11. P[i, j] = k;
12. }
13. }
14. }
15. }
16. return M[1, n];
17. }
int minMul(int d[], int n){
    int **M = new int*[n];
	for(int i=0; i<n; i++)
		M[i] = new int[n-i];
	int **P = new int*[n-1];
	for(int i=0; i<n-1; i++)
		P[i] = new int [n-1-i];
	for(int i=0; i<n; i++)
		M[i][0] = 0;
	for(int diagonal=1; diagnal<n; diagonal++)
	{
		for(int i=0; i<n-diagonal; i++){
			int j = diagonal;
			M[i][j] =  M[i, 0] + M[i+1, j-1] + d[i]*d[i+1]*d[i+j+1];
			P[i][j]=i;
	For k = i+1 to j-1 do{
9. If((M[i, k] + M[k+1, j] + d[i-1]*d[k]*d[j]) < M[i, j]) then {
10. M[i, j] = M[i, k] + M[k+1, j] + d[i-1]*d[k]*d[j];
11. P[i, j] = k;
12. }
		}
	}
	
			
}

Algorithm order(i, j,P[1:n-1][1:n], n){
2. If(i == j) then { Print (“A” + j);
3. Else{
4. k = P[i, j];
5. Print (“(“);
6. order(i, k);
7. order(k+1, j);
8. Print (“)”);
9. }
10. }
