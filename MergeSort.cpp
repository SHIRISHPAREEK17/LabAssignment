#include <iostream>
using namespace std;
void merging(int arr[], int lb1, int ub1, int lb2, int ub2) {
    int size = ub2 - lb1 + 1;
    int temp[size];
    int i = lb1, j = lb2, k = 0;
    while (i <= ub1 && j <= ub2) {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= ub1)
        temp[k++] = arr[i++];
    while (j <= ub2)
        temp[k++] = arr[j++];

    for(int t=0;t<size;t++){
    	arr[lb1+t]=temp[t];
	}
}

void mergeSort(int arr[], int lb, int ub) {
        if(lb>=ub){
		   return;
	    }
        int mid = (lb + ub) / 2;
        mergeSort(arr, lb, mid);
        mergeSort(arr, mid + 1, ub);
        merging(arr, lb, mid, mid + 1, ub);
    
}

int main() {
    int arr[] = {1, 5, 6, 3, 7, 2, 3, 8, 9, 4, 3};
    int n = sizeof(arr) / sizeof(int);

    cout << "Original array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    mergeSort(arr, 0, n - 1);

    cout << "\nSorted array (ascending): ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}

