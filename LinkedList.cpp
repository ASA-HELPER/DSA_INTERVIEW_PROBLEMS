bool isCircular(Node *head)
{
    // simply head ke next se start karenge
    Node*temp = head->next;
    // agar circular linked list hogi toh dubara head par hi paunch jaayenge warna temp=NULL hojaayega
    while(temp && temp!=head)
    {
        temp = temp->next;
    }
    // agar dubara head par hi paunch gaye hai toh circular linked list hai
    if(temp==head)
    {
        return true;
    }
    return false;
}