/*  Paul Pak 
 *  TCSS 333 SP18
 *
 *
 */

#include <stdio.h>
#include <math.h>

int main(void)
{
    int userChoice, sgmnt1, sgmnt2, sgmnt3, sgmnt4, mask;
    char running = 'r';


    printf("\n \n=======[Assignment 1]=======\n \n");

    while(running == 'r')
    {

        printf("What type of conversion do you want? \nEnter 1 for IP-address and subnet, 2 for the host and network prefix: ");
        scanf("%d", &userChoice);
        printf("\nUSER INPUT: %d \n ", userChoice);

        if (userChoice == 1)
        {
            printf("\nEnter the message address:");
            scanf(" %d.%d.%d.%d/%d", &sgmnt1, &sgmnt2, &sgmnt3, &sgmnt4, &mask);
            printf("\nEntered address: %d.%d.%d.%d/%d \n", sgmnt1, sgmnt2, sgmnt3, sgmnt4, mask);



        } else if (userChoice == 2) {
            

        }

        printf("\nEnter r to repeat, q to quit: ");
        scanf(" %c", &running);

        userChoice = 0;

    }


    return 0;
}