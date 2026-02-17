/*
functionDijkstra(L[1..n,1..n]): array [2..n]
array Df2.. n]
{initialization}
C - {2, 3, . .. , n} {S = N \ C exists only implicitly
for i - 2 to n do D[i]- L[1, i]
{greedy loop}
repeat n - 2 times
v - some element of C minimizing D[v]
C - C \ {v} {and implicitly S - S u {v}}
for each w E C do
D[w]- min(D[w],D[v]+L[v,w])
return D
 */
class Dijkstra{
    public static int[] dijkstra(int mat[][],int src){
      int n=mat.length;  
      int result[]= new int[n];
      boolean[]visited=new boolean[n];
      for(int i=0;i<n;i++){
        result[i]=mat[src][i];
      }
      visited[src]=true;
      result[src]=0;
      for(int k=0;k<n-1;k++){
        //to find min from result
        int min=Integer.MAX_VALUE;
        int v=-1;
        for(int i=0;i<n;i++){
            if(!visited[i]&&result[i]<min){
                min=result[i];
                v=i;
            }
        }
        if(v==-1)
            break;
        visited[v]=true;
        for(int j=0;j<n;j++){
            if(!visited[j]&&mat[v][j]!=Integer.MAX_VALUE){
              if(result[v]+mat[v][j]<result[j]){
                result[j]=result[v]+mat[v][j];
              }
            }
        }
      }
      return result;
    }
    public static void main(String args[]){
        int mat[][]={
           {Integer.MAX_VALUE,50,30,100,10},
           {Integer.MAX_VALUE,Integer.MAX_VALUE,Integer.MAX_VALUE,Integer.MAX_VALUE,Integer.MAX_VALUE},
           {Integer.MAX_VALUE,5,Integer.MAX_VALUE,Integer.MAX_VALUE,Integer.MAX_VALUE},
           {Integer.MAX_VALUE,20,50,Integer.MAX_VALUE,Integer.MAX_VALUE},
           {Integer.MAX_VALUE,Integer.MAX_VALUE,Integer.MAX_VALUE,10,Integer.MAX_VALUE}
        };
        int ans[]=dijkstra(mat,0);
        System.out.println("Shortest distances:");
        for (int d : ans) {
            System.out.print(d+" ");
        }
    }
}