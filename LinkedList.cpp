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

// Problem : Merge Sort on doubly linked list GFG
// TC => O(NlogN)  SC => O(1)
// Ye function har baar mujhe lists ke middle node ko find karke dega
struct Node *findMiddleNode(struct Node *head)
{
    if (head == NULL or head->next == NULL)
    {
        return head;
    }
    Node *slow = head;
    Node *fast = head;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// Problem : QuickSort on doubly linked list GFG
class Solution
{
public:
    void swap(int *a, int *b)
    {
        int t = *a;
        *a = *b;
        *b = t;
    }
    Node *partition(Node *l, Node *h)
    {
        // Starting element ko hi pivot maan lenge
        Node *pivot = l;
        // 2 pointers le lenge traverse karne ke liye
        Node *i = l, *j = h;
        bool flag = false;

        while (!flag)
        {
            // jab tak pivot element se samller hai ith pointer par value nodes ka tab tak
            // aage badte rahenge and jese hi ith pointer jth pointer ke equal hoga toh
            // flag ko true kardenge
            while (i != NULL && i->data <= pivot->data)
            {
                if (i == j)
                    flag = true;
                i = i->next;
            }
            // jab tak pivot element se greater hai jth pointer par value nodes ka tab tak
            // aage badte rahenge and jese hi jth pointer ith pointer ke equal hoga toh
            // flag ko true kardenge
            while (j != NULL && j->data > pivot->data)
            {
                if (i == j)
                    flag = true;
                // kyunki doubly linked list hai isliye prev pointer ki help se last to first
                // node traverse kar sakte hai
                j = j->prev;
            }
            // agar flag true nahi hai toh iska matlab ith and jth pointer equal nahi huye hai
            // toh ith and jth node ke values ko swap kardo
            if (!flag)
                swap(i->data, j->data);
        }
        // pivot element and jth element ke values ko swap kardo
        if (flag)
        {
            swap(pivot->data, j->data);
        }

        return j;
    }
};

void quickSort(struct Node *l, struct Node *h)
{
    if (h != NULL && l != h && l != h->next)
    {
        Solution obj;
        struct Node *p = obj.partition(l, h);
        quickSort(l, p->prev);
        quickSort(p->next, h);
    }
}

// Problem : Quick Sort on linked list GFG
// Sorting Linked List using quicksort takes O(n^2) time in worst case and O(nLogn) in average and best cases, otherwise you may get TLE.
// Hum yahan first ke around partition kar rahe hai
node *partition(node *head, node *tail)
{
    node *curr = head;
    node *prev = head;
    node *pivot = head;
    while (curr != tail->next)
    {
        // agar current node ki value pivot se kum hai toh prev ke next se iski value ko swap kardo
        // and prev ko aage badhao
        if (curr->data < pivot->data)
        {
            swap(curr->data, prev->next->data);
            prev = prev->next;
        }
        curr = curr->next;
    }
    // last mein pivot ki value ko prev ki value se swap kardo
    swap(pivot->data, prev->data);
    return prev;
}

void quicksort(node *head, node *tail)
{
    if (head == NULL or head->next == NULL or (head == tail))
    {
        return;
    }
    // Sabse pehle hum linked list ka pivot point nikalenge jesse array mein karte hai
    node *pivot = partition(head, tail);
    // ab head se pivot node tak quicksort lagayenge
    quicksort(head, pivot);
    // ab pivot node ke next se tail tak quicksort lagayenge
    quicksort(pivot->next, tail);
    return;
}

void quickSort(struct node **headRef)
{
    node *head = *headRef, *tail = head;
    if (head == NULL or head->next == NULL)
    {
        return;
    }
    // Hum sabse pehle doubly linked list ka tail nikal lenge
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    quicksort(head, tail);
}

// Ye function lists ko sort karke merge karega
struct Node *mergeSortedLists(struct Node *l1, Node *l2)
{
    if (l1 == NULL)
    {
        return l2;
    }
    if (l2 == NULL)
    {
        return l1;
    }
    Node *dummy = new Node(0);
    Node *ptr = dummy;
    while (l1 != NULL && l2 != NULL)
    {
        if (l1->data <= l2->data)
        {
            ptr->next = l1;
            l1->prev = ptr;
            l1 = l1->next;
        }
        else
        {
            ptr->next = l2;
            l2->prev = ptr;
            l2 = l2->next;
        }
        ptr = ptr->next;
    }
    if (l1 != NULL)
    {
        ptr->next = l1;
        l1->prev = ptr;
    }
    if (l2 != NULL)
    {
        ptr->next = l2;
        l2->prev = ptr;
    }
    // Doubly linked list hai toh dummy ke next ke previous ko NULL karna hoga
    dummy->next->prev = NULL;
    return dummy->next;
}

struct Node *sortDoubly(struct Node *head)
{
    // Base condition
    if (head == NULL or head->next == NULL)
    {
        return head;
    }
    // Har baar linked list ka middle find karlenge and phir middle ke next ko new head banakar
    // uske us new Head ke previous ko NULL and middle node ke next ko NULL kardenge
    Node *midNode = findMiddleNode(head);
    Node *newHead = midNode->next;
    newHead->prev = NULL;
    midNode->next = NULL;

    Node *list1 = sortDoubly(head);
    Node *list2 = sortDoubly(newHead);
    return mergeSortedLists(list1, list2);
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

// Problem : Sorted insert for circular linked list GFG
class Solution
{
public:
    // TC => O(N)    SC => O(1)
    Node *sortedInsert(Node *head, int data)
    {
        // Sabse pehle hume tail node nikalna hi padega is question mein jisse thoda asaan hoga sochna
        Node *tail = head;
        while (tail->next != head)
        {
            tail = tail->next;
        }
        // Agar head hi greater hai hamare new node se toh iska matlab hamara newnode head banega
        // Toh hume tail ke next mein newnode and newnode ke next mein head dekar newnode ko head
        // bana dena hai
        if (data < head->data)
        {
            Node *temp = new Node(data);
            tail->next = temp;
            temp->next = head;
            head = temp;
        }
        // Agar tail se greater hai hamara node toh hume newnode ke next mein head and tail ke next
        // mein newnode ko daalna hai and newnode ke next mein head ko daal dena hai bas
        else if (data > tail->data)
        {
            Node *temp = new Node(data);
            tail->next = temp;
            temp->next = head;
        }
        // warna in between daalna hoga node ko kahin toh hum previous node ka track rakhenge apne
        // paas taaki previous ke next mein given node ko daal saken and given node ke next mein
        // current node ko daal denge
        else
        {
            Node *prev = head;
            Node *curr = head->next;
            while (prev != tail)
            {

                if (data > prev->data && data <= curr->data)
                {
                    Node *temp = new Node(data);
                    prev->next = temp;
                    temp->next = curr;
                }
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};

// Split a Circular Linked List into two halves GFG
// TC => O(N)   SC => O(1)
void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    // Simply fast and next pointers ki help se mid ko find karenge
    Node *slow = head;
    Node *fast = head->next;
    while (fast != head && fast->next != head)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    // mid find karne ke baad first linked list ko original linked list ka head assign
    // kardenge and second linked list ko mid ka next assign kardenge
    *head1_ref = head;
    *head2_ref = slow->next;
    // mid ke next mein phir first linked list ka head dekar usse circular linked list
    // bana denge and second linked list mein traverse karenge jab tak original linked
    // list ka head hamara next naa ho taaki original linked list ke last node ka link
    // uske head se break karke second linked list ke head par laga saken
    slow->next = *head1_ref;
    Node *curr = *head2_ref;
    while (curr->next != head)
    {
        curr = curr->next;
    }
    curr->next = *head2_ref;
}

// Problem : Remove duplicates from sorted linked list GFG
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

// Problem : Delete nodes having greater value on right GFG
// TC => O(N)   SC =>O(N)
class Solution
{
public:
    // Approach : Simply reverse karo phir leaders in a array ki approach lagao and phir reverse karo
    Node *reverse(Node *head)
    {
        Node *temp;
        Node *prev = NULL;
        Node *curr = head;
        while (curr != NULL)
        {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    Node *compute(Node *head)
    {
        head = reverse(head);
        Node *ans = new Node(0);
        Node *temp = ans;

        int maxi = INT_MIN;
        while (head != NULL)
        {
            if (head->data >= mx)
            {
                temp->next = new Node(head->data);
                temp = temp->next;
                maxi = head->data;
            }
            head = head->next;
        }
        return reverse(ans->next);
    }
};

// Problem : Flattening a Linked List
// Approach : Hum last se linked list ko sort karenge jiske liye pehle hum recursively linked list ke last node tak jaayenge
// last node par paunch kar hum linked list ke pairs ko sort karenge pairs ke bottom parts ko
// sort karke. Hum har linked list ke bottoms ko sort karke ek new linked list banayenge jo ki bottom wise hogi
// matlab hum new linked list ke bottom mein hi sorted linked list ko prepare karte rahenge

// If we consider each vertical linked list of size O(M) in the worst case, then in this method we are merging two vertical sub-linked lists at a time.
// Time is taken to merge two linked lists of size M = O(M+M) =O(2M)
// Similarly, the time is taken to merge another linked list of size M with a linked list of size 2M = O(M+2M)=O(3M)
// Similarly, the time is taken to merge another linked list of size M with a linked list of size 3M = O(M+3M) =O(4M).
// This process will take place N times where N is the no of nodes in the horizontal linked list. So, the total time taken till all the nodes are merged = O(2M+3M+4M+5M+...N * M )
// = O(2+3+4+5+6...+N)* M
// = O(N* ( N + 1 ) / 2)* M
// TC => O(N * N * M)
// SC => O(N)
Node *merge(Node *l1, Node *l2)
{
    // new linked list starting node
    Node *dummy = new Node(0);
    // pointer to store the head of the new linked list
    Node *prev = dummy;
    while (l1 != NULL && l2 != NULL)
    {
        if (l1->data < l2->data)
        {
            dummy->bottom = l1;
            dummy = dummy->bottom;
            l1 = l1->bottom;
        }
        else
        {
            dummy->bottom = l2;
            dummy = dummy->bottom;
            l2 = l2->bottom;
        }
    }
    if (l1 != NULL)
    {
        dummy->bottom = l1;
    }
    if (l2 != NULL)
    {
        dummy->bottom = l2;
    }
    return prev->bottom;
}

Node *flatten(Node *root)
{
    if (root->next == NULL)
    {
        return root;
    }
    // recursively linked list ke last tak jaa rahe hai
    root->next = flatten(root->next);
    // linked list last pairs ko merge kar rahe hai and phir wapis send kardenge
    root = merge(root->next, root);
    return root;
}

// Problem : Prime List GFG
class Solution
{
    // TC => O(number of nodes * sqrt(value of node))     SC => O(1)
public:
    // Is function ki help se hum ye check karlenge ki current node ki value prime hai ya nahi
    bool isPrime(int n)
    {
        if (n == 1)
            return false;
        if (n == 2 || n == 3)
            return true;
        if (n % 2 == 0 || n % 3 == 0)
            return false;
        for (int i = 5; i <= sqrt(n); i += 6)
        {
            if (n % i == 0 || n % (i + 2) == 0)
                return false;
        }
        return true;
    }

    int nearestPrime(int n)
    {
        // just before and just after waala prime nikalenge
        int prime1, prime2;
        if (n == 1)
            return 2;
        // Just previous prime nikalenge
        for (int i = n; i > 1; i--)
        {
            if (isPrime(i))
            {
                prime1 = i;
                break;
            }
        }
        // just after waala prime nikalenge
        for (int i = n; i < n * n; i++)
        {
            if (isPrime(i))
            {
                prime2 = i;
                break;
            }
        }
        // ab dono primes ka distance current se nikal kar compare karlenge kiska distance less hai
        if (abs(n - prime1) > abs(n - prime2))
        {
            return prime2;
        }
        else if (abs(n - prime1) < abs(n - prime2))
        {
            return prime1;
        }
        // agar distance same hai toh return karo smaller prime ko
        else
        {
            if (prime1 > prime2)
                return prime2;
            else
                return prime1;
        }
    }

    Node *primeList(Node *head)
    {
        Node *curr = head;
        while (curr)
        {
            // agar prime nahi hai current node ki value tabhi nearest prime nikalenge warna nahi nikalenge
            if (!isPrime(curr->val))
            {
                int new_val = nearestPrime(curr->val);
                // ab current node ko uske nearest pointer ki value assign kardo
                curr->val = new_val;
            }
            curr = curr->next;
        }
        return head;
    }
};

// Problem : Length of longest palindrome in linked list GFG
// TC => O(N*N) SC => O(1)
// Ye function help karega check karne mein ki kitne characters dono side se help kar rahe
// palindrome banane mein
int countCommon(Node *prev, Node *temp)
{
    int count = 0;
    while (prev != NULL && temp != NULL)
    {
        if (temp->data == prev->data)
        {
            count++;
        }
        else
        {
            break;
        }
        prev = prev->next;
        temp = temp->next;
    }
    return count;
}

int maxPalindrome(Node *head)
{
    // Simply reverse linked list ka hi logic hai ye bas har node ko as a center node maan
    // kar uske left and right part ko compare karke dekhenge ki kitni length ka palindrome
    // ban sakta hai. Current node ke piche ki linked ko reverse karte jaaeyenge taaki
    // palindorme ko check kar sake by using previous nodes which are reverse and next nodes
    // of current node
    Node *prev = NULL;
    Node *curr = head;
    Node *temp;
    int len = 0;
    while (curr != NULL)
    {
        temp = curr->next;
        curr->next = prev;
        // agar odd center hai toh uske dono side mein equal same characters honge
        len = max(len, 2 * countCommon(prev, temp) + 1);
        // agar even center hai toh current node ko hum previous ke saath hi jod denge
        // and phir dono side mein kitne equal characters hai nikal lenge
        len = max(len, 2 * countCommon(curr, temp));
        prev = curr;
        curr = temp;
    }
    return len;
}

// Problem : Linked List Matrix GFG
Node *constructLinkedMatrix(int mat[MAX][MAX], int n)
{
    // TC => O(N*N) because hum pure matrix ko hi traverse kar rahe hai
    // SC => O(N*N) because linked list mein N*N elements honge
    // Hum matrix ke starting node ko head bana denge
    Node *head = new Node(mat[0][0]);
    // ab ek temp pointer rakhlenge jo ki har baar hume help karega har row ke columns ke through traverse karne mein
    Node *temp = head;
    for (int i = 0; i < n; i++)
    {
        // Ab hum temp2 pointer ko temp ko point kar wa denge taaki down jaa paayen
        Node *temp2 = temp;
        for (int j = 0; j < n; j++)
        {
            // agar last column hai toh temp ka right NULL hojaayega
            if ((j + 1) == n)
            {
                temp->right = NULL;
            }
            // warna temp ke right mein next column ki value de denge
            else
            {
                temp->right = new Node(mat[i][j + 1]);
            }
            // agar last row hai toh temp ke down ko NULL kardenge
            if ((i + 1) == n)
            {
                temp->down = NULL;
            }
            // warna temp ke down mein current column ke next row ka element de do
            else
            {
                temp->down = new Node(mat[i + 1][j]);
            }
            // temp ke right mein jaate jaao
            temp = temp->right;
        }
        // ab humne temp ki starting ko rakha tha temp2 pointer par toh ab dubara temp ko
        // wahin lekar aayenge and temp ke down mein chale jaayenge jo ki next row paunch
        // jaayega
        temp = temp2;
        temp = temp->down;
    }
    return head;
}

// Problem : Intersection of Two Linked Lists GFG
class Solution
{
public:
    // Brute Force Approach : Sabse basic approach yehi hai ki aap 2 while loops ka use karke linked list 1
    // ke har node ki value ko linked list 2 ke har node ki value ke saath compare karke dekho and jahan bhi
    // match ho wahan par new node banakar new linked list mein append kardo
    // TC => O(N*M)   SC => O(1)
    Node *findIntersection(Node *head1, Node *head2)
    {
        // dummy node new linked list ko banane ke liye
        Node *dummy = new Node(-1);
        // dummy linked list ke through traverse karne ke liye ptr pointer ko use karenge
        Node *ptr = dummy;
        while (head1 != NULL)
        {
            // temp ko point karwa denge linked list 2 ke head par taaki traverse kar saken
            Node *temp = head2;
            while (temp != NULL)
            {
                // agar nodes ki values match huyi toh new node ko new linked list mein appen kardenge
                if (temp->data == head1->data)
                {
                    ptr->next = new Node(head1->data);
                    ptr = ptr->next;
                }
                temp = temp->next;
            }
            head1 = head1->next;
        }
        // new linked list last node ko NULL ko point karwa denge
        ptr->next = NULL;
        // ab kyunki linked list dummy ke next se start ho rahi hai toh dummy ke next ko return karenge
        return dummy->next;
    }

    // Better Approach : Better approach ye hai ki aap linked list 2 ki values ko map mein store karwa lo
    // taaki ye pata kar saken ki konsi nodes common hai dono linked list mein
    // TC => O(N+M)   SC => O(N+M)
    Node *findIntersection(Node *head1, Node *head2)
    {
        // dummy node new linked list ko banane ke liye
        Node *dummy = new Node(-1);
        // dummy linked list ke through traverse karne ke liye ptr pointer ko use karenge
        Node *ptr = dummy;
        unordered_map<int, int> mp;
        // linked list 2 ki saari nodes ki values ko map mein mark kar rahe hai
        while (head2 != NULL)
        {
            mp[head2->data] = 1;
            head2 = head2->next;
        }
        while (head1 != NULL)
        {
            // agar current node ki value map mein hai toh new node ko new linked list mein appen kardenge
            if (mp[head1->data])
            {
                ptr->next = new Node(head1->data);
                ptr = ptr->next;
            }
            head1 = head1->next;
        }
        // new linked list last node ko NULL ko point karwa denge
        ptr->next = NULL;
        // ab kyunki linked list dummy ke next se start ho rahi hai toh dummy ke next ko return karenge
        return dummy->next;
    }
};

// Problem : Union of two linked list GFG
class Solution
{
public:
    // Brute Force Approach : Simply haan merge sort ki help se dono linked list ko sort karlo
    // And phir two pointers ki help se dono linked list mein traverse karte huye new linked list
    // banao jisme saare unique elements ho.
    // TC => O((N+M)log(N+M))   SC => O(N+M)

    // Better Approach : Hum set ka use karlen jo ki hamare linked list ke nodes ko unique bhi rakhega
    // and sorted bhi rakhega and phir set se one by one values ko nikal kar new linked list mein
    // append karte raho.
    // TC => O(N+M)    SC => O(N+M)
    struct Node *makeUnion(struct Node *head1, struct Node *head2)
    {
        set<int> st;
        while (head1 != NULL)
        {
            st.insert(head1->data);
            head1 = head1->next;
        }
        while (head2 != NULL)
        {
            st.insert(head2->data);
            head2 = head2->next;
        }
        Node *dummy = new Node(-1);
        Node *ptr = dummy;
        for (auto it : st)
        {
            ptr->next = new Node(it);
            ptr = ptr->next;
        }
        ptr->next = NULL;
        return dummy->next;
    }
};

// Problem : Reverse alternate nodes in Link List GFG
class Solution
{
    // TC => O(N)     SC => O(1)
public:
    // Reverse function ki help se reverse kardenge
    Node *reversed(Node *node)
    {
        Node *prev = NULL;
        Node *temp;
        Node *curr = node;
        while (curr != NULL)
        {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    void rearrange(struct Node *odd)
    {
        if (odd == NULL || odd->next == NULL)
            return;

        Node *oddHead = odd;
        Node *oddCurr = oddHead;
        Node *evenHead = odd->next;
        Node *evenCurr = evenHead;
        while (oddCurr && evenCurr && evenCurr->next)
        {
            // odd ke next mein even ka next daaldo and odd ko aage badha do pehle
            oddCurr->next = evenCurr->next;
            oddCurr = oddCurr->next;
            // phir even ke next mein odd ka next daal do and phir even ko aage badha do
            evenCurr->next = oddCurr->next;
            evenCurr = evenCurr->next;
        }
        oddCurr->next = reversed(evenHead);
    }
};

// Problem : Reverse alternate K nodes GFG : Question mein yehi kaha tha ki pehle k nodes ko reverse karo , phir next k nodes ko reverse nahi karna
// and aese hi linked list ke last tak karo
Node *kAltReverse(Node *head, int k, int flag)
{
    Node *current = head;
    Node *temp;
    Node *prev = NULL;
    int count = 0;
    // ye while loop reverse linked list ka hi kaam kar raha hai
    while (current != NULL && count++ < k)
    {
        temp = current->next;
        if (flag)
        {
            // reverse link if flag is true
            current->next = prev;
        }
        prev = current;
        current = temp;
    }
    // recursively work kar rahe hai hum yahan par
    if (temp != NULL)
    {
        if (flag)
            head->next = kAltReverse(temp, k, !flag);
        else
            prev->next = kAltReverse(temp, k, !flag);
    }
    // agar flag hoga toh prev return karenge iska matlab hi humne last k nodes ko reverse kiya hai warna head ko return karenge
    if (flag)
        return prev;
    else
        return head;
}

// Problem : Subtraction in linked list GFG
int findLen(Node *node)
{
    int len = 0;
    while (node != NULL)
    {
        len++;
        node = node->next;
    }
    return len;
}

Node *reverse(Node *head)
{
    Node *temp;
    Node *prev = NULL;
    Node *curr = head;
    while (curr != NULL)
    {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}

Node *subLinkedList(Node *l1, Node *l2)
{
    // agar dono mein se ek bhi linked list null huyi toh duri ko return kardenge
    if (l2 == NULL)
    {
        return l1;
    }
    if (l1 == NULL)
    {
        return l2;
    }
    // agar linked list mein trailing zeroes hai toh unhe remove kar rahe hai
    while (l1 && l1->data == 0)
    {
        l1 = l1->next;
    }
    // agar linked list mein trailing zeroes hai toh unhe remove kar rahe hai
    while (l2 && l2->data == 0)
    {
        l2 = l2->next;
    }
    // dono linked list ki length nikal lenge taaki ye pata kar saken ki konsi greater hai
    int n1 = findLen(l1);
    int n2 = findLen(l2);
    // agar second linked list greater hai toh dono linked list ko swap kardenge
    if (n2 > n1)
    {
        swap(l1, l2);
    }
    // agar dono linked list ki length same hai toh ye find karna padega ki konsi greater hai
    if (n1 == n2)
    {
        Node *temp1 = l1;
        Node *temp2 = l2;
        // jab tak linked list ke nodes ki values same hai aage badhte raho
        while (temp1->data == temp2->data)
        {
            temp1 = temp1->next;
            temp2 = temp2->next;
            // agar linked list hi null hogayi toh iska matlab saara nodes dono linked list ke
            // ek dusre ke equal the toh is case mein ek new linked list ko return kardenge jisme
            // sirf ek hi node hoga jiski value zero hogi
            if (temp1 == NULL && temp2 == NULL)
            {
                return new Node(0);
            }
        }
        // agar linked list ke node ki values zyada hai toh swap kardo dono linked list ko
        if (temp2->data > temp1->data)
        {
            swap(l1, l2);
        }
    }
    // dono linked list ko reverse kardo
    Node *temp = reverse(l1);
    Node *ptr = reverse(l2);
    // New node bana lenge
    Node *head = NULL;
    // ek variable le lenge jo ki ye show karega ki abhi difference negative tha ya positive
    // linked list ke nodes ke beech
    int borrow = 0;
    while (temp != NULL)
    {
        // agar second linked list null hogayi hai toh 0 warna second linked list ke node ki
        // value ko consider karenge difference ke liye
        int diff = borrow + temp->data - (ptr == NULL ? 0 : ptr->data);
        // agar difference negative hai iska matlab borrow karne ki zaroorat padegi toh
        // borrow variable ko -1 kardenge and difference mein 10 add kardenge jo ki hume
        // borrow lene ke baad ka difference de dega
        if (diff < 0)
        {
            borrow = -1;
            diff += 10;
        }
        // agar difference positive hai toh borrow zero hoga
        else
        {
            borrow = 0;
        }
        // naya node banayenge jiski value difference hogi jo humne nikala hai
        Node *newNode = new Node(diff);
        // reverse naa karna pade last mein linked list ko isliye har baar new node ke next
        // mein jo linked list hum create kar rahe hai usse hi daal denge and new node ko hi
        // head bana denge
        newNode->next = head;
        head = newNode;
        temp = temp->next;
        // agar second linked list null nahi hai toh hi next node par jaao
        if (ptr != NULL)
        {
            ptr = ptr->next;
        }
    }
    // jab tak head ka next hai and trailing zeroes hai tab tak aaage badho
    while (head->next && head->data == 0)
    {
        head = head->next;
    }
    return head;
}