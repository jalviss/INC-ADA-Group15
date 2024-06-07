#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int *days;
    int s;
} planList;

planList *createplanList(int days){
    planList *pList = (planList *)malloc(sizeof(planList));
    pList->days = (int *)malloc((days + 1) * sizeof(int));
    pList->s = 0;
    return pList;
}

void push(planList *pList, int e){
    int i = ++pList->s;
    while (i > 1 && e > pList->days[i / 2])
    {
        pList->days[i] = pList->days[i / 2];
        i /= 2;
    }
    pList->days[i] = e;
}

int top(planList *pList){
    return pList->days[1];
}

void pop(planList *pList){
    int t = pList->days[pList->s--], parent= 1, child = 2;

    while (child <= pList->s){
        if (child < pList->s && pList->days[child] < pList->days[child + 1]){
            child++;
        }
        if (t >= pList->days[child]){
            break;
        }
        pList->days[parent] = pList->days[child];
        parent= child;
        child *= 2;
    }
    pList->days[parent] = t;
}

void freeplanList(planList *pList){
    free(pList->days);
    free(pList);
}

int main()
{
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    
    int p[n];

	planList *pList = createplanList(n);
	int count = 0;
    for (int i = 0; i < n; i++){
        scanf("%d", &p[i]);
		push(pList, p[i]);
        if (m < p[i]){
            if (k > 0){
                m += top(pList);
                pop(pList);
                k--;
            }
            else break;
        }
        m -= p[i];
		count++;
    }

    printf("%d\n", count);
    freeplanList(pList);

    return 0;
}
