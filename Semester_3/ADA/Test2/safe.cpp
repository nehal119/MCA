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
		M[i][0] = 0;
	
	for(int diagonal=1; diagonal<n; diagonal++) {
		cout << "Diagonal is: " << diagonal << endl;
		for(int i=0; i<n-diagonal; i++){
			cout << "I is: " << i << endl;
			int j = diagonal;
			cout << "J is: " << j << endl;
			M[j][i] =  M[0][i] + M[j-1][i+1] + d[i]*d[i+1]*d[i+j+1];
			cout << "round 1 stored" << "\t" << M[j][i] << "at" << j << i << endl;
			P[i][j-1]=i+1;
			for(int k=i+1; k<=i+j-1; k++){
				cout << "round 2 +++++++++++++++"  << "\t"  << M[k-i][i] + M[i+j-k-1][k+1] + d[i]*d[k+1]*d[i+j+1] << endl;
				cout << "round 3 +++++++++++++++"  << "\t"  << M[j][i] << endl;
				if((M[k-i][i] + M[i+j-k-1][k+1] + d[i]*d[k+1]*d[i+j+1]) < M[j][i]){
					M[j][i] = M[k-i][i] + M[i+j-k-1][k+1] + d[i]*d[k+1]*d[i+j+1];
					cout << "round 4 stored"  << "\t" << M[j][i]  << "at" << j << i << endl;
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
	// order(1, n, P);
	return 0;	
}

int main(){
	int d[] = {5, 2, 3, 4, 6};
	minMul(d, 4);
	return 0;
}
