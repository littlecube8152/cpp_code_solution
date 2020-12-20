#include <iostream>
#include <vector>
using namespace std;

long long int invert = 0;
int count;

void merge(vector<int> &array, int start, int mid, int end)
{
    vector<long long int> left(array.begin() + start, array.begin() + mid + 1),
        right(array.begin() + mid + 1, array.begin() + end + 1);
    long long int iLeft = 0, iRight = 0;
    left.insert(left.end(), 2000005);
    right.insert(right.end(), 2000005);

    for (long long int i = start; i <= end; i++)
    {
        if (left[iLeft] > right[iRight])
        {
            array[i] = right[iRight];
            iRight++;
            invert += (mid - start - iLeft + 1);
        }
        else
        {
            array[i] = left[iLeft];
            iLeft++;
        }
    }
}

void mergeSort(vector<int> &array,  long int start, long int end)
{

    if (start < end)
    {
        int mid = (start + end) / 2;
        mergeSort(array, start, mid);
        mergeSort(array, mid + 1, end);
        merge(array, start, mid, end);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> count;
    vector<int> array;
    array.resize(2000000 * sizeof( int));
    for (long int i = 0; i < count; i++)
        cin >> array[i];

    mergeSort(array, 0, count - 1);
    //prlong long int(array, count);
    cout << invert << '\n';
}