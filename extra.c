#include <stdio.h>

void calculateTimes(int arrival_time[], int burst_time[], int n, int waiting_time[], int turnaround_time[])
{
    waiting_time[0] = 0;
    turnaround_time[0] = burst_time[0];

    for (int i = 1; i < n; i++)
    {
        waiting_time[i] = waiting_time[i - 1] + burst_time[i - 1] - arrival_time[i];
        if (waiting_time[i] < 0)
        {
            waiting_time[i] = 0;
        }
        turnaround_time[i] = waiting_time[i] + burst_time[i];
    }
}

void calculateAverages(int waiting_time[], int turnaround_time[], int n)
{
    float total_waiting_time = 0, total_turnaround_time = 0;

    for (int i = 0; i < n; i++)
    {
        total_waiting_time += waiting_time[i];
        total_turnaround_time += turnaround_time[i];
    }

    printf("Average Waiting Time: %.2f\n", total_waiting_time / n);
    printf("Average Turnaround Time: %.2f\n", total_turnaround_time / n);
}

void displayProcesses(int arrival_time[], int burst_time[], int waiting_time[], int turnaround_time[], int n)
{
    printf("Process\t\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++)
    {
        printf("\t%d\t\t\t%d\t\t\t\t%d\t\t\t\t%d\t\t\t%d\n", i + 1, arrival_time[i], burst_time[i], waiting_time[i], turnaround_time[i]);
    }
}

int main()
{
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int arrival_time[n];
    int burst_time[n];
    int waiting_time[n];
    int turnaround_time[n];

    printf("Enter arrival time and burst time for each process:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Arrival time of process %d: ", i + 1);
        scanf("%d", &arrival_time[i]);
        printf("Burst time of process %d: ", i + 1);
        scanf("%d", &burst_time[i]);
    }

    waiting_time[0] = 0;
    turnaround_time[0] = burst_time[0];

    calculateTimes(arrival_time, burst_time, n, waiting_time, turnaround_time);
    displayProcesses(arrival_time, burst_time, waiting_time, turnaround_time, n);
    calculateAverages(waiting_time, turnaround_time, n);

    return 0;
}
