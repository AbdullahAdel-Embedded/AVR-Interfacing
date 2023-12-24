

#include"declerations.h"
#include <stdio.h>
#include <stdlib.h>


Person *customer_head;
Person *admin_head;
int num_of_customers = 50;




int main()
{
    creating_data_base();
    //printt_data_base(customer_head);

    //printt_data_base(customer_head);



    char mode;
    char user_name[11];
    printf("Welcome to our bank\n");
    // getting the mode
    // note only customer mode works
    printf("Enter c for customer and a for admin \n");
    scanf(" %c", &mode);
    if(mode == 'c')
    {
        printf("Welcome to customer mode, Enter your user name: ");
        scanf(" %s", &user_name);

        //to get the data of the user
        Person *user_data;

        if ( check_the_user_name_and_password(user_name, &user_data, mode) )
        {
            printf("\nWelcome Customer\n");
            customer_operations(&user_data);


        }
        else
        {
            printf("InValid Customer");
        }

    }

   if(mode == 'a')
    {
        printf("Welcome to admin mode, Enter your user name: ");
        scanf(" %s", &user_name);
        Person *user_data;
        if ( check_the_user_name_and_password(user_name, &user_data, mode) )
        {
            printf("\n Valid Admin \n");

        }
        else
        {
            printf("InValid Admin");
        }

    }

    return 0;
}
