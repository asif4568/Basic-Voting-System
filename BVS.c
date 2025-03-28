#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_C 10       // Maximum number of candidates
#define MAX_VOTERS 100 // Maximum number of voters

typedef struct {char name[50];int votes;} Candidate;   // Candidate structure 
typedef struct {char name[50];  char password[50];  int age;    int voted; // 0 if not voted, 1 if voted
} Voter;   // Voter structure 

Candidate candidates[MAX_C]; int candidateCount = 0;
Voter voters[MAX_VOTERS]; int voterCount = 0;

void setupElection(void); void registerVoters(void); void voterMenu(void); void showResults(void);

// Setup election by entering candidates
void setupElection(void) {
    printf("\n--- Election Setup ---\n");
    printf("Enter number of candidates (max %d): ", MAX_C); scanf("%d", &candidateCount);
     if (candidateCount < 1 || candidateCount > MAX_C) {
        printf("Invalid number of candidates. Election setup aborted.\n");
        candidateCount = 0; return;
    }
    for (int i = 0; i < candidateCount; i++) {
        printf("Enter name for candidate %d: ", i + 1); scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }
    printf("Election setup complete.\n");
}

// Register voters
void registerVoters(void) { 
    int num;
    printf("\n--- Voter Registration ---\n");
    printf("Enter number of voters to register: "); scanf("%d", &num); 
    for (int i = 0; i < num; i++) {
        if (voterCount >= MAX_VOTERS) {
            printf("Voter registration limit reached.\n");  break;
        }
        printf("Enter name for voter %d: ", voterCount + 1);    scanf("%s", voters[voterCount].name);
        printf("Enter password for voter %d: ", voterCount + 1);    scanf("%s", voters[voterCount].password);
        printf("Enter age for voter %d: ", voterCount + 1); scanf("%d", &voters[voterCount].age);
        if (voters[voterCount].age < 18) {
            printf("Voter must be at least 18 years old. %s not registered.\n", voters[voterCount].name);
        } else {
            voters[voterCount].voted = 0;
            printf("Voter %s registered successfully.\n", voters[voterCount].name);
            voterCount++;
        }
    }
}

// Voter login and voting process
void voterMenu(void) {
    char name[50], pass[50];    int foundIndex = -1;
    printf("\n--- Voter Login ---\n");
    printf("Enter voter name: ");   scanf("%s", name);
    printf("Enter voter password: ");   scanf("%s", pass);
    for (int i = 0; i < voterCount; i++) {
        if (strcmp(name, voters[i].name) == 0 && strcmp(pass, voters[i].password) == 0) {
            foundIndex = i; break;
        }
    }
    if (foundIndex == -1) {
        printf("Invalid voter credentials. Please register first\n"); return;
    }
    if (voters[foundIndex].voted == 1) {
        printf("You have already voted.\n"); return;
    }
    if (candidateCount == 0) {
        printf("Election is not set up yet.\n"); return;
    }
    printf("\n--- Voting ---\n");
    for (int j = 0; j < candidateCount; j++) {
        printf("%d. %s\n", j + 1, candidates[j].name);
    }
    int choice;
    printf("Enter your vote (candidate number): "); scanf("%d", &choice);
    if (choice < 1 || choice > candidateCount) {
        printf("Invalid candidate choice.\n"); return;
    }
    candidates[choice - 1].votes++;voters[foundIndex].voted = 1;
    printf("Your vote for %s has been recorded.\n", candidates[choice - 1].name);
}

// Show election results
void showResults(void) {
    printf("\n=== Election Results ===\n");
    if (candidateCount == 0) {  printf("Election not set up or no candidates registered.\n");
    } else {
        for (int i = 0; i < candidateCount; i++) {
            printf("Candidate %s received %d votes.\n", candidates[i].name, candidates[i].votes);
        }
    }
    int votedCount = 0, notVotedCount = 0;
    for (int i = 0; i < voterCount; i++) {
        if (voters[i].voted == 1) votedCount++;
        else notVotedCount++;
    }
    printf("\nTotal registered voters: %d\n", voterCount);
    printf("Voters who have voted: %d\n", votedCount);
    printf("Voters who have not voted: %d\n", notVotedCount);
    if (candidateCount > 0) {
        int maxVotes = -1, winnerIndex = -1, tie = 0;
        for (int i = 0; i < candidateCount; i++) {
            if (candidates[i].votes > maxVotes) {
                maxVotes = candidates[i].votes; winnerIndex = i; tie = 0;
            } else if (candidates[i].votes == maxVotes) { tie = 1;
            }
        }
        if (maxVotes <= 0) {   printf("No votes were cast.\n");
        } else if (tie) {   printf("There is a tie between candidates.\n");
        } else {    printf("The winner is %s with %d votes.\n", candidates[winnerIndex].name, candidates[winnerIndex].votes);
        }
    }
}
int main(void) {    
    int choice;
    while (1) {
        printf("\n==== Voting System Main Menu ====\n");
        printf("1. Setup Election\n");  printf("2. Register Voters\n");
        printf("3. Voter Login & Vote\n");  printf("4. Show Results\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");  scanf("%d", &choice);
        switch(choice) {
            case 1: setupElection(); break;
            case 2: registerVoters(); break;
            case 3: voterMenu(); break;
            case 4: showResults(); break;
            case 5: printf("Exiting...\n"); exit(0);
            default: printf("Invalid choice, try again.\n");
        }
    }
    return 0;
}
