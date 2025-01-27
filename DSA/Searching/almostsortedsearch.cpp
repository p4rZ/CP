#include<bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int l, int r, int x) 
{ 
		if (r >= l) 
		{ 
			int mid = l + (r - l) / 2; 
	
			if (arr[mid] == x)  
				return mid; 
			if (mid > l && arr[mid - 1] == x) 
				return (mid - 1); 
			if (mid < r && arr[mid + 1] == x)  
				return (mid + 1); 
			
			if (arr[mid] > x)  
				return binarySearch(arr, l, mid - 2, x); 
		
			return binarySearch(arr, mid + 2, r, x); 
		} 
  
	return -1; 
} 
  
// Driver Code 
int main(void) 
{ 
	int arr[] = {3, 2, 10, 4, 40}; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	int x = 4; 
	int result = binarySearch(arr, 0, n - 1, x); 
	(result == -1) ? printf("Element is not present in array") 
	               : printf("Element is present at index %d",  
	                         result); 
	return 0; 
} 
