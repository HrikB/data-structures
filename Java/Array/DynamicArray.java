package Java;
public class DynamicArray<T> implements Iterable<T> {
    private T[] arr;
    private int len = 0;
    private int capacity = 0;

    public DynamicArray() { this(16); }

    private DynamicArray(int capacity) {
        if(capacity < 0) throw new IllegalArgumentException("Illegal Capacity: " + capacity);
        this.capacity = capacity;
        arr = (T[]) new Object[capacity];
    }

    public int size() { return len; }
    public boolean isEmpty() { return size() == 0; }
    
    public T get(int index) { return arr[index]; }
    public void set(int index, T e) { arr[index] = e; }

    public void clear() {
        for(int i = 0; i < arr.length; i++) {
            arr[i] = null;
        }
        len = 0;
    }

    public void add(T e) {
        if(len + 1 >= capacity) { //resize
            if(capacity == 0) capacity = 1;
            else capacity *= 2;
            T[] new_arr = (T[]) new Object[capacity];
            for (int i = 0; i < arr.length; i++) {
                new_arr[i] = arr[i];
            }
            arr = new_arr;
        }
        arr[len++] = e;
    } 

    public T removeAt(int index) {
        if(index >= len || index < 0) throw new IndexOutOfBoundsException();
        T finalElem = arr[index];
        for(int i = index; i < arr.length; i++) {
            arr[i] = arr[i + 1];
        }
        len--;
        return finalElem;
    }

    public boolean remove(Object obj) {
        for(int i = 0; i < arr.length; i++) {
            if(arr[i].equals(obj)) {
                removeAt(i); return true;
            }
        }
        return false;
    }

    public int indexOf(Object obj) {
        for(int i = 0; i < arr.length; i++) {
            if(arr[i].equals(obj)) return i;
        }
        return -1;
    }

    public boolean contains(Object obj) {
        return indexOf(obj) != -1;
    }

    @Override public java.util.Iterator<T> iterator() {
        return new java.util.Iterator<T> () {
            int index = 0;
            public boolean hasNext() { return index < len; }
            public T next() { return arr[index++]; }
        };
    }

    @Override public String toString() {
        if(len == 0) { return "[]"; }
        StringBuilder sb = new StringBuilder(len).append("[");
        for(int i = 0; i < arr.length - 1; i++) {
            sb.append(arr[i] + ", ");
        }
        return sb.append(arr[len - 1] + "]").toString();
    } 
}