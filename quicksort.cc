#include <iostream>
#include <vector>
#include "tools.h"

using namespace std;

void quicksort(vector<int> *A, int p, int r);
int partition(vector<int> *A, int p, int r);

int main(int argc, char *argv[])
{
    vector<int> A;
    getArgv(argc, argv, &A);
    quicksort(&A, 0, A.size() - 1);
    echo(&A);
    return 0;
}

void quicksort(vector<int> *A, int p, int r)
{
    if (p < r)
    {
        int q = partition(A, p, r);
        quicksort(A, p, q - 1);
        quicksort(A, q + 1, r);
    }
}

int partition(vector<int> *A, int p, int r)
{
    int x = (*A)[p];
    int i = p;
    int tmp;
    for (int j = p + 1; j <= r; j++)
    {
        cout << (*A)[j] << endl;
        if ((*A)[j] <= x)
        {
            ++i;
            tmp = (*A)[i];
            (*A)[i] = (*A)[j];
            (*A)[j] = tmp;
        }
    }
    tmp = (*A)[i];
    (*A)[i] = (*A)[p];
    (*A)[p] = tmp;
    return i;
}
