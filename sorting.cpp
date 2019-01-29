#include <cstdio>
#include <iostream>
using namespace std;

void insertion_sort(int arr[], int n)
{
	int i, j, temp;
	for (i = 1; i<n; i++)
	{
		temp = arr[i];
		for (j = i - 1; j >= 0 && arr[j] > temp; j--)
			arr[j + 1] = arr[j];
		arr[j + 1] = temp;
	}
}

void quick_sort(int arr[], int left, int right)
{
	// 0. if part contains single ele (left==right) or part is invalid(left>right), stop.
	if (left >= right)
		return;
	// arr[left] is pivot
	int i = left, j = right;
	while (i < j)
	{
		// 1. from left find number greater than pivot - i index
		while (i <= right && arr[i] <= arr[left])
			i++;
		// 2. from right find number less than or equal to pivot - j index
		while (arr[j] > arr[left])
			j--;
		// 3. if i < j, swap arr[i] & arr[j]
		if (i < j)
			swap(arr[i], arr[j]);
	} // 4. repeat steps 1-3, till i < j

	// 5. swap pivot (arr[left]) and arr[j]
	swap(arr[left], arr[j]);
	// 6. quick_sort for left part -> 'left' to 'j-1'
	quick_sort(arr, left, j - 1);
	// 7. quick_sort for right part -> 'j+1' to 'right'
	quick_sort(arr, j + 1, right);
}

void merge_sort(int arr[], int left, int right)
{
	// 0. if part contains single ele (left==right) or part is invalid(left>right), stop.
	if (left >= right)
		return;
	// 1. divide array in two equal partitions.
	int mid = (left + right) / 2;
	// 2. sort left part -> left to mid
	merge_sort(arr, left, mid);
	// 3. sort right part -> mid+1 to right
	merge_sort(arr, mid + 1, right);
	// 4. allocate a temp array : num of elements (right - left + 1)
	int cnt = right - left + 1;
	int *temp = new int[cnt];
	// 5. merge two sorted partitions into this temp array
	int i = left, j = mid + 1, k = 0;
	while (i <= mid && j <= right)
		temp[k++] = arr[i] < arr[j] ? arr[i++] : arr[j++];
	//{
	//	if (arr[i] < arr[j])
	//		temp[k++] = arr[i++];
	//	else
	//		temp[k++] = arr[j++];
	//}
	while (i <= mid)
		temp[k++] = arr[i++];
	while (j <= right)
		temp[k++] = arr[j++];
	// 6. copy temp array back to original array partition
	memcpy(arr + left, temp, cnt * sizeof(int));
	//for (k = 0; k<cnt; k++)
	//	arr[left + k] = temp[k];
	// 7. release temp array
	delete[] temp;
}

int main()
{
	int i, arr[] = { 33, 22, 44, 11, 66 };
	int cnt = sizeof(arr) / sizeof(arr[0]);

	printf("\Before Sorting : \n");
	for (i = 0; i < cnt; i++)
		printf("%d, ", arr[i]);
	printf("\n");

	//insertion_sort(arr, cnt);
	//quick_sort(arr, 0, cnt - 1);
	merge_sort(arr, 0, cnt - 1);

	printf("\nAfter Sorting : \n");
	for (i = 0; i < cnt; i++)
		printf("%d, ", arr[i]);
	printf("\n");
	return 0;
}
