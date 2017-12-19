#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED
//不允许有重复项
#include <stdbool.h>

//依情况重定义Item
#define SLEN 20
typedef struct item {
    char petname[SLEN];
    char petkind[SLEN];
} Item;
#define MAXITEMS 10
typedef struct trnode {
    Item item;
    struct trnode * left;
    struct trnode * right;
} Trnode;
typedef struct tree {
    Trnode * root;
    int size;
} Tree;

//操作：将树初始化为空
//前提：ptree指向一个树
//后置：树被初始化为空
void InitializeTree(Tree * ptree);
//确认树是否为空
//前提：ptree指向一个树
//是则返回true，否则返回false
bool TreeIsEmpty(const Tree * ptree);
//确认树是否已满
//前提：ptree指向一个树
//是则返回true，否则返回false
bool TreeIsFull(const Tree * ptree);
//确定树的项数
//前提：ptree指向一个树
//返回树的项数
int TreeItemCount(const Tree * ptree);
//在树中添加一个项
//pi是待添加项的地址；ptree指向一个已初始化的树
//如可添加，添加一个项并返回true；否则返回false
bool AddItem(const Item * pi, Tree * ptree);
//在树中查找一个项
//pi指向一个项；ptree指向一个已初始化的项
//如找到，返回true；否则返回false
bool InTree(const Item * pi, const Tree * ptree);
//删除一个项
//pi指向一个项；ptree指向一个已初始化的项
//如成功删除，返回true；否则返回false
bool DeleteItem(const Item * pi, Tree * ptree);
//将函数应用于树中的每一项
//ptree指向一个树；pfun指向一个函数；该函数接受一个Item类型的参数，并无返回值
//pfun指向的函数为树中每一个项执行一次
void Traverse(const Tree * ptree, void(*pfun)(Item item));
//删除树中所有内容
//ptree指向一个已被初始化的树
//树为空
void DeleteAll(Tree * ptree);



#endif // TREE_H_INCLUDED
