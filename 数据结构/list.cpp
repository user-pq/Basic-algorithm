/**
 * 1、单链表的反转
 * 2、双链表的反转
*/

#include <iostream>
#include <deque>
// 单链表节点
struct Node
{
    int     data_ ;
    Node *  next_ ;
    Node *  pre_;

    Node(int data) : data_(data), next_(nullptr), pre_(nullptr) {}
};

// 打印链表
template<class T>
void PrintList(T *head)
{
    while(head != nullptr)
    {
        std::cout << head->data_ << " ";
        head = head->next_;
    }
    std::cout << std::endl;
}

// 1、单链表反转
Node* ReverseList(Node* head)
{
    Node* pre = nullptr;    // 记录本节点的地址
    Node* next = nullptr;   // 记录节点指向的下一个节点的地址

    while(head != nullptr)
    {
        next = head->next_;     // 保留下一个节点的地址
        head->next_ = pre;      // 节点的下一个地址应该是上一个节点的地址
        pre = head;             // 保留当前节点的地址
        head = next;            
    }

    return pre;
}

// 双链表反转
Node* ReverseDoubleList(Node* head)
{
    Node* pre = nullptr;
    Node* next = nullptr;

    while (head != nullptr)
    {
        next = head->next_;
        head->pre_ = head->next_;
        head->next_ = pre;
        pre = head;
        head = next;
    }

    return pre;
}


int main()
{
    Node *head = new Node(1);
    head->next_ = new Node(2);
    head->next_->next_ = new Node(3);

    PrintList(head);
    head = ReverseList(head);
    PrintList(head);

    std::cout << "-----------------" << std::endl;

    Node* d_head = new Node(1);
    Node* d_list_1 = new Node(2);
    Node* d_list_2 = new Node(3);
    d_head->next_ = d_list_1;
    d_head->pre_ = nullptr;
    d_list_1->next_ = d_list_2;
    d_list_1->pre_ = d_head;
    d_list_2->pre_ = d_list_1;
    d_list_2->next_ = nullptr;

    PrintList(d_head);
    d_head = ReverseDoubleList(d_head);
    PrintList(d_head);

    return 0;

}

