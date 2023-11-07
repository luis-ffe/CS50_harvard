#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates

#define MAX 9

// Candidates have name and vote count

typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates

candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes

bool vote(string name);
void print_winner(void);




int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Test if the limit was not breached

    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }

//populate the array / struct


    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    //now that the array has been populated the votes can be sent and counted

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}



// Update vote totals given a new vote


bool vote(string name)
{
    for ( int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}




// Print the winner (or winners) of the election

void print_winner(void)
{
    string win[candidate_count];
    int arr[candidate_count];
    int high_vote = 0;

    for ( int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > arr[0])
        {
            arr[0] = candidates[i].votes;
            win[0] = candidates[i].name;
        }
    }

    high_vote =arr[0];

    //a funçao anterior guarda o voto mais alto em arr(0)  e compara todos os outros com ele para encontrar um maior
    //quando o encontra para mas guarda o nome do candidato no array winner index 0
    //para nao mexer no valor mais alto encontrado agora pegamos no index acima de 0.

    for ( int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == high_vote)
        {
            int c = 0;
            win[c] = candidates[i].name;
            c++;
        }

    }

    for ( int i = 0; i < candidate_count; i++)
    {
        printf("%s\n", win[i]);
    }

    return;
}