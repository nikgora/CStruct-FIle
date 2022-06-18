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
        Man,Women
    }sex;
}people;

int main() {
    FILE *file;
    if ((file = fopen("my_prog.txt", "r")) == NULL)
    {
        puts("Error! opening file");
        exit(1);
    }
    puts("Enter your name");
    fgets(people.field.name,N,file);
    puts("Enter your age");
    fscanf(file,"%d",&people.field.age);
    people.field.name[strlen(people.field.name)-1]='\0';
    fclose(file);
    if ((file = fopen("my_prog.txt", "w")) == NULL)
    {
        puts("Error! opening file");
        exit(1);
    }
    fprintf(file,"Your name is %s.\nYou are %d years old.",people.field.name,people.field.age);
    fclose(file);
    return 0;
}
