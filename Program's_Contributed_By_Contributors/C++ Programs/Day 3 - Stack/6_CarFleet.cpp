/*
There are n cars going to the same destination along a one-lane road. The destination is target miles away.

You are given two integer array position and speed, both of length n, where position[i] is the position of the ith car and speed[i] is the speed of the ith car (in miles per hour).

A car can never pass another car ahead of it, but it can catch up to it and drive bumper to bumper at the same speed. The faster car will slow down to match the slower car's speed. The distance between these two cars is ignored (i.e., they are assumed to have the same position).

A car fleet is some non-empty set of cars driving at the same position and same speed. Note that a single car is also a car fleet.

If a car catches up to a car fleet right at the destination point, it will still be considered as one car fleet.

Return the number of car fleets that will arrive at the destination.

https://leetcode.com/problems/car-fleet/description/
*/

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        if (n == 0) {
            return 0;
        }

        vector<pair<int, double>> cars;
        for (int i = 0; i < n; ++i) {
            cars.push_back({position[i], (target - position[i]) / static_cast<double>(speed[i])});
        }

        sort(cars.begin(), cars.end(), [](const pair<int, double>& a, const pair<int, double>& b) {
            return a.first > b.first;
        });

        stack<double> fleetTimes;
        int fleets = 0;

        for (const auto& car : cars) {
            double arrivalTime = car.second;
            if (fleetTimes.empty() || arrivalTime > fleetTimes.top()) {
                fleetTimes.push(arrivalTime);
                fleets++;
            }
        }

        return fleets;
    }
};