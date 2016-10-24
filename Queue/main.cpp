#include <iostream>

using namespace std;

class queue {
    public:
        queue(int size);
        int Dequeue();
        void Enqueue(int x);
        bool isEmpty();
        bool isFull();
        void printQueue();

    private:
        int head = 0;
        int *arr;
        int length;
        int count;
};

queue::queue (int size) {
    arr = new int[size];
    length = size;
    count = 0;
}

void queue::Enqueue(int x) {
    if (isEmpty()) {
        arr[head] = x;
        ++count;
    }
    else if (isFull()){
        return;
    } else {
        arr[(head + count)%length] = x;
        ++count;
    }

}

int queue::Dequeue() {
    if (isEmpty())
        return -1;
    int res = arr[(head + count)%length];
    arr[(head + count)%length] = 0;
    --count;
    ++head;
    return res;
}

void queue::printQueue() {
    if (count == 0)
        return;
    cout << arr[head];
    int cur = head+1;
    for (int i=1; i<count; ++i) {
        cout <<','<< arr[cur%length];
        ++cur;
    }
    cout << endl;
}

bool queue::isFull() {
    if (count == length)
        return true;
    return false;
}

bool queue::isEmpty() {
    if (count == 0)
        return true;
    return false;
}

int main()
{
    queue Q(5);
    Q.Enqueue(1);
    Q.Enqueue(2);
    Q.Enqueue(3);
    Q.Enqueue(4);
    Q.Enqueue(5);
    Q.Enqueue(6);
    Q.printQueue();
    Q.Dequeue();
    Q.printQueue();
    Q.Enqueue(7);
    Q.Enqueue(8);
    Q.printQueue();
    Q.Dequeue();
    Q.printQueue();
    Q.Enqueue(9);
    Q.printQueue();
    return 0;
}
