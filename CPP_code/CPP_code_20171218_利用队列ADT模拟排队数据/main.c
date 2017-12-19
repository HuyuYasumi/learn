#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "queue.h"
#define MIN_PER_HR 60.0

bool newcustomer(double x);
Item customertime(long when);

int main()
{
    Queue line;
    Item temp;
    int hours, perhour, wait_time=0;
    long cycle, cyclelimit, turnaways=0, customers=0, served=0, sum_line=0, line_wait=0;
    double min_per_cust;

    InitializeQueue(&line);
    srand((unsigned int)time(0));

    puts("Case Study: Sigmund Lander's Advice Booth");
    puts("Enter the number of simulation hours:");
    scanf("%d", &hours);
    cyclelimit=MIN_PER_HR*hours;
    puts("Enter the average number of customers per hour:");
    scanf("%d", &perhour);
    min_per_cust=MIN_PER_HR/perhour;

    for(cycle=0; cycle<cyclelimit; cycle++) {
        if(newcustomer(min_per_cust)) {
            if(QueueIsFull(&line)) {
                turnaways++;
            } else {
                customers++;
                temp=customertime(cycle);
                EnQueue(temp, &line);
            }
        }
        if(wait_time <= 0 && !QueueIsEmpty(&line)) {
            DeQueue(&temp, &line);
            wait_time=temp.processtime;
            line_wait+=cycle-temp.arrive;
            served++;
        } else {
            wait_time--;
        }
        sum_line+=QueueItemCount(&line);
    }

    if(customers>0) {
        printf("customers accepted: %ld\n", customers);
        printf("customers served: %ld\n", served);
        printf("turnaways: %ld\n", turnaways);
        printf("average queue size: %.2f\n", (double)sum_line/cyclelimit);
        printf("average wait time: %.2f minutes\n", (double)line_wait/served);
    } else {
        puts("No customers!");
    }
    EmptyTheQueue(&line);
    puts("Bye!");
    return 0;
}

//x是顾客到来的平均时间（min）
//如1分钟有顾客到来，返回true
bool newcustomer(double x)
{
    if(rand()*x/RAND_MAX<1) return true;
    else return false;
}

//when是顾客到来的时间
//返回一个Item结构，该顾客到达的时间设置为when
//资讯时间设置为1~3的随机值
Item customertime(long when)
{
    Item cust;
    cust.processtime=rand()%3+1;
    cust.arrive=when;
    return cust;
}
