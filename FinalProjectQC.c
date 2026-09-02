#include <stdio.h>
#include <stdlib.h>
//struct
//{
//   int ;
//   int ;
//   int ;
//   ; //variable length array must be last.
//};
//
int main()
{
    char *line = NULL;
    size_t len = 0;

   char ch,ch2, ch3, ch4, file_name[25];
   char file_name2[25]; char* buf[100];
   FILE *fp;
    int n,m,garbage,it;
    int skipl = 0;
    char text[25];
    char input[100], output[100];
    char lines[256];
    int iter = 0,j;
   printf("Enter name of a file you wish to see\n");
   gets(file_name);

   fp = fopen(file_name, "r"); // read mode

   if (fp == NULL)
   {
      perror("Error while opening the file.\n");
      exit(EXIT_FAILURE);
   }

   while((ch = fgetc(fp)) != EOF)
   //if (ch == '#') {
        //
   //else {
   if (ch == '.'){
        ch2 = fgetc(fp);
            if (ch2 == 'i'){
                ch3 = fgetc(fp);
                if (ch3 == ' '){
                    printf("input size:\n");
                    //while ((ch4 = fgetc(fp)) != '\n')
                    //    printf("%c", ch4);
                    fscanf(fp, "%d", &n);
                    printf(" %i \n", n);
                }
                else {
                    ch4 = fgetc(fp);
                    printf("input variables:\n");
                    //printf("input is : %s/n", buf);
                    while ((ch4 = fgetc(fp)) != '\n')
                        printf("%c", ch4);
                    printf("\n");
                }
            }
            if (ch2 == 'o'){
                ch3 = fgetc(fp);
                if (ch3 == ' '){
                    printf("output size:\n");
                    fscanf(fp, "%d", &m);
                    printf(" %i \n", m);
                    //while ((ch4 = fgetc(fp)) != '\n')
                    //    printf("%c", ch4);
                    //printf("output is : %i/n", m);
                }
                else{
                    if (ch3 =='b'){
                        printf("output variables:\n");
                        while ((ch4 = fgetc(fp)) != '\n')
                            printf("%c", ch4);
                        printf("\n");
                    }
                    //printf("input is : %s/n", buf);
                }
            }
    }
   //}
   //#printf("The contents of %s file are:\n", file_name);
   //#   printf("%c", ch);
// to read the matrices
//while (fscanf(ifp, "%s %d", username, &score) != EOF) {
//  fprintf(ofp, "%s %d\n", username, score+10);
//}
//    while (fscanf(fp,"%*s %s ",buf)==1)
//        printf("%s\n", buf);

    it = 0;
   fclose(fp);
   fp = fopen(file_name, "r");
   for (ch = getc(fp); ch != EOF; ch = getc(fp)) {
        if (ch == '\n') // Increment count if this character is newline
            ch4 = getc(fp);

            if (ch4 == '.' || ch4 == '#') {
                ch2 = getc(fp);
                skipl = skipl + 1;
                if (ch2 == 'e') {
                    skipl = skipl - 1;
                    break;}
                }

}

    fclose(fp);

    //printf("%d\n",skipl);
    fp = fopen(file_name, "r");

    while (fgets(lines, sizeof(lines), fp)) {
        iter++;
        if(iter >= skipl -1 )
        {
            it = it+1;
            if (it>8)  {
                break;}
            fscanf(fp, "%s %s", input, output);
            printf("%s %s\n", input, output);}
            //while (j<n) {
            //    if (input[j])
            //}
        }
        /*
        // Toffoli gates
        //if (ainput == binput && cinput != coutput) {
            t2 a b c
            or
            v c a
            v b a
            t2 c b
            v+ b a
            t2 c b
        }
        else if (ainput == cinput && binput != boutput) {
            t2 a c b
            or
            v b a
            v c a
            t2 b c
            v+ c a
            t2 b c
        }
        else if (binput == cinput && ainput != aoutput) {
            t2 b c a
            or
            v a b
            v c b
            t2 b b
            v+ a b
            t2 b a
        }
        //

       */







    //it = 0;
    //while (it < skipl+8) {
    //    if (it < skipl ) {
    //    fscanf(fp, "%*[^\n]");
    //    }
    //    printf("%d", it);
    //    if (it>skipl) {
    //    fscanf(fp, "%s %s", input, output);
    //    printf("%s %s", input, output);}
    //    it = it + 1;
    //}

    fclose(fp);
    if (m<n) {
        garbage = n - m;
    }

   FILE *fp2;
   printf("Enter name of a file you wish to save as\n");
   gets(file_name2);
   //it = 0;
   // while (it < 9) {
   //     printf( "%d %d", input[it], output[it]);
   //     it = it + 1;
   // }
   fp2 = fopen(file_name2, "w"); // read mode

    fputc('#',fp2);
    printf("Enter comment for the circuit file you wish to save \n");
    gets(text);
    fputs(text,fp2);
    fputc('\n',fp2);
    // total number of variables
    fputs(".numvars ",fp2);
    fprintf(fp2,"%d",(m+n));
    fputs("\n",fp2);
    //
    fputs(".variables \n",fp2);
    fputs(".inputs \n",fp2);
    fputs(".outputs \n",fp2);
    fputs(".constants \n",fp2);
    fputs(".garbage \n",fp2);
    fputs(".begin \n",fp2);
    //fprintf(fp2,"t%d",(ntoff));
    fputs(".end \n",fp2);
    fclose(fp2);
   return 0;
}

