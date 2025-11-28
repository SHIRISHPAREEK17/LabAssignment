public class TwoSumSortedArray {
    public static void pairSearch(int arr[],int target){
        int i=0,j=arr.length-1;
        int sum=0;
        while(i<j){
           sum=arr[i]+arr[j];
            if(sum==target){
               System.out.println(
                "Target is " + target +
                " | Pair index: " + i + "," + j +
                " | Values: i-> " + arr[i] + " j-> " + arr[j]
               );
                return;
            }
            else if(sum<target){
              i++;
            }
            else{
                j--;
            }
        }
        System.out.println("Pair is not found for this target-> "+target); 
    }
    public static void main(String args[]){
      int arr1[]={1,2,7,9};//10 9,11,8,12
      pairSearch(arr1, 10);
      pairSearch(arr1, 9);
      pairSearch(arr1, 11);
      pairSearch(arr1, 8);
      pairSearch(arr1, 12);

    }
}
