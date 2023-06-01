#include <iostream>
#include <cmath>
#include <iomanip> // для красивого выводав консоль с заданными отступами
#include <string>
#include <vector>

using namespace std;

string push(vector<int>& arr) { // преобразовать массив чисел в строку
    string res = "";
    for (int i : arr)
        res += to_string(i) + " ";
    return res;
}

// Динамическая реализация (работает для больших степеней)
int main() {
    int exp = 20; // нужная степень
    exp = max(2,exp); // проверяем, чтобы степень была не меньше 2

    vector<string> arr(exp+1); // массив для хранения всех строк
    vector<int> prev = {1}; // массив, хранящий текущий набор коэффициентов. При определении получил значения коэффициентов для 0 степени

    arr[0] =  push(prev); // вставляем строку с коэффициентами для 0 степени в массив с ответами
    prev.push_back(1); // добавляем недостающий коэффициент для первой степени
    arr[1] = push(prev); // вставляем коэффициенты для 1 степени в массив с ответами 

    for (int e = 1; e <= exp; e++) { // заполняем массив с ответами по принципу построения треугольника (сложения соседних членов строки сверху, для получения члена снизу)
        const int len = prev.size()+1; // исходная длина динамического массива
        int temp = 1; // временная переменная, которая будет хранить предыдущее значение
        
        for (int i = 1; i < len; i++) { // обоновляем значения в строке и добавляем 1 в конце
            if (i == len-1) prev.push_back(1);
            else {
                int temp2 = prev[i];
                prev[i] = prev[i] + temp;
                temp = temp2;
            }
        }
        
        arr[e] = push(prev); // добавляем новую строку в массив с ответами
    }

    // выводим ответы в виде пирамиды
    int c = floor(arr[exp].size() / 2); // центр самой длинной строки, для центрирования пирамиды

    for (int s = 0; s <= exp; s++) {
        int lc = c + floor(arr[s].length() / 2); // центр текущей строки 
        
        cout << setw(to_string(exp).length()) 
             << s 
             << ") " 
             << setw(lc + 2) 
             << arr[s] 
             << endl; // вывод строк 
    }

    return 0;
}

// версия с использованием формулы (работает только до 20 степени)

// unsigned long long factorial(int n) {
//     unsigned long long res = 1;
//     while (n) {
//         res *= n;
//         n--;
//     }

//     return res;
// }

// unsigned long long factorialfromto(int from, int to) {
//     if (from <= 0 || to <= 0) return 1;
//     std::cout << from << " " << to << endl;
//     unsigned long long res = 1;
//     while (from <= to) {
//         res *= from;
//         from++;
//     }

//     return res;
// }

// unsigned long long binom(int n, int k) {
//     // return factorial(n) / (factorial(k) * factorial(n-k));
//     return factorialfromto(k+1, n) / (factorial(n-k));
// }

// int shit() {
//     const int amount = 20; // количество степеней (До 20 включительно)
//     string res [amount+1]; // массив для хранения рядов

//     for (int n = amount; n >= 0; n--) {
//         res[n] = "";
//         for (int k = 0; k <= n; k++) {
//             res[n] +=  to_string(binom(n, k)) + " "; // в каждую ячейку массива добавляем ряд в виде строки
//         }
//     }

//     int c = floor(res[amount].length() / 2); // центр самой длинной строки, для центрирования пирамиды

//     for (int s = 0; s <= amount; s++) {
//         int lc = c + floor(res[s].length() / 2); // центр текущей строки 
//         cout << setw(to_string(amount).length()) 
//              << s 
//              << ")" 
//              << setw(lc + 1) 
//              << res[s] 
//              << endl; // вывод строк 
//     }

//     return 0;
// }
