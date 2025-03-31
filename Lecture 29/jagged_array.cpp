#include <iostream>
using namespace std;

int main() {
    int rows = 3;
    int **jaggedArray = new int *[rows];

    jaggedArray[0] = new int[2]; 
    jaggedArray[1] = new int[4]; 
    jaggedArray[2] = new int[3];  

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < (i + 2); j++) 
        {  
            jaggedArray[i][j] = (i + 1) * (j + 1); 
            cout << jaggedArray[i][j] << " ";
        }
        cout << endl;
    }

   
    for (int i = 0; i < rows; i++) {
        delete[] jaggedArray[i];  
    }
    delete[] jaggedArray;  

    return 0;
}
