import java.util.*;

class Solution {
    private static final int INF = 1 << 30;
    
    public int[] solution(int n, int[][] roads, int[] sources, int destination) {
        List<List<Integer>> neighbors = new ArrayList();
        for (int i = 0; i <= n; i++) {
            neighbors.add(new ArrayList());
        }
        
        for (int[] road : roads) {
            neighbors.get(road[0]).add(road[1]);
            neighbors.get(road[1]).add(road[0]);
        }
        
        int[] dist = new int[n + 1];
        Arrays.fill(dist, INF);
        dist[destination] = 0;
        
        Queue<Integer> q = new LinkedList<>();
        q.add(destination);
        while (!q.isEmpty()) {
            int cur = q.poll();
            for (int next : neighbors.get(cur)) {
                if (dist[next] > dist[cur] + 1) {
                    dist[next] = dist[cur] + 1;
                    q.add(next);
                }
            }
        }
        
        int[] answer = new int[sources.length];
        for (int i = 0; i < sources.length; i++) {
            if (dist[sources[i]] >= INF) answer[i] = -1;
            else answer[i] = dist[sources[i]];
        }
        
        return answer;
    }
}