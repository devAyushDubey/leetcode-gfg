class Compare {
public:
	bool operator()(pair<int, int> a, pair<int, int> b) {
		if(a.second == b.second) {
            return b.first > a.first;
        }
        return b.second > a.second;
	}
};
class TaskManager {
private:
    unordered_map<int, int> taskToUser;
    unordered_map<int, int> taskToPriority;
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> taskQueue;
public:
    TaskManager(vector<vector<int>>& tasks) {
        pair<int, int> p;
        for(vector<int> task: tasks) {
            taskToUser[task[1]] = task[0];
            taskToPriority[task[1]] = task[2];
            p = {task[1], task[2]};
            taskQueue.push(p);
        }
    }
    
    void add(int userId, int taskId, int priority) {
        pair<int, int> p = {taskId, priority};
        taskToUser[taskId] = userId;
        taskToPriority[taskId] = priority;
        taskQueue.push(p);
    }
    
    void edit(int taskId, int newPriority) {
        taskToPriority[taskId] = newPriority;
        pair<int, int> p = {taskId, newPriority};
        taskQueue.push(p);
    }
    
    void rmv(int taskId) {
        taskToUser.erase(taskId);
        taskToPriority.erase(taskId);
    }
    
    int execTop() {
        while((taskToUser.find(taskQueue.top().first) == taskToUser.end()) || (taskToPriority[taskQueue.top().first] != taskQueue.top().second)) {
            if(taskQueue.empty()) break;
            taskQueue.pop();
        }
        if(taskQueue.empty()) return -1;
        int ans = taskToUser[taskQueue.top().first];
        rmv(taskQueue.top().first);
        taskQueue.pop();
        return ans;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */