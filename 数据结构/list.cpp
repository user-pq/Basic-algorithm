/**
 * 1、单链表的反转
 * 2、双链表的反转
 * 3、K个节点的组内逆序调整
 * 4、两个链表相加以后倒序
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

// K个节点的组内逆序调整
/**
 * 给定一个单链表的头节点head和一个正数k
 * 实现k个节点的小组内部逆序，如果最后一组不够k个就不调整
 * eg:
 * 调整前：1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 , k = 3 
 * 调整后：3 -> 2 -> 1 -> 6 -> 5 -> 4 -> 7 -> 8
 * 
 * 思路：
 * 1、找出需要反转部分的每一组的尾
 * 2、对需要反转的部分进行反转
 * 3、将链表连接起来
*/

// 找到需要反转的部分的组的尾
Node * GetGroupEnd(Node* head, int k)
{
    while (--k != 0 && head != nullptr)
    {
        head = head->next_;
    }
    return head;
}

// 对当前组进行反转 
void ReverseGroup(Node* head, Node* tail)
{
    tail = tail->next_;
    Node* next = nullptr;
    Node* pre = nullptr;
    Node* cur = head;
    while(cur != tail)
    {
        next = cur->next_;
        cur->next_ = pre;
        pre = cur;
        cur = next;
    }
    head->next_ = tail;
}

Node *ReverseListByK(Node* head, int k)
{
    Node* begin = head;
    Node* end = GetGroupEnd(head, k);
    if(end == nullptr)
    {
        return head;
    }
    head = end;
    ReverseGroup(begin, end);
    Node* last_end = begin;
    while(last_end != nullptr)
    {
        begin = last_end->next_;
        end = GetGroupEnd(begin, k);
        if(end == nullptr)
        {
            return head;
        }
        ReverseGroup(begin, end);
        last_end->next_ = end;
        last_end = begin;
    }
    return head;
}

// 两个链表相加以后倒序
/**
思路：
1、 对比两个链表的长度，重定向两个链表 长（L） 短（S）
2、 分三种情况
    1、 L有 S有
    2、 L有 S无
    3、 L无 S无
*/

int ListLength(Node* head)
{
    int length = 0;
    while(head != nullptr)
    {
        head = head->next_;
        length++;
    }
    return length;
}


Node* AddTwoNumbers(Node* head1, Node* head2)
{
    int length1 = ListLength(head1);
    int length2 = ListLength(head2);

    Node* L = length1 > length2 ? head1 : head2;
    Node* S = length1 > length2 ? head2 : head1;

    Node* curl = L;
    int carry = 0;  // 进位标志
    int curnum = 0; // 两个数、进位标志之和
    Node* last = curl; // 记录链表最后的指向，用于需要添加链表时的连接
    // 累加的值直接放到长链表里边 节约空间 多出来的部分创建一个结点加进去
    while(S != nullptr)  // 第一阶段 都不为空
    {
        curnum = S->data_ + curl->data_ + carry;
        curl->data_ = curnum % 10;
        carry = curnum / 10;
        last = curl;
        curl = curl->next_;
        S = S->next_;
    }
    while(curl != nullptr)  // 第二阶段 S为空 L不为空
    {
        curnum = curl->data_ + carry;
        curl->data_ = curnum % 10;
        carry = curnum / 10;
        last = curl;
        curl = curl->next_;
    }
    if(carry != 0) // 第三阶段 都为空，查看进位标志
    {
        last->next_ = new Node(1);
    }
    return L;
}

int main()
{
    Node *head = new Node(1);
    head->next_ = new Node(2);
    head->next_->next_ = new Node(3);
    head->next_->next_->next_ = new Node(4);
    head->next_->next_->next_->next_ = new Node(5);
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

    std::cout << "----------------" << std::endl;

    PrintList(head);
    auto test = ReverseListByK(head, 3);
    PrintList(test);
    
    std::cout << "----------------" << std::endl;

    Node *head1 = new Node(1);
    head1->next_ = new Node(2);
    head1->next_->next_ = new Node(3);
    head1->next_->next_->next_ = new Node(4);
    head1->next_->next_->next_->next_ = new Node(5);
    PrintList(head1);

    Node *head2 = new Node(1);
    head2->next_ = new Node(2);
    head2->next_->next_ = new Node(3);
    PrintList(head2);

    head1 = AddTwoNumbers(head1, head2);
    PrintList(head1);
    head1 = ReverseList(head1);
    PrintList(head1);

    return 0;

}

