

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, double>> cars(n);
        for (int i = 0; i < n; ++i) {
            cars[i] = {position[i], (double)(target - position[i]) / speed[i]};
        }
        sort(cars.begin(), cars.end(), greater<pair<int, double>>());

        stack<double> stk;
        for (const auto& car : cars) {
            double time = car.second;
            if (stk.empty() || time > stk.top()) {
                stk.push(time);
            }
        }
        return stk.size();
    }
};
