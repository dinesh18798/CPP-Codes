#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

//Define the structs Workshops and Available_Workshops.
//Implement the functions initialize and CalculateMaxWorkshops

struct Workshops
{
public:
    int startTime, duration, endTime;
};

struct Available_Workshops
{
    int n;
    vector<Workshops> *workshopData = new vector<Workshops>(n);
};

Available_Workshops *initialize(int start_time[], int duration[], int n)
{
    Available_Workshops *currentWorkshops = new Available_Workshops();
    currentWorkshops->n = n;

    for (int i = 0; i < n; ++i)
    {
        Workshops ws;
        ws.startTime = start_time[i];
        ws.duration = duration[i];
        ws.endTime = ws.startTime + ws.duration;
        currentWorkshops->workshopData->push_back(ws);
    }

    return currentWorkshops;
}

int CalculateMaxWorkshops(Available_Workshops *ptr)
{
    int attendWorkshops = 0;
    sort(ptr->workshopData->begin(), ptr->workshopData->end(), [](const Workshops &work1, const Workshops &work2) { return work1.endTime < work2.endTime; });

    int currentEndTime = 0;

    for (auto it = ptr->workshopData->begin(); it != ptr->workshopData->end(); ++it)
    {
        if (currentEndTime <= it->startTime)
        {
            ++attendWorkshops;
            currentEndTime = it->endTime;
        }
    }
    return attendWorkshops;
}

int main(int argc, char *argv[])
{
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int *start_time = new int[n];
    int *duration = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> start_time[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> duration[i];
    }

    Available_Workshops *ptr;
    ptr = initialize(start_time, duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}