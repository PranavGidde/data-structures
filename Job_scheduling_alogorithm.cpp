#include<iostream>
using namespace std;
#define MAX 5
typedef struct Job
{
    int jno;
    int jtime;
}Job;
class CirQueue
{
    Job data[MAX];
    int front,rear;
    public:
    CirQueue()
    {
        front = rear = -1;
    }
    int full()
    {
        if((rear+1)%MAX == front)
        {
            return 1;
        }
        return 0;
    }
    int empty()
    {
        if(rear==-1)
        {
            return 1;
        }
        return 0;
    }
    void enqueue(Job T)
    {
        if(!full())
        {
            if(empty())
            {
                front = rear = 0;
            }
            else
            {
                rear = (rear+1)%MAX;
            }
            data[rear]=T;
        }
        else
        {
            cout<<"Queue is Full\n";
        }
    }
    Job dequeue()
    {
        Job x;
        if(!empty())
        {
            x = data[front];
            if(front==rear)
            {
                front = rear = -1;
            }
            else if(front == MAX-1)
            {
                front = 0;
            }
            else
            {
                front = front + 1;
            }
            return x;
        }
        else
        {
            cout<<"Queue iS Empty\n";
            return x;
        }
    }
};
int main()
{
    CirQueue CQ;
    Job T;
    int n,i,tp;
    cout<<"\nHow Many Jobs\n";
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cout<<"Enter Job no. and Job time\n";
        cin>>T.jno>>T.jtime;
        CQ.enqueue(T);
    }
    cout<<"Enter Time period\n";
    cin>>tp;
    while((!CQ.empty()))
    {
        T = CQ.dequeue();
        T.jtime = T.jtime - tp;
        if(T.jtime>0)
        {
            CQ.enqueue(T);
        }
        else
        {
            cout<<"\nJob Completed...\n";
        }
    }
}
