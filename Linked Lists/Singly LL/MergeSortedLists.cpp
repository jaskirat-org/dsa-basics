#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
}*first = NULL, *second = NULL, *third = NULL;

void createTwoLists(int, int);
void display(struct Node *);
void Merge(struct Node *, struct Node *);

int main(){
    int n, m;
    cout<<"Enter the number of elements in the first sorted linked list: "<<endl;
    cin>>n;
    cout<<"Enter the number of elements in the second sorted linked list: "<<endl;
    cin>>m;
    createTwoLists(n, m);cout<<endl;
    display(first);
    cout<<endl<<endl;
    display(second);
    Merge(first, second);
    cout<<endl<<endl;
    display(third);
}

void createTwoLists(int n, int m){
    struct Node *newNode, *tmp;
    int data;
    
    first = new Node();
    second = new Node();

    if(first==NULL){
        cout<<"'first' is NULL.\n";
        exit(0);
    }
    else{
        cout<<"Enter the data of node 1 of first LL: "<<endl;
        cin>>data;
        first->data = data;
        first->next = NULL;

        tmp = first;
        for(int i=2; i<=n; i++){
            newNode = new Node();
            
            cout<<"Enter the data of node "<<i<<" of first LL: "<<endl;
            cin>>data;

            newNode->data = data;
            newNode->next = NULL;

            tmp->next = newNode;
            tmp = tmp->next;
        }
    }

    if(second==NULL){
        cout<<"'second' is NULL.\n";
        exit(0);
    }
    else{
        cout<<"Enter the data of node 1 of second LL: "<<endl;
        cin>>data;
        second->data = data;
        second->next = NULL;

        tmp = second;
        for(int i=2; i<=m; i++){
            newNode = new Node();
            
            cout<<"Enter the data of node "<<i<<" of second LL: "<<endl;
            cin>>data;

            newNode->data = data;
            newNode->next = NULL;

            tmp->next = newNode;
            tmp = tmp->next;
        }
    }
}

void display(struct Node *p){
    if(p==NULL){
        cout<<"List is empty."<<endl;
        return;
    }
    struct Node *tmp = p;
    for(tmp = p; tmp!=NULL; tmp=tmp->next){
        cout<<tmp->data<<"\t";
    }
    cout<<endl;
}

void Merge(struct Node *p, struct Node *q){
    struct Node *last;
    if(p->data < q->data){
        third = last = p;
        p = p->next;
        third->next = NULL;
    }
    while(p!=NULL && q!=NULL){
        if(p->data < q->data){
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        }
        else{
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }    
    }
    if(p!=NULL) last->next = p;
    if(q!=NULL) last->next = q;
}
