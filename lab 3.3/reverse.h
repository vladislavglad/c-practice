template <typename T>
void reverse(T a[], int size) {
    for (int i = 0; i < size/2; i++) {
        T temp = a[i];
        a[i] = a[size - 1 - i];
        a[size - 1 - i] = temp;
    }
}

template <typename T>
void print(T a[], int size) {
    std::cout << "{";
    for (int i = 0; i < size; i++) {
        std::cout << a[i] << (i != size - 1 ? ", " : "");
    }
    std::cout << "}";
}