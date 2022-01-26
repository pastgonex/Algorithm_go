#include <iostream>
#include <queue>

using namespace std;

typedef struct Bnode
{
    char data;
    struct Bnode *lchild, *rchild;
} Bnode, *Btree;

void CreateTree(Btree &T) // 创建二叉树
{
    //按先序次序输入二叉树中结点的值(一个字符),创建二叉链表表示的二叉树T
    char ch;
    scanf("%c", &ch);
    if (ch == '#')
        T = NULL; //终止条件
    else
    {
        T = new Bnode;
        T->data = ch;
        CreateTree(T->lchild); //递归创建左子树
        CreateTree(T->rchild); //递归创建右子树
    }
}

inline void visit(Btree T)
{
    printf("%c", T->data);
}

void preorder(Btree T) //先序遍历
{
    if (!T)
        return;
    visit(T);
    preorder(T->lchild);
    preorder(T->rchild);
}

void in_order(Btree T)
{
    if (!T)
        return;
    in_order(T->lchild);
    visit(T);
    in_order(T->rchild);
}

void post_order(Btree T)
{
    if (!T)
        return;
    post_order(T->lchild);
    post_order(T->rchild);
    visit(T);
}

bool level_order(Btree T)
{
    if (!T)
        return false;
    queue<Btree> Q;
    Q.push(T);
    while (!Q.empty())
    {
        Btree x = Q.front(); //取队头
        Q.pop();
        printf("%c", x->data);
        if (x->lchild)
            Q.push(x->lchild);
        if (x->rchild)
            Q.push(x->rchild);
    }
    return true;
}

int main()
{
    Btree T;
    puts("按先序序列输入二叉树中结点的值(补空法'#'),创建一棵二叉树: ");
    CreateTree(T);
    puts("\n二叉树的先序遍历结果:");
    preorder(T);
    puts("\n\n二叉树中序遍历结果: ");
    in_order(T);
    puts("\n\n二叉树后序遍历结果: ");
    post_order(T);
    puts("\n\n二叉树层次遍历结果: ");
    level_order(T);
    return 0;
}
