#ifndef QUEUE_H
#define QUEUE_H
#define MAXSIZE 0xFFFF

template <class T>
class Queue{
public:
    Queue();
    bool isEmpty() const ;
    bool add(const T &data);
    bool remove();
    T front() const;
    void traverse(void (*visit)(const T &data));
    virtual ~Queue(){
        delete []queue;
    }
private:
    int frontp;
    int backp;
    T queue[MAXSIZE];
};
#endif