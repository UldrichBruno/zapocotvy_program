using namespace std;

struct Element
{
    string name;
    string surname;
    float age;
    Element *prev;
    Element *next;
};

class Database {
public:
    Element *head;
    Element *tail;
    Database();
    ~Database();
    void add_to_beginning(string name, string surname, float age);
    void add_to_end(string name, string surname, float age);
    void delete_first();
    bool is_empty();
    void print();
    float average_age();
    float num_of_ages();
    float sum_of_ages();
};


