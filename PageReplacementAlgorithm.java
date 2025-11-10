/* 
 * Write a program to simulate the FIFO, LRU,  OPTIMAL, LFU and MFU page replacement 
 * algorithms for a user specified number of frames. Generate a random reference string of length 20 
 * addresses and compute the number of page faults for each.
 */
import java.util.*;
class Algorithms{

    static boolean search(int target, int[] fr){
        for (int page : fr) {
           if (page == target) 
                return true;
            
       }
         return false;
    }

    static int firstInFirtOut(int arr[],int frameSize){
        Set   <Integer>   frames = new HashSet<>();
        Queue <Integer>   queue  = new LinkedList<>();
        int pageFaults = 0;
        
        for(int page:arr){
            if(!frames.contains(page)){
                if(frames.size()==frameSize){
                    int removed=queue.poll();
                    frames.remove(removed);
                }
                 frames.add(page);
                 queue.add(page);
                 pageFaults++;
            }
        }
         return pageFaults;
    }
    //need future information it disadvantage
    static int optimal(int arr[],int frameSize){
        int[] frames = new int[frameSize];
        Arrays.fill(frames, -1);
        int pageFaults = 0;

        for (int i = 0; i < arr.length; i++) {
             if (!search(arr[i], frames)) {
                 pageFaults++;

                 int emptyFrame = -1;
                for (int j = 0; j < frameSize; j++) {
                   if (frames[j] == -1) {
                     emptyFrame = j;
                      break;
                   }
               }

               if (emptyFrame != -1) {
                  frames[emptyFrame] = arr[i];
                } 

             else {
                int future = -1;
                int replace = -1;
                for (int f = 0; f < frameSize; f++) {
                    int j;
                    for (j = i + 1; j < arr.length; j++) {
                        if (frames[f] == arr[j]) break;
                    }
                    if (j > future) {
                        future = j;
                        replace = f;
                    }
                }
                frames[replace] = arr[i];
            }
           }
        }
        return pageFaults;
    }
    static int leastRecentlyUsed(int arr[],int frameSize){
       LRUCache lru = new LRUCache(frameSize);
       for (int page : arr) {
           lru.accessPage(page);
        }
         return lru.pageFaults; 
    }
}
public class PageReplacementAlgorithm {
    public static void main(String args[]){
        int arr[]  =new int[20];
        Random ran=new Random();
        Scanner sc=new Scanner(System.in); 

        System.out.println("Enter frame size" + " it should be less: "+arr.length);
       
        int frameSize=sc.nextInt();
        if(frameSize>arr.length){
            System.err.println("It should be less "+arr.length);
            System.exit(0);
        }
    
        for(int i=0;i<arr.length;i++){
           arr[i]=ran.nextInt(11);
        }

        System.out.print("Refrence String:->");
        for(int i:arr){
           System.out.print(i+" ");
        }
        System.out.println("\n Page Fault in first in first out: -> "+Algorithms.firstInFirtOut(arr,frameSize));
        System.out.println("Page Fault in lru: -> "+Algorithms.leastRecentlyUsed(arr,frameSize));
        System.out.println("Page Fault in optimal: -> "+Algorithms.optimal(arr,frameSize));
    }
}
