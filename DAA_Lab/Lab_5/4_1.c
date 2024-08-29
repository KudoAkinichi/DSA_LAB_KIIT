#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100

// Define the struct person
struct person
{
    int id;
    char name[MAX_NAME_LENGTH];
    int age;
    int height;
    int weight;
};

// Function prototypes
void read_data(struct person **students, int *n, const char *filename);
void create_min_heap(struct person *students, int n);
void create_max_heap(struct person *students, int n);
void display_youngest_weight(struct person *students, int n);
void insert_person(struct person **students, int *n, struct person new_person);
void delete_oldest_person(struct person *students, int *n);
void heapify_min(struct person *students, int n, int i);
void heapify_max(struct person *students, int n, int i);

int main()
{
    int option, n = 0;
    struct person *students = NULL;

    while (1)
    {
        printf("MAIN MENU (HEAP)\n");
        printf("1. Read Data\n");
        printf("2. Create a Min-heap based on the age\n");
        printf("3. Create a Max-heap based on the weight\n");
        printf("4. Display weight of the youngest person\n");
        printf("5. Insert a new person into the Min-heap\n");
        printf("6. Delete the oldest person\n");
        printf("7. Exit\n");
        printf("Enter option: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            read_data(&students, &n, "students.txt");
            break;
        case 2:
            create_min_heap(students, n);
            printf("Min-heap created based on age.\n");
            break;
        case 3:
            create_max_heap(students, n);
            printf("Max-heap created based on weight.\n");
            break;
        case 4:
            display_youngest_weight(students, n);
            break;
        case 5:
        {
            struct person new_person;
            printf("Enter new person details (ID, Name, Age, Height, Weight):\n");
            scanf("%d", &new_person.id);
            getchar(); // Consume newline
            fgets(new_person.name, MAX_NAME_LENGTH, stdin);
            new_person.name[strcspn(new_person.name, "\n")] = 0; // Remove newline
            scanf("%d %d %d", &new_person.age, &new_person.height, &new_person.weight);
            insert_person(&students, &n, new_person);
            printf("New person inserted into the Min-heap.\n");
            break;
        }
        case 6:
            delete_oldest_person(students, &n);
            printf("Oldest person deleted.\n");
            break;
        case 7:
            free(students);
            return 0;
        default:
            printf("Invalid option. Please try again.\n");
        }
    }
    return 0;
}

// Function to read data from a file
void read_data(struct person **students, int *n, const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (!file)
    {
        printf("Unable to open file.\n");
        return;
    }

    fscanf(file, "%d", n);
    *students = (struct person *)malloc(*n * sizeof(struct person));

    for (int i = 0; i < *n; i++)
    {
        fscanf(file, "%d", &(*students)[i].id);
        fgetc(file); // Consume newline
        fgets((*students)[i].name, MAX_NAME_LENGTH, file);
        (*students)[i].name[strcspn((*students)[i].name, "\n")] = 0; // Remove newline
        fscanf(file, "%d %d %d", &(*students)[i].age, &(*students)[i].height, &(*students)[i].weight);
    }

    fclose(file);
}

// Function to create a min-heap based on age
void create_min_heap(struct person *students, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify_min(students, n, i);
}

// Function to create a max-heap based on weight
void create_max_heap(struct person *students, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify_max(students, n, i);
}

// Function to display the weight of the youngest person
void display_youngest_weight(struct person *students, int n)
{
    if (n == 0)
    {
        printf("No data available.\n");
        return;
    }
    printf("Weight of youngest student: %.2f kg\n", students[0].weight * 0.453592);
}

// Function to insert a new person into the min-heap
void insert_person(struct person **students, int *n, struct person new_person)
{
    *n += 1;
    *students = (struct person *)realloc(*students, *n * sizeof(struct person));
    int i = *n - 1;
    while (i > 0 && (*students)[(i - 1) / 2].age > new_person.age)
    {
        (*students)[i] = (*students)[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    (*students)[i] = new_person;
}

// Function to delete the oldest person
void delete_oldest_person(struct person *students, int *n)
{
    if (*n == 0)
    {
        printf("No data available.\n");
        return;
    }
    students[0] = students[--(*n)];
    heapify_min(students, *n, 0);
}

// Function to heapify a subtree with root at index i (min-heap)
void heapify_min(struct person *students, int n, int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && students[left].age < students[smallest].age)
        smallest = left;

    if (right < n && students[right].age < students[smallest].age)
        smallest = right;

    if (smallest != i)
    {
        struct person temp = students[i];
        students[i] = students[smallest];
        students[smallest] = temp;
        heapify_min(students, n, smallest);
    }
}

// Function to heapify a subtree with root at index i (max-heap)
void heapify_max(struct person *students, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && students[left].weight > students[largest].weight)
        largest = left;

    if (right < n && students[right].weight > students[largest].weight)
        largest = right;

    if (largest != i)
    {
        struct person temp = students[i];
        students[i] = students[largest];
        students[largest] = temp;
        heapify_max(students, n, largest);
    }
}
