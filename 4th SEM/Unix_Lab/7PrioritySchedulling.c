#include<stdio.h>

int main() {
    int bt[20], p[20], wt[20], tat[20], pr[20], i, j, n;
    int total = 0, pos, temp, avg_wt, avg_tat;

    // Input number of processes
    printf("Enter Total Number of Process:");
    scanf("%d", &n);

    // Input burst time and priority for each process
    printf("\nEnter Burst Time and Priority\n");
    for (i = 0; i < n; i++) {
        printf("\nP[%d]\n", i + 1);
        printf("Burst Time:");
        scanf("%d", &bt[i]);
        printf("Priority:");
        scanf("%d", &pr[i]);
        p[i] = i + 1;
    }

    // Sort processes based on priority
    for (i = 0; i < n; i++) {
        pos = i;
        for (j = i + 1; j < n; j++) {
            if (pr[j] < pr[pos])
                pos = j;
        }
        temp = pr[i];
        pr[i] = pr[pos];
        pr[pos] = temp;
        temp = bt[i];
        bt[i] = bt[pos];
        bt[pos] = temp;
        temp = p[i];
        p[i] = p[pos];
        p[pos] = temp;
    }

    // Calculate waiting time for each process
    wt[0] = 0;
    for (i = 1; i < n; i++) {
        wt[i] = 0;
        for (j = 0; j < i; j++)
            wt[i] += bt[j];
        total += wt[i];
    }

    // Calculate average waiting time
    avg_wt = total / n;
    total = 0;

    // Display process details and calculate turnaround time
    printf("\nProcess\t Burst Time \tWaiting Time\tTurnaround Time");
    for (i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
        total += tat[i];
        printf("\nP[%d]\t\t %d\t\t %d\t\t\t%d", p[i], bt[i], wt[i], tat[i]);
    }

    // Calculate and display average turnaround time
    avg_tat = total / n;
    printf("\n\nAverage Waiting Time=%d", avg_wt);
    printf("\nAverage Turnaround Time=%d\n", avg_tat);

    return 0;
}
