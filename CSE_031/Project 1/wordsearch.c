#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declarations of the two functions you will implement
// Feel free to declare any helper functions or global variables
void printPuzzle(char** arr);
void searchPuzzle(char** arr, char* word);
void printPath();
int bSize;
typedef struct {
    int row;
    int col;
} Position;

// Main function, DO NOT MODIFY 	
int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <puzzle file name>\n", argv[0]);
        return 2;
    }
    int i, j;
    FILE *fptr;

    // Open file for reading puzzle
    fptr = fopen(argv[1], "r");
    if (fptr == NULL) {
        printf("Cannot Open Puzzle File!\n");
        return 0;
    }

    // Read the size of the puzzle block
    fscanf(fptr, "%d\n", &bSize);
    
    // Allocate space for the puzzle block and the word to be searched
    char **block = (char**)malloc(bSize * sizeof(char*));
    char *word = (char*)malloc(20 * sizeof(char));

    // Read puzzle block into 2D arrays
    for(i = 0; i < bSize; i++) {
        *(block + i) = (char*)malloc(bSize * sizeof(char));
        for (j = 0; j < bSize - 1; ++j) {
            fscanf(fptr, "%c ", *(block + i) + j);            
        }
        fscanf(fptr, "%c \n", *(block + i) + j);
    }
    fclose(fptr);

    printf("Enter the word to search: ");
    scanf("%s", word);
    
    // Print out original puzzle grid
    printf("\nPrinting puzzle before search:\n");
    printPuzzle(block);
    
    // Call searchPuzzle to the word in the puzzle
    searchPuzzle(block, word);
    
    return 0;
}

void printPuzzle(char** arr) {
	// This function will print out the complete puzzle grid (arr). 
    // It must produce the output in the SAME format as the samples 
    // in the instructions.
    // Your implementation here...
    for (int i = 0; i < bSize; i++) {
        for (int j = 0; j < bSize-1; j++) {
            printf("%c ", arr[i][j]);
        }
        printf("%c\n", arr[i][bSize-1]);
    }
    printf("\n");
}

void printPath() {

}

void scanPosition(Position **results, char *word, Position pos, int resultIndex, int wordIndex) {

}

void searchPuzzle(char** arr, char* word) {
    // This function checks if arr contains the search word. If the 
    // word appears in arr, it will print out a message and the path 
    // as shown in the sample runs. If not found, it will print a 
    // different message as shown in the sample runs.
    // Your implementation here...

    // Create an array of Position structs for every possible board position
    Position *firstOccurrences = (Position*) malloc((bSize*bSize)*(sizeof(Position)));

    // Find all occurrences of the first letter of the word
    int numFirstOccur = 0;
    for (int i = 0; i < bSize; i++) {
        for (int j = 0; j < bSize; j++) {
            if (arr[i][j] == word[0]) {
                *(firstOccurrences+numFirstOccur) = (Position) {i, j};
                numFirstOccur++;
            }
        }
    }

    // Create an array of Position paths for each first occurrence
    Position **results = (Position**) malloc((numFirstOccur)*(sizeof(Position*)));

    // Set each Position path to the length of the word
    for (int i = 0; i < numFirstOccur; i++) {
        *(results+i) = (Position*) malloc((strlen(word))*(sizeof(Position)));
        for (int j = 0; i < strlen(word); i++) {
            *(*(results+i)+j) = (Position) {-1, -1};
        }
    }

    // For each first occurrence, check if the word is in the puzzle
    for (int i = 0; i < numFirstOccur; i++) {
        scanPosition(results, word, *(firstOccurrences+i), 0, 0);
    }
}
