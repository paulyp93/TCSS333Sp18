/*  Paul Pak 
 *  TCSS 333 SP18
 *
 *
 */

#include <stdio.h>
#include <math.h>



int minMaxCheck(int s1, int s2, int s3, int s4, int msk);
long getDecimalValue(int s1, int s2, int s3, int s4);
int decimalToBinary(long decNumber);
int decimalToDotDec(int decNumber);
int getnetworkPrefix(int IPadd, int subnetMask);
int getHost(int IPadd, int subnetMask);
int subnetMaskBinToDec(int subnetMaskInt);
int getMaskDec(int networkPrefix);



int main(void)
{


    unsigned int userChoice = 0, sgmnt1 = 0, sgmnt2 = 0, sgmnt3 = 0, sgmnt4 = 0, mask = 0;
    unsigned int hSgmnt1 = 0, hSgmnt2 = 0, hSgmnt3 = 0, hSgmnt4 = 0;
    unsigned int checkMinMax;
    unsigned long IPdecimalValue;
    unsigned int subnetMask = 0, networkPrefix = 0, hostID = 0;
    //controls the while loop
    char running = 'r';



    printf("\n\n============================\n=======[Assignment 1]=======\n============================\n\n\n");


    while(running == 'r')
    {

        printf("What type of conversion do you want? \nEnter 1 for IP-address and subnet, 2 for the host and network prefix: ");
        scanf("%d", &userChoice);

        // IF THE USER CHOOSE OPTION 1
        if (userChoice == 1)
        {

            //Entering the main message adderess
            printf("\nEnter the message address: ");
            scanf(" %d.%d.%d.%d/%d", &sgmnt1, &sgmnt2, &sgmnt3, &sgmnt4, &mask);
            checkMinMax = minMaxCheck(sgmnt1, sgmnt2, sgmnt3, sgmnt4, mask);
            
            //makes sure that the entered values are non-negative
            if (checkMinMax != 1) {
                while (checkMinMax == 0){
                    printf("Wrong address, try again: ");
                    scanf(" %d.%d.%d.%d/%d", &sgmnt1, &sgmnt2, &sgmnt3, &sgmnt4, &mask);
                    checkMinMax = minMaxCheck(sgmnt1, sgmnt2, sgmnt3, sgmnt4, mask);
                }
            }
            
            // Decimal value section of option 1 
            IPdecimalValue = getDecimalValue(sgmnt1, sgmnt2, sgmnt3, sgmnt4);
            printf("\nThe IP-address is %lu in decimal and\n", IPdecimalValue);
            decimalToBinary(IPdecimalValue);
            printf("in binary\n");

            //subnet mask section of option 1
            subnetMask = subnetMaskBinToDec(mask);
            printf("\nThe subnet mask is %u in decimal and \n", subnetMask);
            decimalToBinary(subnetMask);
            printf("in binary\n");
            printf("The subnet mask in dot-decimal is:");
            decimalToDotDec(subnetMask);

            //network prefix section of option 1
            networkPrefix = getnetworkPrefix(IPdecimalValue, subnetMask);
            printf("\n\nThe network prefix is: %u in decimal and\n",networkPrefix);
            decimalToBinary(networkPrefix);
            printf("in binary\n");
            printf("The network prefix in dot-decimal is: ");
            decimalToDotDec(networkPrefix);
            printf("\n");

            //host section of option 1
            hostID = getHost(IPdecimalValue, subnetMask);
            printf("\nThe host id is: %u in decimal and \n", hostID);
            decimalToBinary(hostID);
            printf("in binary\n");
            printf("The host id in dot-decimal is: ");
            decimalToDotDec(hostID);
            printf("\n");


        } else if (userChoice == 2) {
            printf("\nEnter the host:");
            scanf(" %d.%d.%d.%d", &hSgmnt1, &hSgmnt2, &hSgmnt3, &hSgmnt4);
            checkMinMax = minMaxCheck(hSgmnt1, hSgmnt2, hSgmnt3, hSgmnt4, mask);

            //makes sure that the entered values are non-negative
            if (checkMinMax != 1) {
                while (checkMinMax == 0){
                    printf("Wrong address, try again: ");
                    scanf(" %d.%d.%d.%d/%d", &hSgmnt1, &hSgmnt2, &hSgmnt3, &hSgmnt4, &mask);
                    checkMinMax = minMaxCheck(hSgmnt1, hSgmnt2, hSgmnt3, hSgmnt4, mask);
                }
            }

            printf("\nEnter the network prefix: ");
            scanf(" %d.%d.%d.%d", &sgmnt1, &sgmnt2, &sgmnt3, &sgmnt4);
            checkMinMax = minMaxCheck(sgmnt1, sgmnt2, sgmnt3, sgmnt4, mask);
            
            //makes sure that the entered values are non-negative
            if (checkMinMax != 1) {
                while (checkMinMax == 0){
                    printf("Wrong address, try again: ");
                    scanf(" %d.%d.%d.%d/%d", &sgmnt1, &sgmnt2, &sgmnt3, &sgmnt4, &mask);
                    checkMinMax = minMaxCheck(sgmnt1, sgmnt2, sgmnt3, sgmnt4, mask);
                }
            }


            hostID = getDecimalValue(hSgmnt1, hSgmnt2, hSgmnt3, hSgmnt4);
            networkPrefix = getDecimalValue(sgmnt1, sgmnt2, sgmnt3, sgmnt4);
            IPdecimalValue = hostID ^ networkPrefix;

            printf("\nThe message is:");
            decimalToDotDec(IPdecimalValue);


        } else {
            printf("\n\nSorry, incorrect input. \nProgram will now terminate. \n\n");
            running = 'q';
        }

        printf("\nEnter r to repeat, q to quit: ");
        scanf(" %c", &running);

        userChoice = 0;

    }

    printf("\n\n\n=======[END OF PROGRAM]=======\n\n");
    return 0;
}

//Checks if values entered by the user are within the right bounds.
int minMaxCheck(int s1, int s2, int s3, int s4, int msk)
{
    int result;
    
    //Checking to see if any input values are less than 0.
    if (s1 < 0 || s2 < 0 || s3 < 0 || s4 < 0 || msk < 0)
    {
        result = 0;
    
    //checking to see if any input values are more than 255 or if mask is more than 32
    } else if (s1 > 255 || s2 > 255 || s3 > 255 || s4 > 255 || msk > 32) {
        
        result = 0;
    
    } else {
        
        result = 1;
    
    }

    return result;

}

//Calculates the decimal value of the IP address.
long getDecimalValue(int s1, int s2, int s3, int s4)
{
    long result;

    result = (s1 * pow(256, 3)) + (s2 * pow(256, 2)) + (s3 * 256) + s4;
    
    return result;
}

int decimalToBinary(long decNumber)
{
    int numOfBits, binaryNum, decCopy;
 
    for (numOfBits = 31; numOfBits >= 0; numOfBits--)
    {
         binaryNum = decNumber >> numOfBits;
 
        if (binaryNum & 1)
            printf("1");
        else
            printf("0");

        if (numOfBits%8 == 0)
            printf(" ");

    }

    return 0;
}


int decimalToDotDec(int decNumber) 
{
    int decCopy, numOfBits, binaryNum, numHolder, counter, startingBit, endingBit, exponent;
    counter = 4;
    numHolder = 0;

    startingBit = 31;
    endingBit = 24;

    decCopy = decNumber;
 
    while (counter != 0) {
        numHolder = 0;

        exponent = 7;

        for (numOfBits = startingBit; numOfBits >= endingBit; numOfBits--)
        {
            binaryNum = decCopy >> numOfBits;
     
            if (binaryNum & 1)
                numHolder += pow(2, exponent);
            else
                numHolder += 0;

            exponent--;

        }

        if(counter != 1)
            printf("%d.", numHolder);
        else 
            printf("%d", numHolder);

        startingBit -= 8;
        endingBit -= 8;

        counter--;
    }

    return 0;
}


int getnetworkPrefix(int IPadd, int subnetMask)
{
    unsigned int networkPrefix = 0;

    networkPrefix = IPadd & subnetMask;

    return networkPrefix;
}

int getHost(int IPadd, int subnetMask)
{
    unsigned int host = 0;

    host = IPadd & ~subnetMask;

    return host;
}


int subnetMaskBinToDec(int subnetMaskInt) 
{

    unsigned int subnetMask = 0, numOfBits;

    for (numOfBits = 31; numOfBits >= (32 - subnetMaskInt); numOfBits--)
    {
        subnetMask = subnetMask | (1 << numOfBits);
    }

    return subnetMask;
}







