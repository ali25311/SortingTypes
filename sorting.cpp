#include<iostream>
#include<ctime>
#include<time.h>
using namespace std;
void swap(int *xp, int *yp)  
{  
    int temp = *xp;  
    *xp = *yp;  
    *yp = temp;  
}  
  
// A function to implement bubble sort  
int bubbleSort(int arr[], int n)  
{  
	int totalComparisons=0;
    int i, j;  
    for (i = 0; i < n-1; i++)   
	{
		for (j = 0; j < n-i-1; j++) 
		{
			totalComparisons++;
			if (arr[j] > arr[j+1])  
			{
				swap(&arr[j], &arr[j+1]); 
			}
				
		}
			 
	}
	return totalComparisons;
		
}  
 
int insertionSort(int arr[], int n)  
{  
    int i, key, j;  
	int totalComparisons=0;
    for (i = 1; i < n; i++) 
    {  
        key = arr[i];  
        j = i - 1;  
  
        /* Move elements of arr[0..i-1], that are  
        greater than key, to one position ahead  
        of their current position */
        while (j >= 0 && arr[j] > key) 
        {  
			totalComparisons++;
            arr[j + 1] = arr[j];  
            j = j - 1;  
        }  
        arr[j + 1] = key;  
    }  
	return totalComparisons;
}  
int selectionSort(int arr[], int n)  
{  
    int i, j, min_idx;
	int totalComparison=0;
  
    // One by one move boundary of unsorted subarray  
    for (i = 0; i < n-1; i++)  
    {  
        // Find the minimum element in unsorted array  
        min_idx = i;  
        for (j = i+1; j < n; j++)  
		{
			totalComparison++;
			if (arr[j] < arr[min_idx])  
			{
				min_idx = j;
			}
            
		}
          
  
        // Swap the found minimum element with the first element  
        swap(&arr[min_idx], &arr[i]);  
    } 
	return totalComparison;
}  
void merge(int arr[], int l, int m, int r,int &com) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    /* create temp arrays */
    int *L=new int[n1];
	int *R=new int[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) 
    { 
		com++;
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
/* l is for left index and r is right index of the 
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r,int &com) 
{ 
    if (l < r) 
    { 
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        int m = l+(r-l)/2; 
  
        // Sort first and second halves 
        mergeSort(arr, l, m,com); 
        mergeSort(arr, m+1, r,com); 
  
        merge(arr, l, m, r,com); 
    } 
} 
 int partition(int arr[], int low, int high,int &com) 
{ 
    int pivot = arr[high]; // pivot 
    int i = (low - 1); // Index of smaller element 
  
    for (int j = low; j <= high - 1; j++) { 
  
        // If current element is smaller than or 
        // equal to pivot 
		com++;
        if (arr[j] <= pivot) { 
  
            i++; // increment index of smaller element 
            swap(arr[i], arr[j]); 
        } 
    } 
    swap(arr[i + 1], arr[high]); 
    return (i + 1); 
} 
  
int partition_r(int arr[], int low, int high,int &com) 
{ 
    // Generate a random number in between 
    // low .. high 
    srand(time(NULL)); 
    int random = low + rand() % (high - low); 
  
    // Swap A[random] with A[high] 
    swap(arr[random], arr[high]); 
  
    return partition(arr, low, high,com); 
} 
  
/* The main function that implements QuickSort 
arr[] --> Array to be sorted, 
low --> Starting index, 
high --> Ending index */
void quickSort(int arr[], int low, int high,int &com) 
{ 
    if (low < high) { 
  
        /* pi is partitioning index, arr[p] is now 
        at right place */
        int pi = partition_r(arr, low, high,com); 
  
        // Separately sort elements before 
        // partition and after partition 
        quickSort(arr, low, pi - 1,com); 
        quickSort(arr, pi + 1, high,com); 
    } 
} 
/* Function to print an array */
void printArray(int arr[], int size)  
{  
	cout<<"First 10 Entries: ";
    int i;  
    for (i = 0; i < 10; i++)  
        cout << arr[i] << " ";  
    cout << endl;  
	cout<<"Last 10 Entries: ";
    for (i = 90; i < size; i++)  
        cout << arr[i] << " ";  
    cout << endl;  
}  

int main()
{
	srand(time(NULL)); 
	int arr1[100],arr2[100],arr3[100],arr4[100],arr5[100],arr6[100],arr7[100],arr8[100],arr9[100],arr10[100],arr11[100],arr12[100],arr13[100],arr14[100],arr15[100];
	double time1,time2,time3,time4,time5,time6,time7,time8,time9,time10,time11,time12,time13,time14,time15;
	int num1=1,num2=100;
	for(int i=0;i<100;i++)
	{
		arr1[i]=num1;
		arr2[i]=num2;
		arr4[i]=num1;
		arr5[i]=num2;
		arr7[i]=num1;
		arr8[i]=num2;
		arr10[i]=num1;
		arr11[i]=num2;
		arr13[i]=num1;
		arr14[i]=num2;
		num1++;
		num2--;
	}
	for(int i=0;i<100;i++)
	{
		arr3[i]=0;
		arr6[i]=0;
		arr9[i]=0;
		arr12[i]=0;
		arr15[i]=0;
	}
	for(int i=0;i<100;)
	{
		int n=rand() % 100 + 1;  
		bool notFound=true;
		for(int j=0;j<100;j++)
		{
			if(n==arr3[j])
			{
				notFound=false;
			}
		}
		if(notFound)
		{
			arr3[i]=n;
			arr6[i]=n;
			arr9[i]=n;
			arr12[i]=n;
			arr15[i]=n;
			i++;
		}
	}
	cout<<"Arrays Before Sort\n";
	printArray(arr1,100);
	printArray(arr2,100);
	printArray(arr3,100);
	clock_t tStart = clock();
	int bubblesort1=bubbleSort(arr1,100);
	time1=(double)(clock() - tStart)/CLOCKS_PER_SEC;
	tStart = clock();
	int bubblesort2=bubbleSort(arr2,100);
	time2=(double)(clock() - tStart)/CLOCKS_PER_SEC;
	tStart = clock();
	int bubblesort3=bubbleSort(arr3,100);
	time3=(double)(clock() - tStart)/CLOCKS_PER_SEC;
	tStart = clock();
	cout<<"Arrays After Bubble Sort\n";
	printArray(arr1,100);

	printArray(arr2,100);
	printArray(arr3,100);
	int insertionSort1=insertionSort(arr4,100);
	time4=(double)(clock() - tStart)/CLOCKS_PER_SEC;
	tStart = clock();
	int insertionSort2=insertionSort(arr5,100);
	time5=(double)(clock() - tStart)/CLOCKS_PER_SEC;
	tStart = clock();
	int insertionSort3=insertionSort(arr6,100);
	time6=(double)(clock() - tStart)/CLOCKS_PER_SEC;
	tStart = clock();
	cout<<"Arrays After Insertion Sort\n";
	printArray(arr4,100);
	printArray(arr5,100);
	printArray(arr6,100);
	int selectionSort1=selectionSort(arr7,100);
	time7=(double)(clock() - tStart)/CLOCKS_PER_SEC;
	tStart = clock();
	int selectionSort2=selectionSort(arr8,100);
	time8=(double)(clock() - tStart)/CLOCKS_PER_SEC;
	tStart = clock();
	int selectionSort3=selectionSort(arr9,100);
	time9=(double)(clock() - tStart)/CLOCKS_PER_SEC;
	tStart = clock();
	cout<<"Arrays After Selection Sort\n";
	printArray(arr7,100);
	printArray(arr8,100);
	printArray(arr9,100);
	int quick1=0,quick2=0,quick3=0;

	quickSort(arr10,0,99,quick1);
	time10=(double)(clock() - tStart)/CLOCKS_PER_SEC;
	tStart = clock();
	quickSort(arr11,0,99,quick2);
	time11=(double)(clock() - tStart)/CLOCKS_PER_SEC;
	tStart = clock();
	quickSort(arr12,0,99,quick3);
	time12=(double)(clock() - tStart)/CLOCKS_PER_SEC;
	tStart = clock();
	cout<<"Arrays After Quick Sort\n";
	printArray(arr10,100);
	printArray(arr11,100);
	printArray(arr12,100);
	int merge1=0,merge2=0,merge3=0;
	mergeSort(arr13,0,99,merge1);
	time13=(double)(clock() - tStart)/CLOCKS_PER_SEC;
	tStart = clock();
	mergeSort(arr14,0,99,merge2);
	time14=(double)(clock() - tStart)/CLOCKS_PER_SEC;
	tStart = clock();
	mergeSort(arr15,0,99,merge3);
	time15=(double)(clock() - tStart)/CLOCKS_PER_SEC;
	//tStart = clock();
	cout<<"Arrays After Merge Sort\n";
	printArray(arr13,100);
	printArray(arr14,100);
	printArray(arr15,100);
	cout<<"Comparisons of Bubber Sort:\n";
	cout<<"list 1: "<<bubblesort1<<endl;
	cout<<"list 2: "<<bubblesort2<<endl;
	cout<<"list 3: "<<bubblesort3<<endl;
	cout<<"Comparisons of Insertion Sort:\n";
	cout<<"list 1: "<<insertionSort1<<endl;
	cout<<"list 2: "<<insertionSort2<<endl;
	cout<<"list 3: "<<insertionSort3<<endl;
	cout<<"Comparisons of Selection Sort:\n";
	cout<<"list 1: "<<selectionSort1<<endl;
	cout<<"list 2: "<<selectionSort2<<endl;
	cout<<"list 3: "<<selectionSort3<<endl;
	cout<<"Comparisons of Quick Sort:\n";
	cout<<"list 1: "<<quick1<<endl;
	cout<<"list 2: "<<quick1<<endl;
	cout<<"list 3: "<<quick1<<endl;
	cout<<"Comparisons of Merge Sort:\n";
	cout<<"list 1: "<<merge1<<endl;
	cout<<"list 2: "<<merge1<<endl;
	cout<<"list 3: "<<merge1<<endl;


	cout<<"Time of Bubber Sort:\n";
	cout<<"list 1: "<<time1<<endl;
	cout<<"list 2: "<<time2<<endl;
	cout<<"list 3: "<<time3<<endl;
	cout<<"Time of Insertion Sort:\n";
	cout<<"list 1: "<<time4<<endl;
	cout<<"list 2: "<<time5<<endl;
	cout<<"list 3: "<<time6<<endl;
	cout<<"Time of Selection Sort:\n";
	cout<<"list 1: "<<time7<<endl;
	cout<<"list 2: "<<time8<<endl;
	cout<<"list 3: "<<time9<<endl;
	cout<<"Time of Quick Sort:\n";
	cout<<"list 1: "<<time10<<endl;
	cout<<"list 2: "<<time11<<endl;
	cout<<"list 3: "<<time12<<endl;
	cout<<"Time of Merge Sort:\n";
	cout<<"list 1: "<<time13<<endl;
	cout<<"list 2: "<<time14<<endl;
	cout<<"list 3: "<<time15<<endl;
	
	return 0;

}
