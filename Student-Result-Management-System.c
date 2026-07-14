
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
    int roll;
    char name[50];
    float marks;
} student;

// -------- Merge Sort --------
void merge(student arr[], int l, int m, int r) {
    int i, j, k;
    int n1, n2;

    n1 = m - l + 1;
    n2 = r - m;

    student L[n1], R[n2];

    for(i = 0; i < n1; i++)
        L[i] = arr[l + i];

    for(j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;

    while(i < n1 && j < n2) {
        if(L[i].marks <= R[j].marks)
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while(i < n1)
        arr[k++] = L[i++];

    while(j < n2)
        arr[k++] = R[j++];
}

void mergeSort(student arr[], int l, int r) {
    int m;

    if(l < r) {
        m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// -------- Binary Search --------
int binarySearch(student arr[], int n, int key) {
    int low, high, mid;

    low = 0;
    high = n - 1;

    while(low <= high) {
        mid = (low + high) / 2;

        if(arr[mid].roll == key)
            return mid;
        else if(arr[mid].roll < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

// -------- Sort by Roll --------
void sortByRoll(student arr[], int n) {
    int i, j;
    student temp;

    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            if(arr[i].roll > arr[j].roll) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// -------- Main --------
int main() {
    int n, i, key, index;
    student *s;

    printf("Enter number of students: ");
    scanf("%d", &n);

    s = (student*)malloc(n * sizeof(student));

    for(i = 0; i < n; i++) {
        printf("\nEnter Roll, Name, Marks: ");
        scanf("%d %s %f", &s[i].roll, s[i].name, &s[i].marks);
    }

    // Sort by marks
    mergeSort(s, 0, n - 1);

    printf("\n--- Sorted by Marks ---\n");
    for(i = 0; i < n; i++) {
        printf("Roll: %d Name: %s Marks: %.2f\n",
               s[i].roll, s[i].name, s[i].marks);
    }

    // Highest & Lowest
    printf("\nLowest Scorer: %s (%.2f)\n", s[0].name, s[0].marks);
    printf("Highest Scorer: %s (%.2f)\n", s[n-1].name, s[n-1].marks);

    // Sort by roll for binary search
    sortByRoll(s, n);

    printf("\nEnter roll number to search: ");
    scanf("%d", &key);

    index = binarySearch(s, n, key);

    if(index != -1)
        printf("Found: %s (%.2f)\n", s[index].name, s[index].marks);
    else
        printf("Student not found\n");

    free(s);
    return 0;
}
