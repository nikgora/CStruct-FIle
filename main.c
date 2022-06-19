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
    union aboutMe {
        char hobby[N];
        int yearOfBirthday;
        float averageMarkInSchool;
    }aboutMe;
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
    char s[N]="";
    input_enum(num);
    print_enum(people.sex,s);
    puts ("Enter 0 if you tell me about your year of birthday, or 1 if you are tell me about your hobby, or 2 if you are tell me about your average mark in school");
    fscanf(file,"%d",&num);
    puts("Enter what you choose");
    char whatPrint[N]="";
    switch (num) {
        case 0:
            fscanf(file,"%d",&people.aboutMe.yearOfBirthday);
            char temp1[N] = "Your Year of birthday is ";
            for (int i = 0; i < strlen(temp1); ++i) {
                whatPrint[i]=temp1[i];
            }
            break;
        case 1:
            fgets(people.aboutMe.hobby,N,file);
            fgets(people.aboutMe.hobby,N,file);
            char temp2[N] = "Your hobby is ";
            for (int i = 0; i < strlen(temp2); ++i) {
                whatPrint[i]=temp2[i];
            }

            break;
        case 2:
            fscanf(file,"%f",&people.aboutMe.averageMarkInSchool);
            char temp3[N] = "Your average mark in school is ";
            for (int i = 0; i < strlen(temp3); ++i) {
                whatPrint[i]=temp3[i];
            }

            break;
        default:
            puts("No");
    }
    fclose(file);
    if ((file = fopen("my_prog.txt", "w")) == NULL)
    {
        puts("Error! opening file");
        exit(1);
    }
    fprintf(file,"Your name is %s.\nYou are %d years old.\nYour sex is %s.\n%s",people.field.name,people.field.age,s,whatPrint);

    switch (num) {
        case 0:
            fprintf(file,"%d",people.aboutMe.yearOfBirthday);
            break;
        case 1:
            fprintf(file,"%s",people.aboutMe.hobby);
            break;
        case 2:
            fprintf(file,"%f",people.aboutMe.averageMarkInSchool);

            break;
        default:
            puts("No");
    }fclose(file);
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
