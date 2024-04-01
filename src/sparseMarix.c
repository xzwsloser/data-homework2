// 用于演示稀疏矩阵的转置
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10
typedef struct triple{
    int row;
    int col;
    int value;
}Triple;
typedef struct tsMatrix{
    Triple data[MAXSIZE+1]; // 三元组序列
    int mu;// 表示行数,列数和非零元元素个数
}TsMartix;
// 根据稀疏矩阵得到三元组
void getList(int arr[10][10],TsMartix* ts){
    // 首先开始初始化
    int count=0;
   
    
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(arr[i][j]!=0){
                // 开始赋值
                ts->data[count].row=i;
                ts->data[count].col=j;
                ts->data[count].value=arr[i][j];
                count++;
            }
        }
    }
    ts->mu=count;
     
}
// 打印三元表
void displayList(TsMartix* ts){
    for(int i=0;i<ts->mu;i++){

            printf("%-3d",ts->data[i].row);
            printf("%-3d",ts->data[i].col);
            printf("%-3d",ts->data[i].value);
       
    printf("\n");
    }
    printf("\n");
}
// 打印元素
void displayArr(int arr[10][10]){
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            printf("%-5d",arr[i][j]);
        }
        printf("\n");
    }
}
void initArr(int arr[10][10]){
    for(int i=0;i<10;i++){
        for(int  j=0;j<10;j++){
            arr[i][j]=0;
        }
    }
}
int main(){
    int arr[10][10];
    initArr(arr);  // 分析一下,为什么9对应的也是0
    arr[0][2]=-12;
    arr[1][4]=9;
    arr[2][5]=8;
    arr[3][7]=-10;
    arr[5][6]=12;
    arr[6][7]=9;
    arr[8][9]=34;
    arr[9][4]=7;
    printf("稀疏矩阵为:\n");
    displayArr(arr);
    printf("三元组为:\n");
    TsMartix* ts=(TsMartix*)malloc(sizeof(TsMartix));
    getList(arr,ts);
    displayList(ts);
    // 开始遍历得到赋值向量表
    int num[10];
    int cpot[10];
    // 获取辅助向量表
    // 首先置为0
    for(int i=0;i<10;i++){
        num[i]=0;
    }
    // 开始求解非0元素个数
    for(int t=0;t<ts->mu;t++){
        num[ts->data[t].col]++;  // 最终行号就会成为列号,所以这里要对于原来的行号进行操作
    }
    
    // 开始求解cpot数组
    cpot[0]=0;
    for(int y=1;y<10;y++){
        cpot[y]=cpot[y-1]+num[y-1];
    }
    printf("辅助向量表为:\n");
    for(int h=0;h<10;h++){
        printf("%-3d",num[h]);
    }
    printf("\n");
    for(int m=0;m<10;m++){
        printf("%-3d",cpot[m]);
    }
    printf("\n");
    
    // 开始求解新的三元组
    TsMartix* newTs=(TsMartix*)malloc(sizeof(TsMartix));
    newTs->mu=ts->mu;
    printf("%d\n",newTs->mu);
    for(int p=0;p<ts->mu;p++){
        int col=ts->data[p].col;  // 原来操作的就是列号
        int q=cpot[col];
       
        newTs->data[q].row=ts->data[p].col;
        newTs->data[q].col=ts->data[p].row;
        newTs->data[q].value=ts->data[p].value;
        cpot[col]++;
    }
    printf("新的三元组为:\n");
    displayList(newTs);
    // 开始给矩阵赋值
    initArr(arr);
    for(int  i=0;i<newTs->mu;i++){
        arr[newTs->data[i].row][newTs->data[i].col]=newTs->data[i].value;
    }
    printf("转置之后的稀疏矩阵为:\n");
    displayArr(arr);
}

