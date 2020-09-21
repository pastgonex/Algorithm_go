/*从顺序表中删除具有最小值的元素，并由函数返回被删元素的值，
空出的位置由最后一个元素填补，若顺序表为空则显示出错信息并退出运行*/
#include <stdio.h>

typedef int ElemType;
#define MaxSize 10           //定义线性表的最大长度


typedef struct {
    ElemType data[MaxSize];        //顺序表的元素
    int length;               //顺序表的当前长度
} SqList;                     //顺序表的类型定义

bool Del_Min(SqList &L, int &value) {
    //删除顺序表中的最小值元素结点，并通过引用型参数value返回其值
    if (L.length == 0)
        return false;             //表空，中止操作返回
    value = L.data[0];
    int pos = 0;              //假定0号元素的值最小
    for (int i = 1; i < L.length; i++)  //循环，寻找具有最小值的元素
        if (L.data[i] < value) {
            value = L.data[i];       //让value始终记忆当前具有最小值的元素
            pos = i;
        }
    L.data[pos] = L.data[L.length - 1];   //空出的位置由最后一个元素填补
    L.length--;
    return true;                        //此时value即为最小值 
}

int main() {
    SqList L;
    L.length = 0;
    for (int & i : L.data) {
        scanf("%d", &i);
        L.length++;                  //每输入一个数顺序表的当前长度加1
    }
    int a;
    Del_Min(L, a);
    printf("顺序表中最小值为:%d\n", a);
    for (int i = 0; i < L.length; i++) {
        printf("%d ", L.data[i]);
    }
    return 0;
}
