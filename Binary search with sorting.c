#include <stdio.h>
void sortArray(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int binarySearch(int arr[], int size, int key) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int middle = left + (right - left) / 2;

        if (arr[middle] == key)
            return middle;
        else if (arr[middle] < key)
            left = middle + 1;
        else
            right = middle - 1;
    }
    return -1;
}
int main() {
    int size;
    printf("Enter number of elements: ");
    scanf("%d", &size);
    int numbers[size];
    printf("Enter %d numbers: ", size);
    for (int i = 0; i < size; i++)
        scanf("%d", &numbers[i]);
    sortArray(numbers, size);
    printf("Sorted array: ");
    for (int i = 0; i < size; i++)
        printf("%d ", numbers[i]);
    printf("\n");
    int searchNumber;
    printf("Enter number to search: ");
    scanf("%d", &searchNumber);
    int position = binarySearch(numbers, size, searchNumber);
    if (position != -1)
        printf("Number found at index %d\n", position);
    else
        printf("Number not found\n");
    return 0;
}
