#include <cs50.h>
#include <stdio.h>
#include <string.h>

typedef struct{
    string name;
    int votes;
}candidate;

#define MAX 9
int candidate_count;
candidate candidates[MAX];


bool vote(string name)
{
    for (int a = 0; a < candidate_count; a++)
    {
        if (strcmp(candidates[a].name, name) == 0)
        {
            candidates[a].votes++;
            return true;
        }
    }
    return false;
}

void print_winner(){
int highest_votes = 0;

for (int i = 0; i < candidate_count; i++)
{
    if (candidates[i].votes > highest_votes)
    {
        highest_votes = candidates[i].votes;
    }
}

for (int i = 0; i < candidate_count; i++)
{
    if (candidates[i].votes == highest_votes)
    {
        printf("%s\n", candidates[i].name);
    }
}
}
int main(int argc, string argv[]){
    candidate_count = argc-1;
    for(int i=0; i<candidate_count;i++){
        candidates[i].name = argv[i + 1];
    }
    if (candidate_count>9 || candidate_count<1){
        printf("Usage: plurality [candidate ...]");
        return 1;
    }
    int number_voters = get_int("Number of voters: ");
    for (int i = 0; i <number_voters; i++) {
        string voted = get_string("Vote: ");
        vote(voted);
    }
    print_winner();
}
