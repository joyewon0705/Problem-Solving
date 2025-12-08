import java.util.*;

class Solution {
    private final static int N = 51;
    
    private String[][] table = new String[N][N];
    private int[][] id = new int[N][N];
    
    public String[] solution(String[] commands) {
        List<String> result = new ArrayList<>();
        
        for (int i = 1; i < N; i++) {
            for (int j = 1; j < N; j++) {
                id[i][j] = i * N + j;
            }
        }
        
        for (String cmd : commands) {
            String[] tokens = cmd.split(" ");
            
            switch(tokens[0]) {
                    case "UPDATE" -> update(tokens);
                    case "MERGE" -> merge(tokens);
                    case "UNMERGE" -> unmerge(tokens);
                    case "PRINT" -> result.add(print(tokens));
            }
        }
        
        return result.toArray(String[]::new);
    }
    
    private void update(String[] tokens) {
        if (tokens.length == 4) {
            int r = Integer.parseInt(tokens[1]);
            int c = Integer.parseInt(tokens[2]);
            int targetId = id[r][c];
            String value = tokens[3];

            for (int i = 1; i < N; i++) {
                for (int j = 1; j < N; j++) {
                    if (id[i][j] == targetId) {
                        table[i][j] = value;
                    }
                }
            }
        } else if (tokens.length == 3) {
            String value1 = tokens[1];
            String value2 = tokens[2];
            
            for (int i = 1; i < N; i++) {
                for (int j = 1; j < N; j++) {
                    if (table[i][j] != null && table[i][j].equals(value1)) {
                        table[i][j] = value2;
                    }
                }
            }
        }
    }
    
    private void merge(String[] tokens) {
        if (tokens.length != 5) return;
        
        int r1 = Integer.parseInt(tokens[1]);
        int c1 = Integer.parseInt(tokens[2]);
        int r2 = Integer.parseInt(tokens[3]);
        int c2 = Integer.parseInt(tokens[4]);
        int targetId1 = id[r1][c1];
        int targetId2 = id[r2][c2];
        
        if (targetId1 == targetId2) return;
        
        String value = (table[r1][c1] == null) ? table[r2][c2] : table[r1][c1];
        
        for (int i = 1; i < N; i++) {
            for (int j = 1; j < N; j++) {
                if (id[i][j] == targetId2) {
                    id[i][j] = targetId1;
                }
                if (id[i][j] == targetId1) {
                    table[i][j] = value;
                }
            }
        }
    }
    
    private void unmerge(String[] tokens) {
        if (tokens.length != 3) return;
        
        int r = Integer.parseInt(tokens[1]);
        int c = Integer.parseInt(tokens[2]);
        int targetId = id[r][c];
        String value = table[r][c];
        
        for (int i = 1; i < N; i++) {
            for (int j = 1; j < N; j++) {
                if (id[i][j] == targetId) {
                    id[i][j] = i * N + j;
                    table[i][j] = null;
                }
            }
        }
        table[r][c] = value;
    }
    
    private String print(String[] tokens) {
        if (tokens.length != 3) return null;
        
        int r = Integer.parseInt(tokens[1]);
        int c = Integer.parseInt(tokens[2]);
        
        return (table[r][c] == null) ? "EMPTY" : table[r][c];
    }
}