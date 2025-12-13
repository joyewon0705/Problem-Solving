import java.util.*;

class Solution {
    private List<Set<Integer>> graph;
    private int[][] dp;
    private boolean[] visited;
    
    public int solution(int n, int[][] lighthouse) {
        graph = buildGraph(n, lighthouse);
        dp = new int[n + 1][2];
        visited = new boolean[n + 1];
        
        dfs(1);
        
        return Math.min(dp[1][0], dp[1][1]);
    }
    
    private List<Set<Integer>> buildGraph(int n, int[][] edges) {
        List<Set<Integer>> graph = new ArrayList<>(n + 1);
        for (int i = 0; i <= n; i++) {
            graph.add(new HashSet<>());
        }
        
        for (int[] edge : edges) {
            int u = edge[0];
            int v = edge[1];
            graph.get(u).add(v);
            graph.get(v).add(u);
        }
        
        return graph;
    }
    
    private void dfs(int cur) {
        visited[cur] = true;
        dp[cur][1] = 1;
        
        for (int next : graph.get(cur)) {
            if (visited[next]) continue;
            
            dfs(next);
            
            dp[cur][0] += dp[next][1];
            dp[cur][1] += Math.min(dp[next][0], dp[next][1]);
        }
    }
}