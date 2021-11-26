/**
 * Name: Nehal Ahmad
 * Roll Number: 20MCA44
 */

#include<iostream>
using namespace std;

void getNumMulti(int n, int **M){
	cout << M[n -1][0] << endl;
}

void getOrder(int i, int j, int **P){
	if(i == j) cout<<"A"<<j;
	else{
		int k = P[i-1][j-i-1];
		cout<<"(";
		getOrder(i, k, P);
		getOrder(k+1, j, P);
		cout << ")";
	}
}

int multiplier(int d[], int n){
  int **M = new int*[n];
	for(int i=0; i<n; i++){
		M[i] = new int[n-i];
	}

	int **P = new int*[n-1];
	for(int i=0; i<n-1; i++){
		P[i] = new int [n-1-i];
	}

	for(int i=0; i<n; i++){
			M[i][0] = 0;
	}

	for(int diagonal=1; diagonal<n; diagonal++) {
		cout << "Scanning diagonal: " << diagonal << endl;
		for(int i=0; i<n-diagonal; i++){
			int j = diagonal;
			M[j][i] =  M[0][i] + M[j-1][i+1] + d[i]*d[i+1]*d[i+j+1];
			cout << "Store value " << "\t" << M[j][i] << " at " << j << i << endl;
			P[i][j-1]=i+1;
			for(int k=i+1; k<=i+j-1; k++){
				if((M[k-i][i] + M[i+j-k-1][k+1] + d[i]*d[k+1]*d[i+j+1]) < M[j][i]){
					M[j][i] = M[k-i][i] + M[i+j-k-1][k+1] + d[i]*d[k+1]*d[i+j+1];
					cout << "Store value "  << "\t" << M[j][i]  << " at " << j << i << endl;
					P[i][j-1] = k+1;
				}
			}
		}
	}

	for(int i=1; i< n - 1; i++){
		for(int j = n-1; j > 0; j--){
			M[j][i] = M[abs(j-i)][i];
		}
	}

	cout << endl << "Required Matrix is" << endl;;
	for(int i=0; i<n; i++){
		for(int j=0; j<=i; j++)
			cout << M[i][j] << "\t";
		cout<<"\n";
	}

	cout << endl << "Required Order is" << endl;;
	getOrder(1, n, P);

	cout << endl << endl << "Number of multiplications in optimal getOrder is: " << endl;
	getNumMulti(n, M);

	return 0;	
}

int main(){
	int d[] = {5, 2, 3, 4, 6};
	multiplier(d, 4);
	return 0;
}
