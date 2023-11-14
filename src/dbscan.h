#ifndef DBSCAN_H
#define DBSCAN_H

#include <vector>
#include <cmath>

enum point_types{
    UNCLASSIFIED =0,
    CORE_POINT,
    BORDER_POINT,
    NOISE,
    SUCCESS,
    FAILURE
};

using namespace std;

typedef pair<float, size_t> Point;

class DBSCAN {
public:    
    DBSCAN(unsigned int minPts, float eps, vector<Point> points){
        m_minPoints = minPts;
        m_epsilon = eps;
        m_points = points;
        m_pointSize = points.size();
    }
    ~DBSCAN(){}

    size_t run();
    vector<size_t> calculateCluster(Point point);
    size_t expandCluster(Point point, int clusterID);
    inline float calculateDistance(const Point& pointCore, const Point& pointTarget);

    size_t getTotalPointSize() {return m_pointSize;}
    size_t getMinimumClusterSize() {return m_minPoints;}
    size_t getEpsilonSize() {return m_epsilon;}
    
public:
    vector<Point> m_points;
    
private:    
    unsigned int m_pointSize;
    unsigned int m_minPoints;
    float m_epsilon;
};

#endif // DBSCAN_H
