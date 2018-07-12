#include<iostream>
#include "board.h"
#include<cmath>
#include <queue>

// -----------------------------------------------------------------------
// -----------------------------------------------------------------------
// this is the main solver
// -----------------------------------------------------------------------
// b: an initial board configuration
// the board is just a sequence of numbers in row-major order (including the zero element)
// n: number of elements in the board
// type: distance to be used 'm' for manhattan and 'b' for hamming

void solve(unsigned int *b, unsigned int n, char type){
    // TODO.
    unsigned int num_moves = 0;
    Board *root= new Board(b, n, num_moves, type);
    Board *temp;
    std::vector<Board *> *board_vec = new std::vector<Board*>;
    //current_board->neighbors(&board_vec,type);
    //we have to create a priority queue that points to  boards.
    std::priority_queue<Board*, std::vector<Board* >, compare> pq;
    pq.push(root);
    bool check = 0 ;
    if(root->is_solvable() == 0){
        std::cout<<"Unsolvable: "<<std::endl;
        return;
    }
    do{
        temp = pq.top();
        pq.pop();
        if(temp ->is_goal()){
            std::cout<<"Number of moves: "<<temp->get_n_moves()<<std::endl;
            return;
        }
        temp->neighbors(board_vec,type);
        delete temp;
        for(unsigned int i = 0 ; i <board_vec->size();i++){
                pq.push(board_vec->at(i));
            }
  }while(!check);
}
// -----------------------------------------------------------------------
// -----------------------------------------------------------------------
// it all starts here
// -----------------------------------------------------------------------
int main(int argc, char **argv) {
    // reads the search type from a command line argument (either h or m)
    // reads all initial board values from the stdin.
    // calls the solver passing the values of the board and the search type.
    char type = *argv[1];
    unsigned int num;
    std::cin>>num;
    unsigned int  n_elements = num*num;
    unsigned int p[n_elements];
    for(unsigned int i = 0 ; i <n_elements;i++){
        std::cin>>p[i];
    }
    solve(p,n_elements,type);

    return 0;
    // ...
}
