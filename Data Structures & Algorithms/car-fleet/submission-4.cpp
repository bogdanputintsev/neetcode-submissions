struct Car {
    int pos;
    int speed;
    double steps;
    bool operator<(const Car& other) const {
        return pos > other.pos;
    }
};

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<Car> cars;
        cars.reserve(position.size());
        for (int i = 0; i < position.size(); i++) {
            const double steps = static_cast<double>(target - position[i]) / speed[i];
            cars.emplace_back(position[i], speed[i], steps);
        }
        sort(cars.begin(), cars.end());

        stack<double> fleets;
        for (const auto& car : cars) {
            if (fleets.empty() || car.steps > fleets.top()) {
                fleets.push(car.steps);
            }
        }

        return fleets.size();
    }
};
