#include      <stdio.h>
#include      <stdlib.h>
#include      <math.h>        
#include      <ctype.h>       
#include      <string.h>      
#define LETTER          'a'
#define DIGIT           '0'
#define MAXXSIZE        1800
#define MAXYSIZE        1800 
#define MAXLINE         200
#define MAXWORD         16
#define	BUFSIZE	100
char	buf[BUFSIZE];
int 	bufp = 0;
FILE    *imgfilein, *imgfileout;
int i, j, k, l, opn, w;
int     xsize, ysize, max;
int   e;
unsigned int d;
int    c;
 char sx[10];
char s1[10];
//int getline(char *, int);
int a[MAXXSIZE][MAXYSIZE];
main(argc, argv) /* ******** main function block ******** */
int argc;
char *argv[];


{
int x;
 int ii, r, jj, nn, kk;
        FILE *fopen();
         char  line[MAXLINE], word[MAXWORD];  
      /* check argument error */

        if ( argc != 5){
                printf("USAGE: <progname>  infilename xsize ysize outfilename\n");
                exit(0);
        }
       
        imgfilein  = fopen ( argv[1], "r");
        imgfileout = fopen ( argv[4],"w");
        if ( imgfilein == NULL ) {
                printf (" input image file : NOT FOUND \n");
                exit (0);
        }

        xsize = atoi(argv[2]);
        ysize = atoi(argv[3]);



        if ( imgfileout == NULL ) {
                printf (" error : output image file : NOT OPEN \n");
                exit (0);
        }
    /* write the first four  lines */ 
          fprintf(imgfileout,"%s\n", "P2");
          fprintf(imgfileout,"%s\n", "# created by ^&*^*^*^^*&^*&^*&&*^^&^&^&*^^&^*^%");
          fprintf(imgfileout,"%s %s\n", argv[3], argv[2] );
          fprintf(imgfileout,"%s\n", "255" );
        


   i = 0; kk = 0;
   while( (c = fgetc(imgfilein)) != EOF ){
         if ( c   & 0x80 ){
            c = c & 0x7f;
            d = c + 128;
         }
         else
            d = c;


         nn = d; 
         ii = 0;

         do{

           r = nn % 10;
           nn = (nn/10);
           sx[ii] = r + '0' ;
           ii = ii+1;
         }while ( nn );

         jj = 0;
 
         while(ii)
           s1[jj++] = sx[--ii];

 
         s1[jj] = '\0';

         for(x=0; x<= jj; x++)
           putc(s1[x], imgfileout);
 
           putc(' ', imgfileout);
     
         kk++;
         if ( kk == 17 ){
       putc(10, imgfileout);
       kk = 0;
     }

  } 
       putc(10, imgfileout);
 
}

//int getline(s, lim)
//char s[];
//int lim;
//{
//  int c, i;
//
//  for ( i = 0; i < lim - 1 && (c = getc(imgfilein)) != EOF && c!= '\n'; i++)
//     s[i] =c;
//
//  if ( c == '\n'){
//   s[i] = c;
//   i++;
//  }
//
//  s[i] = '\0';
//  return(i);
//}

getword(w, lim)
char *w;
int lim;
{

   int c, t;
   if ( type ( c = *w++ =getch()) != DIGIT){
     *w = '\0';
     return(c);
   }
   while ( --lim > 0){
     t = type ( c = *w++ = getch());
     if ( t != LETTER && t!= DIGIT) {
        ungetch(c);
        break;
     }
   }
   *(w-1) = '\0';
   return(LETTER);
 }

getch()  /* get a possibly pushed back character */
{
   return((bufp > 0) ? buf[--bufp] : getc(imgfilein));
}

ungetch(c)    /* push charcter back on input */
int c;
{
   if ( bufp > BUFSIZE)
     printf("ungetch: error ; too many characters");
   else
     buf[bufp++] = c;
}

type(c)   /* return type of ASCII chracters */
int c;
{
    if ( c >= 'a'  &&  c <= 'z'   || c >= 'A'  &&  c <= 'Z')
      return(LETTER);
    else if ( c >= '0' && c <= '9')
      return(DIGIT);
    else
      return(c);
}


   /* function to read inout image file & fill a image matrix */
readimg()
{
        int i, j ;

        for ( i= 0 ; i <= xsize - 1; i++){
                for (j=0; j <= ysize - 1 ; j++)
                        a[i][j] =  getc(imgfilein) /* - '0'*/ ;
        /*  getc(imgfilein); */
     }
        fclose(imgfilein);

        return(0);
}

writeimg()      /* write image file */
{
        int i, j; 

        for ( i= 0 ; i <= xsize - 1; i++){
                for (j=0; j <= ysize - 1 ; j++)
                        putc(a[i][j]/*+'0'*/,imgfileout);
      /*    putc('\n', imgfileout); */
        }
        fclose(imgfileout);   
        return(0);
}


