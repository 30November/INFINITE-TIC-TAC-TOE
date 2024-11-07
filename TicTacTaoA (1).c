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
    //Vertical winning's
    if (choice[0] == s && choice[3] == s && choice[6] == s) return s;
    if (choice[1] == s && choice[4] == s && choice[7] == s) return s;
    if (choice[2] == s && choice[5] == s && choice[8] == s) return s;
    
    //Horizontal winnings
    if (choice[0] == s && choice[1] == s && choice[2] == s)return s;
    if (choice[3] == s && choice[4] == s && choice[5] == s)return s;
    if (choice[6] == s && choice[7] == s && choice[8] == s) return s;
    
	//Diagonal winning 
    if (choice[0] == s && choice[4] == s && choice[8] == s) return s;
    if (choice[2] == s && choice[4] == s && choice[6] == s) return s;

    return 'A';
    
}

void replace(int pos,char choice[])
{
	int index=pos-1;
	switch(index)
	{
		case 0: 
		choice[index]='1';
		break;
		case 1:
		choice[index]='2';
		break;
		case 2: 
		choice[index]='3';
		break;
		case 3: 
		choice[index]='4';
		break;
		case 4: 
		choice[index]='5';
		break;
		case 5: 
		choice[index]='6';
		break;
		case 6: 
		choice[index]='7';
		break;
		case 7: 
		choice[index]='8';
		break;
		case 8: 
		choice[index]='9';
		break;
	}
}

int main()
{
    //Player 1 deals with X
    //Player 2 deals with O
    printf("\n-----------------TIC TAC TOE GAME ----------------\n");
    printf("\n---------------- *BY BISWAYAN B.MAL* ---------------\n");
    printf("\n---------------- *CON. BY AYUSHMAN GHOSH* ---------------\n");
    printf("\nNOTE:'#' warns at the position where your oldest sign will get deleted.\n");
    int pos;
    char choice[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int p1[3]={0,0,0},index1=0;
    int p2[3]={0,0,0},index2=0;
    while (1)
    {
        // for Player 1
        labelX:
        if (p1[index1]) choice[p1[index1]-1]='#';
        printboard(choice);
        printf("Enter the position Player1 (X):");
        scanf("%d", &pos);
        if  (1<=pos && pos<=9)
		{
        	if (choice[pos-1]=='X' || choice[pos-1]=='O')
        	{printf("	ALREADY OCUUPIED	"); goto labelX;}
        	
        	if (p1[index1]) replace(p1[index1],choice);
        	
        	p1[index1]=pos;
			index1=(index1+1)%3;	
			
			choice[pos-1]='X';
			
		}
		else
		{ 
			printf("    INVALID INPUT    ");
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
        if (p2[index2]) choice[p2[index2]-1]='#';	
        printboard(choice);
        printf("Enter the position player2 (O):");
        scanf("%d", &pos);
        if  (1<=pos && pos<=9)
		{
        	if (choice[pos-1]=='X' || choice[pos-1]=='O')
        	{printf("Somebody has already placed"); goto labelO;}
        	
        	if (p2[index2]) replace(p2[index2],choice);
        	
        	p2[index2]=pos;
			index2=(index2+1)%3;
			
			choice[pos-1]='O';
		}
		else
		{ 
			printf("Invalid Input");
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
