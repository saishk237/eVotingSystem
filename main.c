#include <stdio.h>
#include <string.h>

#define CANDIDATE1 "Yash Salunke"
#define CANDIDATE2 "Ajay Shendage"
#define CANDIDATE3 "Amaan Tamboli"
#define CANDIDATE4 "Om Bidve"
#define CANDIDATE5 "Saish Kothawade"

#define MAX 10

#define password "VOTING_SYSTEM_2021"
struct system
{
    char name[25];
    int age;
    int no;
    int choice;
}details[MAX];

int votes_count1 = 0, votes_count2 = 0, votes_count3 = 0, votes_count4 = 0, votes_count5 = 0, nota_votes = 0;

void cast_vote()
{
    static int v = 0;
    int yn;
    if (v < MAX)
    {

    line30:
        printf("\n\n **** Please choose your Candidate ****\n");
        printf("\n1. %s", CANDIDATE1);
        printf("\n2. %s", CANDIDATE2);
        printf("\n3. %s", CANDIDATE3);
        printf("\n4. %s", CANDIDATE4);
        printf("\n5. %s", CANDIDATE5);
        printf("\n6. %s", "None of The Above");

        printf("\n\nInput your choice (1 - 5) : ");
        scanf("%d", &details[v].choice);

        switch (details[v].choice)
        {
        case 1:
            votes_count1++;
            v++;
            break;
        case 2:
            votes_count2++;
            v++;
            break;
        case 3:
            votes_count3++;
            v++;
            break;
        case 4:
            votes_count4++;
            v++;
            break;
        case 5:
            votes_count5++;
            v++;
            break;
        case 6:
            nota_votes++;
            v++;
            break;
        default:
            printf("\nInvalid choice, Please retry");
            goto line30;
        }
        printf("\nThanks for voting !!");
    }
    else
    {
        printf("\nReached limit of voters");
    }
}

void votes_count()
{
  printf("\nLoading...\n");
    for(int i=0; i<1000000000; i++)
    {

    }
    printf("\n**** Voting Statistics ****");
    printf("\n%s - %d", CANDIDATE1, votes_count1);
    printf("\n%s - %d", CANDIDATE2, votes_count2);
    printf("\n%s - %d", CANDIDATE3, votes_count3);
    printf("\n%s - %d", CANDIDATE4, votes_count4);
    printf("\n%s - %d", CANDIDATE5, votes_count5);
    printf("\n%s - %d", "NOTA", nota_votes);
}

void get_LeadingCandidate()
{
  printf("\nLoading...\n");
    for(int i=0; i<1000000000; i++)
    {

    }
    printf("\nLeading Candiate ==> ");
    if (votes_count1 > votes_count2 && votes_count1 > votes_count3 && votes_count1 > votes_count4 && votes_count1 > votes_count5)
        printf(" [%s]", CANDIDATE1);
    else if (votes_count2 > votes_count3 && votes_count2 > votes_count4 && votes_count2 > votes_count5 && votes_count2 > votes_count1)
        printf(" [%s]", CANDIDATE2);
    else if (votes_count3 > votes_count4 && votes_count3 > votes_count5 && votes_count3 > votes_count2 && votes_count3 > votes_count1)
        printf(" [%s]", CANDIDATE3);
    else if (votes_count4 > votes_count5 && votes_count4 > votes_count1 && votes_count4 > votes_count2 && votes_count4 > votes_count3)
        printf(" [%s]", CANDIDATE4);
    else if (votes_count5 > votes_count1 && votes_count5 > votes_count2 && votes_count5 > votes_count3 && votes_count5 > votes_count4)
        printf(" [%s]", CANDIDATE5);
    else
        printf("Warning !! No-win situation");
}

void change()
{
    int a_no;
    int p;
    int c = 1;

    printf("\nEnter your Aadhar No. as entered while Voting: ");
    scanf("%d", &a_no);

    for (int i = 0; i < MAX; i++)
    {
        if (details[i].no == a_no)
        {
            p = details[i].choice;
            switch (p)
            {
            case 1:
                votes_count1--;
                break;
            case 2:
                votes_count2--;
                break;
            case 3:
                votes_count3--;
                break;
            case 4:
                votes_count4--;
                break;
            case 5:
                votes_count5--;
                break;
            case 6:
                nota_votes--;
                break;
            }
        line143:
            printf("\n**** Please choose your Candidate again ****\n");
            printf("\n1. %s", CANDIDATE1);
            printf("\n2. %s", CANDIDATE2);
            printf("\n3. %s", CANDIDATE3);
            printf("\n4. %s", CANDIDATE4);
            printf("\n5. %s", CANDIDATE5);
            printf("\n6. %s", "None of The Above");

            printf("\n\nInput your choice (1 - 6) : ");
            scanf("%d", &details[i].choice);

            switch (details[i].choice)
            {
            case 1:
                votes_count1++;
                break;
            case 2:
                votes_count2++;
                break;
            case 3:
                votes_count3++;
                break;
            case 4:
                votes_count4++;
                break;
            case 5:
                votes_count5++;
                break;
            case 6:
                nota_votes++;
                break;
            default:
                printf("\nInvalid choice! Please retry");
                goto line143;
            }
            printf("\nThanks for voting !!\n");
            c = 0;
        }
    }
    if (c)
    {
        printf("\nSorry. There is no such entry");
    }
}

int main()
{
    int n, vcount = 1;
    char key[20];

    while (1)
    {
        int n, vcount = 1;

        for (int j = 0; j < MAX; j++)
        {
            int k = 1;

            printf("\n----------------------------------------------");
            printf("\n\t***** WELCOME TO e-ELECTION 2021 *****");
            printf("\n----------------------------------------------");
            printf("\n\nEnter your Name: ");
            scanf("%s", details[j].name);
            printf("Enter your Age: ");
            scanf("%d", &details[j].age);
            printf("Enter your Aadhar No.: ");
            scanf("%d", &details[j].no);

            if (details[j].age < 18)
            {
                printf("\nSorry you are not eligible to vote\n");
                getchar();
                continue;
            }
            int yn = 1;
            while (yn)
            {
                printf("\n\n\t  |-MENU-|");
                printf("\nSelect the Operation:-");
                printf("\n1. Cast your Vote");
                printf("\n2. Current Vote Count");
                printf("\n3. Find Leading Candidate");
                printf("\n4. Change your vote");
                printf("\n5. Next Voter");
                printf("\n0. End Voting Process");

                printf("\n\nPlease enter your choice : ");
                scanf("%d", &n);
                switch (n)
                {
                case 1:

                    if (k)
                    {
                        printf("\n<VOTER NO. %d>", vcount);
                        cast_vote();
                        vcount++;
                    }
                    else
                    {
                        printf("\nSorry. You cannot vote twice");
                    }
                    k = 0;
                    break;
                case 2:
                    votes_count();
                    break;
                case 3:
                    get_LeadingCandidate();
                    break;
                case 4:
                    change();
                    break;
                case 5:
                    yn = 0;
                    break;
                case 0:
                    printf("\nEnter password to close the voting: ");
                    scanf("%s", key);
                    if (strcmp(key, password) != 0)
                    {
                        printf("\nWRONG PASSWORD!!! Voting will continue");
                    }
                    else
                    {
                        goto end;
                    }
                    break;
                default:
                    printf("\nError: Invalid Choice");
                }
            }
        }
    end:
        printf("\nEND OF VOTING PROCESS\n");
        votes_count();
        printf("\n");
        get_LeadingCandidate();
        break;
    }

    return 0;
}
