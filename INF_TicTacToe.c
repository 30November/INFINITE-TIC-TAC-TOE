#include <stdio.h>

void printboard(char choice[])
{
    printf("\n     |     |    \n");
    printf("  %c  |  %c  |  %c \n", choice[0], choice[1], choice[2]);
    printf("     |     |    \n");
    printf("-----------------\n");
    printf("     |     |    \n");
    printf("  %c  |  %c  |  %c \n", choice[3], choice[4], choice[5]);
    printf("     |     |    \n");
    printf("-----------------\n");
    printf("     |     |    \n");
    printf("  %c  |  %c  |  %c \n", choice[6], choice[7], choice[8]);
    printf("     |     |    \n\n");
}

char checkwin(char s,char choice[])
{
    
    int i;
    for (i = 0; i < 3 ; i++)
    {
    	if (choice[i]==s && choice[i+3]==s && choice[i+6]==s) return s; //V
    	if (choice[3*i]==s && choice[3*i+1]==s && choice[3*i+2]==s) return s; //H
    	if (choice[i]==s && choice[4]==s && choice[8-i]==s) return s; //D
	}

    return 'A';
    
}


int main()
{
    //Player 1 deals with X
    //Player 2 deals with O
    printf("\n-----------------TIC TAC TOE GAME ----------------\n");
    printf("\n---------------- *BY BISWAYAN B.MAL* ---------------\n");
    printf("\n---------------- *CON. BY AYUSHMAN GHOSH* ---------------\n");
    int pos;
    char choice[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int p1[3]={0,0,0},index1=0;
    int p2[3]={0,0,0},index2=0;
    while (1)
    {
        // for Player 1
        labelX:
        printboard(choice);
		if (p1[index1]) printf("\nALERT: Old 'X' will get deleted\n");
        printf("Enter the position Player1 (X):");
        scanf("%d", &pos);
        if  (1<=pos && pos<=9)
		{
        	if (choice[pos-1]=='X' || choice[pos-1]=='O')
        	{printf("\n 	ALREADY OCUUPIED	\n"); goto labelX;}
        	
        	if (p1[index1]) choice[p1[index1] - 1] = p1[index1] + 48;
        	
        	p1[index1]=pos;
			index1=(index1+1)%3;	
			
			choice[pos-1]='X';
			
		}
		else
		{ 
			printf("\n    INVALID INPUT    \n");
			goto labelX;
		}

        if (checkwin('X',choice)=='X')
        {
            printboard(choice);
            printf("*************  PLAYER 1 wins  ****************");
            break;
        }
        
        // for Player 2
        labelO:
        printboard(choice);
		if (p2[index2]) printf("\nALERT: Old 'O' will get deleted\n");	
        printf("Enter the position Player2 (O):");
        scanf("%d", &pos);
        if  (1<=pos && pos<=9)
		{
        	if (choice[pos-1]=='X' || choice[pos-1]=='O')
        	{printf("\n 	ALREADY OCUUPIED	\n"); goto labelO;}
        	
        	if (p2[index2]) choice[p2[index2] - 1] = p2[index2] + 48;
        	
        	p2[index2]=pos;
			index2=(index2+1)%3;
			
			choice[pos-1]='O';
		}
		else
		{ 
			printf("\n    INVALID INPUT    \n");
			goto labelO;
		}

        if (checkwin('O',choice)=='O')
        {
            printboard(choice);
            printf("*************  PLAYER 2 wins  ****************");
            break;
        }
    }
    
    //For play Again
    int op; scanf("%d",&op,printf("\nDo you want to play again?(0/1)"));
	if (op) return main();
	return 0;

}          
