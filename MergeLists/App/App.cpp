#include <iostream>

struct List
{
    int info;
    List* pred, * next;
};

void CreateListR(List*& h, List*& t, int n)
{
    h = new List;
    t = new List;
    List* last = h;
    h->next = t;
    t->pred = h;
    List* p = NULL;
    for (int i = 0; i < n; i++)
    {
        p = new List;
        int temp;
        std::cin >> temp;
        p->info = temp;
        t->pred = p;
        last->next = p;
        p->pred = last;
        p->next = t;
        last = p;
    }
}

void involve(List* h1, List* t1, List* h2, List* t2)
{                                                   
    List* p1 = h1->next;
    List* p2 = h2->next;

    while (p1 != t1) {
        List* inv = new List;
        inv->info = p1->info; 

        while (p2 != t2 && p1->info >= p2->info)
            p2 = p2->next;

        inv->next = p2;
        inv->pred = p2->pred;
        p2->pred->next = inv;
        p2->pred = inv;

        p1 = p1->next;
    }
}

int main()
{
    int fst, snd;
    std::cin >> fst >> snd;

    List* h1 = NULL; List* t1 = NULL;
    List* h2 = NULL; List* t2 = NULL;

    CreateListR(h1, t1, fst);
    CreateListR(h2, t2, snd);

    involve(h1, t1, h2, t2);

    List* p = h2->next;
    while (p != t2)
    {
        std::cout << p->info<< " ";
        p = p->next;
    }
    std::cout << std::endl;

}
