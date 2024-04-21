#include <cstring>
#include <iostream>
using namespace std;

bool notSpace(char ch) {
    bool flag = isalnum(ch) || (ch == '\'') || (ch == '-');
    return flag;
}

int main() {
    char text[220]{0};
    cin.getline(text, 220);
    char result[100][100] = {0};
    char signs[100][10] = {0};

    int r_i = 0;

    for (int i = 0; text[i] != '\0'; ++i) {
        int j = 0;
        while (notSpace(text[i])) {
            result[r_i][j] = text[i];
            ++j;
            ++i;
        }
        result[r_i][j] = '\0';
        j = 0;
        while (!notSpace(text[i])) {
            if (text[i] == '\0') {
                break;
            }
            signs[r_i][j] = text[i];
            ++j;
            ++i;
        }
        if (text[i] != '\0') {
            --i;
        }
        signs[r_i][j] = '\0';
        if (r_i != 0 && strcmp(result[r_i], result[r_i - 1]) == 0) {
            strcpy(signs[r_i - 1], signs[r_i]);
            --r_i;
        }
        ++r_i;
    }
    for (int i = 0; i < r_i; ++i) {
        cout << result[i] << signs[i];
    }
    system("pause");
    return 0;
}