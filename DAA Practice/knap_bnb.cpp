#include <iostream>
#include <vector>
#include <algorithm>

/*
Branch and bound and dynamic programming are both optimization techniques used to solve combinatorial optimization problems, such as the 0-1 Knapsack problem. While both approaches aim to find the optimal solution, they differ in their strategies and the way they explore the solution space.

Branch and Bound:
Strategy:

Exploration: Branch and bound explores the solution space by considering various branches and bounding the search to avoid exploring certain paths that cannot lead to an optimal solution.
Pruning: It employs pruning techniques to eliminate subproblems or branches that cannot contribute to the optimal solution, reducing the overall search space.
Application:

Branch and bound is particularly useful for problems with a large solution space, where exploring all possible solutions is not feasible.
Memory Usage:

Generally, branch and bound may use less memory compared to dynamic programming because it explores the solution space in a depth-first or breadth-first manner without storing all subproblem solutions.
Dynamic Programming:
Strategy:

Memoization: Dynamic programming uses a memoization table to store and reuse solutions to subproblems. It breaks down the problem into smaller overlapping subproblems and solves each subproblem only once, storing the result for future use.
Bottom-Up Approach: Dynamic programming often uses a bottom-up approach, starting with the smallest subproblems and building up to the overall problem.
Application:

Dynamic programming is well-suited for problems with optimal substructure and overlapping subproblems, where solutions to subproblems can be reused.
Memory Usage:

Dynamic programming may use more memory due to the need to store solutions to all subproblems in a table. However, this can be more efficient than recomputing solutions multiple times.
Differences:
Exploration Strategy:

Branch and bound explores the solution space by considering different branches and pruning, while dynamic programming breaks down the problem into smaller subproblems and solves them independently.
Memory Usage:

Branch and bound tends to use less memory as it explores the solution space incrementally, whereas dynamic programming may use more memory to store solutions to all subproblems.
Problem Characteristics:

Branch and bound is often preferred for problems with a large solution space, while dynamic programming is effective for problems with optimal substructure and overlapping subproblems.
Optimality:

Both approaches aim to find the optimal solution, but the path to reaching that solution and the way solutions are stored and reused differ.
In summary, while branch and bound and dynamic programming share the goal of finding optimal solutions, they employ different strategies for exploration, pruning, and memory management, making each approach suitable for different types of optimization problems.

*/

using namespace std;

// Structure to represent items
struct Item
{
    int weight;
    int value;
};

// Function to compare items based on the value-to-weight ratio
bool compareItems(Item i1, Item i2)
{
    return (static_cast<double>(i1.value) / i1.weight) > (static_cast<double>(i2.value) / i2.weight);
}

class Knapsack
{
private:
    int capacity;
    vector<Item> items;
    int maxValue;

public:
    Knapsack(int capacity, vector<Item> items)
    {
        this->capacity = capacity;
        this->items = items;
        this->maxValue = 0;
    }

    // Function to solve the 0-1 Knapsack problem using branch and bound
    void solve()
    {
        // Sort items based on the value-to-weight ratio in descending order
        sort(items.begin(), items.end(), compareItems);

        // Initialize variables
        int currentWeight = 0;
        int currentValue = 0;
        int level = -1;

        // Call the branch and bound recursive function
        branchAndBound(level, currentWeight, currentValue);

        // Output the result
        cout << "Maximum value in Knapsack: " << maxValue << endl;
    }

private:
    // Recursive function for branch and bound
    void branchAndBound(int level, int currentWeight, int currentValue)
    {
        // Increment level
        level++;

        // If we reached the end of the items or the capacity is 0, return
        if (level == items.size() || currentWeight == capacity)
        {
            if (currentValue > maxValue)
            {
                maxValue = currentValue;
            }
            return;
        }

        // Calculate the bound for the current node
        double bound = currentValue + (capacity - currentWeight) * (static_cast<double>(items[level].value) / items[level].weight);

        // Check if the node can be included
        if (bound > maxValue)
        {
            // Include the current item
            if (currentWeight + items[level].weight <= capacity)
            {
                branchAndBound(level, currentWeight + items[level].weight,
                               currentValue + items[level].value);
            }

            // Exclude the current item
            branchAndBound(level, currentWeight, currentValue);
        }
    }
};

int main()
{
    // Example usage
    int capacity = 50;
    vector<Item> items = {{10, 60}, {20, 100}, {30, 120}};

    Knapsack knapsack(capacity, items);
    knapsack.solve();

    return 0;
}
