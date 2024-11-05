//Базаров Алмазбек Султанбаевич
// КИ20-07б(1 подгруппа)
//сложность : 100%
//2 вариант
/*
Разработать программу, которая вводит строку символов, содержащую буквы латинского алфавита, арабские цифры, знаки препинания и пробелы и
выполняет действия из табл. 3. Если задание подразумевает изменение строки, то изменённая строка должна быть сформирована в памяти, а затем
выведена.
*/

#include <iostream>
#include <string>
using namespace std;

string SubString(string s) {
    string sub1, sub2, snew = "";
    bool x;
    for (int i = 0; i < s.size(); i++) {
        x = false;
        sub1 = s.substr(i, 1);
        if (sub1 == "a" || sub1 == "b" || sub1 == "c" || sub1 == "d" || sub1 == "e" || sub1 == "f" || sub1 == "g" || sub1 == "h" || sub1 == "i" || sub1 == "j" || sub1 == "k" || sub1 == "l" || sub1 == "m") {
            x = true;
            for (int j = 0; j < i; j++) {
                sub2 = s.substr(j, 1);
                if (sub1 == sub2) x = false;
            }

        }
        if (sub1 == "n" || sub1 == "o" || sub1 == "p" || sub1 == "q" || sub1 == "r" || sub1 == "s" || sub1 == "t" || sub1 == "u" || sub1 == "v" || sub1 == "w" || sub1 == "x" || sub1 == "y" || sub1 == "x") {
            x = true;
            for (int j = 0; j < i; j++) {
                sub2 = s.substr(j, 1);
                if (sub1 == sub2) x = false;
            }

        }
        if (sub1 == "A" || sub1 == "B" || sub1 == "C" || sub1 == "D" || sub1 == "E" || sub1 == "F" || sub1 == "G" || sub1 == "H" || sub1 == "I" || sub1 == "J" || sub1 == "K" || sub1 == "L" || sub1 == "M") {
            x = true;
            for (int j = 0; j < i; j++) {
                sub2 = s.substr(j, 1);
                if (sub1 == sub2) x = false;
            }

        }
        if (sub1 == "N" || sub1 == "O" || sub1 == "P" || sub1 == "Q" || sub1 == "R" || sub1 == "S" || sub1 == "T" || sub1 == "U" || sub1 == "V" || sub1 == "W" || sub1 == "X" || sub1 == "Y" || sub1 == "X") {
            x = true;
            for (int j = 0; j < i; j++) {
                sub2 = s.substr(j, 1);
                if (sub1 == sub2) x = false;
            }

        }
        if (x == true) snew = snew + sub1;
    }
    return snew;
};

int main()
{
    string s, snew;
    cout << "Enter string:";
    getline(cin, s);
    snew = SubString(s);
    cout << snew;
    return 0;
}