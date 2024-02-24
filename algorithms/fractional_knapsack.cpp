#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int comparator(pair<double, double> A, pair<double, double> B){
    return A.second > B.second;
}

double fractional_knapsack(vector<double>& values, vector<double>& weights, double capacity){

    // Create a vector that stores value per weight
    vector<pair<double, double>> vpw;
    for(int i=0; i<weights.size(); i++){
        pair<double, double> item = {weights[i], values[i] / weights[i]};
        vpw.push_back(item);
    }

    sort(vpw.begin(), vpw.end(), comparator);

    double weight_added = 0;
    double total_profit = 0;

    // Apply the fractional knapsack algorithm
    for(auto p : vpw){

        if(weight_added + p.first <= capacity){
            weight_added += p.first;
            total_profit += p.first * p.second;
        }
        else{
            total_profit += (capacity - weight_added) * p.second;
            break;
        }
    }
    return total_profit;
}

int main(){

    // Test Case 1
    vector<double> profit = {280, 100, 120, 120};
    vector<double> weight = {40, 10, 20, 24};
    double capacity = 60;

    double total_profit = fractional_knapsack(profit, weight, capacity);

    cout << "--- First Test Case ---" << endl;
    cout << "Total profit earned: " << total_profit << endl;
    cout << endl;

    // Test Case 2
    profit = {5, 10, 15, 7, 8, 9, 4};
    weight = {1, 3, 5, 4, 1, 3, 2};

    total_profit = fractional_knapsack(profit, weight, capacity);

    cout << "--- Second Test Case ---" << endl;
    cout << "Total profit earned: " << total_profit << endl;
    cout << endl;

    return 0;
}