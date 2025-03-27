class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> OrderGrid;
        int v = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                OrderGrid.push_back(grid[i][j]);
            }
        }

        int rest = OrderGrid[0] % x;
        for(int i : OrderGrid){
            if((i % x) != rest)return -1;
        }

        stable_sort(OrderGrid.begin(), OrderGrid.end());

        int n = OrderGrid.size();
        int op = 0;

        int median = OrderGrid[n/2];
        for(int element : OrderGrid){
            while(element != median){
                if(element < median)element += x;
                if(element > median)element -= x;
                op++;
            }
        }
        return op;
    }
};
