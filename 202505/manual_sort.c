#include<stdio.h>
void swap(int *a, int *b) {//注意要传入指针，传入变量没用
	int temp = *a;
	*a = *b;
	*b = temp;
}


/*********************简单排序*********************/
void bubble_sort(int arr[], int n) {//冒泡排序：每轮都从前往后依次比较相邻的两个，逆序就交换
	int swapped;
	do {//dowhile循环判断是否有序，while(有序了)就不do了
		swapped = 0;
		for (int j = 0; j < n - 1; j++) {  // 只需要一层循环
			if (arr[j] > arr[j + 1]) {
				swap(&arr[j], &arr[j + 1]);
				swapped = 1;
			}
		}
	} while (swapped);
}
//void bubble_sort(int arr[],int n){//冒泡排序：已经有序了也还要排
//	for(int i = 1; i < n; i++){
//		for(int j = 0; j < n - i; j++){
//			if(arr[j]>arr[j+1])swap(&arr[j],&arr[j+1]);
//		}
//	}
//}
void insertion_sort(int arr[], int n) {//插入排序：从无序中选第一个，插入有序中对应位置。序列基本有序时效率较高
	for (int i = 1; i < n; i++) {
		int temp = arr[i];   // 保存当前要插入的元素
		int j = i - 1;
		// 将比 temp 大的元素向后移动一位
		while (j >= 0 && arr[j] > temp) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = temp; // 把 temp 插入到正确位置
	}
}
void selection_sort(int arr[],int n){//选择排序：从无序中选最小的，和无序中首位交换
	for(int i = 0; i < n; i++){
		int min = arr[i];
		int key = i;
		for(int j = i; j < n; j++){
			if(arr[j] < min){
				min = arr[j];
				key = j;
			}
		}
		swap(&arr[key],&arr[i]);
	}
}


/*********************改进排序*********************/
void insertion_sort_with_gap(int arr[], int n,int gap) {//插入排序：从无序中选第一个，插入有序中对应位置。序列基本有序时效率较高
	for (int i = gap; i < n; i++) {
		int temp = arr[i];   // 保存当前要插入的元素
		int j = i - gap;
		// 将比 temp 大的元素向后移动gap位
		while (j >= 0 && arr[j] > temp) {
			arr[j + gap] = arr[j];
			j-=gap;
		}
		arr[j + gap] = temp; // 把 temp 插入到正确位置
	}
}
void shell_sort(int arr[], int n) {
	for (int gap = n / 2; gap > 0; gap /= 2) {
		insertion_sort_with_gap(arr, n, gap);
	}
}
void print_arr(int arr[],int n){
	for(int i = 0; i < n; i++){
		printf("%d ",arr[i]);
	}
}
int arr[200005];
int main(){
	int n;
	scanf("%d",&n);
	for(int i = 0;i < n; i++){
		scanf("%d",&arr[i]);
	}
	shell_sort(arr,n);
//	swap(&arr[1],&arr[2]);
	print_arr(arr,n);
}

