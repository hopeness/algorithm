#include <iostream>
#include <vector>

using namespace std;

void getArgv(int argc, char *argv[], vector<int> *A)
{
    while (--argc)
        A->push_back(atoi(*(++argv)));
}

void echo(vector<int> *A)
{
    for (vector<int>::const_iterator iter = A->begin(); iter != A->end(); ++iter)
        cout << *iter << " ";
    cout << endl;
}
