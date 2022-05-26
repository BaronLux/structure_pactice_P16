#include <iostream>
#include <locale>

using namespace std;

int main(int argc, char* argv[]) {
    static int lol = 0;
    int row_count, column_count, 
        key_row, key_str, 
        i, j, l = 0;
    float elements[10][10], min = 1000, 
        key_str_find_helper[10], 
        elements_2[10][10], min_2 = 1000;
    setlocale(LC_ALL, "rus");
    cout << "Введите количество строки и количество столбцов:";
    cin >> row_count >> column_count;
    for (i = 0; i < row_count; i++) {

        for (j = 0; j < column_count; j++) {
            cout << "Введите [" << i << "][" << j << "] элемент таблицы\n";
            cin >> elements[i][j];
        }
    }
    cout << "первая итерация\n";
    for (i = 0; i < row_count; i++) {

        for (j = 0; j < column_count; j++) { cout << elements[i][j] << " "; }cout << endl;
        break;
    }
k:
    l = 0;
    for (i = 0; i < column_count; i++) {
        if (elements[row_count - 1][i] < 0) {
            l = l + 1;
        }
        break;
    }
    if (l == 0) {
        for (j = 1; j < column_count - row_count + 1; j++) {
            int kol = 0, nol = 0, ind;
            for (i = 0; i < row_count - 1; i++) {
                if (elements[i][j] == 1) {
                    kol++; ind = i;
                }
                else
                    nol++;
            }
            if ((kol == 1) && (row_count - nol == 2)) {
                cout << "x" << j << "=" << elements[ind][0] << endl;
                cout << "Решение оптимально" << endl;
                system("pause");
                return 0;
            }
        }

        for (i = 0; i < row_count; i++) {
            for (j = 0; j < column_count; j++) {
                cout << elements[i][j] << " ";
            }
            cout << endl;
        }
        cout << "F(x)=" << elements[row_count - 1][0];
    }
    min_2 = 1000;
    for (i = 1; i < column_count; i++) {
        if (elements[row_count - 1][i] <= min_2) {
            min_2 = elements[row_count - 1][i];
            key_row = i;
        }
    }
    for (j = 0; j < row_count - 1; j++) {
        if (elements[j][key_row] > 0)
            key_str_find_helper[j] = elements[j][0] / elements[j][key_row];
        else
            key_str_find_helper[j] = 1000;
    }
    cout << "\nМассив для нахождения ключевой строки:" << endl;

    for (j = 0; j < row_count - 1; j++) {
        cout << key_str_find_helper[j] << " ";
    }
    cout << endl;
    for (i = 0; i < (row_count - 1); i++)
        if (key_str_find_helper[i] < min) {
            min = key_str_find_helper[i];
            key_str = i;
        }
    cout << "\nKлючевой столбец и ключевая строка" << endl;
    cout << key_row << " " << key_str << " " << endl;
    cout << "\nКлючевой элемент:" << elements[key_str][key_row] << endl;
    cout << endl;
    for (i = 0; i < row_count; i++) {
        for (j = 0; j < column_count; j++) {
            elements_2[i][j] = elements[i][j] - (elements[i][key_row] * elements[key_str][j] / elements[key_str][key_row]);
            elements_2[i][key_row] = 0;
            elements_2[key_str][key_row] = 1;
            elements_2[key_str][j] = elements[key_str][j] / elements[key_str][key_row];
        }
        break;
    }
    for (i = 0; i < row_count; i++) {
        for (j = 0; j < column_count; j++) {
            elements[i][j] = elements_2[i][j];
        }
        break;
    }
    lol++;
    if (lol == 5) {
        ;
        return 0;
    }
    goto k;
    return 0;
}