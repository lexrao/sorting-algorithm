#include <stdio.h>

// Function prototypes
void selectionSort(int arr[], int n);
void bubbleSort(int arr[], int n);
void insertionSort(int arr[], int n);
void quickSort(int arr[], int low, int high);

// Utility function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to print an array
void printArray(int arr[], int n, FILE *fp) {
    for (int i = 0; i < n; i++)
        fprintf(fp, "%d ", arr[i]);
    fprintf(fp, "\n");
}

int main() {
    int choice;
    int arr[100];
    int n;

    FILE *input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    fscanf(input_file, "%d", &n);
    for (int i = 0; i < n; i++) {
        fscanf(input_file, "%d", &arr[i]);
    }
    fclose(input_file);

    printf("Choose sorting algorithm:\n");
    printf("1. Selection Sort\n");
    printf("2. Bubble Sort\n");
    printf("3. Insertion Sort\n");
    printf("4. Quick Sort\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Sorting using Selection Sort:\n");
            selectionSort(arr, n);
            break;
        case 2:
            printf("Sorting using Bubble Sort:\n");
            bubbleSort(arr, n);
            break;
        case 3:
            printf("Sorting using Insertion Sort:\n");
            insertionSort(arr, n);
            break;
        case 4:
            printf("Sorting using Quick Sort:\n");
            quickSort(arr, 0, n - 1);
            break;
        default:
            printf("Invalid choice\n");
    }

    FILE *output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }

    printf("Sorted array: \n");
    printArray(arr, n, output_file);
    fclose(output_file);
    return 0;
}

// Selection Sort
void selectionSort(int arr[], int n) {
    // implementation of selection sort
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(&arr[minIndex], &arr[i]);
    }
}

// Bubble Sort
void bubbleSort(int arr[], int n) {
    // implementation of bubble sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

// Insertion Sort
void insertionSort(int arr[], int n) {
    // implementation of insertion sort
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Quick Sort
void quickSort(int arr[], int low, int high) {
    // implementation of quick sort
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
