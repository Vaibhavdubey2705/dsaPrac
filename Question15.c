#include <stdio.h>
#include <stdlib.h>

int arr[10], size;

void getElements(){
    printf("Enter the elements:\n");
    int i;
    for( i=0; i<size; i++){
        printf("Enter element %d: ", i+1);
        scanf("%d", &arr[i]);
    }
}

void disp(int arr[10], int size){
    printf("\n");
    int i;
    for (i=0; i<size; i++)
        printf("%d\t", arr[i]);
}

void Insertion(){
	int i,j,temp;
	for(i=0;i<=size-1;i++)
	{
		j = i;
		while(j>0 && arr[j-1]>arr[j])
		{
			temp = arr[j];
			arr[j] = arr[j-1];
			arr[j-1] = temp;
			j--;
		}
	}
}



void merge(int l, int mid, int r){
    int i=l;
    int j=mid+1;
    int k=l;
    int temp [10];
    while(i<=mid && j<=r){
        if(arr[i] <= arr[j]){
            temp[k++] = arr[i++];
        }
        else
            temp[k++] = arr[j++];
    }
    if(i > mid)
        for(j; j<=r; j++)
            temp[k++] = arr[j];
    else
        for(i; i<=mid; i++)
            temp[k++] = arr[i];

    for(k=l; k<=r; k++)
        arr[k] = temp [k];
}

void mergeSort(int l, int r){
    if(l < r){
        int mid = (l+r)/2;
        mergeSort(l, mid);
        mergeSort(mid+1, r);
        merge(l, mid, r);
    }
}
void swap(int *a,int *b)
{
	int temp = *a;
	*a = *b;
	*b= temp;
}
int partition(int low,int high)
{
  int pivot=arr[high];
  int i=(low-1); 
  int j;
  for(j=low;j<=high;j++)
  {
    //If current element is smaller than the pivot
    if(arr[j]<pivot)
    {
      //Increment index of smaller element
      i++;
      swap(&arr[i],&arr[j]);
    }
  }
  swap(&arr[i+1],&arr[high]);
  return (i+1);
}        
void quickSort(int low,int high)
{
  if(low<high)
  {
    int pi=partition(low,high);
    quickSort(low,pi-1);
    quickSort(pi+1,high);
  }
}

void menu(){
    printf("\nMENU:\n\n");
    printf("1.Insertion Sort\n");
    printf("2.Merge Sort\n");
    printf("3.Quick Sort\n");
    printf("Enter your choice: ");
    int ch;
    scanf("%d", &ch);
    printf("\nUnSorted Array:");
    disp(arr, size);
    switch(ch){
        case 1: Insertion();
            break;
        case 2: mergeSort(0,size-1);
            break;
        case 3: quickSort(0,size-1);
            break;
        default : printf("\n\nWrong choice entered, retry: ");
            menu();
    }

    printf("\n\nSorted Array:");
    disp(arr, size);
}

void main(){
	char c;
	do{
    	printf("\nEnter size of the array: ");
    	scanf("%d", &size);
    	if( size <=1 && size >20){
        	printf("Invalid size entered");
        	return;
    	}
   		getElements();
    	menu();
    	printf("\n\nDo you want to continue? ");
    	scanf(" %c", &c);
	}while(c=='Y'||c=='y');
}
