#include <stdio.h>
int Sudoku();
void Tictactoe();
int check();
void display();
void Minesweeper();
char t[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };

int main()
{
	int choice;
	printf("\n\n\t\t\t\t\t------------PLAY GAME----------\n\n");
	printf("\nEnter Your Choice\n\n\n");
	printf("1.) Sudoku\n\n");
	printf("2.) Tic-Tac-Toe\n\n");
	printf("3.) Minesweeper\n\n");
	scanf("%d",&choice);
	
	switch(choice)
	{
		case 1:
			Sudoku();
			break;

		case 2:
		 	Tictactoe();
            break;

		case 3:
			Minesweeper();
		    break;

		default:
		 	 exit(0);	
	}

	

	return 0;
}




int Sudoku()
{
	printf("\t\t Welcome to Sudoku\n\n");
	int i,j,x=0,sum=0,counter=0;
	//problem grid
	int a[9][9]={
				{4,5,2,8,3,7,6,1,9},
				{0,7,1,6,4,9,8,2,5},
				{9,8,6,1,2,5,3,4,7},
				{0,9,5,3,1,2,4,7,6},
				{6,2,3,5,7,4,9,8,1},
				{7,1,4,9,8,6,5,3,2},
				{1,4,9,2,6,8,7,5,3},
				{2,6,8,7,5,3,1,9,4},
				{5,3,7,4,9,1,2,6,8},
			};
	//solution grid
	int solution[9][9]={
						{4,5,2,8,3,7,6,1,9},
						{3,7,1,6,4,9,8,2,5},
						{9,8,6,1,2,5,3,4,7},
						{8,9,5,3,1,2,4,7,6},
						{6,2,3,5,7,4,9,8,1},
						{7,1,4,9,8,6,5,3,2},
						{1,4,9,2,6,8,7,5,3},
						{2,6,8,7,5,3,1,9,4},
						{5,3,7,4,9,1,2,6,8},
						};
	int answer[9][9];

	int a1[9][9]={
				{1,5,2,4,8,9,3,7,6},
				{7,3,9,2,5,6,8,4,1},
				{4,6,8,3,7,1,2,9,5},
				{3,8,7,1,2,4,6,5,9},
				{5,9,1,7,6,3,4,2,8},
				{2,4,6,8,9,5,7,1,3},
				{9,1,4,6,3,7,5,8,2},
				{6,2,5,9,4,8,1,3,7},
				{8,7,3,5,1,2,9,6,4},
	           };

	 int s1[9][9]={
				{1,0,0,4,8,9,0,0,6},
				{7,3,0,0,0,0,0,4,0},
				{0,0,0,0,0,1,2,9,5},
				{0,0,7,1,2,0,6,0,0},
				{5,0,0,7,0,3,0,0,8},
				{0,0,6,0,9,5,7,0,0},
				{9,1,4,6,0,0,0,0,0},
				{0,2,0,0,0,0,0,3,7},
				{8,0,0,5,1,2,0,0,4},
	           };


	int s2[9][9]={
				{0,2,0,6,0,8,0,0,0},
				{5,8,0,0,0,9,7,0,0},
				{0,0,0,0,4,0,0,0,0},
				{3,7,0,0,0,0,5,0,0},
				{6,0,0,0,0,0,0,0,4},
				{0,0,8,0,0,0,0,1,3},
				{0,0,0,0,2,0,0,0,0},
				{0,0,9,8,0,0,0,3,6},
				{0,0,0,3,0,6,0,9,0},
	            };

	int a2[9][9]={
				{1,2,3,6,7,8,9,4,5},
				{5,8,4,2,3,9,7,6,1},
				{9,6,7,1,4,5,3,2,8},
				{3,7,2,4,6,1,5,8,9},
				{6,9,1,5,8,3,2,7,4},
				{4,5,8,7,9,2,6,1,3},
				{8,3,6,9,2,4,1,5,7},
				{2,1,9,8,5,7,4,3,6},
				{7,4,5,3,1,6,8,9,2},
	            };            

	int a3[9][9]={
				{5,8,1,6,7,2,4,3,9},
				{7,9,2,8,4,3,6,5,1},
				{3,6,4,5,9,1,7,8,2},
				{4,3,8,9,5,7,2,1,6},
				{2,5,6,1,8,4,9,7,3},
				{1,7,9,3,2,6,8,4,5},
				{8,4,5,2,1,9,3,6,7},
				{9,1,3,7,6,8,5,2,4},
				{6,2,7,4,3,5,1,9,8},
				};

	int s3[9][9]={
				{0,0,0,6,0,0,4,0,0},
				{7,0,0,0,0,3,6,0,0},
				{0,0,0,0,9,1,0,8,0},
				{0,0,0,0,0,0,0,0,0},
				{0,5,0,1,8,0,0,0,3},
				{0,0,0,3,0,6,0,4,5},
				{0,4,0,2,0,0,0,6,0},
				{9,0,3,0,0,0,0,0,0},
				{0,2,0,0,0,0,1,0,0},
				};			            
                      
	        //copy the question in answer array
			for(i=0;i<9;i++)
				{
					for(j=0;j<9;j++)
					{
						answer[i][j]=a[i][j];
					}	
				
				}	
	
				int checker=0;
	//calculate the sum of question set
				for(i=0;i<9;i++)
				{
					for(j=0;j<9;j++)
					{
						sum=sum + answer[i][j];
						if(a[i][j]==0)
						{
							checker++;
						}
					}
				
				}	
				//printf("%d\n", sum);

	//this code displays sudoku grid
	for(i=0;i<9;i++)
	{
		if(i==0)
		{
			//printf("--------------------------------------------------------------------------\n");
			printf("__________________________________________________________________________\n\n");
		}
		for(j=0;j<9;j++)
		{
			if(j==0)
			{
				printf("|");
			}
			printf("\t%d",a[i][j]);
			if(j==2 || j==5)
			{
				printf(" | ");
			}
			if(j==8)
			{
				printf("|");
			}
		}
		printf("\n");
		if(i==2 || i==5 || i==8)
		{
			//printf("--------------------------------------------------------------------------\n");
			printf("__________________________________________________________________________\n\n");
		}
	}	


	// ask for user input
	while(checker!=0)
	{
		printf("Enter row number\n");
		scanf("%d",&i);
		printf("Enter column number\n");
		scanf("%d",&j);
		if(a[i][j]!=0)
		{
		  printf("invalid input,try another input\n\n\n");
	     continue;
	    }
		printf("Enter the value\n");
		scanf("%d",&x);
		answer[i][j]=x;
		
		sum=sum+x;
		checker--;

					//this code displays sudoku grid
		for(i=0;i<9;i++)
		{
			if(i==0)
			{
				//printf("--------------------------------------------------------------------------\n");
				printf("__________________________________________________________________________\n\n");
			}
			for(j=0;j<9;j++)
			{
				if(j==0)
				{
					printf("|");
				}
				printf("\t%d",answer[i][j]);
				if(j==2 || j==5)
				{
					printf(" | ");
				}
				if(j==8)
				{
					printf("|");
				}
			}
			printf("\n");
			if(i==2 || i==5 || i==8)
			{
				//printf("--------------------------------------------------------------------------\n");
				printf("__________________________________________________________________________\n\n");
			}
		}	
	}	//end while

	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			if(answer[i][j]==solution[i][j])
			{
				counter++;
			}
		}
	}//end for

	//printf("%d\n",counter);
		//Declare result
		if(counter==81)
		{
			printf("You win!!!\n");
		}
		else
		{
			printf("Your solution is Wrong. You Lose :'( \n");
		}

	return 0;
}//end sudoku


//Tic-tac-toe
void Tictactoe()
{



  int player,i,ch,turn;
  char sym;
  turn =1;
  player=1;
   
  do
  {
  display();

  if(turn%2==1)
  {
    player=1;
  }
  else if(turn%2==0)
  {
    player=2;
  }

  //update player and x and o
   if(player==1)
  {
    sym='O';
  }
  else if(player==2)
  {
    sym='X';
  }




   printf("enter a number:");
   scanf("%d", &ch);
    if (ch== 1 && t[1] == '1')
            t[1] = sym;
    else if (ch == 2 && t[2] == '2')
            t[2] = sym;
    else if (ch == 3 && t[3] == '3')
            t[3] = sym;
    else if (ch == 4 && t[4] == '4')
            t[4] = sym;
    else if (ch == 5 && t[5] == '5')
            t[5] = sym;
    else if (ch == 6 && t[6] == '6')
            t[6] = sym;
    else if (ch == 7 && t[7] == '7')
            t[7] = sym;
    else if (ch == 8 && t[8] == '8')
            t[8] = sym;
    else if (ch == 9 && t[9] == '9')
            t[9] = sym;
    else
     {
      printf("Invalid move ");
      turn=turn-1;
      //getch();
     }
    i=check();
    turn++;
    }while(i==-1);
    
    display();
    if(i==1)
    {
      turn=turn-1;
      printf("Player %d win\n ",player);
    } 
    else if(i==0)
    {
      printf("draw\n");
    }
getch();
}

int check()
{
  if (t[1] == t[2] && t[2] == t[3])
  return 1;
        
  else if (t[4] == t[5] && t[5] == t[6])
  return 1;
        
  else if (t[7] == t[8] && t[8] == t[9])
  return 1;
  
  else if (t[1] == t[4] && t[4] == t[7])
  return 1;
        
  else if (t[2] == t[5] && t[5] == t[8])
  return 1;
        
  else if (t[3] == t[6] && t[6] == t[9])
  return 1;
   
  else if (t[1] == t[5] && t[5] == t[9])
  return 1;
        
  else if (t[3] == t[5] && t[5] == t[7])
  return 1;
        
  else if ((t[1] != '1')&& (t[2] != '2')&& (t[3] != '3') && (t[4] != '4') && (t[5] != '5')
   && (t[6] != '6') && (t[7] != '7') && (t[8] != '8') && (t[9] != '9'))
        return 0;
  else
   return -1;
}

void display()
 {   //clrscr();
    printf("\n\n\t\t\t ---------Tic Tac Toe----------\n\n");
    printf("Player 1  is 'O', Players 2 is sym is 'X'\n\n");
   
    printf("\t\t\t\t\t%c|%c|%c \n",t[1],t[2],t[3]);
    printf("\t\t\t\t\t-----\n");
    printf("\t\t\t\t\t%c|%c|%c\n",t[4],t[5],t[6]);
    printf("\t\t\t\t\t-----\n");
    printf("\t\t\t\t\t%c|%c|%c\n\n",t[7],t[8],t[9]);
 }



//Minsweeper is Here
 // extern "C"
void Minesweeper()
{
	//the solution grid
	char a[8][8]={
					{'1','1','1','1','1','1','1','*'},
					{'2','*','2','1','*','2','2','2'},
					{'2','*','3','2','2','2','*','1'},
					{'2','3','3','*','2','2','2','1'},
					{'*','2','*','2','3','*','2','$'},
					{'2','3','2','1','2','*','4','2'},
					{'1','*','1','$','1','2','*','*'},
					{'1','1','1','$','$','1','2','2'},
			};
	
	int i=0,j=0,dummy,rno,cno;

	int solution[8][8]={
							{'0','0','0','0','0','0','0','0'},
							{'0','0','0','0','0','0','0','0'},
							{'0','0','0','0','0','0','0','0'},
							{'0','0','0','0','0','0','0','0'},
							{'0','0','0','0','0','0','0','0'},
							{'0','0','0','0','0','0','0','0'},
							{'0','0','0','0','0','0','0','0'},
							{'0','0','0','0','0','0','0','0'},
						};

	printf("\n\t\t\t\tWELCOME TO MINESWEEPER\n\n");
	printf("\n\t Instructions");
	printf("\n\t 1. Enter the Row number and Column number");
	printf("\n\t 2. The number unveiled indicate the number of mines in vicinity");
	printf("\n\t 3. Once Mine is revealed game terminates\n\n");
	//display initial grid
	printf("\t\t\t_________________________________________");
	for (i=0;i<8;i++)
	{
		printf("\n\t\t\t|----|----|----|----|----|----|----|----|\n");
		printf("\t\t\t| ");
		for(j=0; j<8;j++)
		{
			printf("[] | ");
		}				
	}
	printf("\n\t\t\t|----|----|----|----|----|----|----|----|\n");
	printf("\t\t\t|---------------------------------------|\n\n\n");

	//Enter the grid number to unveil
	while(solution[rno][cno]!='*')
	{
		printf("\n\tEnter the row number\n");
		scanf("%d",&rno);
		printf("\tEnter the column number\n");
		scanf("%d",&cno);
		solution[rno][cno]=a[rno][cno];

		printf("\n\t\t\t|-------------------------------|\n");
		for(i=0;i<8;i++)
		{
			printf("\t\t\t");
			for (j= 0; j < 8; j++)
			{
				if (solution[i][j]!=0)
				{
					printf("|[%c]",solution[i][j]);
				}
				else
				{
					printf("|[%c]",a[i][j]);
				}
			}
			printf("|\n");
			printf("\t\t\t|---|---|---|---|---|---|---|---|\n");
		}
	}//end while


	printf("\n\n\t\t\t------GAME END------\n\n");

	printf("\t\tThe Mines were Here\n\n");
	//print solution
	printf("\n\t\t\t|-------------------------------|\n");
		for(i=0;i<8;i++)
		{
			printf("\t\t\t");
			for (j= 0; j < 8; j++)
			{
				{
					printf("|[%c]",a[i][j]);
				}
			}
			printf("|\n");
			printf("\t\t\t|---|---|---|---|---|---|---|---|\n");
		}
		printf("\n\n");
 
 }
