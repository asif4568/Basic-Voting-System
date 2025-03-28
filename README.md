# Basic-Voting-System
# Advanced Voting System

A secure command-line voting system application written in C that implements voter registration, authentication, and secure voting procedures.

## Features

- **Election Setup**
  - Configure up to 10 candidates
  - Set candidate names and initialize vote counts

- **Voter Registration**
  - Register up to 100 voters
  - Store voter details (name, password, age)
  - Age verification (minimum 18 years)
  - Unique voter credentials

- **Secure Voting Process**
  - Voter authentication (login required)
  - One vote per registered voter
  - Prevention of duplicate voting
  - Candidate selection validation

- **Comprehensive Results**
  - Individual candidate vote counts
  - Total voter statistics
  - Voter turnout information
  - Winner determination with tie detection

## How to Compile

To compile the program, use the following command:

```
gcc -o voting_system voting_system.c
```

## How to Run

After compiling, run the program:

```
./voting_system
```

## Usage Instructions

1. **Setup Election** (Option 1)
   - Enter the number of candidates (1-10)
   - Input names for each candidate

2. **Register Voters** (Option 2)
   - Enter the number of voters to register
   - For each voter:
     - Enter name
     - Set password
     - Enter age (must be 18 or older)

3. **Vote** (Option 3)
   - Login with registered credentials
   - Select a candidate from the list
   - Confirm vote submission

4. **View Results** (Option 4)
   - See individual candidate vote counts
   - View voter turnout statistics
   - Check for election winner or ties

5. **Exit** (Option 5)
   - Safely terminate the program

## Sample Output

```
==== Voting System Main Menu ====
1. Setup Election
2. Register Voters
3. Voter Login & Vote
4. Show Results
5. Exit
Enter your choice: 1

--- Election Setup ---
Enter number of candidates (max 10): 3
Enter name for candidate 1: John
Enter name for candidate 2: Sarah
Enter name for candidate 3: Michael
Election setup complete.

[... registration and voting process ...]

=== Election Results ===
Candidate John received 5 votes.
Candidate Sarah received 3 votes.
Candidate Michael received 2 votes.

Total registered voters: 10
Voters who have voted: 10
Voters who have not voted: 0

The winner is John with 5 votes.
```

## Security Features

- Password-protected voter accounts
- Prevention of duplicate voting
- Age verification for voter registration
- Input validation for all user entries

## Requirements

- C compiler (gcc recommended)
- No external libraries required
- Command-line interface 
