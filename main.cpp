
#include<stdio.h>                      
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#include<unistd.h>  //for sleep function

typedef struct voter_information
{
	char id[10];
	char name[20];
	//char m_no[10];
	char birth_date[15];
	//char father_name[20],mother_name[20];
	//struct voter_information * next;
}node;
node *head;



void main_loges(int,int,int,int,int);
void admin(int*,int*,int*,int*,int*);
void winner(int,int,int,int,int);
void stop();

void voting(int *c1,int *c2,int *c3,int *c4,int *c5)
{
	int B,j;
	system("cls");
	printf("\n\n\n");
	printf("\t\t ----CANDIDATES ARE:--- \n");
	sleep(1);
	printf("\t\t\t   NAME           SYMBOL \n\n");
	printf("\t\t\t 1. Ramesh        1.hand \n\n");
	printf("\t\t\t 2. Vikram        2.leaf \n\n");
	printf("\t\t\t 3. Amulya        3.mango \n\n");
	printf("\t\t\t 4. Shifali       4.box \n\n");
	printf("\t\t\t 5. Rudra         5.joining hands \n\n");
	printf("\t\t\t PLEASE ENTER YOUR CHOICE   \n\n\n");
	for(j=1 ; j<=1 ;j++)
	{
		scanf("%d",&B);
		if(B == 1)
		{
			(*c1)++;
		}
		else if(B == 2)
		{
			(*c2)++;
		}
		else if(B == 3)
		{
			(*c3)++;
		}
		else if(B == 4)
		{
			(*c4)++;
		}
		else if(B == 5)
		{
			(*c5)++;
		}
		else
		{
			printf("\t\t\t --ENTER RIGHT CHOICE-- \n");
			main_loges(*c1,*c2,*c3,*c4,*c5);
		}
	}
	int R;
	system("cls");
	printf("\n\n\n");
	printf("\t\t\t ENTER ONE(1) TO VIEW PRESENT WINNER  OR \n\n\n ENTER ZERO(0) FOR MAIN LOGES\n\n");
	scanf("%d",&R);
	if(R == 1)
	{
		winner(*c1,*c2,*c3,*c4,*c5);
	}
    if(R == 0)
    {
        main_loges(*c1,*c2,*c3,*c4,*c5);
	}
}

void show(int c1,int c2,int c3,int c4,int c5)
{
    system("cls");
    printf("\n\n\n");
    printf("\t\t\tVote Count\n\n\n");
    sleep(1);
    printf("\t\t\t Ramesh  got %d votes\n",c1);
    sleep(1);
    printf("\t\t\t Vikram  got %d votes\n",c2);
    sleep(1);
    printf("\t\t\t Amulya  got %d votes\n",c3);
    sleep(1);
    printf("\t\t\t Shifali got %d votes\n",c4);
    sleep(1);
    printf("\t\t\t Rudra   got %d votes\n",c5);
    sleep(1);

    int R;
    printf("\t\t\t ENTER ONE(1) FOR MAIN LOGES OR \n\n\n ENTER ZERO(0) FOR EXIT");
    scanf("%d",&R);
    if(R == 1)
    {
        main_loges(c1,c2,c3,c4,c5);
    }
    if(R != 1)
    {
        exit(0);
    }
}

void voter_insert(int count,int c1,int c2,int c3,int c4,int c5,int R)
{
 
    node p;
    FILE * f;
	int i,t;
	char n[25],b[15],idd[10];
	getchar( );
	for(R=3 ; R>0 ; R--)
	{
		system("cls");
		printf("\n\n\n\n");
		f = fopen("voting.txt", "r");
		if (f == NULL) 
		{
        	printf("\n Error in opening\n");
        	exit(0);
    	}
		printf("\t\t ---PLEASE ENTER THE INFORMATION AS REGISTERED---  \n");
		sleep(1);
		printf("\t\t  IF YOU INPUT WRONG INFORMATION %d TIMES THEN PROGRAM STOPS AUTOMATICALLY  \n",R);
		sleep(1);
		
		printf("\t\t\tENTER YOUR ID NUMBER  :  \n");
		gets(idd);
		printf("\t\t\tENTER YOUR NAME  :  \n");
		gets(n);
		printf("\t\t\tENTER YOUR BIRTH DATE  :  \n");
		gets(b);
		
		while (fread( & p,sizeof(p), 1, f)==1)
    	{
        	if (strcmp(p.name, n) == 0 && strcmp(p.id,idd)==0  && strcmp(p.birth_date,b)==0)
			{
            	count++;
				if(count > 1) ///To ensure that same person is not voting 2 times
				{
					system("cls");
					printf("\t\t\t ---YOU CAN NOT GIVE VOTE MORE THAN 1 TIME---  \n");
					printf("\t\t\t  PRESS 1 TO GO TO MAIN LOGES \n OR \n PRESS 0 TO EXIT   \n");
					scanf("%d",&i);
					if(i==1)
						main_loges(c1,c2,c3,c4,c5);
					else
						exit(0);
					break;
				}
				voting(&c1,&c2,&c3,&c4,&c5);
				break;
			}
        }
		printf("\n\n\n");
		printf("\t\t  Your information is wrong  \n");
		sleep(1);
		printf("\t\t ---PLEASE REENTER--- \n");
		sleep(1);
		 
	}
	if(R==0)
	{
		stop();
		
	}
    fclose(f);
    
    printf("Enter 1 to enter main loges \n\t\t or \n Enter 0 to exit\n");
    scanf("%d",&t);
    if(t==1)
    	main_loges(c1,c2,c3,c4,c5);
    else
    	exit(0);
	
	
}
void regi(int c1,int c2,int c3,int c4,int c5)
{
	system("cls");
	printf("\n\n\n\n");
	FILE *f;
	node p;
	int t;
	f = fopen("voting.txt", "a+");
	
	printf("\n Enter id: ");
    scanf("%s",p.id);
	
	printf("\nEnter name: ");
    scanf("%s",p.name);
	   
    printf("Enter birth data:");
    scanf("%s",p.birth_date);
    
    fwrite( & p, sizeof(p), 1, f);
    printf("\nSuccessfully registered\n");
    fclose(f);
    
    printf("Enter 1 to enter main loges \n\t\t or \n Enter 0 to exit\n");
    scanf("%d",&t);
    if(t==1)
    	main_loges(c1,c2,c3,c4,c5);
    else
    	exit(0);
}
void display(int c1,int c2,int c3,int c4,int c5) 
{
	int B;
    printf("\n\n\n");
    printf("\t\t\tEnter Password to unlock VOTER LIST\n\n");
    scanf("%d",&B);
    if(B==12345)
    {
        system("cls");
		printf("\n\n\n\n");
		int i;
    	node p;
    	FILE * f;
    	f = fopen("voting.txt", "r");
    	if (f == NULL)
		{
        	printf("\n No contacts detected yet!:\n");
        	exit(0);
    	}
    	printf("\n\n\n Voter details are as follows:\n\n ");
    	printf("\tID\t\tNAME\t\tBIRTH-DATE\n");
    	while (fread( & p,sizeof(p), 1, f)==1)
    	{
        	printf("\t%s\t\t%s\t\t%s \n", p.id, p.name, p.birth_date);
       		
    	}	
    	fclose(f);
    	
    	printf("\n\nEnter 1 to enter main loges \n\t\t or \n Enter 0 to exit\n");
    	scanf("%d",&i);
    	if(i==1)
    		main_loges(c1,c2,c3,c4,c5);
    	else
    		exit(0);
    }
    else
    {
        printf("Wrong Password\n");
    }
	
}
void main_loges(int c1,int c2,int c3,int c4,int c5)
{
	int count=0,R=3;
	
	
	while(1)
	{
		system("cls");  //works under windows.h
		printf("\n\n\n");
		printf("\t\t\t 1 . Registeration       \n");

		printf("\t\t\t 2 . Vote Entry       \n");

		printf("\t\t\t 3 . Admin Panel       \n");

		printf("\t\t\t 4 . Winner       \n");

		printf("\t\t\t 5 . Voter list       \n");

		printf("\t\t\t 6 . Exit       \n");

		printf("\t\t\t ---FIRST GIVE VOTER ENTRY THEN GO FOR VOTING---       \n");

		printf("\t\t\t ---Enter your choice here :  ");

		int T;
		scanf("%d",&T);
		switch(T)
		{
			case 1: 
					regi(c1,c2,c3,c4,c5);
			break;
			case 2:
					voter_insert(count,c1,c2,c3,c4,c5,R);
			break;
			case 3: 
					admin(&c1,&c2,&c3,&c4,&c5);
			break;
			case 4: 
					winner(c1,c2,c3,c4,c5);
			break;
			case 5: 
					display(c1,c2,c3,c4,c5);
			break;
			case 6: 
					exit(0);
			break;
			default:return;
		}
	}
}
int main()
{
	int c1=0,c2=0,c3=0,c4=0,c5=0;
	system("cls");  //to clear system screen
	printf("\n\n\n\t   ---WELCOME TO ONLINE VOTING SYSTEM---   \n\n");
	sleep(1);
	printf("\t\t  --PLEASE ENTER ONE(1) FOR LOGGING INTO MAIN VLOGES--- \n\n\n");
	int B;
	scanf("%d",&B);
	if(B == 1)
	{
		main_loges(c1,c2,c3,c4,c5);
	}
	return 0;
}
void stop()
{
	system("cls");
	printf("\n\n\n");
	printf("\t------SORRY YOU CAN NOT GIVE YOUR VOTE FOR YOUR WRONG ENTRY------\n");
	sleep(1);
	printf("\t------PLEASE TRY AGAIN FEW MOMENT LATER-----\n");
	sleep(1);
	printf("\t\t\t\t*THANK YOU*  \n");
}

void admin(int *c1,int *c2,int *c3,int *c4,int *c5)
{
    int B;
    printf("\n\n\n");
    printf("\t\t\tEnter Password to unlock Admin Panel\n\n");
    scanf("%d",&B);
    if(B==12345)
    {
        show(*c1,*c2,*c3,*c4,*c5);
    }
    else
    {
        printf("Wrong Password\n");
    }
}

void winner(int c1,int c2,int c3,int c4,int c5)
{
    system("cls");
    printf("\n\n\n");
    if(c2<c1 && c3<c1 && c4<c1 && c5<c1)
        printf("\t\t\t Ramesh is the present winner with %d votes\n\n\n",c1);
    if(c1<c2 && c3<c2 && c4<c2 && c5<c2)
        printf("\t\t\t Vikram is the present winner with %d votes\n\n\n",c2);
    if(c1<c3 && c2<c3 && c4<c3 && c5<c3)
        printf("\t\t\t Amulya is the present winner with %d votes\n\n\n",c3);
    if(c1<c4 && c2<c4 && c3<c4 && c5<c4)
        printf("\t\t\t Shifali is the present winner with %d votes\n\n\n",c4);
    if(c1<c5 && c2<c5 && c3<c5 && c4<c5)
        printf("\t\t\t Rudra is the present winner with %d votes\n\n\n",c5);
    int T;
    printf("\t\t\t ENTER ONE(1) FOR MAIN LOGES OR\n\n\n ENTER ZERO(0) FOR EXIT\n");
    scanf("%d",&T);
    if(T == 1)
    {
        main_loges(c1,c2,c3,c4,c5);
    }
    if(T != 1)
    {
        exit(0);
    }
}

