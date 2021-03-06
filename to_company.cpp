//
// Created by manout on 18-3-26.
//

#include <vector>
#include <algorithm>

#include "common_use.h"
using std::sort;
using std::vector;



int TaxiTime(Point office, vector<Point>& taxis,int walktime,  int taxitime)
{
    auto cond = [&](Point& a, Point& b)
    {
        return a.sum() < b.sum();
    };
    
    sort(taxis.begin(), taxis.end(), cond);
    int totaxi_time = walktime * taxis[0].sum();
    int taxi_time = taxitime * (office - taxis[0]).sum();
    return totaxi_time + taxi_time;
}

int WalkTime(Point office, int walk)
{
    return walk * office.sum();
}

int to_company(int n, vector<Point>& taxis, Point office, int walktime, int taxitime)
{
    return std::min(TaxiTime(office, taxis, walktime, taxitime), WalkTime(office, walktime));
}