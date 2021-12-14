package Java.PriorityQueues;
import java.util.*;

public class PriorityQueue <T extends  Comparable<T>>{
    
    //# of elements curr in heap
    private int heapSize = 0;

    //internal cap
    private int heapCapacity = 0;

    //Dynamic list for element storage
    private List<T> heap = null;

    /**
     * This data structure yields a mapping from each value 
     * in the list to its index (or indicies if there are
     * multiple instancees of the element). Allows for O(log(n))
     * removal since lookup is O(1) in HashMap as opposed to a 
     * O(n) linear look up without map leading to total O(nlog(n))
     * removal. This obviously comes at the cost of extra space to store
     * the map.
     */
    private Map<T, TreeSet<Integer>> map = new HashMap();

    public PriorityQueue(){ this(1); }

    public PriorityQueue(int size) {
        heap = new ArrayList<T>(size);
    
    }

    //Priority queue creation in O(n) time with heapify
    public PriorityQueue(T[] elems) {
        heapSize = heapCapacity = elems.length;
        heap = new ArrayList<T>(heapCapacity);
        //Insert elems into heap
        for(int i = 0; i < heapSize; i++)  {
            mapAdd(elems[i], i);
            heap.add(elems[i]);
        }
        //Heapify (occurs in O(n))
        //Start at last element above lowest level
        for (int i = Math.max(0, (heapSize/2)); i >= 0; i--) {
            sink(i);
        }
    }
    
    //Priority queue creation in O(nlogn) time complexity
    public PriorityQueue(Collection<T> elems) {
        this(elems.size());
        for(T elem: elems) add(elem); 
    }

    public boolean isEmpty() {
        return size() == 0; 
    }

    public void clear() {
        for(int i = 0; i < heapCapacity; i++) {
            heap.set(i, null);
        }
        heapSize = 0;
        map.clear();
    }

    public int size() {
        return heapSize;
    }

    public T peek() {
        if(isEmpty()) return null;

        return heap.get(0);
    }

    //removes root of heap. Time complexity of O(logn)
    public T poll() {
        return removeAt(0);
    }

    public boolean contains(T e) {
        if(e == null) return false;
        //hash map implemntation allows for O(1) lookup
        return map.containsKey(e);
    }

    //No null elements
    //Adds element to PQueue
    //O(logn)
    public void add(T e) {
        if(e == null) throw new IllegalArgumentException();
        if(heapSize < heapCapacity) heap.set(heapSize, e);
        else {
            heap.add(e);
            heapCapacity++;
        }

        mapAdd(e, heapSize);
        swim(heapSize);
        heapSize++;
    }

    // Returns true if node i <= node j
    //Does not check for valid indices, will have be done in calling function, O(1)
    private boolean less(int i, int j) {
        T node1 = heap.get(i);
        T node2 = heap.get(j);
        return node1.compareTo(node2) <= 0;
    }

    //bubble up O(logn)
    private void swim(int k) {

        //index of parents
        int parent = (k / 2) - 1;

        //Continue loop until parents is reached
        //OR k is greater than parent
        while(k > 0 && less(k, parent)) {
            swap(parent, k);
            k = parent;
        }

        //Get index of next parent
        parent = (k / 2) - 1;
    }

    //bubble down O(logn)
    private void sink(int k) {
        while(true) {
            int left = 2 * k + 1;
            int right = 2 * k + 2;
            int smallest = left; //Assume left is smallest 
            //If right is smaller, set smallest to right
            if(right < heapSize && less(right, left)) {
                smallest = right;
            }

            //if outside of tree bounds or k cannot be sunk anymore, break
            if( left >= heapSize || less(k, smallest)) break;

            swap(smallest, k);
            k = smallest;
        }
    }

    //Swap two nodes
    //Does not check for valid indices, will have be done in calling function, O(1)
    private void swap(int i, int j) {
        T iData = heap.get(i);
        T jData = heap.get(j);
        
        heap.set(i, jData);
        heap.set(j, iData);

        mapSwap(iData, jData, i, j);
    }

    public boolean remove(T e) {
        if(e == null) return false;

        //Remove with map yields O(logn)
        Integer i = mapGet(e);
        if(i != null) removeAt(i);
        return i != null;

        //Linear remove with by check all elements O(n)
        // for(int i = 0; i < heapSize; i++) {
        //     if(e.equals(heap.get(i))){
        //         removeAt(i);
        //         return true;
        //     }
        // }
    }

    private T removeAt(int i) {
        if(isEmpty()) return null;
         heapSize--;

        T removed = heap.get(i);
        swap(i, heapSize); //swap index to remove and last node

        //no remove the last node (which is now the node to remove after swap)
        heap.set(heapSize, null);
        mapRemove(removed, heapSize);


        if(i == heapSize) return removed; //removed last element

        T e = heap.get(i);
        sink(i);

        //Try bubble down, if nothing happened, bubble up
        if(heap.get(i).equals(e)) swim(i);

        return removed;
    }



    private void mapAdd(T val, int i) {
        TreeSet <Integer> set = map.get(val);


        //New val insertion
        if(set == null) {
            set = new TreeSet<>();
            set.add(i);
            map.put(val, set);
        }
        else set.add(i);

    }

    private void mapRemove(T val, int i) {
        TreeSet<Integer> set = map.get(val);
        set.remove(i); //TreeSets implemented with balanced BST, removal is O(logn)
        if(set.size() == 0) map.remove(val);
    }

    private Integer mapGet(T val) {
        TreeSet<Integer> set = map.get(val);
        if(set != null) return set.last();
        return null;
    }

    private void mapSwap(T val1, T val2, int val1I, int val2I) {
        Set<Integer> set1 = map.get(val1);
        Set<Integer> set2 = map.get(val2);

        set1.remove(val1I);
        set2.remove(val2I);

        set1.add(val2I);
        set2.add(val1I);
    }

    @Override public String toString() {
        return heap.toString();
    }
}

