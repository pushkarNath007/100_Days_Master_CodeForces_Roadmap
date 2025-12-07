#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// Function to calculate factorial
int factorial(int n)
{
    if (n <= 1)
        return 1;
    else
        return n * factorial(n - 1);
}

// Function to calculate total distance for a path
int calculateDistance(vector<vector<int>> &graph, vector<int> &path)
{
    int distance = 0;
    for (int i = 0; i < path.size() - 1; ++i)
    {
        distance += graph[path[i]][path[i + 1]];
    }
    distance += graph[path[path.size() - 1]][path[0]]; // Return to the start
    return distance;
}

// Function to find the shortest path using naive approach
void tsp_naive(vector<vector<int>> &graph, int start)
{
    int n = graph.size();
    vector<int> all_cities;
    for (int i = 0; i < n; ++i)
    {
        if (i != start)
            all_cities.push_back(i);
    }

    int min_distance = INT_MAX;
    vector<int> best_path;

    // Generate all permutations of cities
    vector<int> permutation = all_cities;
    do
    {
        int distance = graph[start][permutation[0]];
        for (int i = 0; i < permutation.size() - 1; ++i)
        {
            distance += graph[permutation[i]][permutation[i + 1]];
        }
        distance += graph[permutation[permutation.size() - 1]][start]; // Return to the start

        if (distance < min_distance)
        {
            min_distance = distance;
            best_path = permutation;
        }
    } while (next_permutation(permutation.begin(), permutation.end()));

    cout << "Minimum distance: " << min_distance << endl;
    cout << "Best path: ";
    cout << start << " ";
    for (int i = 0; i < best_path.size(); ++i)
        cout << best_path[i] << " ";
    cout << start << endl;
}

int main()
{
    vector<vector<int>> graph = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}};

    int start_city = 0; // Assuming the starting city is A (0-indexed)

    tsp_naive(graph, start_city);

    return 0;
}
