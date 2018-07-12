#include<iostream>
#include<cmath>
#include "board.h"
unsigned int* swap_neighs(const unsigned int *arr, unsigned int n, int a, int b){
    unsigned int *new_neigh = new unsigned int[n];
    for(unsigned int i = 0; i < n; i++){
        new_neigh[i] = arr[i];
    }
    unsigned int temp = new_neigh[a];
    new_neigh[a] = new_neigh[b];
    new_neigh[b] = temp;
    return new_neigh;
}
Board::Board(){
    n_elem = 0;//size of the board
    unsigned int *boardGrid = new unsigned int[n_elem];//each node is a separate puzzle state.
    numMoves = 0;//number of moves in the.
    }
Board::Board( unsigned int *b, unsigned int n, unsigned int m, char type){
    // b: an initial board configuration.
    // the board is just a sequence of numbers in row-major order (including the zero element).
    // n: number of elements in the board.
    // m: an initial number of moves.
    // type: distance to be used 'm' for manhattan and 'b' for hamming.
    boardGrid =b;
    n_elem = sqrt(n);//3
    l = n;/*(n_elem*n_elem)*/;
   // std::cout<<"n_elem constructor: "<<n_elem<<std::endl;
    //std::cout<<"l constructor: "<<l<<std::endl;
    numMoves = m;
   /* unsigned int *boardGrid = new unsigned int[n_elem];//each node is a separate puzzle state.
    for(unsigned int i = 0 ; i<l;i++){
        boardGrid[i] =b[i];
    }*/
}
Board::~Board(){
    /*if(boardGrid!=NULL){
        delete[] boardGrid;
    }*/

}
// verifies whether the board is solvable
bool Board::is_solvable(){
    unsigned int num_inv = inversions();
   // unsigned int blank_index =0;
    int blank_row =0;
    for(unsigned int i = 0 ; i<l;i++){
        if(boardGrid[i] == 0){
            //blank_index = i;
            blank_row = i/n_elem;
        }
    }
    if((l%2) != 0 && num_inv%2 == 0){    //the board size is odd and number of inversions == EVEN
        return true;//board is solvable..
    }
    else if((l%2) == 0 && (num_inv+blank_row)%2 != 0){  //the board size is even
        return true;//not solvable..
        }
    return false;
}
// verifies whether the board is a goal board.
bool Board::is_goal(){
    bool temp = true;
        for(unsigned int i = 0 ;i<l-1;i++){
            //std::cout<<i<<"The value at i: "<<boardGrid[i]<<std::endl;
            if(boardGrid[i]-1 == i){
                temp = true;
             //   return true;
            }
            else{
                temp = false;
                break;
               // return false;
            }
        }
        return temp;
    }

// returns in neigh a list of neighbors for this node
void Board::neighbors(std::vector<Board *> *neigh, char type){
    unsigned int blank_row;
    unsigned int blank_col;
    unsigned int blank_index;
   for(unsigned int i = 0 ; i<l; i++){
            if(boardGrid[i] == 0){
                blank_index = i;
                blank_row = (blank_index/n_elem);
                blank_col = (blank_index%n_elem);
                i = l;
            }
        }
   //down.
    if(blank_row!= n_elem - 1){
        //create the neibour swapped board.
        unsigned int *new_board1 = swap_neighs(boardGrid, l, blank_index, blank_index + (n_elem));
        Board *new_neighbour1 = new Board(new_board1, l, numMoves + 1, type);
        /*std::cout<<"down: "<<std::endl;
        new_neighbour1->print_board();
        std::cout<<std::endl;*/
        //update the pointer to neigh. Which points to the new board.
        neigh->push_back(new_neighbour1);
    }
    //up.
    if(blank_row != 0){
        //create the neibour swapped board.
        unsigned int *new_board2 = swap_neighs(boardGrid, l, blank_index, blank_index - (n_elem));
        Board *new_neighbour2 = new Board(new_board2, l, numMoves + 1, type);
        //update the pointer to neigh. Which points to the new board.
        /*std::cout<<"up: "<<std::endl;
        new_neighbour2->print_board();
        std::cout<<std::endl;*/
        neigh->push_back(new_neighbour2);
    }
    //left.
    if(blank_col != 0){
        //create the neibour swapped board.
        unsigned int *new_board3 = swap_neighs(boardGrid, l, blank_index, blank_index - 1);
        Board *new_neighbour3 = new Board(new_board3, l, numMoves + 1, type);
        /*std::cout<<"left: "<<std::endl;
        new_neighbour3->print_board();
        std::cout<<std::endl;*/
        //update the pointer to neigh. Which points to the new board.
        neigh->push_back(new_neighbour3);
    }
    //right.
    if(blank_col != n_elem - 1){
        //create the neibour swapped board.
        unsigned int *new_board4 = swap_neighs(boardGrid, l, blank_index, blank_index + 1);
        Board *new_neighbour4 = new Board(new_board4, l, numMoves + 1, type);
        //update the pointer to neigh. Which points to the new board.
        /*std::cout<<"right: "<<std::endl;
        new_neighbour4->print_board();
        std::cout<<std::endl;*/
        neigh->push_back(new_neighbour4);
    }
}

 // gets the number of moves made so far (up to this node)
unsigned int Board::get_n_moves(){
        return numMoves;
    }
     // returns the hamming distance to the goal.
unsigned int Board::hamming(){
    unsigned int count = 0;
    //number of positions  which are not in order.
    for(unsigned int i = 0 ; i<l-1;i++){
        if((boardGrid[i]-1) != i){
            count++;
        }
        else if(boardGrid[i] == 0){
            continue;
        }
    }
    return count;
}
    // returns the manhattan distance to the goal
unsigned int Board::manhattan(){
    unsigned int colDist = 0; //column position on the unsolved board.
    unsigned int rowDist = 0; //row position on the unsolved board.
    unsigned int colDistCurrrent=0;  //correct column position on the board.
    unsigned int rowDistCurrrent=0;  //correct row position on the board.
    unsigned int manhatNum = 0; //manhattan distance of each element on the board
    unsigned int colDiff=0; //CORRECT column coordinate that the number is suppose to be in.
    unsigned int rowDiff=0; //CORRECT row coordinate that the number is suppose to be in.
    unsigned int manhattSum[l];  //contains the manhattan distance of each number in the board.
    unsigned int sum = 0;  //total manhattan distance.
    for(unsigned int i = 0 ;i<=l-1;i++){
         if(boardGrid[i]==0){
                continue;
            }
                // get CURRENT WRONG row and cols.
            colDistCurrrent = i%n_elem;
            rowDistCurrrent = (i/n_elem);
                //get the CORRECT rows and cols.
            colDist =  (boardGrid[i]-1)%n_elem ;
            rowDist =   (boardGrid[i]-1)/n_elem;

            colDiff = abs(colDistCurrrent-colDist);
            rowDiff = abs(rowDistCurrrent-rowDist);
            manhatNum = abs(colDiff+rowDiff);
            manhattSum[i] = manhatNum;
            sum = sum + manhattSum[i];
        }
        return sum;
    }
// counts the number of inversions on a particular board
unsigned int Board::inversions(){
    unsigned int counter = 0;
    for(unsigned int i = 1 ;i<l;i++){
       if(boardGrid[i]!=0){
           for(int j = i-1;j>=0;j--){
              if(boardGrid[j] != 0){
                    if(boardGrid[i]<boardGrid[j]){
                        counter++;
                    }
               }
           }
        }
    }
    return counter;
}


void Board::print_board() {
    // the loop below assumes that `N` is the length of your array,
    // if you have another variable name for this, please adjust
    // the code properly
    // (for a 3 by 3 board, the value of N is 9)
    // also, if you have another name for `board` just replace it below
    for (unsigned int i = 0 ; i < l ; i ++) {
        std::cout << boardGrid[i] << " ";
    }
}
