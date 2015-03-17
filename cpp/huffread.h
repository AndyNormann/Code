struct tree_leaf{
    std::string word;
    int count;
};

void read_file(std::vector<tree_leaf> *list, const std::string filename);
bool in_list(std::string word, std::vector<tree_leaf> *list);
void add_to_list(std::string word, std::vector<tree_leaf> *list);
void print_list(std::vector<tree_leaf> *list);
bool leaf_sort(const tree_leaf &t1, const tree_leaf &t2);

void read_file(std::vector<tree_leaf> *list, const std::string filename)
{
    //The file to read;
    std::ifstream infile(filename);
    //The current word we're reading
    std::string word;

    while(infile >> word){
        switch(word.back()){
            case ',':
                add_to_list(",", list);
                word.pop_back();
            case '.':
                add_to_list(".", list);
                word.pop_back();
        }
        add_to_list(word, list);
    }
    infile.close();
}

//Prints the words and frequencies in the given list
void print_list(std::vector<tree_leaf> *list)
{
    for (auto &t : *list) {
        std::cout << t.word << "  " << t.count << std::endl;
    }
}

//Adds a word to the list, if the word is in the list the frequency is incremented
void add_to_list(std::string word, std::vector<tree_leaf> *list)
{
    if(!in_list(word, list)){
        tree_leaf cur;
        cur.word = word;
        cur.count = 1;
        (*list).push_back(cur);
    }
}

//Returns true and increments the frequency if the word is in the list, returns false otherwise
bool in_list(std::string word, std::vector<tree_leaf> *list)
{
    for (auto &t : *list) {
       if(word.compare(t.word) == 0){ 
           t.count++;
          return true; 
       }
    }
    return false;
}

bool leaf_sort(const tree_leaf &t1, const tree_leaf &t2)
{
    return t1.count < t2.count;
}
