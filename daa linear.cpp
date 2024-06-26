 #include <stdio.h>

int linearSearch(int arr[], int size, int target) {
    int i;
    for (i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // return the index of the found element
        }
    }
    return -1; // return -1 if the element is not found
}

int main() {
    int arr[100]; // array to store integers
    int size; // size of the array
    int target; // target value to search for
    int result; // result of the search

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    printf("Enter %d integers: ", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the target value to search for: ");
    scanf("%d", &target);

    result = linearSearch(arr, size, target);

    if (result!= -1) {
        printf("Element %d found at index %d\n", target, result);
    } else {
        printf("Element %d not found in the array\n", target);
    }

    return 0;
}