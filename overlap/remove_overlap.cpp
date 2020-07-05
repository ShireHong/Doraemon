#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*去掉尽可能少的区间，使剩下的区间都不相交*/


/*
此题的思路主要时将区间按右区间的大小排序
一个比较重要的点是最小的那个区间一定是在所求区间内的
*/

/*存储左右区间的值*/
typedef struct _sec{
    int a;
    int b;
}sec_t;

void sort_sec(sec_t * ss,int len)
{
    int i,j;
    for(i=0;i<len;i++)
    {
        for(j=0;j<len-j;j++)
        {
            sec_t tmp;
            if(ss[j].b > ss[j+1].b)
            {
                tmp = ss[j];
                ss[j] = ss[j+1];
                ss[j+1] = tmp;
            }
        }
    }
}

int main()
{
    int i,n;
    scanf("%d",&n);
    sec_t *vv = (sec_t*)malloc(n*sizeof(sec_t));
    memset(vv,n,0); 

    /*要排序，左区间的值一定小于右区间*/
    for(i=0;i<n;i++)
    {
        scanf("%d %d",&vv[i].a,&vv[i].b);
        if(vv[i].a > vv[i].b)
        {
            vv[i].a = vv[i].a^vv[i].b;
            vv[i].b = vv[i].a^vv[i].b;
            vv[i].a = vv[i].a^vv[i].b;
        }
    }
   
    /*
    将输入的区间按照右区间值的大小进行排序
    */
    sort_sec(vv,n);
    #if 0
    for(i=0;i<n;i++)
    {
        printf("%d %d\n",vv[i].a,vv[i].b);
    }
    #endif
    int a[100] = {0};
    /*
    这个地方默认第一个区间肯定是互相不重叠区间的一个
    因为区间已经经过排序，其区间都是与后续区间的重叠度最低
    */
    a[0] = 1;
    for(i=1;i<n;i++)
    {
        /*
        判定两个区间是否有重叠，就是上一个区间的右值是否大于当前区间的左值。
        如果是大于的话，就是重叠，同步更新一下当前值的右区间的值，为下一个判断做准备。
        */
        if(vv[i-1].b > vv[i].a)
        {
            vv[i].b = vv[i-1].b;
            a[i] = 0;
        }
        else{
            a[i] = 1;
        }
    }
    #if 1
    printf("********************************\n");
    int sum = 0;
    for(i=0;i<n;i++)
    {
        if(a[i] == 1)
        {
            printf("%d %d\n",vv[i].a,vv[i].b);
            sum++;
        }
    }
    printf("%d \n",sum);
    #endif

}