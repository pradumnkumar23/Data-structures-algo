#include<bits/stdc++.h>
using namespace std;

int recover(int input[], int n, int output[]){
	int left, right;
	int mid=n/2;
	int i=0;
	if(n%2!=0){
		output[mid]=input[0];
		i++;
		left=mid-1;
		right=mid+1;
	}
	else{
		left=mid-1;
		right=mid;
	}
	while(i<n){
		output[left]=input[i];left--;
		i++;
		output[right]=input[i];
		right++;
		i++;
	}
} 

int main(){
	int n;
	cin>>n;
	int input[1000];
	int output[1000];
	for(int i=0;i<n;i++) cin>>input[i];
	recover(input, n, output);
	for(int i=0;i<n;i++) cout<<output[i]<<" ";
}

/*
#include <iostream>
using namespace std;

void recoverArray(int input[], int n, int output[]) {
	int left, right;
	
  int mid = n/2;
	int i = 0;
	if(n % 2 != 0) {
		output[mid] = input[i];
		left = mid - 1;
		right = mid + 1;
		i++;
	}
	else {
		left = mid - 1;
		right = mid;
	}

	while(i < n) {
		output[left] = input[i];
		left--;
		i++;
		output[right] = input[i];
		right++;
		i++;
	}
}

int main() {
	int input[100];
	int n;

	int output[100];

	cin >> n;

	for(int i = 0; i < n; i++) {
		cin >> input[i];
	}

	recoverArray(input, n, output);

	for(int i = 0; i < n; i++) {
		cout << output[i] << " ";
	}

}
*/
