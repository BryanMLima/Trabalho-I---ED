/*!
    @file stack.h
    @brief classe pilha encadeada

    @author Bryan Lima
    @author Isac Campos

    @date 21 May 2019
*/
#include <cstdint>
#include <stdexcept>

namespace structures {
//! pilha encadeada
template<typename T>
class LinkedStack {
 public:
    LinkedStack();

    ~LinkedStack();
    //! limpa pilha
    void clear();
    //! empilha
    void push(const T& data);
    //! desempilha
    T pop();
    //! dado no topo
    T& top() const;
    //! pilha vazia
    bool empty() const;
    //! tamanho da pilha
    std::size_t size() const;

 private:
    //! elementos
    class Node {
     public:
        explicit Node(const T& data) :
            data_{data}
        {}
        Node(const T& data, Node* next) :
            data_{data},
            next_{next}
        {}
        //! getter: info
        T& data() {
            return data_;
        }
        //! getter-constante: info
        const T& data() const {
            return data_;
        }
        //! getter: próximo
        Node* next() {
            return next_;
        }
        //! getter-constante: próximo
        const Node* next() const {
            return next_;
        }
        //! setter: próximo
        void next(Node* next) {
            next_ = next;
        }

     private:
        T data_;
        Node* next_;
    };
    //! nodo-topo
    Node* top_;
    //! tamanho
    std::size_t size_;
};

template<typename T>
LinkedStack<T>::LinkedStack() {
    top_ = nullptr;
    size_ = 0;
}

template<typename T>
LinkedStack<T>::~LinkedStack() {
    clear();
}

template <typename T>
void LinkedStack<T>::clear() {
    while (!empty())
        pop();
    top_ = nullptr;
    size_ = 0;
}

template<typename T>
void LinkedStack<T>::push(const T& data) {
    Node *new_element = new Node(data, nullptr);
    if (new_element == nullptr)
        throw std::out_of_range("não há espaço");
    if (!empty())
        new_element -> next(top_);
    top_ = new_element;
    size_++;
}

template<typename T>
T LinkedStack<T>::pop() {
    if (empty())
        throw std::out_of_range("lista vazia");
    Node *elemento_saindo = top_;
    if (size_ == 1) {
        top_ = nullptr;
    } else {
        top_ = top_->next();
    }
    size_--;
    T volta = elemento_saindo->data();
    delete(elemento_saindo);
    return volta;
}


template<typename T>
T& LinkedStack<T>::top() const {
    if (empty())
        throw std::out_of_range("lista vazia");
    return top_->data();
}

template<typename T>
bool LinkedStack<T>::empty() const {
    return !size_;
}

template<typename T>
std::size_t LinkedStack<T>::size() const {
    return size_;
}

}  // namespace structures
