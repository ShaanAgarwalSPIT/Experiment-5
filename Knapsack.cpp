#include<bits/stdc++.h>

using namespace std;

// A structure to represent items in the knapsack
struct Item {
    int value;
    int weight;
    double ratio; // value to weight ratio
};

// Function to compare items based on their ratio
bool compareItems(Item i1, Item i2) {
    return (i1.ratio > i2.ratio);
}

// Function to solve the fractional knapsack problem using greedy approach
double knapsack(int W, vector<Item>& items) {
    double max_value = 0.0;
    sort(items.begin(), items.end(), compareItems); // Sort items based on their ratio

    cout << left << setw(10) << "Item"
         << setw(10) << "Value"
         << setw(10) << "Weight"
         << setw(10) << "Ratio"
         << setw(10) << "Take"
         << setw(10) << "Value Taken"
         << endl;

    for (int i = 0; i < items.size(); i++) {

        int wt = items[i].weight;
        int val = items[i].value;
        double fraction = 0.0;

        if (W >= wt) {
            // Take the whole item
            W -= wt;
            max_value += val;
            cout << left << setw(10) << i+1
                 << setw(10) << val
                 << setw(10) << wt
                 << setw(10) << items[i].ratio
                 << setw(10) << "Yes"
                 << setw(10) << val
                 << endl;
        } else {
            // Take a fraction of the item
            fraction = (double) W / (double) wt;
            max_value += (val * fraction);
            W = 0;
            cout << left << setw(10) << i+1
                 << setw(10) << val
                 << setw(10) << wt
                 << setw(10) << items[i].ratio
                 << setw(10) << fixed << setprecision(2) << fraction
                 << setw(10) << fixed << setprecision(2) << val*fraction
                 << endl;
        }
    }

    return max_value;
}

// Main function
int main() {
    int n; // Number of items
    int W; // Total weight capacity of the knapsack

    cout << "Enter the number of items: ";
    cin >> n;

    cout << "Enter the total weight capacity of the knapsack: ";
    cin >> W;

    vector<Item> items(n);

    for (int i = 0; i < n; i++) {
        cout << "Enter the value and weight of item " << i+1 << ": ";
        cin >> items[i].value >> items[i].weight;
        items[i].ratio = (double) items[i].value / (double) items[i].weight;
    }

    double max_value = knapsack(W, items);

    cout << "The maximum value that can be obtained is: " << max_value << endl;

    return 0;
}

