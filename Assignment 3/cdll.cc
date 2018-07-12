#include "cdll.h"
#include <iostream>
#include<string>
#include <algorithm>

CDLLNode::CDLLNode(const char *ti, const char *tw) {
    time = ti;
    tweet = tw;
    next = NULL;
    prev = NULL;

}
CDLLNode::~CDLLNode() {
    // no dynamic memory allocation, nothing to destroy
}

CDLL::CDLL() {
    head = NULL;
    current = NULL;
}

CDLL::~CDLL() {
    // TODO: Needs to delete ALL elements from the list.
    CDLLNode*tempDel;
    while(!head){
        tempDel =head;
        head = head -> next;
        delete tempDel;
    }

}

void CDLL::prepend(const char *time, const char *tweet) {
    // TODO: Inserts a node at front.
    CDLLNode* temp; //temp pointer on the stack.like tail
    if(head == NULL){//when there are no elements in the list.
        CDLLNode *new_Node = new CDLLNode(time,tweet);  //contains the time and the tweet.
        head = new_Node;
        head->next = head;
        head->prev = head;
    }
    else{
        CDLLNode *new_Node = new CDLLNode(time,tweet);  //contains the time and the tweet.
        temp = head->prev;
        new_Node->next = head;
        new_Node->prev = temp;
        temp->next = head->prev=new_Node;
        head = new_Node;
    }
}
void CDLL::append(const char * time, const char * tweet) {
    //inserts a node at the end.
    if(head == NULL){//when there are no elements in the list
        CDLLNode *new_Node = new CDLLNode(time,tweet);//creates a new node on heap
        head = new_Node;
        head->next = head;
        head->prev = head;
    }
    else{
        CDLLNode *new_Node = new CDLLNode(time,tweet);
        CDLLNode *temp; //temp pointer on the stack.like tail.
        temp = head->prev;
        new_Node->next = head;
        head->prev = new_Node;
        temp->next = new_Node;
        new_Node->prev = temp;
    }
}

void CDLL::go_next() {
    // TODO.
    if(current){//if current exists move current to the next node.
        current = current->next;
    }
}

void CDLL::go_prev() {
    // TODO.
    if(current){//if current exists move current to prev node
        current = current->prev;
    }
}
//moves the current to the head.
void CDLL::go_first(){
    if (head){//if head exists go move the current to head
        current = head;
    }
}

void CDLL::go_last(){
    // TODO.
    if(head->prev){//head prev is the last guy.
        current = head->prev;
    }
}
void CDLL::skip(unsigned int n) {
    // TODO.
    for(unsigned int i = 0;i<n;i++){//goes through n number of times.
         if(current){
            current = current->next; //current = current->ntimes;
            }
    }
}
void CDLL::search(const char *word){
   CDLLNode* temp = current;//temp node to current pointer
   while(current->next != temp){// goes through the whole Cdll.
        current = current->next;//starts the loop at currents's next
        std::string copy = current->tweet;
        transform(copy.begin(),copy.end(),copy.begin(), ::tolower);
       //if the word is found in the current tweet.
       if(copy.find(word) != std::string::npos){  //finds a word in the current tweet
            return;
       }
   }
    current = current->next;//if the word id not found moves the pointer to the next.
}

void CDLL::print_current() {
    if (current) {
        std::cout << current->time.substr(0,19) << "    " <<current->tweet<< std::endl;
    }
}

void CDLL::print_all() {
    if (head) {
        CDLLNode *p = head;
        while (1) {
            std::cout << p->time << " ";
            if (p->next == head) {
                break;
            }else {
                p = p->next;
            }
        }
    }
    std::cout << std::endl;
}
