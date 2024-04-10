#ifndef HEATNODE_HH
#define HEATNODE_HH

template<class  T>
class heatNode{
    private:
        T coolantLevel;
        int power;

    public:
        heatNode<T>* next;
        heatNode(T i, int p);
        ~heatNode();

        T getCoolantLevel() const;

        int getPower() const;

};
#endif