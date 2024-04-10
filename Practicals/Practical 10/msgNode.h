#ifndef MSGNODE_H
#define MSGNODE_H

template<class T>
class msgNode{
    private:
        T message;
        double size;

    public:
        msgNode* next;
        msgNode(T i, double s);
        ~msgNode();

        T getMessage() const;

        double getSize() const;
};
#endif