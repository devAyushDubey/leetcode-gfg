class Compare {
public:
	bool operator()(pair<string, int>& a, pair<string, int>& b) {
        if(a.second == b.second) {
            return b.first < a.first;
        }
		return b.second > a.second;
	}
};

class FoodRatings {
private:
    unordered_map<string, int> foodRating;
    unordered_map<string, string> foodCuisine;
    unordered_map<string, priority_queue<pair<string, int>, vector<pair<string, int>>, Compare>> ratingsJug; 
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for(int i=0; i<n; i++) {
            foodCuisine[foods[i]] = cuisines[i];
            foodRating[foods[i]] = ratings[i];
            pair<string, int> p = {foods[i], ratings[i]};
            if(ratingsJug.find(cuisines[i]) == ratingsJug.end()) {
                priority_queue<pair<string, int>, vector<pair<string, int>>, Compare> pq;
                pq.push(p);
                ratingsJug[cuisines[i]] = pq;
            }
            else {
                ratingsJug[cuisines[i]].push(p);
            }
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuisine = foodCuisine[food];
        foodRating[food] = newRating;
        pair<string, int> p = {food, newRating};
        ratingsJug[cuisine].push(p);
    }
    
    string highestRated(string cuisine) {
        pair<string, int> highest = ratingsJug[cuisine].top();
        while(foodRating[highest.first] != highest.second) {
            ratingsJug[cuisine].pop();
            highest = ratingsJug[cuisine].top();
        }
        return highest.first;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */