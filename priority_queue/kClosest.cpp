#include <vector>
#include <queue>

struct Point {
    int x;
    int y;
};

int dist(const Point& p)
{
    return p.x * p.x + p.y * p.y;
}

std::vector<Point> kClosest(const std::vector<Point>& points, int k)
{
    std::priority_queue<std::pair<int, Point>> pq;

    for (const Point& p : points)
    {
        pq.push({ dist(p), p });

        if ((int)pq.size() > k)
            pq.pop();
    }

    std::vector<Point> result;
    while (!pq.empty())
    {
        result.push_back(pq.top().second);
        pq.pop();
    }

    return result;
}
