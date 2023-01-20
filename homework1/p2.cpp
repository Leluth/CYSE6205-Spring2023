/*----------------------------------------------------------------
Copyleft (c) 2023 Author: Jagadeesh Vasudevamurthy
file: p2.cpp
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has p2 class definition
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
YOU CANNOT INCLUDE ANY OTHER FILES
-----------------------------------------------------------------*/
#include "p2.h"

/*----------------------------------------------------------------
WRITE CODE BELOW
-----------------------------------------------------------------*/

int get_cols(int num){
    return num + num - 1;
}

void draw_chars_line(char ch, int num){
    for(int i = 0; i < num; i++){
        cout << ch;
    } 
}

void draw_begin_line(int num){
    draw_chars_line('-', 20);
    cout << " n = " << num << endl;
}

void draw_cols_header(int cols) {
    for(int i = 0; i < cols; i++){
        cout << i;
    }
    cout << endl;
}

void draw_conclussion(int num, int sum){
    cout << "N = " << num << " Number of * = " << sum << endl;
}

int p2::d1(int num, char ch){
    int cols = get_cols(num);
    int sum = 0;
    draw_begin_line(num);
    draw_cols_header(cols);
    for(int i = 1; i <= num; i++){
        sum += i;
        int chars = get_cols(i);
        int spaces = cols - chars;
        draw_chars_line(' ', spaces / 2);
        for(int i = 0; i < chars; i++){
            if(i & 1) {
                cout << ' ';
            } else {
                cout << '*';
            }
        }
        draw_chars_line(' ', spaces / 2);
        cout << endl;
    }
    draw_conclussion(num, sum);
    return sum;
}

int p2::d2(int num, char ch){
    int cols = get_cols(num);
    int sum = 0;
    draw_begin_line(num);
    draw_cols_header(cols);
    for(int i = num; i >= 1; i--){
        sum += i;
        int chars = get_cols(i);
        int spaces = cols - chars;
        draw_chars_line(' ', spaces / 2);
        for(int i = 0; i < chars; i++){
            if(i & 1) {
                cout << ' ';
            } else {
                cout << '*';
            }
        }
        draw_chars_line(' ', spaces / 2);
        cout << endl;
    }
    draw_conclussion(num, sum);
    return sum;
}

int p2::d3(int num, char ch){
    int cols = num;
    draw_begin_line(num);
    draw_cols_header(cols);
    for(int i = 0; i < num; i++){
        int left = abs(num / 2 - i);
        int right = cols - 1 - left;
        for(int j = 0; j < num; j++){
            if(j == left || j == right)
                cout << '*';
            else
                cout << ' ';
        }
        cout << endl;
    }
    int sum = num == 1? 1: num * 2 - 2;
    draw_conclussion(num, sum);
    return sum;
}

int p2::d4(int num, char ch){
    int cols = num;
    int rows = num + num - 1;
    int sum = 0;
    draw_begin_line(num);
    draw_cols_header(cols);
    for(int i = 1; i <= rows; i++){
        int chars = i <= num? i: num + num - i;
        sum += chars;
        draw_chars_line('*', chars);
        cout << endl;
    }
    draw_conclussion(num, sum);
    return sum;
}

int p2::d5(int num, char ch){
    int cols = num;
    int rows = num + num - 1;
    int sum = 0;
    draw_begin_line(num);
    draw_cols_header(cols);
    for(int i = 1; i <= rows; i++){
        int chars = i <= num? i: num + num - i;
        sum += chars;
        draw_chars_line(' ', cols - chars);
        draw_chars_line('*', chars);
        cout << endl;
    }
    draw_conclussion(num, sum);
    return sum;
}

int p2::d6(int num, char ch){
    int cols = get_cols(num);
    int sum = 0;
    draw_begin_line(num);
    draw_cols_header(cols);
    for(int i = num; i >= 1; i--){
        sum += i;
        int chars = get_cols(i);
        int spaces = cols - chars;
        draw_chars_line(' ', spaces / 2);
        for(int i = 0; i < chars; i++){
            if(i & 1) {
                cout << ' ';
            } else {
                cout << '*';
            }
        }
        draw_chars_line(' ', spaces / 2);
        cout << endl;
    }
    for(int i = 1; i <= num; i++){
        sum += i;
        int chars = get_cols(i);
        int spaces = cols - chars;
        draw_chars_line(' ', spaces / 2);
        for(int i = 0; i < chars; i++){
            if(i & 1) {
                cout << ' ';
            } else {
                cout << '*';
            }
        }
        draw_chars_line(' ', spaces / 2);
        cout << endl;
    }
    draw_conclussion(num, sum);
    return sum;
}

void p2::riceOnChessBoard(int num){
    unsigned long long nsqrt = 1, sum = 0, unit = 1;
    for(int i = 1; i <= num; i++, nsqrt <<= 1){
        sum += nsqrt;
        cout << "Rice on Square " << i << " = " << nsqrt << endl;
    }
    cout << "Total Rice = " << sum << endl;
    cout << "Total Rice must be = 18446744073709551615" << endl;
}
//EOF
