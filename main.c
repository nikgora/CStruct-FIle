#include <string.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define N 100

void print_znachenie(char str[N]);//вывод строки в прямом порядке принимает строку

void print_reverse_znachenie(char str[N]);//вывод строки в обратном порядке принимает строку

void reverse_znachenie(char str[N]);//инвертирование строки принимает строку результат строка

void scanword_znachenie(char word[N]);//ввод строки  принимает строку в которую надо записать строку результат строка

void skipspace_znachenie(
        char word[N]);//пропуск серии пробелов принимает строку которую надо отфарматировать результат отфаромотированая строка


int main()
{
    char symbol;
    char sent[N]="";
    int i = 1,j=0;
    do {
        char word[N] = "";
        _Bool q = 0;
        scanword_znachenie(word);
        symbol = word[strlen(word) - 1];
        if (symbol == '.') {
            q = 1;
        }
        if (symbol==' ' && strlen(word)==1) i--;
        word[strlen(word) - 1] = '\0';

        if (i % 2 ) {
            i++;
            for (int k = 0; k < strlen(word); ++k) {
                sent[j]=word[k];
                ++j;
            }
        } else {
            i++;
            for (int k = 0; k < strlen(word); ++k) {
                reverse_znachenie(word);
                sent[j]= word[k];
                ++j;
                reverse_znachenie(word);
            }
        }
        if (q)
        {
            sent[j]=('.');
            j++;
        }
        else
        {
            sent[j]=(' ');
            j++;
        }

    } while (symbol != '.');
    skipspace_znachenie(sent);
    print_znachenie(sent);
    //print_znachenie(skipspace_znachenie("    ad!@ 1332       m       m    "));
    return 0;
}

void print_znachenie(char str[N]) {
    for (int i = 0; i < strlen(str); ++i) {
        printf("%c", str[i]);
    }
}

void reverse_znachenie(char str[N]) {
    char res[N] = "";
    int j = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[strlen(str) - i - 1] != '\0') {
            res[j] = str[strlen(str) - i - 1];
            j++;
        }
    }
    /*
    for (int i = 0; i < strlen(str); ++i) {
        printf("i=%d res[i]=%c\n", i, res[i]);
    }
    */
    for (int i = 0; i < strlen(res); ++i) {
        str[i] = res[i];
    }
    for (int i = strlen(res); i < N; ++i) {
        str[i] = '\0';
    }
}

void print_reverse_znachenie(char str[N]) {
    reverse_znachenie(str);
    print_znachenie(str);
}

void scanword_znachenie(char word[N]) {
    char symbol;
    int i = 0;
    do {
        scanf("%c", &symbol);
        word[i] = symbol;
        i++;
    } while (symbol != ' ' && symbol != '.');
}

void skipspace_znachenie(char word[N]) {
    char res[N] = "";
    _Bool q = 0;
    int j = 0;
    for (int i = 0; i < strlen(word); ++i) {
        if (word[i] == ' ' && q) {
            res[j] = word[i];
            j++;
            q = 0;
        }
        if (word[i] != ' ') {
            res[j] = word[i];
            q = 1;
            j++;
        }
    }
    if (res[strlen(res) - 1] == ' ')res[strlen(res) - 1] = '\0';
    for (int i =0; i< strlen(res);++i){
        word[i]=res[i];
    }
    for (int i = strlen(res); i < N; ++i) {
        word[i]='\0';
    }
}