#include <iostream>
using namespace std;

int min(int N[], int x, int n, int r){
	int j = n-x;
	int min;
	for(int i=0; i<x; i++){
		if(N[j]>N[j+1]){
			if(N[j+1]>r){
				min = N[j+1];
			}
		}
		j++;
	}
	return min;
}

int search(int N[], int x, int n, int r){
	int j = n-x;
	int k;
	for(int i=0; i<x; i++){
		if(N[j]>N[j+1]){
			if(N[j+1]>r){
				k = j+1;
			}
		}
		j++;
	}
	return k;
}

int main() {
	int n; 
	cin >> n;
	int A[n];
	for(int i=0; i<n;i++){
		cin >> A[i];
	}
	
	int h,m;
	
	for(int i = n-1; i>=0;i--){
		if(A[i]>A[i-1]){
			int v = A[i-1];
			m = min(A,i,n,v);
			h = search(A,i,n,v);
			//cout << v << " ";
			//cout << h << " ";
			//cout << m << " ";
			//cout << A[h] << " ";
			//cout << A[i-1] << " ";
			A[h] = A[i-1];
			A[i-1] = m;
			int x = i;
			for (int i = x; i < n ; i++){
			    for (int j = (n - 1); j > i; j--){
			      if (A[j - 1] > A[j]){
			        int tmp = A[j - 1];
			        A[j - 1] = A[j];
			        A[j] = tmp;
			      }
		    	} 
			}
			for(int i=0;i<n;i++){
				cout << A[i] ;
			}
		break;
		}
	}
	
	return 0;
}