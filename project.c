/*
 *Mini Project
 *Food Management System
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

struct customer
{
    char name[50];
    char address[50];
    char dob[10];
    int  id;
}c1;

struct hotel
{
    char name[100];
    int registeration_id;
    int password;
    char food[5][20];
    int price[5];
    int count_food;
}h1;

struct delivery
{
    char name[50];
    char vehicle_name[20];
    int vehicle_number;
}d1;

struct management
{
    int delivered_on_time;
    int packaged_properly;
    int complete_order_recieved;
    int bill_recieved;
}m1;

/*
 * This function generates random numbers within a limit using long int as a parameter for the the upper limit. 
 */
int random_number_generator(long int limit){
    
    int temporary = (rand()%(limit+1));
    return temporary;
}


/*
 * This function is used to produce a delay of output during runtime of the program.
 * The amount of time the function needs to delay is taken as a parameter in the function.
 */
void delay(int number_of_seconds)
{

    // seconds are converted into milli seconds because clock measures time in milli seconds
    int milli_seconds = 1000 * number_of_seconds;   
 
    clock_t start_time = clock();

    // empty loop until corresponding time is elapsed
    while (clock() < start_time + milli_seconds){} 
}


/*
 * This function lets the hotel register itself and start using other services
 */
void hotel_login(){
    
    printf("\nEnter your hotel details\n");
    printf("Name: ");
    // getchar is used to empty the input stream containing \n from previous integer input.
    getchar(); 
    // fgets is used to take input of the string using standard input                 
    fgets(h1.name,100,stdin);   

    printf("Password(only in numerical digits): ");
    scanf("%d", &h1.password);
    // this loop is used to confirm the entered password
    while(1){
        int temp;
        printf("Confirm Password: ");
        scanf("%d", &temp);
        if (temp==h1.password)
        {
            break;
        }
    
    }

    // assigning ID to hotel using random number generator.
    h1.registeration_id = random_number_generator(999999999);
    
}

/*
 * This function displays the entered information by user
 */
void display_hotel(){

    printf("\nYou have successfully registered your hotel.\n");
    printf("\t%s", h1.name);
    printf("Here is your registration ID: %d\n", h1.registeration_id);

}


/*
 * This function helps the hotel to create thier menu and list the prices of food.
 */
void hotel_food(){

    printf("\nEnter the food items and its rate you would be serving (Enter X to stop entering itmes):\n");
    int i=0;

    // This loop is used to input the food and its price for the menu
    while(i<5){
        char current_food[20];
        printf("Food: ");
        // getchar is used to empty the input stream containing \n from previous integer input.
        getchar();
        fgets(current_food, 20, stdin);

        if(current_food[0]=='X'){
            break;
        }
        else{
            strcpy(h1.food[i], current_food);

            printf("Price: ");
            scanf("%d", &h1.price[i]);
            i++;
        }

    }
    h1.count_food = i;
    printf("\n");

}


/*
 * This function is used to display the menu to customer while he is ordering food
 */
void display_menu(){

    printf("\nThe menu is:\n");
    printf("Code\tName\n");
    for(int index=0; index<h1.count_food; index++){
        printf("%d\t%s\n", index+1, h1.food[index]);
    }


}


/*
 * This function lets the customer register and use the services.
 */
void customer_login(){
    
    printf("\nEnter your details\n");
    printf("Name: ");
    getchar();
    fgets(c1.name,50,stdin);

    printf("Address: ");
    fgets(c1.address, 50, stdin);

    printf("Date of birth: ");
    fgets(c1.dob, 10, stdin);

    c1.id = random_number_generator(4444);
    printf("\n");

}

/*
 * This function displays the information entered by the customer.
 */
void display_customer(){

    printf("\nYou registration is successfull! You can now use our services\n");
    printf("Your details are\n");
    printf("Name: %s", c1.name);
    printf("Address: %s", c1.address);
    printf("Your registration id is: %d\n", c1.id);

}

/*
 * This function lets the user order food
 */
void order(){

    display_menu();

    // the bill variable starts with zero and increases as the customer orders
    int bill = 0;

    // loop to take the order from customer
    while(1){

        int food_code, quantity_food;
        printf("Enter the code of the item you would like to buy (enter -1 to stop ordering and display your bill): ");
        // getchar is used to empty the input stream containing \n from previous integer input.
        getchar();
        scanf("%d", &food_code);

        if(food_code==-1){
            break;
        }

        printf("Enter the quantity you would like to buy: ");
        scanf("%d", &quantity_food);

        bill = bill + quantity_food*h1.price[food_code-1];

    }

    printf("\nYour bill is %d rupees.\n", bill);


}


/*
 * This function lets the delivery man register.
 */
void delivery_man_login(){

    printf("\nEnter your information\n");
    printf("Name: ");
    // getchar is used to empty the input stream containing \n from previous integer input.
    getchar();
    fgets(d1.name, 50, stdin);
    printf("Vehicle name: ");
    fgets(d1.vehicle_name, 20, stdin);
    printf("Vehicle number: ");
    scanf("%d", &d1.vehicle_number);

}


/*
 * This function displays the delivery information to the customer 
 */
void display_delivery_info(){

    // delay is used to show that the order is being prepared
    delay(4);
    printf("\n\nYour order is on its way\n");
    printf("Delivery Man information is \n");
    printf("Name: %s", d1.name);
    printf("Vehicle name: %s", d1.vehicle_name);
    printf("Vehicle mnumber: %d", d1.vehicle_number);
}


/*
 * this function asks the user for feedback once the order is complete.
 */
void ask_feedback(){

    // delay is being used to show that the order is on its way
    delay(6);
    printf("\n\nYour order is delivered\n");
    printf("\nPlease provide your feedback (enter 1 for satisfied and 0 for not satisfied): \n");
    printf("1. Did you recieved your order on time: ");
    scanf("%d", &m1.delivered_on_time);
    printf("2. Did you recieved your order packaged properly: ");
    scanf("%d", &m1.packaged_properly);
    printf("3. Was the order you recived correct and complte: ");
    scanf("%d", &m1.complete_order_recieved);
    printf("4. Did you recieved bill with your order: ");
    scanf("%d", &m1.bill_recieved);

    printf("\nThank you for providing feedback! Our management team will positively work to improve our services based on your feedback.\n");
}



int main(){


    printf("\n\nWelcome to ABC company\n\n");
    
    // the loop that controls the flow of whole program
    while(1){

        printf("\nAre you a\n\tHotel Manager (enter 1)\n\tCustomer (enter 2)\n\tDelivery Man (enter 3)\n\tEnter -1 to exit\n");
        int field_selector;
        scanf("%d", &field_selector);

        if(field_selector==1){

            printf("\nPlease register before you start using our services\n");

        
            hotel_login();
            display_hotel();
            hotel_food();

        }
        else if(field_selector==2){

            printf("\nPlease register before you start using our services\n");

            customer_login();
            display_customer();
            order();
            printf("Your order will be delivered soon...");
            display_delivery_info();
            ask_feedback();

        }
        else if(field_selector==3){

            delivery_man_login();

        }
        else if(field_selector==-1){
            printf("Thank you for using our services.");
            break;
        }

    }
    

    return 0;
}
