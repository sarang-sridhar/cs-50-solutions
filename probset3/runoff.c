include <cs50.h>
#include <stdio.h>
#include <string.h>

#define MAX_VOTERS 100
#define MAX_CANDIDATES 9


int preferences[MAX_VOTERS][MAX_CANDIDATES];


typedef struct  // name, votes and whether candidate is eliminated
{
    string name;
    int votes;
    bool eliminated;
}
candidate;


candidate candidates[MAX_CANDIDATES];


int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    
    for (int i = 0; i < voter_count; i++) // getting all votes
    {

        
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    
    while (true)  // hold runoff till winner obtained
    {
        
        tabulate();

        
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}


bool vote(int voter, int rank, string name)  // store preferences if vote is valid
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name,  candidates[i].name) == 0)
        {
            preferences[voter][rank] = i;
            return true;
        }
    }
    return false;
}


void tabulate(void)
{
    for (int j = 0; j < voter_count; j++)
    {
        int i = 0;
        // for every voter loops until I find a candidate that it is still in the race
        while (candidates[preferences[j][i]].eliminated)
        {
            i++;
        }
        // then add one vote for that candidate
        candidates[preferences[j][i]].votes++;
    }
    return;
}


bool print_winner(void)  //print winner 
{
    for (int j = 0; j < candidate_count; j++)
    {
        if (candidates[j].votes > voter_count / 2)
        {
            printf("%s\n", candidates[j].name);
            return true;
        }
    }
    return false;
}


int find_min(void)  // retur minimum votes any candidate has 
{
    int minimumVotes = 101;
    for (int i = 0; i < candidate_count; i++)
    {
        if (!candidates[i].eliminated)
        {
            if (candidates[i].votes < minimumVotes)
            {
                minimumVotes = candidates[i].votes;
            }
        }
    }
    return minimumVotes;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    int votesWinner = 0;
    // stores value of the number of most votes
    for (int j = 0; j < candidate_count; j++)
    {
        if (candidates[j].votes > votesWinner)
        {
            votesWinner = candidates[j].votes;
        }
    }

    for (int i = 0; i < candidate_count; i++)
    {
        if (!candidates[i].eliminated)
        {
            if (candidates[i].votes < votesWinner)
            {
                return false;
            }
        }
    }
    return true;
}


void eliminate(int min)   // eliminate candidates in last place
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == min)
        {
            candidates[i].eliminated = true;
        }
    }

    return;
}
