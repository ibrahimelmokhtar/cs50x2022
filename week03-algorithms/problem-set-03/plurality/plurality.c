#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Custom Types:
typedef struct {
    string name;
    int votes;
} candidate;

// Global Variables:
#define MAX 9
candidate candidates[MAX] = {};
int candidate_count = 0;

// Functions Declaration:
void initialize_candidates(void);
string capitalize_name(string);
void print_candidates(void);
void copy_candidates(int, string[]);
int voters_count(void);
void start_voting(int);
bool vote(string);
void sort_candidates(void);
void print_winner(void);

// Main Entry Point:
int main(int argc, string argv[]) {
    // Display appropriate error message, if needed:
    if (argc < 3) {
        printf("Error: Min number of candidates is 2\n");
        return 1;
    } else if (argc > MAX + 1) {
        printf("Error: Max number of candidates is %i\n", MAX);
        return 1;
    }

    // Initialize empty array of default candidates:
    initialize_candidates();

    // Fill candidates array with the actual values:
    copy_candidates(argc, argv);

    // Obtain voters count from the user:
    int voters_counter = voters_count();

    // Start the voting process:
    start_voting(voters_counter);

    // Sort candidates by votes first then by names:
    sort_candidates();

    // Display the winner(s):
    print_winner();

    return 0;
}

// Functions Implementation:
void initialize_candidates(void) {
    for (int i=0; i<MAX; i++) {
        candidates[i].name = "";
        candidates[i].votes = 0;
    }
}

string capitalize_name(string name) {
    name[0] = toupper(name[0]);
    for (int i=1; i<strlen(name); i++) {
        name[i] = tolower(name[i]);
    }

    return name;
}

void print_candidates(void) {
    printf("Candidates: ");
    for (int i=0; i<candidate_count; i++) {
        printf("( %s, %i )  ", candidates[i].name, candidates[i].votes);
    }
    printf("\n");
}

void copy_candidates(int argc, string argv[]) {
    for (int i=0; i<argc-1; i++) {
        candidates[i].name = capitalize_name(argv[i+1]);
        candidate_count++;
    }
}

int voters_count(void) {
    int voters = 0;
    do {
        voters = get_int("Number of voters: ");
    } while (voters <= 0);

    return voters;
}

void start_voting(int voters) {
    for (int i=0; i<voters; i++) {
        string name = get_string("Vote: ");
        name = capitalize_name(name);
        bool is_found = vote(name);
        if (!is_found) {
            printf("Invalid vote.\n");
        }
    }
}

bool vote(string name) {
    for (int i=0; i<candidate_count; i++) {
        if (strcmp(candidates[i].name, name) == 0) {
            candidates[i].votes++;
            return true;
        }
    }

    return false;
}

void sort_candidates(void) {
    // Sort candidates by votes: (using Selection Sort)
    for (int i=0; i<candidate_count; i++) {
        int max_votes = candidates[i].votes;
        int max_index = i;
        for (int j=i+1; j<candidate_count; j++) {
            if (candidates[j].votes > max_votes) {
                max_votes = candidates[j].votes;
                max_index = j;
            }
        }
        // Swap these TWO candidates:
        candidate temp = candidates[i];
        candidates[i] = candidates[max_index];
        candidates[max_index] = temp;
    }

    // Sort similarly-voted candidates by names: (using Bubble Sort)
    for (int i=0; i<candidate_count-1; i++) {
        bool is_swapped = false;
        for (int j=0; j<candidate_count-1-i; j++) {
            if (candidates[j].votes == candidates[j+1].votes) {
                if (strcmp(candidates[j].name, candidates[j+1].name) == 1) {
                    is_swapped = true;
                    // Swap these TWO candidates:
                    candidate temp = candidates[j];
                    candidates[j] = candidates[j+1];
                    candidates[j+1] = temp;
                }
            }
        }
        if (!is_swapped) {
            break;
        }
    }
}

void print_winner(void) {
    printf(">>> Winner(s):\n");
    int max_votes = candidates[0].votes;
    for (int i=0; i<candidate_count; i++) {
        if (candidates[i].votes == max_votes) {
            printf("  %i. %s: %i votes\n", i+1, candidates[i].name, candidates[i].votes);
        }
    }
}
