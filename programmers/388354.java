import java.util.*;

class Solution {
    
    public int[] solution(int[] nodes, int[][] edges) {
        
        // node 번호의 최대값
        int maxNode = Arrays.stream(nodes).max().orElse(0);
        
        // 인접 리스트 생성
        List<List<Integer>> graph = buildGraph(maxNode, edges);
        
        boolean[] visited = new boolean[maxNode + 1];
        int[] answer = { 0, 0 };

        // 연결 요소 탐색
        for (int node : nodes) {
            if (!visited[node]) {
                int[] cnt = { 0, 0 };
                dfs(node, visited, graph, cnt);
                
                if (cnt[0] == 1) answer[0]++;
                if (cnt[1] == 1) answer[1]++;
            }
        }
        
        return answer;
    }
    
    private List<List<Integer>> buildGraph(int n, int[][] edges) {
        List<List<Integer>> graph = new ArrayList<>(n + 1);
        for (int i = 0; i <= n; i++) {
            graph.add(new ArrayList<>());
        }
        
        for (int[] e : edges) {
            graph.get(e[0]).add(e[1]);
            graph.get(e[1]).add(e[0]);
        }
        
        return graph;
    }
    
    private void dfs(
        int cur, boolean[] visited, List<List<Integer>> graph, int[] cnt
    ) {
        if (visited[cur]) return;
        visited[cur] = true;
        
        // 노드 종류 판단
        int degree = graph.get(cur).size();
        if (cur % 2 == degree % 2) {
            cnt[0]++;
        }
        else {
            cnt[1]++;
        }
        
        // 인접 노드 DFS
        for (int next : graph.get(cur)) {
            dfs(next, visited, graph, cnt);
        }
    }
}