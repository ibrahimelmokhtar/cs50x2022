#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Max number of candidates:
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j:
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j:
bool locked[MAX][MAX];

// Each pair has a winner, loser:
typedef struct {
    int winner;
    int loser;
} pair;

// Array of candidates:
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes:
string capitalize_name(string);
bool vote(int, string, int[]);

void record_preferences(int[]);
void print_preferences();

void add_pairs(void);
void print_pairs(void);
void sort_pairs(void);

void lock_pairs(void);
void print_locked(void);

void print_winner(void);

// Main Entry Point:
int main(int argc, string argv[]) {
    // Check for invalid usage:
    if (argc < 2) {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates:
    candidate_count = argc - 1;
    if (candidate_count > MAX) {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }

    for (int i=0; i<candidate_count; i++) {
        candidates[i] = capitalize_name(argv[i+1]);
    }

    // Clear graph of locked in pairs:
    for (int i=0; i<candidate_count; i++) {
        for (int j=0; j<candidate_count; j++) {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes:
    for (int i=0; i<voter_count; i++) {
        // ranks[i] is voter's ith preference:
        int ranks[candidate_count];

        // Query for each rank:
        printf(">>> Voter #%i:\n", i+1);
        for (int j=0; j<candidate_count; j++) {
            string name = get_string("Rank %i: ", j + 1);
            name = capitalize_name(name);

            if (!vote(j, name, ranks)) {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    // print_preferences();

    add_pairs();
    sort_pairs();
    // print_pairs();

    lock_pairs();
    // print_locked();

    print_winner();

    return 0;
}

string capitalize_name(string name) {
    name[0] = toupper(name[0]);
    for (int i=1; i<strlen(name); i++) {
        name[i] = tolower(name[i]);
    }

    return name;
}

// Update ranks given a new vote:
bool vote(int rank, string name, int ranks[]) {
    // TODO
    for (int index=0; index<candidate_count; index++) {
        if (strcmp(candidates[index], name) == 0) {
            ranks[rank] = index;
            return true;
        }
    }

    return false;
}

// Update preferences given one voter's ranks:
void record_preferences(int ranks[]) {
    // TODO
    for (int i=0; i<candidate_count; i++) {
        for (int j=i; j<candidate_count; j++) {
            if (ranks[i] != ranks[j]) {
                preferences[ranks[i]][ranks[j]]++;
            }
        }
    }

    return;
}

void print_preferences() {
    printf(">>> Preferences:\n");
    for (int i=0; i<candidate_count; i++) {
        for (int j=0; j<candidate_count; j++) {
            printf("%i  ", preferences[i][j]);
        }
        printf("\n");
    }
}

// Record pairs of candidates where one is preferred over the other:
void add_pairs(void) {
    // TODO
    for (int i=0; i<=(candidate_count/2); i++) {
        for (int j=0; j<candidate_count; j++) {
            if ((j > i) && (preferences[i][j] != preferences[j][i])) {
                pair current_pair;
                if (preferences[i][j] > preferences[j][i]) {
                    current_pair.winner = i;
                    current_pair.loser = j;
                } else {
                    current_pair.winner = j;
                    current_pair.loser = i;
                }
                pairs[pair_count] = current_pair;
                pair_count++;
            }
        }
    }

    return;
}

// Sort pairs in decreasing order by strength of victory:
void sort_pairs(void) {
    // TODO
    for (int i=0; i<pair_count; i++) {
        int max_margin = -1, max_index = i;
        for (int j=i; j<pair_count; j++) {
            int winner = pairs[j].winner, loser = pairs[j].loser;
            int current_margin = preferences[winner][loser] - preferences[loser][winner];
            if (current_margin > max_margin) {
                max_margin = current_margin;
                max_index = j;
            }
        }
        // Swap these TWO pairs:
        pair temp = pairs[i];
        pairs[i] = pairs[max_index];
        pairs[max_index] = temp;
    }

    return;
}

void print_pairs(void) {
    printf(">>> Pairs:\n{ ");
    for (int i=0; i<pair_count; i++) {
        printf("( %i, %i )", pairs[i].winner, pairs[i].loser);
        (i != pair_count-1) ? printf(", ") : printf(" ");
    }
    printf("}\n");
}

// Lock pairs into the candidate graph in order, without creating cycles:
void lock_pairs(void) {
    // TODO
    for (int i=0; i<pair_count; i++) {
        int winner = pairs[i].winner, loser = pairs[i].loser;
        if (i != pair_count-1) {
            locked[winner][loser] = true;
        } else {
            bool won_before = false;
            for (int j=0; j<candidate_count-1; j++) {
                if (pairs[j].winner == winner) {
                    won_before = true;
                    break;
                }
            }
            if (won_before) {
                locked[winner][loser] = true;
            }
        }
    }

    return;
}

void print_locked() {
    printf(">>> Locked:\n");
    for (int i=0; i<candidate_count; i++) {
        for (int j=0; j<candidate_count; j++) {
            printf("%i  ", locked[i][j]);
        }
        printf("\n");
    }
}

// Print the winner of the election:
void print_winner(void) {
    // TODO
    for (int i=0; i<candidate_count; i++) {
        int count = 0;
        for (int j=0; j<candidate_count; j++) {
            if (locked[j][i] == false) {
                // this candidate did NOT lose this comparison:
                count++;
            }
        }
        if (count == candidate_count) {
            // this candidate did NOT lose any comparison:
            printf(">>> Winner: %s\n", candidates[i]);
            break;
        }
    }

    return;
}
