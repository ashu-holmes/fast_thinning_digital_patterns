#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
	int x;
	int y;
	struct node *link;
}list;

int r,c;
list *header, *ptr, *temp,*ptr1,*temp1,*temp2;
void push(int x1,int y1)
{
	 list* temp;
	 temp = (list *) malloc(sizeof(list));
	temp->x = x1;
	temp->y = y1;
	temp->link = header->link;
	header->link = temp;
}
 list *pop(int img[][7])
{
	
	if(header->link == NULL)
	{
		printf("\nEmpty Linked List. Deletion not possible.\n");
		return;
	}
	else
	{
		ptr = header->link;
		//set to white
		header->link= ptr->link;
		return ptr;
	}	
}
int A(int img[][7],int x, int y )

{

    int array[10] = {0,0,1,2,2,2,1,0,0,0};

    int k=array[0] , n=array[2];

    int i,count=0 ;
    int u=x+k-1,v=y+n-1;
    int c=img[x+k-1][y+n-1];

    for(i=1;i<8;i++)

    {

        k=array[i];

        n=array[i+2];

       if(c==0&&img[x+k-1][y+n-1]!=c)
       count++;
       c=img[x+k-1][y+n-1];
    }
    if(c==0&&img[u][v]!=c)
    count++;
    return count;

}//Circular traversal around the pixel
int B(int img[][7],int i, int j)
{
	int counter=0;
	if(img[i-1][j-1]==1)
	counter++;
		if(img[i-1][j]==1)
	counter++;
		if(img[i-1][j+1]==1)
	counter++;
		if(img[i][j-1]==1)
	counter++;
		if(img[i][j+1]==1)
	counter++;
		if(img[i+1][j-1]==1)
	counter++;
		if(img[i+1][j]==1)
	counter++;
		if(img[i+1][j+1]==1)
	counter++;
	return counter;  
}
void thin(int img[][5])
{

int check=1,count=0,i,j;
 while(check==1)
{
	//step1
	check=0;
	count=0;
	for(i=1;i<r-1;i++)
	{
		for(j=1;j<c-1;j++)
		{
		  if(img[i][j]==1&&B(img,i,j)>=2&&B(img,i,j)<=6&&A(img,i,j)==1&&(img[i-1][j]==0||img[i][j+1]==0||img[i+1][j]==0)&&(img[i][j-1]==0||img[i][j+1]==0||img[i+1][j]==0))
		  {
		  push(i,j);
		  check=1;
		  count++;
		  }	
		}
	}
	for(i=1;i<=count;i++)
	{
		for(i=1;i<=count;i++)
	{
		temp1 = (list *) malloc(sizeof(list));
	    temp1=pop(img);
	    img[temp1->x][temp1->y]=0;//white
	}
	}
	//*****************************************************************************************************************************************
	//step 2
	check=0;
	count=0;
	for(i=1;i<r;i++)
	{
		for(j=1;j<c;j++)
		{
		  if(img[i][j]==1&&B(img,i,j)>=2&&B(img,i,j)<=6&&A(img,i,j)==1&&(img[i-1][j]==0||img[i][j+1]==0||img[i][j-1]==0)&&(img[i][j-1]==0||img[i-1][j]==0||img[i+1][j]==0))
		  {
		  push(i,j);
		  check=1;
		  count++;
		  }	
		}
	}
	for(i=1;i<=count;i++)
	{
		for(i=1;i<=count;i++)
	{
		temp1 = (list *) malloc(sizeof(list));
	    temp1=pop(img);
	    img[temp1->x][temp1->y]=0;//white
	}
	}
}
}
int main()
{
  	header = (list *) malloc(sizeof(list));	
	header->x =0;
	header->y=0;
	header->link = NULL;
	r=12;
	c=7;
	int img[ ][7]={	0,0,0,0,0,0,0,
					0,1,1,1,1,1,0,
					0,1,1,1,1,1,0,
					0,1,1,1,1,1,0,
					0,0,1,1,1,0,0,
					0,0,1,1,1,0,0,
					0,0,1,1,1,0,0,
					0,0,1,1,1,0,0,
					0,1,1,1,1,1,0,
					0,1,1,1,1,1,0,
					0,1,1,1,1,1,0,
					0,0,0,0,0,0,0}; 
	int check=1,count=0,i,j;
 while(check==1)
{
	//step1
	check=0;
	count=0;
	for(i=1;i<r-1;i++)
	{
		for(j=1;j<c-1;j++)
		{
		  if(img[i][j]==1&&B(img,i,j)>=2&&B(img,i,j)<=6&&A(img,i,j)==1&&(img[i-1][j]==0||img[i][j+1]==0||img[i+1][j]==0)&&(img[i][j-1]==0||img[i][j+1]==0||img[i+1][j]==0))
		  {
		  push(i,j);
		  printf("push loop 1\n",i,j);
		  check=1;
		  count++;
		  }	
		}
	}
		for(i=1;i<=count;i++)
	{
		temp1 = (list *) malloc(sizeof(list));
	    temp1=pop(img);
	    printf("pop loop 1\n");
	    img[temp1->x][temp1->y]=0;//white
	}
	
	//*****************************************************************************************************************************************
	//step 2
	
	count=0;
	for(i=1;i<r-1;i++)
	{
		for(j=1;j<c-1;j++)
		{
		  if(img[i][j]==1&&B(img,i,j)>=2&&B(img,i,j)<=6&&A(img,i,j)==1&&(img[i-1][j]==0||img[i][j+1]==0||img[i][j-1]==0)&&(img[i][j-1]==0||img[i-1][j]==0||img[i+1][j]==0))
		  {
		  push(i,j);
		  printf("push 2 loop\n");
		  check=1;
		  count++;
		  }	
		}
	}
	
		for(i=1;i<=count;i++)
	{
		temp2 = (list *) malloc(sizeof(list));
	    temp2=pop(img);
	    img[temp2->x][temp2->y]=0;//white
	}
	
}

	int i1,j1;
	for(i1=0;i1<r;i1++)
	{
		for(j1=0;j1<c;j1++)
	     printf("%d ",img[i1][j1]);
	     printf("\n");
	}
	
		return 0;
}
