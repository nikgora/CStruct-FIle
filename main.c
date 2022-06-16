#include <stdio.h>
#include <string.h>
#define N 100
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
    puts("Enter your name");
    gets(people.field.name);
    puts("Enter your age");
    scanf("%d",&people.field.age);
    printf("Your name is %s.\nYou is %d years old.",people.field.name,people.field.age);
    return 0;
}
