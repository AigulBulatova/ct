#include <iostream>


struct Node {
    int x;
    Node *next;
};

class List {
    Node *Head = NULL;
    Node *Tail = NULL;
    int size = 0;

    public:
    ~List ();
    void add (int x);  
    void delete_ (int number);  

    void show ();
    int count();
    
    //     void add (int x);
    // void add_end (int x);
    // void add_between (int x, int item);
};

int List::count ()
{
    return size;
}

List::~List ()
{
    while (Head != NULL)
    {
        Node *temp = Head->next;
        delete Head;
        Head = temp;
    }
}

void List::add (int x)
{
    size++;    

    Node *temp = new Node;                             
    temp->next = Head;                                  
    temp->x = x; 

    if (Head != NULL)                                   
    {
      Tail->next = temp;                                
      Tail = temp;                             
    }
    else Head = Tail = temp;  

    return;
}

void List::delete_ (int number)
{
    if (number > size) {
        std::cout << "cannot delete an item with this number";
        return;
    }

    Node *temp = Head, *prev = NULL;
    int i = 0;

    while (temp && i < number)
    {
        i++;
        prev = temp;
        temp = temp->next;
    }

    if (Head == temp) {
        Head = temp->next;
    }
    else {
        if (prev)
            prev->next = temp->next;
    }

    size--;
    free (temp);

    return;
}

void List::show ()
{
    Node *tempHead = Head;

    for (int i = 0; i < size; ++i) {
        std::cout << tempHead->x << " ";
        tempHead = tempHead->next;
    }

    return;
}

int main()
{
    List list1;

    list1.add(10);
    list1.add (20);

    list1.show();
    //list1.~List();

    return 0;
}







// void List::add (int x, int number)
// {
//     size++;

//     if (number > size) {
//         std::cout << "cannot add item with this number";
//         return;
//     }
    

//     else if (number == 1 || number == size) {
//         Node *new_node = new Node;
//         new_node->next = Head;
//         new_node->x = x;

//         if (Head != NULL) {
//             Tail->next = new_node;
//             if (number == 1) {
//                 Head = new_node;
//             }
//             else Tail = new_node;
//         }

//         else {
//             Head = Tail = new_node;
//             new_node->next = new_node;
//         }
//     }

//     else {
//         // if (Head == NULL) {
//         //     Head = new Node;
//         //     Head->x = x;
//         //     Head->next = Head;
//         //     Tail = Head;
//         // }
//         Node *temp = Head;

//         for (int i = 0; temp && i < number - 1; i++) {
//             // prev = temp;
//             temp = temp->next;
//         }

//         Node *new_node = new Node;
//         new_node->x = x;
//         new_node->next = temp->next;
//         temp->next = new_node;

//     }

//     return;
// }

// void List::add_begin (int x)
// {
//     size++;
//     Node *temp = new Node;

//     temp->next = Head;
//     temp->x = x;

//     if (Head != NULL) {
//         Tail->next = temp;
//         Head = temp;
//     }
//     else {
//         Head = Tail = temp;
//     }

//     return;
// }

// void List::add_end (int x) 
// {
//     size++;
//     Node *temp = new Node;
//     temp->x = x;
//     temp->next = Head;

//     if (Head == NULL) {
//         Head = Tail = temp;

//     }

//     Tail->next = temp;
//     Tail = temp;

//     return;
// }



// void List::add_between (int x, int item)
// {
//     Node *temp = NULL;
//     Node *p = Head;

//     do 
//     {
//         if (p->x == item) {
//             temp = new Node;

//             temp->x = x;
//             temp->next = p->next;
//             p->next = temp;

//             if (p == Tail) {
//                 Tail = temp;
//             }
//             return;
//         }
//         p = p->next;
//     }
//     while (p != Head);

//     std::cout << item << " not present in the list." << std::endl;

//     return;
// }