#ifndef __BOARD_H__
#define __BOARD_H__
#include <vector>
#include <functional>
/*class searchNode  {
    private:
        unsigned int n;
        unsigned int num_Moves;//number of moves made to reach the board.
        unsigned int *bb= new unsigned int[n];
        char types;
        Board currentBoard(bb,n,num_Moves,types);
    public:
        searchNode(unsigned int *current_b, unsigned int n_moves);
        ~searchNode();
};*/
class Board {
    private:
        // TODO.
        // define your data members and private methods here.
        unsigned int n_elem; //size of the board
        unsigned int l;//number of elements in theboard array.
        unsigned int *boardGrid ;  //each node is a separate puzzle state.
        unsigned int numMoves;//number of moves in the.
        unsigned int dist;
    public:
        // default constructor (for creating an empty board)
        Board();
        // full constructor
        // b: an initial board configuration
        // the board is just a sequence of numbers in row-major order (including the zero element)
        // n: number of elements in the board
        // m: an initial number of moves.
        // type: distance to be used 'm' for manhattan and 'b' for hamming
        Board(unsigned int *b, unsigned int n, unsigned int m, char type);
        // destructor
        ~Board();
        // verifies whether the board is solvable
        bool is_solvable();
        // verifies whether the board is a goal board
        bool is_goal();
        // returns in neigh a list of neighbors for this node
        void neighbors(std::vector<Board *> *neigh, char type);
        // gets the number of moves made so far (up to this node)
        unsigned int get_n_moves();
        // returns the hamming distance to the goal
        unsigned int hamming();
        // returns the manhattan distance to the goal
        unsigned int manhattan();
        // counts the number of inversions on a particular board
        unsigned int inversions();
        void print_board();
        friend class compare;
};
class compare{
    public:
        //overload the operator <.
        bool operator()( Board *b1, Board *b2){
            return b1->dist < b2->dist;
    }
};
#endif
