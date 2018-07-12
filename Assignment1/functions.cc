/*
    Library Helper Functions.
    --------------------------
*/
//power function to calculate the power of a number eg: 2^2 = 4.
unsigned int pows(unsigned int num, unsigned int powss){
	if (powss <= 0){
		return 1;
	}
	else{
	    return num * pows(num, powss-1);
	}
}
//function to get the length of the string.
int strlens(const char *str)
{
    int length = 0;
    for (int i=0; str[i] != '\0'; i++){
        length++;
    }
    return length;
}

    /*
        Question 1:-
        ------------
    */

void sort_three(int a, int b, int c,int* list){
    //
    if(a<b){
        if(a<c){
            if(b<c){        //a is the smallest!
                list[0] = c;
                list[1] = b;
                list[2] = a; //a
            }
            else{                   //c <= b : a < c <= b
                list[0] = b;
                list[1] = c;
                list[2] = a;
            }
        }
        else{       //a >= c : c <= a < b.
            list[0] = b;
            list[1] = a;
            list[2] = c;
        }
    } //end if 1st one!
    else{
        if(b<c){
            if(a<c){        //b is the smallest!  b <= a < c
                list[0] = c;
                list[1] = a;
                list[2] = b; //b
            }
            else{  //??             a >= c  : b < c <= a
                list[0] = a;
                list[1] = c;
                list[2] = b;  //
            }
        }
        else{       //if b is not the smallest c is!   c <= b  : c <= b <= a
            list[0] = a;
            list[1] = b;
            list[2] = c;
        }
    }
}
/*
    Question 2:
    ------------
*/


bool isPrime(unsigned int n){
    //checking for edge cases 0 and 1
    if(n == 0 || n==1){
        return false;
    }
    //checks if the number is prime or not.
    else{
        for(unsigned int i = 2 ; i<n;i++){
            if(n%i==0){
                return false;
            }

        }
        return true;
    }

}
bool circular_prime(unsigned int n){
    unsigned int temp = n;
    unsigned int counter = 0;
    bool decider = 0;
    //loop to count the number of power required.
    while(temp>0){
        temp/=10;
        counter++;
    }
    unsigned int num = n;
    unsigned int count = 0;
    //loop through the number of digits
    while(isPrime(num)){
        unsigned int rem = num%10;
        unsigned int divi = num/10;
            //find all the rotations of the number !
        num = (pows(10, counter - 1)) * rem + divi;

        //if it the same number we dont need it!
        if(num==n){
            decider = 1;
            break;
        }
         count++;
    }
    //retuns true if circular prime false other wise.
    if(decider == 1){
        return true;
    }
    else if(decider == 0){
        return false;
    }

}
/*
    Question 3 :-
   --------------
*/

/* Helper function:-
To returns an integer when the number is between '0' and '9' to int(0,1,2..)
respectively and return an int for the corresponding vale of 'A','B','C','D'
respectively.
*/
int convert(const char c)
{
    // for all decimal numbers.
    if (c >= '0' && c <= '9')
    {
        // to convert a char number into an integer.
        return (int)c - '0';
    }
    //for all alphabet conversions.
    else
    {
        //to convert an alphabet in the string of char into an integer.
        return (int)c - 'A' + 10;
    }
}
/*takes an int b which is the base of the number  system,an array which */
unsigned long int any2dec(const char *num, unsigned int b){
    unsigned long int power;
    unsigned long int sum = 0;//to store the calculated sum of the numbers.
    unsigned long int length = strlens(num);
    for(int i = length-1; i>=0;i--)
    {
        //formulae to convert the string into a decimal.
        power = pows(b,length-i-1)*convert(num[i]);
        sum = sum+power;
    }
    return sum;
}
/*
    Question 4:-
   ------------
*/
void hex2rgb(const char *hex, char *rgb){
    /*Getting the array of 2 characters in hexadecimal array.*/
    char r[3]={hex[1],hex[2]};
    char g[3]={hex[3],hex[4]};
    char b[3]={hex[5],hex[6]};
//Converts hex into decimal
    unsigned long int rr = any2dec(r, 16);
    unsigned long int gg = any2dec(g, 16);
    unsigned long int bb = any2dec(b, 16);

    /*
        CONVERTING THE INTS TO CHARACTERS.
    */
        //This is for the 1st number rr - RED.
    int ones = rr%10;
    char cones = (char)ones + '0';
    int leftover = rr/10;
    int tenths = leftover%10;
    char ctenths = (char)tenths + '0';
    int hunderedths = leftover/10;
    char chunderedths = (char)hunderedths + '0';

    //This is for the 2nd number gg GREEN - .
    int onesg = gg%10;
    char conesg = (char)onesg + '0';
    int leftoverg = gg/10;
    int tenthsg = leftoverg%10;
    char ctenthsg = (char)tenthsg + '0';
    int hunderedthsg = leftoverg/10;
    char chunderedthsg = (char)hunderedthsg + '0';

    //This is for the 3rd number bb - BLUE.
    int onesb = bb%10;
    char conesb = (char)onesb + '0';
    int leftoverb = bb/10;
    int tenthsb = leftoverb%10;
    char ctenthsb = (char)tenthsb + '0';
    int hunderedthsb = leftoverb/10;
    char chunderedthsb = (char)hunderedthsb + '0';

//Seting up the char array for the converted numbers.
    char rrr[4] = {chunderedths,ctenths,cones};        //.  RED
    char ggg[4] = {chunderedthsg,ctenthsg,conesg};        //.  BLUE
    char bbb[4] = {chunderedthsb,ctenthsb,conesb};        //1.  GREEN
    //------------------------------------------------------------------------------------------------------------------------------

  /*Here we start writing to the rgb array*/
   int counter = 0;
    rgb[0] = 'r';
    rgb[1] = 'g';
    rgb[2] = 'b';
    rgb[3] = '(';

     counter = 4; //to start putting number at 4.keps track of where you are in the loop
     bool findL0r = true; //to keep teack of the leading 0's
    // RED.
    //condition to check for  all 0's.
        if(rrr[0]=='0'&& rrr[1]=='0'&& rrr[2]=='0'){
                rgb[counter] = rrr[0];
                counter++;
            }
        else{
            //goes through the length of the the red array.
            for(int j = 0 ; j<strlens(rrr);j++){
                //inserts elements at the rigt place
                rgb[counter] = rrr[j];
                counter++;
                //leading zeros
                if(rrr[j]=='0'&&findL0r==true){
                    counter--;
        }
        else{
            findL0r = false;
        }
    }
}

    rgb[counter] = ',';
    counter++;
    // GREEN.
        if(ggg[0]=='0'&& ggg[1]=='0'&& ggg[2]=='0'){
                rgb[counter] = ggg[0];
                counter++;
            }
        else{
            bool findL0g = true;
            for(int k = 0;k<strlens(ggg);k++){
                rgb[counter] = ggg[k];
                counter++;
                //leading zeros
                if(ggg[k]=='0'&&findL0g==true){
                    counter--;
                }
                else{
                    findL0g = false;
                }
            }
        }


    rgb[counter] = ',';
    counter++;
 // BLUE.

    if(bbb[0]=='0'&& bbb[1]=='0'&& bbb[2]=='0'){
                rgb[counter] = bbb[0];
                counter++;
            }
    else{
        bool findL0b = true;
        for(int l = 0;l<strlens(bbb);l++){
            rgb[counter] = bbb[l];
            counter++;
            //leading zeros
            if(bbb[l]=='0' && findL0b==true){
                counter--;
            }
            else{
                findL0b = false;
        }
    }
}
    rgb[counter] = ')';
    rgb[(counter+1)] = 0; //sets the rest to null.
}


/*
    Question 5:-
   ------------
*/
//returns the number of ouccurences of the word intthe given string.
unsigned int str_search(const char *pattern, const char *text){
     unsigned int found =0;
    unsigned int counter = 0;
    unsigned int len1 = strlens(text);
    unsigned int len2=  strlens(pattern);
    //goes through text.
    for(unsigned int i = 0 ;i<len1;i++ ){
        found = 1;
        //goes through pattern.
        for(unsigned int j = 0 ; j<len2;j++){
            /*
            if the str is not found come out of the loop.
            */
            if(pattern[j]!= text[i + j] ){
                found = 0;
                break;
            }
        }
        //to count the number of oucurences of the str
        if(found == 1){
            counter++;
        }
    }
    return counter;
    }

/*
    Question 6:-
   ------------
*/

void to_hostname(char *address){
    int counter = 0 ; //to keep track where we are in the array.
    int len = strlens(address);
    //To conver the address into lower case letters.
    for (int i = 0; address[i]!='\0'; i++){
		if (address[i] >= 'A' && address[i] <= 'Z'){
			address[i] = address[i] + 32;
		}
	}
    //breaks at ://.To check for protocols.
    for(int i =0;i<len;i++){
        counter++;
        if(address[i] == '/'&& address[i+1]=='/'){
            break;
        }

    }
    //inserting the address.
    for(int j = 0 ; address[j] !='\0';j++){
        address[j] = address[counter+1];
        counter++;
        //takes care of the file path.
        if(address[j] == '/'){
            address[j] ='\0';
        }
        //to take care of the port number.
        if(address[j] ==':'&&address[j+1]!='/'){
            address[j] = '\0';
        }
    }
    address[counter] = '\0'; //sets the remainder to null.
}
