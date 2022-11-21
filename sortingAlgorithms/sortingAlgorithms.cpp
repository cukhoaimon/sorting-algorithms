#include "./sorting-method/all.h"
#include "./controller/base.h"


typedef void (*sortPtr)(int*, int);
sortPtr sortMethod[] = {
    HeapSort,
    InsertionSort
};

int main()
{
    int arr[3000] = {0};
    int n = 3000;

    // case Heapsort - index = 0
    int sortIdx = 0;

    Timer t;
    t.start();
    sortMethod[sortIdx](arr, n);
    auto duration = t.duration();

    return 6969;
}
