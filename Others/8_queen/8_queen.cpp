// 8皇后问题
/*
 let solution_number = ref 0;;

 let solutions n =
 let show board =
 incr solution_number; (* 增加解决方案编号 *)
 Printf.printf "Solution #%d:\n" !solution_number;
 let pr v =
 for i = 1 to n do
 print_string (if i=v then " q" else " _");
 done;
 print_newline() in
 List.iter pr board;
 print_newline() in

 let rec safe i j k = function
 | [] ‐> true
 | h::t ‐> h<>i && h<>j && h<>k && safe i (j+1) (k‐1) t in

 let rec loop col p =
 for i = 1 to n
 do
 if safe i (i+1) (i‐1) p then
 let p' = i::p in
 if col = n then show p'
 else loop (col+1) p'
 done in

 loop 1 [] in

 let n =
 if Array.length Sys.argv > 1
 then int_of_string Sys.argv.(1)
 else 8 in
 solutions n
*/
#include <iostream>
#include <vector>

using namespace std;

// 完全照搬的写法：

int count = 0;

void show(vector<int> *board) {
    count++;
    cout << "解法" << count << ":" << endl;
    int n = board->size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j == (*board)[i]) {
                cout << "Q ";
            } else {
                cout << "_ ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

bool safe(int i, int j, int k, std::vector<int> board) {
    if (board.size() == 0) {
        return true;
    } else {
        std::vector<int> b_ = board;
        b_.erase(b_.begin());
        return (i != board[0] && j != board[0] && k != board[0] && safe(i, j + 1, k - 1, b_));
        /*与第一相邻的一列相比，是否处在平行、上一或下一的位置
        如果没有，则判断与第二相邻的一列是否处在平行、上二或下二的位置
        以此类推，直到没有判断完所有列*/
    }
}

void loop(int n, int col, std::vector<int> board) {
    for (int i = 0; i < n; i++) {
        if (safe(i, i + 1, i - 1, board)) {
            vector<int> b_ = board;
            b_.insert(b_.begin(), i);
            if (col == n - 1) {
                show(&b_);
            } else {
                loop(n, col + 1, b_);
            }
        }
    }
}

// 不完全照搬，只是借鉴算法

vector<int> b = {-10, -10, -10, -10, -10, -10, -10, -10};

void rec(int n) {
    if (n == 8) {
        show(&b);
        return;
    }
    for (int j = 0; j < 8; j++) {
        b[n] = j;
        bool safe = true;
        for (int k = n - 1; k >= 0; k--) {
            int d = n - k;
            if (j != b[k] && (j + d) != b[k] && (j - d) != b[k]) {

            } else {
                safe = false;
                break;
            }
        }
        if (safe) {
            rec(n + 1);
            b[n] = -10;
        } else {
            b[n] = -10;
        }
    }
}

int main() {
#ifdef _WIN32
    system("chcp 65001");
#endif
    int n = 8;
    loop(n, 0, {});
    system("pause");

    count = 0;
    rec(0);
    system("pause");
    return 0;
}