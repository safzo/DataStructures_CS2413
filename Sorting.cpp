#include <iostream>
using namespace std;

// SINGLETON LIST means LOW = HIGH

void print_arr(int *arr, int size){
    cout << "{" << arr[0] ;
    for (int i = 1; i < size; i++){
        cout << ", " << arr[i];
    }
    cout << " }" << endl;
}

void selection_sort(int *arr, int size){
    int min, temp;
    for(int i = 0; i < size - 1; i++){
        min = i;
        for (int j = i+1; j < size; j++){
            if (arr[j] < arr[min]){
                min = j;
            }
        }
        temp = arr[min];
        arr[min] = arr[i];
        arr[i]= temp;
    }
}

void bubble_sort(int *arr, int size) {
    int temp;
    for (int i = 0; i < size -1; i++){
        for (int j = 0; j < size -i; j++) {
            if (arr[j-1] > arr[j]) {
                temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
        }
    }
}

void insertion_sort (int* arr, int size){
    int min, temp;
    for (int i = 0; i < size -1; i++){
        min = i;
        for (int j = 0; j < size; j++){
            if (arr[j] < arr[min]){
                min = j;
            }
        }
        temp = arr[min];
        for (int j= min; j<i; j--){
            arr[j] = arr [j-1];
        }
        arr[i] = temp;
    }
}

void merge_sort(int *arr, int size){
    if (size > 1) {
        int lsize = size / 2;
        int *larr = new int[lsize];
        int *rarr = new int[size - lsize];
        for (int i = 0; i < lsize; i++) {
            larr[i] = arr[i];
        }
        for (int i = lsize; i < size; i++) {
            rarr[i - lsize] = arr[i];
        }
        merge_sort(larr, lsize);
        merge_sort(rarr, size - lsize);
        merge(arr, larr, rarr, size);
        delete larr;
        delete rarr;
    }
}

int main() {
    int arr[] = { 42, 68, 12, 2, 19, 100 };
    print_arr(arr, 6);

    selection_sort(arr, 6);
    print_arr(arr, 6);

    bubble_sort(arr, 6);
    print_arr(arr, 6);
    //system("pause"); for Microsoft Windows ONLY
    return 0;
}
