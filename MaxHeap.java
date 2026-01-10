class MaxHeap{
    //Up-Heapify
    static void insertIntoHeap(int []a,int i,int item){
        int ptr,par;
        ptr=i;//Current index
        while(ptr>0){
            par=(ptr-1)/2;//Parent index
            if(item<a[par]){
                a[ptr]=item;
                return;
            }
            a[ptr]=a[par];
            ptr=par;
        }
         a[ptr]=item;
    }
    //Down-Heapify
    static int deleteHeap(int a[],int n){
        int item,last,ptr,left,right;
        item=a[0];
        last=a[n];
        n--;
        ptr=0;
        left=1;
        right=2;
        while(right<=n){ 
            if(last>=a[left] && last>=a[right]){
                System.out.println("Execute");
                a[ptr]=last;//...
                return item;
            }
            //---//
            if(a[left]>=a[right]){
                a[ptr]=a[left];
                ptr=left;
            }
            else{
                a[ptr]=a[right];
                ptr=right;
            }
            left=ptr*2+1;//...
            right=left+1;
        }
        if(left==n && a[left]>=last){
            //only LEFT child
            a[ptr]=a[left];
            ptr=left;
        }
        a[ptr]=last;//if no left and no right
        return item;
    }
    static void heapSorting(int []a){
        int n=a.length;
        //Insert into heap
        for(int i=1;i<n;i++){
           insertIntoHeap(a,i,a[i]);
        }
        
        // delete from array
        while(n>0){
          int item=deleteHeap(a,n-1);
          a[n-1]=item;
          n--;
        } 
    }
    public static void main(String args[]){
       int a[] = {100, 90, 80, 70, 60, 50, 40};
       heapSorting(a);
       for(int i=0;i<a.length;i++){
        System.out.print(a[i]+" ");
       }
    }
}

