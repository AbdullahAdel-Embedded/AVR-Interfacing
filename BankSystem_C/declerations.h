#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define correct_password 1
#define wrong_password 0




// typedef to store the operations of user, no_operatoin to be set to the new users
typedef enum {no_operation, deposit, withdraw} operation;
typedef struct Admin
{
    char user_name[10];
    char password[10];
    struct Admin *next;

}Admin;

typedef struct Person
{
    char user_name[10];
    char password[10];
    int balance;
    operation last_op[10];
    int amount[10];

    struct Person *next;
}Person;


void customer_operations(Person* *user);
void creating_data_bas();
void creating_Admin_data_base();
int get_and_check_password(Person* user);
int check_the_user_name_and_password(char* user_name, Person* *user_data, char mode);
int check_the_Admin_name_and_password(char* user_name, Admin* *user_data);
void printt_data_base(Person* customer_head);
