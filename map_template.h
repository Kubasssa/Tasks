#include <iostream>
using namespace std;

template <typename T, typename C>
class map_template
{

  struct node
  {
    node *next;
    T ID;
    C value;

    node (T k):next (NULL)
    {
      
    }

    node ()
    {
      next=NULL;
    }


    ~node ()
    {
      
    }

};


    node *head;
public:

    map_template ()
    {
        head = NULL;
    }

    map_template (const map_template & l)
    {
        head=NULL;
        node* n = l.head;

        while(n)
            {
            Add(n->ID,n->value);
            n=n->next;
        }

    }

    ~map_template ()
    {
        node *p = head;
        node *tmp;
        
        while (p != NULL)
        {
            tmp = p;
            p = p->next;
            delete tmp;
        }
        
    }

    void Add (T id, C val)
    {
        node *nowy = new node;
        nowy->next = head;
        head = nowy;
        nowy->value = val;
        nowy->ID = id;
    }


    C* Find (T id)
    {
        node *p =head; 
        while (p) 
        {
            if (p->ID == id)
                return &(p->value);          
            p = p->next;
        }
        return NULL;
    }

    void swap (map_template & l)
    {
        node *t = head;
        head = l.head;
        l.head = t;
    }

    map_template & operator= (const map_template & l)
    {
         if (&l == this)
            return *this;
            
        map_template t (l);
        swap (t);
        return *this;
    }

    friend ostream& operator << (ostream& o, const map_template& l)
 	{
        node* p = l.head;
        o << "Database:" << endl;

        while(p)
        {
            o << "ID: " << p->ID << endl;
            o << p->value;
            p=p->next;
        }
        return o;
    }
    
};



