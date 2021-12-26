#include<iostream>
using namespace std;

void knapsack_Dynamic(int w[], int p[], int n, int W){
	int **P = new int*[n+1];

	for(int i=0; i<=n; i++)
		P[i] = new int[W+1];

	bool **keep = new bool*[n];

	for(int i=0; i<n; i++)
		keep[i] = new bool[W];

	for(int j=0; j<=W; j++) P[0][j] = 0;

	for(int i=1; i<=n; i++)
		for(int j=0; j<=W; j++){
			if(j>= w[i-1] && (p[i-1]+P[i-1][j-w[i-1]] > P[i-1][j])){
				P[i][j] = p[i-1] + P[i-1][j-w[i-1]];  keep[i-1][j-1]=true;
			}else{
				P[i][j] = P[i-1][j]; keep[i-1][j-1] = false;
			}
		}
	
	cout << "\nMatrix P\n";
	for(int i=0; i<=n; i++){
		for(int j=0; j<=W; j++)
			cout << P[i][j] << "\t";
		cout<<"\n";
	}

	cout<<"\nMatrix keep\n";
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<W; j++)
			cout << keep[i][j] << "\t";
		cout << "\n";
	}

	int k=W;
	cout<<"\nOptimal set = {";
	for(int i=n; i>=1; i--){
		if(keep[i-1][k-1] == true) {
			cout<<"item-"<<i <<", ";
			k = k - w[i-1];
		}
	}
	cout<<"\b\b}\nMax. Profit = " << P[n][W];
}

int main(){
	int w[] = {5, 4, 6, 3};
	int p[] = {10, 40, 30, 50};
	int n = 4, W = 10;
	knapsack_Dynamic(w, p, n, W);
	return 0;
}
