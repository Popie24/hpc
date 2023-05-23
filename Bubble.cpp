#include <iostream>

#include <omp.h>
using namespace std;

int main()
{
    int temp, value;
    cout << "Enter Size of Array: ";
    cin >> value;
    int array[value];

    for (int i = 0; i < value; i++)
    {

        cin >> temp;
        array[i] = temp;
    }

    cout << "\nArray: \n";
    for (int i = 0; i < value; i++)
    {

        cout << array[i] << " ";
    }
    
    // Bubble Sorting
    int i,j;
    for( i=0; i<value; i++){
    
    #pragma omp parallel for shared(j,array)
        for( j=0; j<value-1; j++){
        
            if(array[j] > array[j+1]){
            
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
                
            }
        
        }
    
    }
    
    cout << "\nSorted Array: \n";
    for (int i = 0; i < value; i++)
    {

        cout << array[i] << " ";
    }
    
    

    return 0;
}
