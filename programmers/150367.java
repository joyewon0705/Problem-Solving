import java.util.*;

class Solution {
    public int[] solution(long[] numbers) {
        int n = numbers.length;
        int[] answer = new int[n];
        
        for (int i = 0; i < n; i++) {
            String binaryTree = toFullBinaryTree(numbers[i]);
            if (isValid(binaryTree)) {
                answer[i] = 1;
            }
        }
        
        return answer;
    }
    
    // 수를 포화 이진트리로 변환
    private String toFullBinaryTree(long n) {
        String binary = Long.toBinaryString(n);
        int len = binary.length();
        int height = (int) Math.ceil(Math.log(len + 1) / Math.log(2));
        int targetLen = (int) Math.pow(2, height) - 1;
        
        if (targetLen > len) {
            return "0".repeat(targetLen - len) + binary;
        }
        return binary;
    }
    
    // 포화 이진트리가 유효한지 검사
    private boolean isValid(String tree) {
        int len = tree.length();
        
        if (len == 1) {
            // 리프 노드인 경우
            return true;
        }
        
        int mid = len / 2;
        char root = tree.charAt(mid);
        
        if (root == '0') {
            // 루트 노드가 더미인 경우, 자식 노드도 모두 더미여야 함
            if (tree.indexOf('1') != -1) {
                return false;
            }
        } else {
            // 루트 노드가 존재하는 경우, 좌우 서브 트리 검사
            if (!isValid(tree.substring(0, mid))
               || !isValid(tree.substring(mid + 1))) {
                return false;
            }
        }
        return true;
    }
}