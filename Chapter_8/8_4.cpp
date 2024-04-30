// 实验八：函数
// 编一函数，功能为统计字符串中各个字母（不区分大、小写）出现的频率，同时找出频率出现最高的字母及次数，
// 假设出现次数最多的字母只有一个。函数形式为：
#include <cstring>
#include <iostream>

using namespace std;

void freq(char s[], int p[], char &chmax, int &max) {
    int n = strlen(s);
    for (int i = 0; i < n; i++) {
        if ('a' <= s[i] && s[i] <= 'z') {
            p[s[i] - 'a']++;
        }
        if ('A' <= s[i] && s[i] <= 'Z') {
            p[s[i] - 'A']++;
        }
    }
    chmax = s[0];
    max = 0;
    for (int i = 0; i < 26; i++) {
        if (p[i] > max) {
            max = p[i];
            chmax = 'a' + i;
        }
    }
}

int main() {
    char s[100];
    cin.getline(s, 100);
    char cmax;
    int max;
    int freqs[26] = {};
    freq(s, freqs, cmax, max);
    for(int i = 0; i < 26; i++) {
        cout << (char)('a' + i) << "----" << freqs[i] << endl;
    }
    cout << "max: " << cmax << "----" << max << endl;
    system("pause");
    return 0;
}