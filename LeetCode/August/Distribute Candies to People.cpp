class Solution 
{
public:
    vector<int> distributeCandies(int candies, int num_people) 
    {
        int c = 1, i = 0;
        
        vector<int> result(num_people, 0);
        
        while(candies) {

            int give = min(c, candies);
            result[i] += give;
            candies -= give;
            
            c++;
            i = (i+1) % num_people; 
        }
        
        return result;
    }
};