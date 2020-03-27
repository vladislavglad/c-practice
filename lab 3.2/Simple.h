template <typename T>
class Simple {
    private:
            T val;
    public:
            Simple(T val) : val(val) {}
            T getVal() {return val;}
            void setVal(T v) {val = v;}
            void print() {std::cout << val;}
};
