#include <stdio.h>
#include <string.h>

struct Vehicle
{
    char number[20];
    int occupied;
    int duration;
};

int main()
{
    struct Vehicle v[5];
    int choice, i, found;
    int available = 5;
    int fee;
    char inputNumber[20];

    // Initially all parking spaces are empty
    for(i = 0; i < 5; i++)
    {
        v[i].occupied = 0;
    }

    while(1)
    {
        printf("\n--- SMART CAMPUS PARKING SYSTEM ---\n");
        printf("1. Vehicle Entry\n");
        printf("2. Vehicle Exit\n");
        printf("3. Check Parking Availability\n");
        printf("4. Check Vehicle Status\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter vehicle registration number: ");
                scanf("%19s", inputNumber);

                found = 0;

                // Check for duplicate entry
                for(i = 0; i < 5; i++)
                {
                    if(v[i].occupied == 1 &&
                       strcmp(v[i].number, inputNumber) == 0)
                    {
                        found = 1;
                        break;
                    }
                }

                if(found == 1)
                {
                    printf("Vehicle is already parked!\n");
                }
                else if(available == 0)
                {
                    printf("Parking area is full!\n");
                }
                else
                {
                    for(i = 0; i < 5; i++)
                    {
                        if(v[i].occupied == 0)
                        {
                            strcpy(v[i].number, inputNumber);
                            v[i].occupied = 1;
                            available--;

                            printf("Vehicle parked successfully!\n");
                            printf("Parking space: %d\n", i + 1);
                            break;
                        }
                    }
                }
                break;

            case 2:
                printf("Enter vehicle registration number: ");
                scanf("%19s", inputNumber);

                found = 0;

                // Search for the vehicle
                for(i = 0; i < 5; i++)
                {
                    if(v[i].occupied == 1 &&
                       strcmp(v[i].number, inputNumber) == 0)
                    {
                        found = 1;

                        printf("Enter parking duration in hours: ");
                        scanf("%d", &v[i].duration);

                        fee = v[i].duration * 20;

                        printf("\nVehicle exited successfully!\n");
                        printf("Vehicle Number: %s\n", v[i].number);
                        printf("Parking Duration: %d hours\n",
                               v[i].duration);
                        printf("Parking Fee: Rs. %d\n", fee);

                        v[i].occupied = 0;
                        available++;

                        break;
                    }
                }

                if(found == 0)
                {
                    printf("Vehicle not found in parking area!\n");
                }
                break;

            case 3:
                printf("Total Parking Spaces: 5\n");
                printf("Occupied Spaces: %d\n", 5 - available);
                printf("Available Spaces: %d\n", available);
                break;

            case 4:
                printf("Enter vehicle registration number: ");
                scanf("%19s", inputNumber);

                found = 0;

                for(i = 0; i < 5; i++)
                {
                    if(v[i].occupied == 1 &&
                       strcmp(v[i].number, inputNumber) == 0)
                    {
                        found = 1;

                        printf("Vehicle is currently parked.\n");
                        printf("Parking Space: %d\n", i + 1);
                        break;
                    }
                }

                if(found == 0)
                {
                    printf("Vehicle is not currently parked.\n");
                }
                break;

            case 5:
                printf("Thank you for using Smart Campus Parking System!\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}