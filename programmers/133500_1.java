import java.util.*;

class Solution {
    public int solution(int n, int[][] lighthouse) {
        List<Set<Integer>> graph = buildGraph(n, lighthouse);
        Queue<Integer> leaves = getLeaves(graph);
        boolean[] removed = new boolean[n + 1];
        int answer = 0;
        
        while (!leaves.isEmpty()) {
            int leaf = leaves.poll();
            if (removed[leaf] || graph.get(leaf).size() == 0) continue;
            
            int parent = graph.get(leaf).iterator().next();
            if (removed[parent]) continue;
            
            removed[parent] = true;
            answer++;
            
            for (int child : graph.get(parent)) {
                graph.get(child).remove(parent);
                
                if (!removed[child] && graph.get(child).size() == 1) {
                    leaves.offer(child);
                }
            }
        }
        
        return answer;
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
    
    private Queue<Integer> getLeaves(List<Set<Integer>> graph) {
        Queue<Integer> leaves = new ArrayDeque<>();
        
        for (int i = 0; i < graph.size(); i++) {
            if (graph.get(i).size() == 1) {
                leaves.offer(i);
            }
        }
        return leaves;
    }
}