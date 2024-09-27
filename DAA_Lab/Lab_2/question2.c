#include <stdio.h>
#include <stdlib.h>
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
void processGCD(FILE *inFile, FILE *outFile)
{
    int num1, num2;
    while (fscanf(inFile, "%d %d", &num1, &num2) != EOF)
    {
        int result = gcd(num1, num2);
        fprintf(outFile, "The GCD of %d and %d is %d\n", num1, num2, result);
    }
}
int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: %s <source file> <destination file>\n", argv[0]);
        return 1;
    }
    char *sourceFileName = argv[1];
    char *destFileName = argv[2];
    FILE *inFile = fopen("C:\\Users\\KIIT\\Documents\\Coding\\DSA_LAB\\DAA_Lab\\Lab_2\\input2.dat", "r");
    if (inFile == NULL)
    {
        perror("Error opening source file");
        return 1;
    }
    FILE *outFile = fopen("C:\\Users\\KIIT\\Documents\\Coding\\DSA_LAB\\DAA_Lab\\Lab_2\\output3.dat", "w");
    if (outFile == NULL)
    {
        perror("Error opening destination file");
        fclose(inFile);
        return 1;
    }
    processGCD(inFile, outFile);
    fclose(inFile);
    fclose(outFile);
    printf("GCD calculation completed. Check the output file: %s\n", destFileName);
    return 0;
}
