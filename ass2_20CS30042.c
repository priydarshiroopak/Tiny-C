/*
  Name - Roopak Priydarshi
  Roll No. - 20CS30042
  Assignment 2
*/
// including required library(ies)
#include "myl.h"
// define macros
#define BUFFSIZE 33
#define INT_MAX __INT32_MAX__
#define INT_MIN (-INT_MAX -1)
#define PRECISION_DIG 6
// function to print a string of characters (terminated by '\0')
// returns number of characters printed
int printStr(char *st) {
    int bytes=0;
    while(st[bytes] != '\0') bytes++;   // find the length of the string 
    __asm__ __volatile__ (
        "movl $1, %%eax \n\t"
        "movq $1, %%rdi \n\t"
        "syscall \n\t"
        :
        :"S"(st), "d"(bytes)
    );
    return bytes;                       // return the (printed) length
}
// function to read signed integer in_buff '%d' format
// returns OK (for success) or ERR (on failure)
int readInt(int* n) {
    char in_buff[BUFFSIZE];
    int len, isPos = 1, i=0, d;
    long num = 0;
    __asm__ __volatile__ (
        "movq $0, %%rax \n\t"
        "movq $0, %%rdi \n\t"
        "syscall \n\t"
        : "=a"(len)
        : "S"(in_buff), "d"(BUFFSIZE)
    );
    if(len < 0) return ERR;
    if(i < len) {                       // store sign of number
        if(in_buff[i] == '+') i++;
        else if(in_buff[i] == '-') {
            isPos = -1;
            i++;
        }
    }
    while(i < len && in_buff[i] != '\n' && in_buff[i] != ' ') {
        if(in_buff[i] > '9' || in_buff[i] < '0') return ERR;
        d = (int)(in_buff[i]-'0');      // consider digit(s)
        num *= 10;
        num += (isPos * d);
        if(num > INT_MAX || num < INT_MIN) return ERR;
        i++;
    }
    *n = num;
    return OK;
}
// function to print integer value 'n'
// returns number of characters printed
int printInt(int n) {
    char out_buff[BUFFSIZE], tmp;
    int len = 0, i, j;
    long ni = n;
    if(n == 0) out_buff[len++]='0';
    else {
        if(ni<0) {
            ni=-ni;
            out_buff[len++]='-';
        }
        while(ni) {
            out_buff[len++]=ni%10+'0';    // convert digit to character
            ni/=10;
        }
    }
    i = (out_buff[0]=='-');
    j = len-1;
    while(i<j) {                    // reversing the (absolute) number
        tmp = out_buff[i];
        out_buff[i++] = out_buff[j];
        out_buff[j--] = tmp;
    }
    __asm__ __volatile__(
        "movq $1, %%rax \n\t"
        "movq $1, %%rdi \n\t"
        "syscall \n\t"
        :
        : "S"(out_buff), "d"(len)
    );
    return len;                     // return length of (printed) string
}
// function to read floating point values (in_buff %f format) from input
// returns OK (for success) or ERR (on failure)
int readFlt(float *f) {
    char in_buff[BUFFSIZE];
    int len;
    __asm__ __volatile__ (
        "movl $0, %%eax \n\t" 
        "movq $0, %%rdi \n\t"
        "syscall \n\t"
        : "=a"(len)
        :"S"(in_buff), "d"(BUFFSIZE));
    if(len < 0)
        return ERR;
    int isPos = 1, i = 0, d;
    double flt = 0, mul=1, df;
    if(i < len) {                           // read sign
        if(in_buff[i] == '+') i++;
        else if(in_buff[i] == '-') {
            isPos = -1;
            i++;
        }
    }
    while(i < len && in_buff[i] != '\n' && in_buff[i] != '.') {
        if(in_buff[i] > '9' || in_buff[i] < '0') return ERR;
        d = (int)(in_buff[i] - '0');        // consider digits till decimal point
        flt *= 10;
        flt += d;
        i++;
    }
    if(i < len && in_buff[i] == '.') {
        i++;
        while(i < len && in_buff[i] != '\n') {
            if(in_buff[i] > '9' || in_buff[i] < '0') return ERR;
            df = (int)(in_buff[i] - '0');    // consider digits after decimal point
            mul /= 10;
            df *= mul;
            flt += df;
            i++;
        }
    }
    *f = isPos * flt;                       // change signed value
    return OK;
}
// function to print floating point value 'f'
// returns number of characters printed
int printFlt(float f) {
    char tmp, out_buff[BUFFSIZE];
    int len = 0, i, j, integer_num, frac_num, t;
    if (f < 0) {                            // insert sign to stream
        out_buff[len++] = '-';
        f = -f;                             // consider absoute value
    }
    integer_num = (int)f;
    f -= integer_num;
    while (integer_num) {                   // consider the integral part
        out_buff[len++] = (char)('0' + (integer_num % 10));
        integer_num /= 10;
    }
    if (!len || out_buff[len - 1] == '-') out_buff[len++] = '0';
    i = (out_buff[0] == '-');
    j = len - 1;
    while (i < j) {                         // reverse the (absolute) integral part
        tmp = out_buff[i];
        out_buff[i++] = out_buff[j];
        out_buff[j--] = tmp;
    }
    out_buff[len++] = '.';                  // insert decimal point
    for (int i = 0; i < PRECISION_DIG; i++) f *= 10;
    frac_num = (int)f;
    t = len;                                // store number of integer digits
    for(int ctr=0; ctr<PRECISION_DIG; ctr++) {                      // consider decimals upto PRECISION_DIG digits
        out_buff[len++] = (char)('0' + (frac_num % 10));
        frac_num /= 10;
    }
    i = t;
    j = len - 1;
    while (i < j) {                         // reverse the (absoute) decimal value
        tmp = out_buff[i];
        out_buff[i++] = out_buff[j];
        out_buff[j--] = tmp;
    }
    while(out_buff[len-1] == '0') len--;    // ommit ending decimal zeroes from output
    __asm__ __volatile__(
        "movl $1, %%eax \n\t"
        "movq $1, %%rdi \n\t"
        "syscall \n\t"
        :
        : "S"(out_buff), "d"(len)
    );
    return len;                             // returns number of printed characters
}