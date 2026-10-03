import java.util.*;

class Solution {
    public int solution(int n, int[][] edge) {
        ArrayList<Integer>[] adj = new ArrayList[n+1];
        int[] dist = new int[n+1];
        Arrays.fill(dist,-1);
        for(int i=1;i<=n;i++)adj[i] = new ArrayList<>();
        
        for(int[] node : edge){
            adj[node[0]].add(node[1]);
            adj[node[1]].add(node[0]);
        }
        
        Queue<Integer> q = new ArrayDeque<>();
        q.offer(1);
        dist[1] = 0;
        
        while(!q.isEmpty()){
            int node = q.poll();
            for(int nxt : adj[node]){
                if(dist[nxt] == -1){
                    dist[nxt] = dist[node] + 1;
                    q.offer(nxt);
                }
            }
        }
        int maximal = Arrays.stream(dist).max().getAsInt();
        return (int)Arrays.stream(dist).filter(d->d==maximal).count();
    }
}