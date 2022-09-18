#include <bits/stdc++.h>
using namespace std;


class Family{
    public:
    string m_name;
    int age;
    Family*next;
    Family*prev;
    Family(string m_name,int age){
        this->m_name=m_name;
        this->age=age;
        next=NULL;
        prev=NULL;
    }
};


void append(Family* &head,string m_name,int age){
    Family*temp=head;
    Family*new_node=new Family(m_name,age);
    if(temp==NULL){
        head=new_node;
    }
    else{
        while(temp->next!=NULL){temp=temp->next;}
        temp->next=new_node;
        new_node->prev=temp;
    }
}


void insert_at_head(Family*&head,string m_name,int age){
     Family*new_node=new Family(m_name,age);
     new_node->next=head;
     head->prev=new_node;
     head=new_node;
}


void display_start(Family*head){
    Family*temp=head;
    while(temp!=NULL){cout<<"[Name:"<<temp->m_name<<" Age:"<<temp->age<<"]"<<"<=>";temp=temp->next;}
    cout<<endl;
}


void display_end(Family*head){
    Family*temp=head;
    while(temp->next!=NULL){temp=temp->next;}
    while(temp!=NULL){cout<<"[Name:"<<temp->m_name<<" Age:"<<temp->age<<"]"<<"<=>";temp=temp->prev;}
    cout<<endl;
}

void delete_ind(Family*&head,int i){
    if(i==0){
        Family*temp=head;
        head=temp->next;
        head->prev=NULL;
        delete temp;
    }
    else{
        Family*temp=head;
        for(int j=0;j<i;j++){temp=temp->next;}
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        delete temp;
    }
}

void pop(Family*&head){
    Family*temp=head;
    while(temp->next!=NULL){temp=temp->next;}
    temp->prev->next=NULL;
    delete temp;
}

int main(){
    Family*head=NULL;
    append(head,"MEMBER A",80);
    append(head,"MEMBER B",50);
    append(head,"MEMBER C",47);
    append(head,"MEMBER D",22);
    append(head,"MEMBER E",19);
    cout<<endl;

    cout<<"Doubly Linked list with family members:"<<endl;
    cout<<endl;
    display_start(head);
}
