#include<iostream>
using namespace std;
void order(int i, int j, int **P){
	if(i == j) cout<<"A"<<j;
	else{
		int k = P[i-1][j-i-1];
		cout<<"(";
		order(i, k, P);
		order(k+1, j, P);
		cout << ")";
	}
}

int minMul(int d[], int n){
  int **M = new int*[n];
	for(int i=0; i<n; i++)
		M[i] = new int[n-i];
	
	int **P = new int*[n-1];
	for(int i=0; i<n-1; i++)
		P[i] = new int [n-1-i];
	
	for(int i=0; i<n; i++)
		M[0][i] = 0;
	
	for(int diagonal=1; diagonal<n; diagonal++) {
		for(int i=0; i<n-diagonal; i++){
			int j = diagonal;
			M[i][j] =  M[i][0] + M[i+1][j-1] + d[i]*d[i+1]*d[i+j+1];
			P[i][j-1]=i+1;
			for(int k=i+1; k<=i+j-1; k++){
				if((M[i][k-i]+M[k+1][i+j-k-1]+d[i]*d[k+1]*d[i+j+1]) < M[i][j]){
					M[i][j] = M[i][k-i]+M[k+1][i+j-k-1]+d[i]*d[k+1]*d[i+j+1];
					P[i][j-1] = k+1;
				}
			}
		}
	}
	cout << "\nMatrix M is\n";
	for(int i=0; i<n; i++){
		for(int j=0; j<n-i; j++)
			cout << M[i][j] << "\t";
		cout<<"\n";
	}
	cout << "\nMatrix P is\n";
	for(int i=0; i<n-1; i++){
		for(int j=0; j<n-1-i; j++)
			cout << P[i][j] << "\t";
		cout<<"\n";
	}
	order(1, n, P);
	return 0;	
}

/*
Algorithm order(i, j,P[1:n-1][1:n], n){
2. If(i == j) then { Print (�A� + j);
3. Else{
4. k = P[i, j];
5. Print (�(�);
6. order(i, k);
7. order(k+1, j);
8. Print (�)�);
9. }
10. }
*/
int main(){
	int d[] = {5, 2, 3, 4, 6};
	minMul(d, 4);
	return 0;
}
