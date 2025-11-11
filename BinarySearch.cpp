#include <iostream>

using namespace std;
bool binarySearch(int arr[],int n,int target){
	int lb=0;
	int ub=n-1;
	while(lb<=ub){
		int mid=(lb+ub)/2;
		if(arr[mid]==target){
			return true;
		}
		if(arr[mid]>target)
			ub=mid-1;	
		else 
		 lb=mid+1;
	}
	return false;
}

int main() {
    int arr[] = {10,30,45,46,49,51,55,67,70,72};
    if(binarySearch(arr,10,70)){
    	cout<<"Found"<<endl;;
	}
	else {
		cout<<"Not found"<<endl;
	}
    return 0;
}

