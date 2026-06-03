#pragma once
#include <string>

bool isValid(std::string s);

namespace strukdat
{
namespace stack
{
    /**
     * @brief Node pada stack berbasis linked list (singly linked list)
     */
    template <typename T>
    struct Node
    {
        T data;
        Node* next;
    };

    /**
     * @brief Alias pointer ke Node
     */
    template <typename T>
    using NodePtr = Node<T>*;

    /**
     * @brief Membuat stack kosong
     *
     * @return pointer ke elemen teratas stack (nullptr jika kosong)
     */
    template <typename T>
    NodePtr<T> create_stack()
    {
        return nullptr;
    }

    /**
     * @brief Mengecek apakah stack kosong
     *
     * @param top pointer ke elemen teratas stack
     * @return true jika stack kosong, false jika tidak
     */
    template <typename T>
    bool isEmpty(NodePtr<T> top)
    {
        return top == nullptr;
    }

    /**
     * @brief Mengambil nilai elemen teratas tanpa menghapusnya
     *
     * @param top pointer ke elemen teratas stack
     * @return nilai dari elemen teratas stack
     */
    template <typename T>
    T top(NodePtr<T> top)
    {
        // TODO: Implementasikan fungsi untuk mengambil data teratas
        return top->data;
    }

    /**
     * @brief Menambahkan elemen ke atas stack (push)
     *
     * @param top referensi pointer ke elemen teratas stack
     * @param data data yang akan ditambahkan ke stack
     */
    template <typename T>
    void push(NodePtr<T>& top, const T& data)
    {
        // TODO: Implementasikan fungsi push
        NodePtr<T> newNode = new Node<T>;
        newNode->data = data;
        newNode->next = top;
        top = newNode; 
    }

    /**
     * @brief Menghapus elemen teratas dari stack (pop)
     *
     * @param top referensi pointer ke elemen teratas stack
     * @note Jika stack kosong, fungsi tidak melakukan apa-apa
     */
    template <typename T>
    void pop(NodePtr<T>& top)
    {
        // TODO: Implementasikan fungsi pop
        if (!isEmpty(top)){
            NodePtr<T> temp = top;
            top = top->next;
            delete temp;
        } 
    }

    /**
     * @brief Menghapus seluruh elemen dalam stack untuk mencegah memory leak
     *
     * @param top referensi pointer ke elemen teratas stack
     */
    template <typename T>
    void destroy_stack(NodePtr<T>& top)
    {
        while (!isEmpty(top))
        {
            pop(top);
        }
    }

} // namespace stack
} // namespace strukdat
