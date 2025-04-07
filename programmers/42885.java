import java.util.*;

class Solution {
    
    public int solution(int[] people, int limit) {
        int answer = 0;
        int low, high;
        
        Arrays.sort(people);
        
        low = 0;
        high = people.length - 1;
        while (low <= high) {
            if (people[high] + people[low] > limit) {
                high--;
            }
            else {
                high--;
                low++;
            }
            answer++;
        }
        
        return answer;
    }
}