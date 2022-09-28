#include <iostream>
#include <time.h>

using namespace std;

int* randNum();
bool numMatch(int* array);

int main()
{
    

    return 0;
}

int* randNum() {
    ifNumDontFit:
    srand(time(0));
    int* array = new int[4];
    for (int i = 0; i < sizeof(array); i++){
        array[i] = rand() % 9;
        
        for (int j = 0; j <= i; j++){
            if (array[i] == array[j]){
                goto ifNumDontFit;
            }
        }
    }
    return array;
}

bool numMatch(int* array){
    int userNum;
    int* userArray = new int[4];
    
    cout << "Введите число: ";
    cin >> userNum;
    
    while(true){
        userArray.insert(userArray.begin(), userNum % 10);
        userNum /= 10;
    }
    
    
}
