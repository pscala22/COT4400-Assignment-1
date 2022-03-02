#include <bits/stdc++.h>
using namespace std;

void swap(int* a, int* b) //swap Function
{
   int t = *a;
   *a = *b;
   *b = t;
}


int part (int arr[], int l, int h) //part Function
{
   int pivot = arr[h]; // pivot
   int i = (l - 1); // Index of smaller element

   for (int j = l; j <= h - 1; j++)
   {
       // If current element is smaller than the pivot
       if (arr[j] < pivot)
       {
           i++; // increment index of smaller element
           swap(&arr[i], &arr[j]);
       }
   }
   swap(&arr[i + 1], &arr[h]);
   return (i + 1);
}


void quickSort(int arr[], int low, int high) //quickSort Function
{
   if (low < high)
   {
      
       int pi = part(arr, low, high);

       // Separately sort elements before
       // partition and after partition
       quickSort(arr, low, pi - 1);
       quickSort(arr, pi + 1, high);
   }
}


void printArray(int arr[], int size) //printArray Function
{
   int i;
   for (i = 0; i < size; i++)
       cout << arr[i] << " ";
   cout << endl;
}

// Driver Code
int main()
{
   int arr[] = {10,80,3,19,14,7,5,12}; //Initializing the array
   int n = sizeof(arr) / sizeof(arr[0]);
   cout << "Part 1 Unsorted Array:  \n";
   printArray(arr, n);
   quickSort(arr, 0, n - 1); //Calling quickSort Function
   cout << "Part 1 Sorted array: \n";
   printArray(arr, n); //Printing Sorted array
   int a[100],a1[1000];
   srand(time(0));

   for(int i=0;i<100;i++){
   			a[i] = rand() % 100; //Generating 100 random numbers
   					}
	cout << "Part 2 Unsorted Array:  \n";
   	printArray(a, 99);
   	quickSort(a,0,99); //Calling quickSort Function
   	cout<<"Part 2 Sorted array: \n";
  	printArray(a,100); //Printing Sorted array
  
   for(int i=0;i<1000;i++){
   			a1[i] = rand() % 100; //Generating 1000 random numbers
   			}
	cout << "Part 3 Unsorted Array:  \n";		   
	printArray(a1, 999);
   	quickSort(a1,0,999); //Calling quickSort Function
   	cout<<"Part 3 Sorted array: \n";
   	printArray(a1,1000); //Printing Sorted array
   return 0;
}

