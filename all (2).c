
#include <stdio.h>

struct Vehicle
{
    int id;
    char name[50];
    char brand[50];
    int type;
    int seats;
    int rented;
};

int main()
{
    struct Vehicle v[100];
    int count = 0;
    int choice, i, searchID, found;

    do
    {
        printf("\n\n===== VEHICLE RENTAL MANAGEMENT SYSTEM =====");
        printf("\n1. Add Vehicle");
        printf("\n2. Display All Vehicles");
        printf("\n3. Search Vehicle");
        printf("\n4. Rent Vehicle");
        printf("\n5. Return Vehicle");
        printf("\n6. Display Available Vehicles");
        printf("\n7. Exit");

        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:

                if(count >= 100)
                {
                    printf("\nVehicle Storage Full!");
                    break;
                }

                printf("\nEnter Vehicle ID: ");
                scanf("%d", &v[count].id);

                printf("Enter Vehicle Name: ");
                scanf(" %[^\n]", v[count].name);

                printf("Enter Brand: ");
                scanf(" %[^\n]", v[count].brand);

                printf("\nSelect Vehicle Type:");
                printf("\n1. Car");
                printf("\n2. Bike");

                printf("\nEnter choice: ");
                scanf("%d", &v[count].type);

                if(v[count].type != 1 && v[count].type != 2)
                {
                    printf("\nInvalid Vehicle Type!");
                    break;
                }

                if(v[count].type == 1)
                {
                    printf("Enter Number of Seats: ");
                    scanf("%d", &v[count].seats);
                }
                else
                {
                    v[count].seats = 2;
                }

                v[count].rented = 0;
                count++;

                printf("\nVehicle Added Successfully!");

                break;

            case 2:

                if(count == 0)
                {
                    printf("\nNo Vehicles Found!");
                    break;
                }

                printf("\n===== ALL VEHICLES =====");

                for(i = 0; i < count; i++)
                {
                    printf("\n\nVehicle ID: %d", v[i].id);
                    printf("\nName: %s", v[i].name);
                    printf("\nBrand: %s", v[i].brand);

                    if(v[i].type == 1)
                        printf("\nType: Car");
                    else
                        printf("\nType: Bike");

                    printf("\nSeats: %d", v[i].seats);

                    if(v[i].rented == 1)
                        printf("\nStatus: Rented");
                    else
                        printf("\nStatus: Available");
                }

                break;

            case 3:

                printf("\nEnter Vehicle ID to Search: ");
                scanf("%d", &searchID);

                found = 0;

                for(i = 0; i < count; i++)
                {
                    if(v[i].id == searchID)
                    {
                        printf("\nVehicle Found!");
                        printf("\nName: %s", v[i].name);
                        printf("\nBrand: %s", v[i].brand);
                        printf("\nSeats: %d", v[i].seats);

                        if(v[i].type == 1)
                            printf("\nType: Car");
                        else
                            printf("\nType: Bike");

                        if(v[i].rented == 1)
                            printf("\nStatus: Rented");
                        else
                            printf("\nStatus: Available");

                        found = 1;
                        break;
                    }
                }

                if(found == 0)
                    printf("\nVehicle Not Found!");

                break;

            case 4:

                printf("\nEnter Vehicle ID to Rent: ");
                scanf("%d", &searchID);

                found = 0;

                for(i = 0; i < count; i++)
                {
                    if(v[i].id == searchID)
                    {
                        found = 1;

                        if(v[i].rented == 0)
                        {
                            v[i].rented = 1;
                            printf("\nVehicle Rented Successfully!");
                        }
                        else
                        {
                            printf("\nVehicle Already Rented!");
                        }

                        break;
                    }
                }

                if(found == 0)
                    printf("\nVehicle Not Found!");

                break;

            case 5:

                printf("\nEnter Vehicle ID to Return: ");
                scanf("%d", &searchID);

                found = 0;

                for(i = 0; i < count; i++)
                {
                    if(v[i].id == searchID)
                    {
                        found = 1;

                        if(v[i].rented == 1)
                        {
                            v[i].rented = 0;
                            printf("\nVehicle Returned Successfully!");
                        }
                        else
                        {
                            printf("\nVehicle Was Not Rented!");
                        }

                        break;
                    }
                }

                if(found == 0)
                    printf("\nVehicle Not Found!");

                break;

            case 6:

                printf("\n===== AVAILABLE VEHICLES =====");

                found = 0;

                for(i = 0; i < count; i++)
                {
                    if(v[i].rented == 0)
                    {
                        printf("\n\nVehicle ID: %d", v[i].id);
                        printf("\nName: %s", v[i].name);
                        printf("\nBrand: %s", v[i].brand);

                        if(v[i].type == 1)
                            printf("\nType: Car");
                        else
                            printf("\nType: Bike");

                        found = 1;
                    }
                }

                if(found == 0)
                    printf("\nNo Available Vehicles!");

                break;

            case 7:

                printf("\nThank You for Using Vehicle Rental System!");
                break;

            default:

                printf("\nInvalid Choice! Try Again.");
        }

    } while(choice != 7);

    return 0;
}


