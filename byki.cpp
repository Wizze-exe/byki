#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>

using namespace std;

//Функция генерации неповторяющихся цифр
vector<int> initialDigits();

//Функция ввода пользователем цифр
vector<int> getUserNumber();

//Функция проверки количества быков и коров
vector<int> checkBullsAndCows(vector<int> vec1, vector<int> vec2);

//Печать значений
void printVector(vector<int> vec);

int main()
{
    NewGame:
    vector<int> bullsAndCows; //Массив для записи количества быков и коров
    vector<int> sequence_nums; //Для генерации цифра
    vector<int> sequence_user; //Пользовательские догадки
    char repeatGame;
    
    sequence_nums = initialDigits();
    while(true){
        sequence_user = getUserNumber();
        
        bullsAndCows = checkBullsAndCows(sequence_nums, sequence_user);
        if (bullsAndCows[0] == 4)
            break;
            
        cout << "быки: " << bullsAndCows[0] << "\nКоровы: " << bullsAndCows[1] << "\n" << endl;
    }
    
    cout << "Загаданная последовательность: " << endl;
    printVector(sequence_nums);
    
    while(true){
        cout << "Хотите сыграть ещё раз? (y/n): ";
        cin >> repeatGame;
    
        if (repeatGame == 'y')
            goto NewGame;
        else if (repeatGame == 'n'){
            cout << "\nЛадно";
            break;
        }
        else 
            cout << "\nВведено неверное значение" << endl;
    }
    
    return 0;
}

vector<int> initialDigits(){
    srand(time(0));
    
    vector<int> seq;
    for (int i = 0; i < 10; i++){
        seq.push_back(i);
    }
    
    vector<int> ret;
    for (int i = 0; i < 4; i++){
        int position = rand() % seq.size(); //рандомная позиция элемента
        
        ret.push_back(seq[position]);
        seq.erase(seq.begin() + position);
    }
    
    return ret;
}

vector<int> getUserNumber(){
    int userNum;
    vector<int> ret;
    
    while(true){
        cout << "Введите четырёхзначное число: " << endl;
        cin >> userNum;
        if (userNum <= 9876 && userNum >= 1023){
            break;
        }
    }
    
    while(userNum > 0){
        ret.push_back(userNum % 10);
        userNum /= 10;
    }
    reverse(ret.begin(), ret.end());
    
    return ret;
}

vector<int> checkBullsAndCows(vector<int> vec1, vector<int> vec2){
    vector<int> ret(2); //0 - быки, 1 - коровы
    
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            if (vec1[i] == vec2[j]){
                if (i == j)
                    ret[0] += 1;
                else
                    ret[1] += 1;
                    
                break;
            }
        }
    }
    
    return ret;
}

void printVector(vector<int> vec){
    vector<int>::iterator cur;
    for (cur = vec.begin(); cur < vec.end(); cur++)
        cout << *cur;
    cout << "\n" << endl;
}
