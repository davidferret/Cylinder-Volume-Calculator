#include <stdio.h>
#define PI 3.141593

void calculateVolume(float radius, float height, float *vol);
void convertUnits(float volume);

int main(void) {
    int num_calculations;
    float r, h, v;
    
    printf("Enter the number of calculations: ");
    scanf("%d", &num_calculations);
    
    for (int i = 0; i < num_calculations; i++) {
        printf("\nEnter radius (-1 to exit): ");
        scanf("%f", &r);
        if (r == -1)
            break;
        
        printf("Enter height: ");
        scanf("%f", &h);
        
        calculateVolume(r, h, &v);
        printf("Volume of a cylinder = %.4f cubic cm\n", v);
        convertUnits(v);
    }
    
    printf("Program terminated!\n");
    return 0;
}

void calculateVolume(float radius, float height, float *vol) {
    *vol = PI * radius * radius * height;
}

void convertUnits(float volume) {
    int choice;
    printf("Select unit for conversion:\n");
    printf("1 - Liters\n");
    printf("2 - Milliliters\n");
    printf("3 - Cubic Inches\n");
    printf("4 - Cubic Feet\n");
    printf("5 - Gallons (US)\n");
    printf("6 - All Units\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
    
    printf("Equivalent volume:\n");
    if (choice == 1 || choice == 6) printf("%.4f liters\n", volume / 1000); // cm³ to liters
    if (choice == 2 || choice == 6) printf("%.4f milliliters\n", volume); // cm³ to mL
    if (choice == 3 || choice == 6) printf("%.4f cubic inches\n", volume * 0.0610237); // cm³ to cubic inches
    if (choice == 4 || choice == 6) printf("%.4f cubic feet\n", volume * 0.0000353147); // cm³ to cubic feet
    if (choice == 5 || choice == 6) printf("%.4f gallons (US)\n", volume * 0.000264172); // cm³ to gallons (US)
}
