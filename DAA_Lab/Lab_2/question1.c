#include <stdio.h>
#include <stdlib.h>
void decToBinary(int num, char *binary, int index)
{
    if (num > 1)
    {
        decToBinary(num / 2, binary, index - 1);
    }
    binary[index] = (num % 2) + '0';
}
void writeBinaryToFile(FILE *outFile, int num)
{
    char binary[16] = "0000000000000000";
    decToBinary(num, binary, 15);
    fprintf(outFile, "The binary equivalent of %d is %s\n", num, binary);
}
int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("Usage: %s <n> <source file> <destination file>\n", argv[0]);
        return 1;
    }
    int n = atoi(argv[1]);
    char *sourceFileName = argv[2];
    char *destFileName = argv[3];
    FILE *inFile = fopen("C:\\Users\\KIIT\\Documents\\Coding\\DSA_LAB\\DAA_Lab\\Lab_2\\input1.dat", "r");
    if (inFile == NULL)
    {
        perror("Error opening source file");
        return 1;
    }
    FILE *outFile = fopen("C:\\Users\\KIIT\\Documents\\Coding\\DSA_LAB\\DAA_Lab\\Lab_2\\output2.dat", "w");
    if (outFile == NULL)
    {
        perror("Error opening destination file");
        fclose(inFile);
        return 1;
    }
    int num;
    for (int i = 0; i < n && fscanf(inFile, "%d", &num) != EOF; i++)
    {
        writeBinaryToFile(outFile, num);
    }
    fclose(inFile);
    fclose(outFile);
    outFile = fopen("C:\\Users\\KIIT\\Documents\\Coding\\DSA_LAB\\DAA_Lab\\Lab_2\\output2.dat", "r");
    if (outFile == NULL)
    {
        perror("Error opening destination file for reading");
        return 1;
    }
    char line[256];
    while (fgets(line, sizeof(line), outFile) != NULL)
    {
        printf("%s", line);
    }
    fclose(outFile);
    return 0;
}
