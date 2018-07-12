#include "cdll.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

void read_file(const char *fname, CDLL *list) {
    std::ifstream myfile(fname);
    if (myfile) {
        std::string line;
        std::string tweet_id, tweet_time, tweet_text;
        // for each line in file
        while (getline(myfile,line)) {
            // splits the line by the delimiter '|'
            std::istringstream mystream(line);
            std::getline(mystream, tweet_id, '|');
            std::getline(mystream, tweet_time, '|');
            std::getline(mystream, tweet_text, '|');
            // -------------------------------------------
            // TODO - insert tweet into your CDLL
            // -------------------------------------------
            const char* times = tweet_time.c_str();
            const char* tweet = tweet_text.c_str();
            list->prepend(times, tweet);
        }
        myfile.close();
    }
}

int main(int argc, char *argv[]) {
    // creates an empty linked list
    CDLL list;
    // reads the contents of input file and insert tweets into list
    read_file(argv[1], &list);
    // main loop: waits for user interaction
    std::string command, word;
    // set current to the first element in the list.
    list.go_first();
    while (true) {
        // prints the `current` tweet
        list.print_current();
        // reads entire line from user
        std::getline(std::cin, command);
        // creates a tokenizer to iterate over words
        std::stringstream tokens(command);
        // gets the first word from `tokens`
        tokens >> word;
        if (!word.compare("n")) {
            // TODO: move `current` to next.
            list.go_next();
        }
        if (!word.compare("p")) {
            // TODO: move `current` to previous.
            list.go_prev();
        }
        if (!word.compare("f")) {
            // TODO: move `current` to first
            list.go_first();
        }
        if (!word.compare("l")) {
            // TODO: move `current` to last.
            list.go_last();
        }
        if (std::all_of(word.begin(), word.end(), ::isdigit)) {
            int skip = std::stoi(word);
            // TODO: move `current` to `skip` positions ahead (circularly).
            list.skip((unsigned int)skip);

        }
        if (!word.compare("s")) {
            tokens >> word;
            // TODO: move `current` to the next occurrence of `word`.n
            list.search(word.c_str());
        }
        if (! word.compare("q")) {
            break;
        }
    }
}
