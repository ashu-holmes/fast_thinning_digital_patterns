#include<stdio.h>
int main()
{
FILE *fp;
int i,j,img[512][512];
fp=fopen("a.raw","r");
for(i=0;i<512;i++)
{
for(j=0;j<512;j++)
{
img[i][j]=(int)getc(fp);
}
}
fclose(fp);
fp=fopen("final.raw","w");
for(i=0;i<512;i++)
{
for(j=0;j<512;j++)
{
putc(img[i][j],fp);
}
}
fclose(fp);
return 0;
}
