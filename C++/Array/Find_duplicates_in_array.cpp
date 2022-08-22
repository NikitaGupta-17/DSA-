//only in the elements in array are from the range 0 to size-1
#include <iostream>
using namespace std;
 
int main()
{
    int arr_size;
    cout << "Enter the size of array : ";
    cin >> arr_size;
    int num[arr_size];
    cout << "Enter the elements of array : ";
    for(int i=0;i<arr_size;i++)
    {
        cin >> num[i];
    }
    // count the frequency
    for (int i = 0; i < arr_size; i++) {
        num[num[i] % arr_size]
            = num[num[i] % arr_size] + arr_size;
    }
    cout << "The repeating elements are : " << endl;
    for (int i = 0; i < arr_size; i++) {
        if (num[i] >= arr_size * 2) {
            cout << i << " ";
        }
    }
    return 0;
}
// for every possible case sort the array then calculate frequency of each element and whose frequency >1 is repeated