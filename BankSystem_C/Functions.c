#include "declerations.h"
#include "user_names.h"

extern Person *customer_head;
extern Person *admin_head;
extern int num_of_customers;



void customer_operations(Person* *user)
{
    char mode=0;

    //to break from the loop after 3 trails
    int i=0;
while(1)
{
    while(mode != 'i' && mode!='o' && (i<3))
    {
        printf("Enter 'i' For inquiries, 'o' for operation\n");
        scanf(" %c", &mode);
        i++;
    }

    if(mode == 'i')
    {
        printf("Your balance is %d\n", (*user)->balance);
        mode=0;

    }

    else if(mode == 'o')
    {
        mode=0;
        // getting the operation
        // two operations only, withdraw and deposit

        int i=0;
        char op =0;
        while(op != 'w' && op!='d' && (i<3))
        {
            printf("Enter 'w' For withdraw, 'd' for deposit: ");
            scanf(" %c", &op);
            i++;
        }

        if(op =='w')
        {
            int amount_to_withdraw = 0;
            printf("Enter the amount: ");
            scanf(" %d",&amount_to_withdraw);
            if( (*user)->balance >= amount_to_withdraw )
            {
                (*user)->balance -= amount_to_withdraw;
                printf("\nYour new balance is : %d",(*user)->balance);
            }
            else
            {
                printf("\nyour balance is less than that \n");

            }


        }

        else if(op == 'd')
        {
            int amount_to_deposit = 0;
            printf("Enter the amount to deposit:  ");
            scanf(" %d",&amount_to_deposit);
            (*user)->balance += amount_to_deposit;
            printf("\nYour new balance is : %d\n",(*user)->balance);

        }


    }


}

}


// reads the password from the user and check it with the password that corresponded with the Entered username
int get_and_check_password(Person* user)
{
    //printf("%s\n", user->password);

    //to read the input
    char input_password[12];
    int n_trials = 3;


    while(1) //will be broken by returning in the else statement
    {
        printf("Please Enter Your Password: ");

          // Read input from the user and display asterisks
            int i = 0;
            char c;
        while ((c = getch()) != '\r')
        {
            // '\r' represents the Enter key
            if (c == '\b' && i > 0)
            {
                // '\b' represents the Backspace key
                i--;
                printf("\b \b"); // erase the last asterisk
            }
            else
            {
                input_password[i++] = c;
                printf("*");
            }
        }

        input_password[i] = '\0';

        //comparing passwords
        if( strcmp(input_password, user->password) == 0)
        {
            //printf("\n correct pass\n");
            return correct_password;
        }
        else if(n_trials >0 )
        {
            printf("\nwrong pass, you have only %d trials\n",n_trials );
            n_trials--;
        }
        else
        {
            return wrong_password;
        }
    }


}


int check_the_user_name_and_password(char* user_name, Person* *user_data, char mode)
{
    Person *user;
    int num_of_iterations = 0;
    //loop over the list, to search for the user_name existence
    if(mode == 'c')
    {
         user = customer_head;
         num_of_iterations = num_of_customers;
    }
    else if(mode == 'a')
    {
         user = admin_head;
         num_of_iterations = 3;
    }
    else
    {

    }

    for(int i=0; i<num_of_iterations;i++)
    {
        if(strcmp(user->user_name, user_name) == 0)
        {

            //printf("%s \n", user->password);
            if(get_and_check_password(user) )
            {
                //printf("Done");

                //pass the real physical address of the user struct
                *user_data = user;
                return 1;
            }
            else
            {
                return 0;
            }
        }

        else
        {
            user = user->next;
        }

    }

    //The input user is not exist
    return 0;
}

/*
int check_the_Admin_name_and_password(char* user_name, Admin* *user_data)
{
    //loop over the list, to search for the user_name existence
    Admin *user = admin_head;

    for(int i=0; i<num_of_customers;i++)
    {
        if(user->user_name == user_name)
        {
            //check for the password
            if(1)//get_check_password(user->password) )
            {
                *user_data = user;
                return 1;
            }
            else
            {
                return 0;
            }

        }
        else
        {
            user = user->next;
        }

    }

    //The input user is not exist
    return 0;
}
*/
void creating_data_base()
{
    int i=0;
    Person *last_node = NULL;

    //Creating the first user
    Person *new_user = malloc(sizeof(Person));
    // Makes head points to it
    customer_head = new_user;

    // write its data
    strcpy(new_user->user_name, users[i]);
    strcpy(new_user->password, users[i]);
    new_user->balance = (i+1)*100;
    new_user->next = NULL;

    i++;
    last_node = new_user;

    for( i=1; i<num_of_customers;i++ )
    {
        // creating new customer
        new_user = malloc(sizeof(Person));

        //link add it to the end of the list
        last_node->next = new_user;
        // write its data

        strcpy(new_user->user_name, users[i]);
        strcpy(new_user->password, users[i]);
        new_user->balance = (i+1)*100;
        new_user->next = NULL;

        last_node = new_user;

    }
}

void creating_Admin_data_base()
{
    //Creating the first user
    Person *Admin_Ahmed = malloc(sizeof(Person));
    Person *Admin_Mohamed = malloc(sizeof(Person));
    Person *Admin_Ali = malloc(sizeof(Person));

    admin_head = Admin_Ahmed;
    strcpy(Admin_Ahmed->user_name,'Ahmed_95');
    strcpy(Admin_Ahmed->password, 'Ahmed_95');
    Admin_Ahmed->next, Admin_Mohamed;

    strcpy(Admin_Mohamed->user_name, 'Mohamed5');
    strcpy(Admin_Mohamed->password, 'Mohamed5');
    Admin_Mohamed->next = Admin_Ali;

    strcpy(Admin_Ali->user_name, 'Ali_959');
    strcpy(Admin_Ali->password , 'Ali_959');
    Admin_Ali->next = NULL;



    //*Admin_head = new_user;
}
void printt_data_base(Person* customer_head)
{
    for(int i=0; i<num_of_customers; i++)
    {
        printf("%s \n", customer_head->user_name);
        printf("%s \n", customer_head->password);
        printf("%d \n", customer_head->balance);
        customer_head = customer_head->next;

    }
}

