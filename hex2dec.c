#include <stdio.h>
#include <string.h> 
#include <stdlib.h>
#include <math.h>

// globals
int bitops;                             // yes or no option set, can probably use this is gui version

long isd=0;                             // results which are passed between functions 
char ish[15];
char isb[25];
char isa[12];

void show_resv(void)                    // reserved or not completed message
{ 
        fflush(stdin);
        
        printf("\n\nThis section is reserved for furture use.\nPress <Enter> to return.");

        getchar();
        return;
        
}

void showascii(void)                    // show ascii chart 
{
        printf("\n\n   [ Notation:   Dec, Hex = Ascii ]\n");
	
	printf("\n  32, 20 =     33, 21 = !   34, 22 = \"   35, 23 = #   36, 24 = $   37, 25 = %%   38, 26 = &   39, 27 = \' "); 
	
	printf("\n  40, 28 = (   41, 29 = )   42, 2A = *   43, 2B = +   44, 2C = ,   45, 2D = -   46, 2E = .   47, 2F = / ");
	
	printf("\n  48, 30 = 0   49, 31 = 1   50, 32 = 2   51, 33 = 3   52, 34 = 4   53, 35 = 5   54, 36 = 6   55, 37 = 7 ");  
	
	printf("\n  56, 38 = 8   57, 39 = 9   58, 3A = :   59, 3B = ;   60, 3C = <   61, 3D = =   62, 3E = >   63, 3F = ? "); 
	
	printf("\n  64, 40 = @   65, 41 = A   66, 42 = B   67, 43 = C   68, 44 = D   69, 45 = E   70, 46 = F   71, 47 = G ");
	 
	printf("\n  72, 48 = H   73, 49 = I   74, 4A = J   75, 4B = K   76, 4C = L   77, 4D = M   78, 4E = N   79, 4F = O ");
	
	printf("\n  80, 50 = P   81, 51 = Q   82, 52 = R   83, 53 = S   84, 54 = T   85, 55 = U   86, 56 = V   87, 57 = W ");
	
	printf("\n  88, 58 = X   89, 59 = Y   90, 5A = Z   91, 5B = [   92, 5C = /   93, 5D = ]   94, 5E = ^   95, 5F = _ ");
	
	printf("\n  96, 60 = `   97, 61 = a   98, 62 = b   99, 63 = c  100, 64 = d  101, 65 = e  102, 66 = f  103, 67 = g ");
	
	printf("\n 104, 68 = h  105, 69 = i  106, 6A = j  107, 6B = k  108, 6C = l  109, 6D = m  110, 6E = n  111, 6F = o ");
	
	printf("\n 112, 70 = p  113, 71 = q  114, 72 = r  115, 73 = s  116, 74 = t  117, 75 = u  118, 76 = v  119, 77 = w ");
	
	printf("\n 120, 78 = x  121, 79 = y  122, 7A = z  123, 7B = {  124, 7C = |  125, 7D = }  126, 7E = ~\n");

        printf("\n\nPress <Enter> to continue.");
        fflush(stdin);
        getchar();
        
        return;
}

void submenu(void)                      // menu for "do another", ascii chart, bit operations 
{
        int x=1;
        
        while(x != 0)
        {
      
        printf("\n\nPlease enter :\n\nA - ASCII chart\nB - Bitwise operations\nC - Convert another number\nQ - Quit\n\n    >> ");

        fflush(stdin);
        x = getchar();
  
                switch(x)
                {
                        case 'A':
                        case 'a':
                        printf("ASCII chart\n");
                        showascii();
                        break;
                        
                        case 'B':
                        case 'b':
                        show_resv();
                        
                        case 'C':
                        case 'c':
                        show_resv();
                        
                        default:
                        x=0;
                }
        }
        return;
}

void isansi(void)                       // get ANSI equivelant if possible
{
        if(( isd >= 0x20  && isd <= 0x7e )) // || ( isd >= 161 && isd <= 255))
	{
                sprintf(isa,"%c",(int)isd);

	}
	else
		sprintf(isa,"Non-ASCII");

}

void ltoa(long int n, char s[])         // long int to ascii
{
      int i, j, sign;
       char c;
 
     if ((sign = n) < 0)  /* record sign */
         n = -n;          /* make n positive */
     i = 0;
     do {       /* generate digits in reverse order */
         s[i++] = n % 10 + '0';   /* get next digit */
     } while ((n /= 10) > 0);     /* delete it */
     if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
 
 for (i = 0, j = strlen(s)-1; i<j; i++, j--) {
         c = s[i];
         s[i] = s[j];
         s[j] = c;
     }
}

void tobin(void)                        // Decimal to Binary
{	
	int cht[] = {32768,16384,8192,4096,2048,1024,512,256,128,64,32,16,8,4,2,1};
	char bits[] = {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0'};
	int t=0;
	long n3;
	
	n3 = isd;
	for(;;)	{
		
	if( n3 == cht[t] ) { bits[t] = '1'; break; } 
		if( n3 < cht[t] && n3 > cht[t+1] )
			{
				bits[t+1] = '1'; 
				n3 = n3 - cht[t+1];
			}
					
		t++;
	}
			
	sprintf(isb,"%c%c%c%c %c%c%c%c %c%c%c%c %c%c%c%c",bits[0], bits[1], bits[2], bits[3], bits[4],	bits[5] ,
	bits[6] ,bits[7] ,bits[8] ,bits[9] ,bits[10] ,bits[11] ,bits[12] ,bits[13] ,bits[14] ,bits[15]);
				
	return;
}
	
void d2h(void)                          // decimal to hex
{
	sprintf(ish,"0x%lX",isd);        
}

void parn(char dnum[])                  // take spaces out of a binary number entered.  can probably use this is gui version
{
        int z,a,ct=0;
        char fnum[25];
        
        z=strlen(dnum);

        for(a=0;a<z;a++)
        {
                if(dnum[ct] == '\n') {break;}
                if(dnum[ct] == ' ') {ct++;}
                fnum[a]=dnum[ct];
                ct++;
        }
        
        fnum[ct-1]='\n';
        fnum[ct]='\0';
        
        printf("\n the new binary is %s, the old binary was %s\n",fnum,dnum);
        return;
}
        
char getnumtype(char cnum[])            // catagorize num - H=hex, D=Dec etc.  can probably use this is gui version
{
        int x,y,z;
        char isnum = 'D';
        
        if(cnum[1] == 'x' || cnum[1] == 'X') { isnum = 'H';}
        if(cnum[4] == ' ' && cnum[5] > 2 ) { parn(cnum); isnum = 'B';}

        if(cnum[4] == '\n' && isnum != 'H' && isnum != 'B')
        {
                for(x=0;x<4;x++)
                {
                        putchar(cnum[x]);
                        if(cnum[x] != '0' && cnum[x] != '1')
                        {
                                isnum = 'D';
                                break;
                        }
                }
 
                for(;;) {
                fflush(stdin);
                printf("\nIs this number binary (y/n)? ");
                y=getchar();
                if( y == 'y' || y == 'Y') { isnum = 'B'; break;}
                if( y == 'n' || y == 'N') { isnum = 'D'; break;}
                printf("\nPlease enter y or n only!\n");
                }
        }

        if(cnum[1] == '\n')
        {
                z=(int)cnum[0];

                if(z > 31 && z <127) {isnum = 'A';}
        }

        return isnum;
}
        
void mainresult(void)                   // show results ask if binary ops
{
        int y;
        fflush(stdin);
        
        printf("\n\nDecimal    : %ld",isd);
        printf("\nHexdecimal : %s",ish);
        printf("\nBinary     : %s",isb);
        printf("\nANSI       : %s",isa);
        
        printf("\n\nEnter <M> for menu or <Enter> to quit : ");

        fflush(stdin);
        y=getchar();
        
        if( y == 'M' || y == 'm')
        {
                submenu();
        }
        
        return;
}

void amenu(char ach[])                  // converts the character type to ansi 
{
        char x;
        int y;
        
        x = ach[0];
        
        isa[0] = x;
        isa[1] = '\0';
  
        y = (int)isa[0];
        isd = y;
        
        d2h();
        tobin();
        mainresult();

        return;
                
}

void hmenu(char entry[])                // convert hex [string] to Decimal number
{
	char asi[15];    
	char hnum[15]; 
	int x=0;
	int y=0;
	char z[15];
	int b;
	char ans;
  	int c;
	long d=0;
	int e=0;	

// strip '\n' and preceeding '0x'
        
        b=strlen(entry);
        strcpy(ish,entry);
        ish[b-1] = '\0';
        
        for(x=0;x<b;x++)
        {
                ans = entry[x];
                
                if(ans == '\n' || ans == '\0')
                {
                        asi[x-2] = '\0';
                        strcpy(ish,asi);
                        break;
                }

                asi[x]=entry[x+2];
        }

        strcpy(hnum,asi);

        
        y=strlen(hnum);
        b=y;

        for(x=0;x<y;x++)
        {
                b--;
                z[x]=hnum[b];    
                
                if( b == 0 ) { break; }
        }

        z[x+1] = '\0';    

        for(x=0;x<y;x++)   {
        if(z[x] == 'a' || z[x] == 'A')  {   c=10; } else
        if(z[x] == 'b' || z[x] == 'B')  {   c=11; } else
        if(z[x] == 'c' || z[x] == 'C')  {   c=12; } else
        if(z[x] == 'd' || z[x] == 'D')  {   c=13; } else
        if(z[x] == 'e' || z[x] == 'E')  {   c=14; } else
        if(z[x] == 'f' || z[x] == 'F')  {   c=15; } 
	else {
	        c = z[x] - 48;
        }
                e= pow(16,x);
                d = d + (c * e);
        }

        isd = d;
        tobin();
        isansi();
        mainresult();
        
        return;

}

void dmenu(char num[])                  // convert number entered from string to long decimal 
{
        isd=strtol(num,0,10);

        d2h();
        tobin();
        isansi();
        mainresult();

        return;
}

void getastring(char bnum[])            // gets a string from user input
{
        int x;
        int a;
        
        fflush(stdin);
        for(x=0;x<25;x++)
        {
                a=getchar();
                bnum[x]=a;
                if(a == '\n') {break;}
        }
        bnum[x+1]='\0';
        return;
}
        
int main(int argc, char *argv[])
{
        char a;
        char anum[15];
        
        if(argc > 1)
        {
                strcpy(anum,argv[1]);

                
        }
        else
        {
                printf("\n\nHex and Decimal Number Converter");
                printf("\n--------------------------------");

                printf("\n\nEnter the number be converted (use 0x for hex): ");
                getastring(anum);
        }

        a=getnumtype(anum);
        
        switch(a)
        {
                case 'D':
                dmenu(anum);
                break;
                
                case 'H':
                hmenu(anum);
                break;
                
                case 'B':
                show_resv();
                break;
                
                case 'A':
                amenu(anum);
                break;
                
        }
        
        printf("\nNumber %s type %c\n",anum,a);
        
        return 0;
}
