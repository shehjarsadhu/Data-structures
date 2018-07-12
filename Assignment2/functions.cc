//function to get the length of the string.
int strlens(const char *str){
    int length = 0;
    for (int i=0; str[i] != '\0'; i++){
        length++;
    }
    return length;
}
/*Function that takes 2 pointers as parameters */
void q1_swap(int *a, int *b){
    int temp;
    // Swaping contets of the pointer by dereferencing them.
    temp  = *a;
    *a = *b;
    *b = temp;
}
/*
    Question 1 : Inversions.
   -------------------------
*/
unsigned int n_inversions(const int *A, unsigned int n){
    unsigned int counter = 0;
    for(unsigned int i = 1 ;i<n;i++){
        for(int j = i-1;j>=0;j--){
            if(A[i]<A[j]){
                counter++;
            }
        }
    }
    return counter;
}
/*
    Question 2 : lmod
    -------------------------
*/
unsigned int  l_mode(const int *A, unsigned int n){
    int count[1001];
    int possAs[1001];  //contains all the possible values that can be in the array -500 to 500.
    int counterPoss = -500;
    for(int i = 0 ; i <1001;i++){
        count[i] =0; //setting the new array to 0 .
        //put things in poss array.
        possAs[i] = counterPoss;
        counterPoss++;
    }
    for(unsigned int j = 0 ; j <n;j++){
        count[A[j]+500]++;
    }
    //finding the max.
    int max = 0 ;
    int index = 0;
    for(int k = 0 ; k<1001;k++){
        if(count[k]>max){
            index = k;    //this is the index of the max ouccuring feq .
            max = count[k];
        }
    }
    for(unsigned int l = 0 ; l<n ; l++){
        //searching for the right frequency!
        if(A[l] == possAs[index]){
            return l;
        }
    }
}
/*
    Question 3 :-
   --------------
*/
unsigned int unique_letters(const char *S){
    //to convert the const char's to chars so that we can modify them.
   // char copy[strlens(S) + 1];
    char *copy = new char[strlens(S) + 1];
   //  int counter = 0 ;
    for(int i = 0 ; S[i]!='\0';i++){
        copy[i] = S[i];
       //counter++;
    }
   // copy[counter] ='\0';
//use copy :-
 //To convert the address into lower case letters.
    for (int i = 0; copy[i]!='\0'; i++){
		if (copy[i] >= 'A' && copy[i] <= 'Z'){
			copy[i] = copy[i] + 32;
		}
	}
	int count[26];
    for(int k= 0 ; k <26;k++){
        count[k] =0;//sets the count array to zeros.

    }
    for(int i = 0 ; copy[i] != '\0';i++){
             //because we are looking for characters only
        switch(copy[i]){
            case  'a': count[0]++;
            break;
            case  'b': count[1]++;
            break;
            case  'c': count[2]++;
            break;
            case  'd': count[3]++;
            break;
            case  'e': count[4]++;
            break;
            case  'f': count[5]++;
            break;
            case  'g': count[6]++;
            break;
            case  'h': count[7]++;
            break;
            case  'i': count[8]++;
            break;
            case  'j': count[9]++;
            break;
            case  'k': count[10]++;
            break;
            case  'l': count[11]++;
            break;
            case  'm': count[12]++;
            break;
            case  'n': count[13]++;
            break;
            case  'o': count[14]++;
            break;
            case  'p': count[15]++;
            break;
            case  'q': count[16]++;
            break;
            case  'r': count[17]++;
            break;
            case  's': count[18]++;
            break;
            case  't': count[19]++;
            break;
            case  'u': count[20]++;
            break;
            case  'v': count[21]++;
            break;
            case  'w': count[22]++;
            break;
            case  'x': count[23]++;
            break;
            case  'y': count[24]++;
            break;
            case  'z': count[25]++;
            break;
        }

    }
   unsigned int countUniq = 0;
   for(int i = 0 ; i<26 ;i++){
        if(count[i]>0){
            countUniq++;
        }
    }
    delete[]copy;
    return countUniq;
}
/*
   Question 4 : palindrome.
   ------------------------
*/
bool palindrome(const char *S, unsigned int n){
//base case there is only one element -> true.
    if(n==1|| n==0){
        return true;
    }
    return (*S == S[n-1]) ? palindrome(S+1, n-2) : false;
}

/*
    Question 5:-
   -------------
*/
void r_selection_sort(int *A, unsigned int n){
    unsigned int maxIn = 0, temp = 0, i = 0;
    for (i = maxIn ; i<n; i++){
        if (A[i]>A[maxIn] ) {
            maxIn = i;
        }
    }
    //performing the swap.
    temp = A[n-1];
    A[n-1] = A[maxIn];
    A[maxIn] = temp;
    //recursive call.
    if(n>1){ // number of elements can't be 0.
        r_selection_sort(A,n-1);
    }
}
/*
    Question 6 :
    -------------------------
*/
bool isVowel(const char*V){
    for(int i = 0 ; V[i]!='\0';i++){
        if(V[i] =='a'|| V[i] =='e'||V[i] =='i'||V[i] =='o'||V[i] =='u'||V[i] =='A'|| V[i] =='E'||V[i] =='I'||V[i] =='O'||V[i] =='U'){
            return true;

        }else{
            return false;
        }
    }
}
bool v_sorted(const char *A){
        int n = strlens(A);
        if(isVowel(A) == true && n==1){
            return true;
        }
        else if(isVowel(A) == false){
            return true;
        }
    if(A[n-1] > A[n-2] && isVowel(A) == true){
        return true;
        v_sorted(A+1);

    }
    else if(A[n-1] < A[n-2] &&isVowel(A) == true){
        return false;
        v_sorted(A+1);

    }

}

/*
    Question 7 : Suffix Sum.
    -------------------------
*/
unsigned long int suffix_sum(unsigned int n, unsigned int s){
    return (s==1) ?  n : (n + suffix_sum(n-1, s-1));
}
/*
    Question 8 : Order.
    -------------------
*/
int order(const int *A, unsigned int n){
    if(n==2){
        if(A[n-1]>A[n-2]){
            return 1;
        }
         else if(A[n-1]<A[n-2]){
            return -1;
        }
        else if(A[n-1]==A[n-2]){
            return 0;
        }
    }
    int ordeVal = order(A,n-1);
    if(ordeVal == 1 && A[n-1]>A[n-2]){
        return 1;
    }
    else if(ordeVal == -1 && A[n-1]<A[n-2]){
        return -1;
    }
    else{
        return 0;
    }
}
