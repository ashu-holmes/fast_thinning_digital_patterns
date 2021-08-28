#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#include<ctype.h>
#include<math.h>  


int main(int argc, char *argv[])
{

  int   i,j,k,iret,ROW,COL;
  char  s1[10],s2[100];
  float fret;
  FILE *fp_in,*fp_out;

  if(argc != 3){
                  printf("\n Usage: %s in_img_file(pgm)  out_img_file(bin&float)\n",argv[0]);  exit(1); }

  fp_in  = fopen(argv[1], "r");
  if(fp_in == NULL) { printf("\n FILE CAN'T BE OPENED FOR READING...MAKING EXIT..\n"); exit(1); }
  fp_out = fopen(argv[2], "w");
  //fscanf(fp_in,"%s", s1); 
  //fgets(s2,100,fp_in);
  fscanf(fp_in,"%d",&COL);
  fscanf(fp_in,"%d",&ROW);
  fscanf(fp_in,"%d",&iret);

  printf("\n first string:%s, second string:%s, row:%d, col:%d, max:%d\n", s1,s2,COL, ROW, iret);
  for(i=0;i<ROW;i++)
  for(j=0;j<COL;j++)
    {
     fscanf(fp_in, "%d",&iret);
     putc(iret,fp_out);
   //  fret = (float)iret;
   //  fwrite(&fret,4,1,fp_out);
    }

  fclose(fp_in); 
  fclose(fp_out); 
  printf("\n OUTPUT IMAGE :  Name:%s,  ROWSIZE:%d,  COLSIZE:%d\n", argv[2],ROW,COL);
}
  
