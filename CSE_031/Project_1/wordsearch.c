#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// =============================================== STRATEGY ===============================================
// 1. Create an array 'firstOccurrences' of Position structs for every possible board position.
// 2. Append the board position of each first letter occurrence of the word to 'firstOccurrences'.
// 3. Create a 2D array 'results', each row containing the path of the word starting from the first letter.
// 4. Recursively search surrounding positions of a letter starting from each first letter occurence,
//    appending the position of the next letter of 'word' found to the corresponding row in 'results'.
// 5. Print out each path in 'results' if the path is complete (Positions with -1 signal incomplete paths).
// ========================================================================================================

// Declarations of the two functions you will implement
// Feel free to declare any helper functions or global variables
typedef struct {
    int row;
    int col;
} Position;

void printPuzzle(char** arr);
void searchPuzzle(char** arr, char* word);
void printFinalPuzzle(int** arr);
void scanPosition(char **block, Position **results, char *word, Position pos, int resultIndex, int wordIndex);
int bSize;

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
            printf("%c ", *(*(arr+i)+j));
        }
        printf("%c\n", *(*(arr+i)+bSize-1));
    }
    printf("\n");
}

void printFinalPuzzle(int** arr) {
    for (int i = 0; i < bSize; i++) {
        for (int j = 0; j < bSize-1; j++) {
            printf("%-6d", *(*(arr+i)+j));
        }
        printf("%d\n", *(*(arr+i)+bSize-1));
    }
}

char toUpper(char c) {
    return (c >= 'a' && c <= 'z') ? c-32 : c;
}

void scanPosition(char **block, Position **results, char *word, Position pos, int resultIndex, int wordIndex) {
    // Recursion terminates if the path is complete or the next letter is not found.
    if (wordIndex < strlen(word)) {
        for (int i = -1; i < 2; i++) {
            for (int j = -1; j < 2; j++) {
                if (i == 0 && j == 0) { // Skip center(current) position
                    continue;
                } else if (pos.row+i < 0 || pos.row+i >= bSize || pos.col+j < 0 || pos.col+j >= bSize) { // Skip out of bounds
                    continue;
                } else if (toUpper(*(*(block+pos.row+i)+pos.col+j)) != toUpper(*(word+wordIndex))) { // Skip incorrect letters
                    continue;
                }

                // Append the position of a successful match to the path, then recursively search from that 
                Position foundPosition = (Position) {pos.row+i, pos.col+j};
                *(*(results+resultIndex)+wordIndex) = foundPosition;
                scanPosition(block, results, word, foundPosition, resultIndex, wordIndex+1);
            } 
        }
    }
}

void searchPuzzle(char** arr, char* word) {
    // This function checks if arr contains the search word. If the 
    // word appears in arr, it will print out a message and the path 
    // as shown in the sample runs. If not found, it will print a 
    // different message as shown in the sample runs.
    // Your implementation here...
    
    // Allocate memory for arrays to store first occurrences and path results
    int numFirstOccur = 0;
    int numPaths = 0;
    int **finalBlock = (int**) malloc(bSize * sizeof(int*));
    Position *firstOccurrences = (Position*) malloc((bSize*bSize)*(sizeof(Position)));
    Position **results = (Position**) malloc(numFirstOccur*(sizeof(Position*)));

    // Find all occurrences of the first letter of the word on the board
    for (int i = 0; i < bSize; i++) {
        for (int j = 0; j < bSize; j++) {
            if (toUpper(*(*(arr+i)+j)) == toUpper(*word)) {
                *(firstOccurrences+numFirstOccur) = (Position) {i, j};
                numFirstOccur++;
            }
        }
    }

    // Initialize Position structs in path arrays to the length of the word with -1 values
    for (int i = 0; i < numFirstOccur; i++) {
        *(results+i) = (Position*) malloc((strlen(word))*(sizeof(Position)));
        for (int j = 1; j < strlen(word); j++) {
            *(*(results+i)+j) = (Position) {-1, -1};
        }
        *(*(results+i)) = *(firstOccurrences+i); // Set the first position of each path to the first occurrence
    }

    // Initialize the finalBlock board values to 0
    for (int i = 0; i < bSize; i++) {
        *(finalBlock+i) = (int*) malloc(bSize * (sizeof(int)));
        for (int j = 0; j < bSize; j++) {
            *(*(finalBlock+i)+j) = 0;
        }
    }

    // For each first letter occurrence check if the word is in the puzzle
    for (int i = 0; i < numFirstOccur; i++) {
        scanPosition(arr, results, word, *(firstOccurrences+i), i, 1);
    }

    // Done with original input block array and firstOccurrences array
    free(arr);

    // Fill in finalBlock with the results
    for (int i = 0; i < numFirstOccur; i++) {
        // Skip incomplete paths
        if ((*(results+i)+strlen(word)-1)->row == -1) {
            continue;
        }

        // Fill in positions with the path number, concatenate values if the position is already filled
        for (int j = 0; j < strlen(word); j++) {
            int *currentPos = *(finalBlock+(*(results+i)+j)->row)+(*(results+i)+j)->col;
            *currentPos = *currentPos ? (j+1) * pow(10, (int)log10(*currentPos) + 1) + *currentPos : (j+1);
        }

        numPaths++;
    }

    // Done with input word and results array
    free(word);
    free(results);

    if (numPaths) {
        printf("Word found!\nPrinting the search path:\n");
        printFinalPuzzle(finalBlock);
    } else {
        printf("Word not found!");
    }
}
