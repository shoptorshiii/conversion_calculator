#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>


void decimalToBinary(int decimal, FILE *file);
void binaryToDecimal(const char *binary, FILE *file);
void decimalToOctal(int decimal, FILE *file);
void octalToDecimal(const char *octal, FILE *file);
void decimalToHexadecimal(int decimal, FILE *file);
void hexadecimalToDecimal(const char *hex, FILE *file);
void decimalToRoman(int decimal, FILE *file);
void romanToDecimal(const char *roman, FILE *file);

void unitConversion(FILE *file);
void numberConversion(FILE *file);
void generateFileName(char *fileName);

void fillMatrix(int rows, int cols, int matrix[rows][cols]);
void printMatrix(int rows, int cols, int matrix[rows][cols]);
void printMatrixFloat(int rows, int cols, float matrix[rows][cols]);
void transposeMatrix(int rows, int cols, int matrix[rows][cols], int transpose[cols][rows]);
int inverseMatrix2x2(int matrix[2][2], float inverse[2][2]);
void calculateEigenvalues2x2(int matrix[2][2]);
void matrixOperations();


void generateFileName(char *fileName)
{
    time_t now = time(NULL);
    struct tm *t = localtime(&now);

    int hour = t->tm_hour;
    int minute = t->tm_min;
    char meridiem[3] = "AM";

    if (hour >= 12)
    {
        meridiem[0] = 'P';
        if (hour > 12) hour -= 12;
    }
    else if (hour == 0)
    {
        hour = 12;
    }

    sprintf(fileName, "%02d-%02d%s.txt", hour, minute, meridiem);
}

void convertCurrency()
{
    int fromCurrency, toCurrency;
    float amount;

    float rates[9][9] =
    {
        {1.0, 1.1, 1.25, 0.013, 1.5, 1.35, 3.75, 1300.0, 85.0},  // From USD
        {0.91, 1.0, 1.14, 0.012, 1.36, 1.24, 3.41, 1181.82, 77.27}, // From EUR
        {0.8, 0.88, 1.0, 0.011, 1.2, 1.08, 3.0, 1036.36, 68.0},   // From GBP
        {76.92, 83.33, 90.91, 1.0, 110.0, 99.0, 270.0, 100000.0, 6800.0}, // From INR
        {0.67, 0.74, 0.83, 0.0067, 1.0, 0.92, 2.47, 875.0, 58.0},  // From AUD
        {0.74, 0.81, 0.93, 0.007, 1.09, 1.0, 2.69, 950.0, 63.0},  // From CAD
        {3.0, 3.25, 3.6, 0.0037, 4.06, 3.72, 1.0, 3530.0, 235.0},  // From SAR
        {0.0077, 0.0085, 0.0097, 0.00028, 0.00114, 0.00105, 0.00028, 1.0, 0.066},  // From KRW
        {0.012, 0.013, 0.015, 0.00015, 0.017, 0.016, 0.0043, 15.15, 1.0}  // From BDT
    };

    printf("\n* Currency Conversion *\n");

    printf("Select the currency you want to convert from:\n");
    printf("1. USD\n");
    printf("2. EUR\n");
    printf("3. GBP\n");
    printf("4. INR\n");
    printf("5. AUD\n");
    printf("6. CAD\n");
    printf("7. SAR\n");
    printf("8. KRW\n");
    printf("9. BDT\n");
    printf("Enter the number corresponding to your currency: ");
    scanf("%d", &fromCurrency);

    printf("Select the currency you want to convert to:\n");
    printf("1. USD\n");
    printf("2. EUR\n");
    printf("3. GBP\n");
    printf("4. INR\n");
    printf("5. AUD\n");
    printf("6. CAD\n");
    printf("7. SAR\n");
    printf("8. KRW\n");
    printf("9. BDT\n");
    printf("Enter the number corresponding to the target currency: ");
    scanf("%d", &toCurrency);

    printf("Enter the amount to convert: ");
    scanf("%f", &amount);

    float result = amount * rates[fromCurrency - 1][toCurrency - 1];
    printf("Converted Amount: %.2f\n", result);
}



void numberConversion(FILE *file)
{
    int choice, number;
    char input[50];

    printf("\n* Number Conversion *\n");
    printf("1. Decimal to Binary\n");
    printf("2. Binary to Decimal\n");
    printf("3. Decimal to Octal\n");
    printf("4. Octal to Decimal\n");
    printf("5. Decimal to Hexadecimal\n");
    printf("6. Hexadecimal to Decimal\n");
    printf("7. Decimal to Roman Numerals\n");
    printf("8. Roman Numerals to Decimal\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        printf("Enter the decimal number: ");
        scanf("%d", &number);
        printf("Binary: ");
        fprintf(file, "Binary: ");
        decimalToBinary(number, file);
        break;

    case 2:
        printf("Enter the binary number: ");
        scanf("%s", input);
        printf("Decimal: ");
        fprintf(file, "Decimal: ");
        binaryToDecimal(input, file);
        break;

    case 3:
        printf("Enter the decimal number: ");
        scanf("%d", &number);
        printf("Octal: ");
        fprintf(file, "Octal: ");
        decimalToOctal(number, file);
        break;

    case 4:
        printf("Enter the octal number: ");
        scanf("%s", input);
        printf("Decimal: ");
        fprintf(file, "Decimal: ");
        octalToDecimal(input, file);
        break;

    case 5:
        printf("Enter the decimal number: ");
        scanf("%d", &number);
        printf("Hexadecimal: ");
        fprintf(file, "Hexadecimal: ");
        decimalToHexadecimal(number, file);
        break;

    case 6:
        printf("Enter the hexadecimal number: ");
        scanf("%s", input);
        printf("Decimal: ");
        fprintf(file, "Decimal: ");
        hexadecimalToDecimal(input, file);
        break;

    case 7:
        printf("Enter the decimal number: ");
        scanf("%d", &number);
        printf("Roman Numerals: ");
        fprintf(file, "Roman Numerals: ");
        decimalToRoman(number, file);
        break;

    case 8:
        printf("Enter the Roman numeral: ");
        scanf("%s", input);
        printf("Decimal: ");
        fprintf(file, "Decimal: ");
        romanToDecimal(input, file);
        break;

    default:
        printf("Invalid choice.\n");
    }
}


int main()
{
    int choice;
    char fileName[50];
    generateFileName(fileName);

    FILE *file = fopen(fileName, "w");
    if (file == NULL)
    {
        printf("Error creating file.\n");
        return 1;
    }

    while (1)
    {
        printf("\n* Conversion Calculator *\n");
        printf("1. Number Conversion\n");
        printf("2. Unit Conversion\n");
        printf("3. Matrix Operations\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            numberConversion(file);
            break;

        case 2:
            unitConversion(file);
            break;

        case 3:
            matrixOperations(file);
            break;

        case 4:
            printf("Exiting...\n");
            fclose(file);
            return 0;

        default:
            printf("Invalid choice. Try again.\n");
        }
    }

    fclose(file);
    return 0;
}





void decimalToBinary(int decimal, FILE *file)
{
    if (decimal == 0)
    {
        printf("0");
        fprintf(file, "0");
        return;
    }

    int binary[32], i = 0;
    while (decimal > 0)
    {
        binary[i++] = decimal % 2;
        decimal /= 2;
    }

    for (int j = i - 1; j >= 0; j--)
    {
        printf("%d", binary[j]);
        fprintf(file, "%d", binary[j]);
    }
    fprintf(file, "\n");
}

void binaryToDecimal(const char *binary, FILE *file)
{
    int decimal = 0, base = 1, len = strlen(binary);

    for (int i = len - 1; i >= 0; i--)
    {
        if (binary[i] == '1')
            decimal += base;
        base *= 2;
    }

    printf("%d", decimal);
    fprintf(file, "%d\n", decimal);
}

void decimalToOctal(int decimal, FILE *file)
{
    if (decimal == 0)
    {
        printf("0");
        fprintf(file, "0");
        return;
    }

    int octal[32], i = 0;
    while (decimal > 0)
    {
        octal[i++] = decimal % 8;
        decimal /= 8;
    }

    for (int j = i - 1; j >= 0; j--)
    {
        printf("%d", octal[j]);
        fprintf(file, "%d", octal[j]);
    }
    fprintf(file, "\n");
}

void octalToDecimal(const char *octal, FILE *file)
{
    int decimal = 0, base = 1, len = strlen(octal);

    for (int i = len - 1; i >= 0; i--)
    {
        decimal += (octal[i] - '0') * base;
        base *= 8;
    }

    printf("%d", decimal);
    fprintf(file, "%d\n", decimal);
}

void decimalToHexadecimal(int decimal, FILE *file)
{
    if (decimal == 0)
    {
        printf("0");
        fprintf(file, "0");
        return;
    }

    char hex[32];
    int i = 0;
    while (decimal > 0)
    {
        int temp = decimal % 16;
        hex[i++] = (temp < 10) ? temp + '0' : temp - 10 + 'A';
        decimal /= 16;
    }

    for (int j = i - 1; j >= 0; j--)
    {
        printf("%c", hex[j]);
        fprintf(file, "%c", hex[j]);
    }
    fprintf(file, "\n");
}

void hexadecimalToDecimal(const char *hex, FILE *file)
{
    int decimal = 0, base = 1, len = strlen(hex);

    for (int i = len - 1; i >= 0; i--)
    {
        int value = (hex[i] >= '0' && hex[i] <= '9') ? hex[i] - '0' : hex[i] - 'A' + 10;
        decimal += value * base;
        base *= 16;
    }

    printf("%d", decimal);
    fprintf(file, "%d\n", decimal);
}

void decimalToRoman(int decimal, FILE *file)
{
    if (decimal <= 0 || decimal > 3999)
    {
        printf("Invalid input (1-3999 only).\n");
        fprintf(file, "Invalid input (1-3999 only).\n");
        return;
    }

    struct Roman
    {
        int value;
        char symbol[3];
    } roman[] =
    {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
        {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
        {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
    };

    for (int i = 0; i < 13; i++)
    {
        while (decimal >= roman[i].value)
        {
            printf("%s", roman[i].symbol);
            fprintf(file, "%s", roman[i].symbol);
            decimal -= roman[i].value;
        }
    }
    fprintf(file, "\n");
}

void romanToDecimal(const char *roman, FILE *file)
{
    struct Roman
    {
        char symbol[3];
        int value;
    } romanSymbols[] =
    {
        {"M", 1000}, {"CM", 900}, {"D", 500}, {"CD", 400},
        {"C", 100}, {"XC", 90}, {"L", 50}, {"XL", 40},
        {"X", 10}, {"IX", 9}, {"V", 5}, {"IV", 4}, {"I", 1}
    };

    int length = strlen(roman);
    int decimal = 0, i = 0;

    while (i < length)
    {
        for (int j = 0; j < 13; j++)
        {
            if (strncmp(roman + i, romanSymbols[j].symbol, strlen(romanSymbols[j].symbol)) == 0)
            {
                decimal += romanSymbols[j].value;
                i += strlen(romanSymbols[j].symbol);
                break;
            }
        }
    }

    printf("%d", decimal);
    fprintf(file, "%d\n", decimal);
}

void unitConversion(FILE *file)
{
    int choice;
    float input, result;

    printf("\n* Unit Conversion *\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Meters to Kilometers\n");
    printf("4. Kilometers to Meters\n");
    printf("5. Kilograms to Pounds\n");
    printf("6. Pounds to Kilograms\n");
    printf("7. Centimeters to Inches\n");
    printf("8. Inches to Centimeters\n");
    printf("9. Meters to Feet\n");
    printf("10. Feet to Meters\n");
    printf("11. Liters to Gallons\n");
    printf("12. Gallons to Liters\n");
    printf("13. Radians to Degrees\n");
    printf("14. Degrees to Radians\n");
    printf("15. Light-years to Kilometers\n");
    printf("16. Light-years to Miles\n");
    printf("17. Currency Conversion\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        printf("Enter temperature in Celsius: ");
        scanf("%f", &input);
        result = (input * 9 / 5) + 32;
        printf("Temperature in Fahrenheit: %.2f\n", result);
        fprintf(file, "Celsius to Fahrenheit: %.2f Celsius = %.2f Fahrenheit\n", input, result);
        break;
    case 2:
        printf("Enter temperature in Fahrenheit: ");
        scanf("%f", &input);
        result = (input - 32) * 5 / 9;
        printf("Temperature in Celsius: %.2f\n", result);
        fprintf(file, "Fahrenheit to Celsius: %.2f Fahrenheit = %.2f Celsius\n", input, result);
        break;
    case 3:
        printf("Enter length in meters: ");
        scanf("%f", &input);
        result = input / 1000;
        printf("Length in kilometers: %.3f\n", result);
        fprintf(file, "Meters to Kilometers: %.3f meters = %.3f kilometers\n", input, result);
        break;
    case 4:
        printf("Enter length in kilometers: ");
        scanf("%f", &input);
        result = input * 1000;
        printf("Length in meters: %.3f\n", result);
        fprintf(file, "Kilometers to Meters: %.3f kilometers = %.3f meters\n", input, result);
        break;
    case 5:
        printf("Enter weight in kilograms: ");
        scanf("%f", &input);
        result = input * 2.20462;
        printf("Weight in pounds: %.3f\n", result);
        fprintf(file, "Kilograms to Pounds: %.3f kg = %.3f lbs\n", input, result);
        break;
    case 6:
        printf("Enter weight in pounds: ");
        scanf("%f", &input);
        result = input / 2.20462;
        printf("Weight in kilograms: %.3f\n", result);
        fprintf(file, "Pounds to Kilograms: %.3f lbs = %.3f kg\n", input, result);
        break;
    case 7:
        printf("Enter length in centimeters: ");
        scanf("%f", &input);
        result = input / 2.54;
        printf("Length in inches: %.3f\n", result);
        fprintf(file, "Centimeters to Inches: %.3f cm = %.3f inches\n", input, result);
        break;
    case 8:
        printf("Enter length in inches: ");
        scanf("%f", &input);
        result = input * 2.54;
        printf("Length in centimeters: %.3f\n", result);
        fprintf(file, "Inches to Centimeters: %.3f inches = %.3f cm\n", input, result);
        break;
    case 9:
        printf("Enter length in meters: ");
        scanf("%f", &input);
        result = input * 3.28084;
        printf("Length in feet: %.3f\n", result);
        fprintf(file, "Meters to Feet: %.3f meters = %.3f feet\n", input, result);
        break;
    case 10:
        printf("Enter length in feet: ");
        scanf("%f", &input);
        result = input / 3.28084;
        printf("Length in meters: %.3f\n", result);
        fprintf(file, "Feet to Meters: %.3f feet = %.3f meters\n", input, result);
        break;
    case 11:
        printf("Enter volume in liters: ");
        scanf("%f", &input);
        result = input * 0.264172;
        printf("Volume in gallons: %.3f\n", result);
        fprintf(file, "Liters to Gallons: %.3f liters = %.3f gallons\n", input, result);
        break;
    case 12:
        printf("Enter volume in gallons: ");
        scanf("%f", &input);
        result = input / 0.264172;
        printf("Volume in liters: %.3f\n", result);
        fprintf(file, "Gallons to Liters: %.3f gallons = %.3f liters\n", input, result);
        break;
    case 13:
        printf("Enter angle in radians: ");
        scanf("%f", &input);
        result = input * (180.0 / 3.141592653589793);
        printf("Angle in degrees: %.3f\n", result);
        fprintf(file, "Radians to Degrees: %.3f radians = %.3f degrees\n", input, result);
        break;
    case 14:
        printf("Enter angle in degrees: ");
        scanf("%f", &input);
        result = input * (3.141592653589793 / 180.0);
        printf("Angle in radians: %.3f\n", result);
        fprintf(file, "Degrees to Radians: %.3f degrees = %.3f radians\n", input, result);
        break;
    case 15:
        printf("Enter distance in light-years: ");
        scanf("%f", &input);
        result = input * 9.4607e12;
        printf("Distance in kilometers: %.3e\n", result);
        fprintf(file, "Light-years to Kilometers: %.3f light-years = %.3e kilometers\n", input, result);
        break;
    case 16:
        printf("Enter distance in light-years: ");
        scanf("%f", &input);
        result = input * 5.8786e12;
        printf("Distance in miles: %.3e\n", result);
        fprintf(file, "Light-years to Miles: %.3f light-years = %.3e miles\n", input, result);
        break;
    case 17:
        convertCurrency();
        break;
    default:
        printf("Invalid choice.\n");
    }
}


void fillMatrix(int rows, int cols, int matrix[rows][cols])
{
    printf("Enter elements of the matrix (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("Element [%d][%d]: ", i+1, j+1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int rows, int cols, int matrix[rows][cols])
{
    printf("\nMatrix (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%4d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void printMatrixFloat(int rows, int cols, float matrix[rows][cols])
{
    printf("\nMatrix (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%7.2f ", matrix[i][j]);
        }
        printf("\n");
    }
}

void transposeMatrix(int rows, int cols, int matrix[rows][cols], int transpose[cols][rows])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            transpose[j][i] = matrix[i][j];
        }
    }
}

int inverseMatrix2x2(int matrix[2][2], float inverse[2][2])
{
    int determinant = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    if (determinant == 0)
    {
        printf("Matrix is singular, cannot find its inverse.\n");
        return 0;
    }
    float detInv = 1.0 / determinant;
    inverse[0][0] = detInv * matrix[1][1];
    inverse[0][1] = -detInv * matrix[0][1];
    inverse[1][0] = -detInv * matrix[1][0];
    inverse[1][1] = detInv * matrix[0][0];
    return 1;
}

void calculateEigenvalues2x2(int matrix[2][2])
{
    float trace = matrix[0][0] + matrix[1][1];
    float determinant = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    float discriminant = trace * trace - 4 * determinant;

    if (discriminant < 0)
    {
        printf("Eigenvalues are complex:\n");
        float realPart = trace / 2;
        float imaginaryPart = sqrt(-discriminant) / 2;
        printf("lambda1 = %.2f + %.2fi\n", realPart, imaginaryPart);
        printf("lambda2 = %.2f - %.2fi\n", realPart, imaginaryPart);
    }
    else
    {
        printf("Eigenvalues are real:\n");
        float lambda1 = (trace + sqrt(discriminant)) / 2;
        float lambda2 = (trace - sqrt(discriminant)) / 2;
        printf("lambda1 = %.2f\n", lambda1);
        printf("lambda2 = %.2f\n", lambda2);
    }
}

void matrixOperations()
{
    int choice;
    printf("\n* Matrix Operations *\n");
    printf("1. Matrix Addition\n");
    printf("2. Matrix Subtraction\n");
    printf("3. Matrix Multiplication\n");
    printf("4. Matrix Transpose\n");
    printf("5. Matrix Inverse (2x2 only)\n");
    printf("6. Eigenvalues (2x2 only)\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    int rows1, cols1, rows2, cols2;
    printf("Enter rows and columns for matrix 1: ");
    scanf("%d%d", &rows1, &cols1);

    int matrix1[rows1][cols1];
    fillMatrix(rows1, cols1, matrix1);

    if (choice == 1 || choice == 2 || choice == 3)
    {
        printf("Enter rows and columns for matrix 2: ");
        scanf("%d%d", &rows2, &cols2);

        int matrix2[rows2][cols2];
        fillMatrix(rows2, cols2, matrix2);

        if (choice == 1 && rows1 == rows2 && cols1 == cols2)
        {
            int result[rows1][cols1];
            for (int i = 0; i < rows1; i++)
            {
                for (int j = 0; j < cols1; j++)
                {
                    result[i][j] = matrix1[i][j] + matrix2[i][j];
                }
            }
            printf("\nMatrix Addition Result:\n");
            printMatrix(rows1, cols1, result);
        }
        else if (choice == 2 && rows1 == rows2 && cols1 == cols2)
        {
            int result[rows1][cols1];
            for (int i = 0; i < rows1; i++)
            {
                for (int j = 0; j < cols1; j++)
                {
                    result[i][j] = matrix1[i][j] - matrix2[i][j];
                }
            }
            printf("\nMatrix Subtraction Result:\n");
            printMatrix(rows1, cols1, result);
        }
        else if (choice == 3 && cols1 == rows2)
        {
            int result[rows1][cols2];
            for (int i = 0; i < rows1; i++)
            {
                for (int j = 0; j < cols2; j++)
                {
                    result[i][j] = 0;
                    for (int k = 0; k < cols1; k++)
                    {
                        result[i][j] += matrix1[i][k] * matrix2[k][j];
                    }
                }
            }
            printf("\nMatrix Multiplication Result:\n");
            printMatrix(rows1, cols2, result);
        }
        else
        {
            printf("Invalid dimensions for the selected operation.\n");
        }
    }
    else if (choice == 4)
    {
        int transpose[cols1][rows1];
        transposeMatrix(rows1, cols1, matrix1, transpose);
        printf("\nMatrix Transpose Result:\n");
        printMatrix(cols1, rows1, transpose);
    }
    else if (choice == 5 && rows1 == 2 && cols1 == 2)
    {
        float inverse[2][2];
        if (inverseMatrix2x2(matrix1, inverse))
        {
            printf("\nMatrix Inverse Result:\n");
            printMatrixFloat(2, 2, inverse);
        }
    }
    else if (choice == 6 && rows1 == 2 && cols1 == 2)
    {
        calculateEigenvalues2x2(matrix1);
    }
    else
    {
        printf("Operation is only implemented for specific dimensions.\n");
    }
}
