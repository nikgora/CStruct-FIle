#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 10000

struct people  {
    struct field {
        int age;
        char name[N];
    } field;
    enum sex {
        Man=0,Woman
    }sex;
}people;
enum sex input_enum (int num) ;
void print_enum (enum sex sex,char s[N]);
int main() {
    FILE *file;
    if ((file = fopen("my_prog.txt", "r")) == NULL)
    {
        puts("Error! opening file");
        exit(1);
    }
    puts("Enter your name");
    int num=0;
    fgets(people.field.name,N,file);
    puts("Enter your age");
    fscanf(file,"%d",&people.field.age);
    people.field.name[strlen(people.field.name)-1]='\0';
    puts ("Enter 0 if you are man or 1 if you are woman");
    fscanf(file,"%d",&num);
    fclose(file);
    if ((file = fopen("my_prog.txt", "w")) == NULL)
    {
        puts("Error! opening file");
        exit(1);
    }
    char s[N]="";
    input_enum(num);
    print_enum(people.sex,s);
    fprintf(file,"Your name is %s.\nYou are %d years old.\nYour sex is %s.",people.field.name,people.field.age,s);
    fclose(file);
    return 0;
}

enum sex input_enum (int num)

{


    switch (num)

    {

        case 0: people.sex = Man;

            break;

        case 1: people.sex = Woman;

            break;

        default: puts("no");

            return num;

    }

}

void print_enum (enum sex sex,char s[N])

{

    switch (sex)

    {

        case 1:
            s[0]='W';
            s[1]='o';
            s[2]='m';
            s[3]='a';
            s[4]='n';
            break;

        case 0:
            s[0]='M';
            s[1]='a';
            s[2]='n';
            break;

        default:
            s[0]='N';
            s[1]='o';
    }
}
