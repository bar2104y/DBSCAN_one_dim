#include <stdio.h>
#include <iostream>
#include "dbscan.h"

#define MINIMUM_POINTS 2     // minimum number of cluster
#define EPSILON (0.1*0.1)  // distance for clustering, metre^2

void readBenchmarkData(vector<Point>& points)
{
    // load point cloud
    FILE *stream;
    stream = fopen ("benchmark2.dat","ra");

    size_t minpts, num_points =0, cluster, i = 0;
    float epsilon;
    num_points=120;

    Point *p = (Point *)calloc(num_points, sizeof(Point));

    while (i < num_points)
    {
          fscanf(stream, "%f, %ld\n", &(p[i].first), &cluster);
          p[i].second = UNCLASSIFIED;
          points.push_back(p[i]);
          ++i;
    }

    free(p);
    fclose(stream);
}

void printResults(vector<Point>& points, int num_points)
{
    int i = 0;
    printf("Number of points: %u\n"
        " x        cluster_id\n"
        "-----------------------------\n["
        , num_points);
    while (i < num_points)
    {
          printf("[%5.2lf,  %ld],\n",
                points[i].first,
                points[i].second);
          ++i;
    }
    printf("]");
}

int main()
{    
    vector<Point> points;

    // read point data
    readBenchmarkData(points);

    // constructor
    DBSCAN ds(MINIMUM_POINTS, EPSILON, points);

    // main loop
    ds.run();

    // result of DBSCAN algorithm
    printResults(ds.m_points, ds.getTotalPointSize());    

    return 0;
}
