// Problem : Delete node in Doubly Linked List GFG
class Solution
{
    // TC => O(N)       SC => O(1)
public:
    Node *deleteNode(Node *head, int x)
    {
        Node *temp = head;
        // Jab tak exact position par nahi paunch jaate tab tak temp pointer ko next node par lekar jaate jaayenge
        while (--x)
        {
            temp = temp->next;
        }
        // jis node ko delete karna hai agar uska previous hai toh uske previous ke next mein node ka next daaldo
        if (temp->prev)
        {
            temp->prev->next = temp->next;
        }
        // jis node ko delete karna hai agar uska next hai toh uske next ke previous mein node ka previous daaldo
        if (temp->next)
        {
            temp->next->prev = temp->prev;
        }
        // Jis node ko delete karna hai agar woh head hi hai toh head ko ek aage badha do
        if (temp == head)
        {
            head = head->next;
        }
        // delete keyword ki help se node ko delete kardo
        delete temp;
        return head;
    }
};

// Problem : Reverse a Doubly Linked List GFG
Node *reverseDLL(Node *head)
{
    // TC => O(N)       SC => O(1)
    // Simply three pointers ka use karenge
    // previous pointer jiski help se hum current ka previous handle karenge taaki puri list ko
    // traverse karne ke baad hume new head mil sake
    Node *prev = NULL;
    // current pointer ko use karke hum given linked list ke through traverse karenge
    Node *curr = head;
    // temp pointer ko use karke hum current pointer ke next ko hold karenge
    Node *temp;
    while (curr != NULL)
    {
        // sabse pehle current ke next ko temp mein store kar lenge
        // phir current ke next mein prev ko daal denge
        // phir current ke previous mein temp ko daaldenge
        // phir current ko previous bana do and temp ko current bana do
        temp = curr->next;
        curr->next = prev;
        curr->prev = temp;
        prev = curr;
        curr = temp;
    }
    head = prev;
    return head;
}

// Problem : Check If Circular Linked List GFG
bool isCircular(Node *head)
{
    // TC => O(N)     SC => O(1)
    // simply head ke next se start karenge
    Node *temp = head->next;
    // agar circular linked list hogi toh dubara head par hi paunch jaayenge warna temp=NULL hojaayega
    while (temp && temp != head)
    {
        temp = temp->next;
    }
    // agar dubara head par hi paunch gaye hai toh circular linked list hai
    if (temp == head)
    {
        return true;
    }
    return false;
}

// Remove duplicates from sorted linked list GFG
// TC => O(N)     SC => O(1)
Node *removeDuplicates(Node *head)
{
    // Simply hum ek pointer le lenge jo ki linked ke through traverse karne mein help karega
    Node *temp = head;
    // Jab tak temp NULL nahi ho jaata hai tab tak hum linked list ke through traverse karenge
    while (temp != NULL)
    {
        // ab jab tak temp ka next NULL nahi hota and current node and next node ki value same hai tab tak temp ke next mein
        // temp ke next ka next daal te rahenge
        while (temp->next != NULL && temp->data == temp->next->data)
        {
            temp->next = temp->next->next;
        }
        // ab kyunki temp ki value uske next ki value ke equal nahi hai toh temp ko aage move karenge
        temp = temp->next;
    }
    return head;
}

// Problem : Remove duplicates from unsorted linked list GFG
class Solution
{
    // TC => O(N)  SC => O(N)
public:
    Node *removeDuplicates(Node *head)
    {
        // Jab tak temp NULL nahi ho jaata hai tab tak hum linked list ke through traverse karenge
        Node *temp = head;
        // previous pointer ki help se hum next to next waala logic implement kar paayenge
        Node *prev = head;
        unordered_map<int, int> mp;
        while (temp != NULL)
        {
            // agar node already present hai list mein toh hume prev ke next mein temp ka next dena hai
            // and temp ko prev ka next bana dena hai
            if (mp[temp->data])
            {
                prev->next = temp->next;
                temp = prev->next;
            }
            // agar present nahi hai toh node ko map mein mark karenge and temp ko previous banakar
            // temp ko aage move kardenge
            else
            {
                mp[temp->data] = 1;
                prev = temp;
                temp = temp->next;
            }
        }
        return head;
    }
};