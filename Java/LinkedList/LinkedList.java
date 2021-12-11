package Java.LinkedList;

public class LinkedList<T> implements Iterable <T>{
    private int size = 0;
    private Node<T> head = null;

    private class Node<T>  {
        T data;
        Node<T> next;
        public Node(T data, Node<T> next) {
            this.data = data;
            this.next = next;
        }

        @Override public String toString() {
            return data.toString();
        }

    }

    public void clear() {
        Node<T> temp = head;
        while(temp != null) {
            Node<T> next = temp.next;
            temp.next = null;
            temp.data = null;
            temp = next;
        }
        head = temp = null;
        size = 0;
    }

    public int size() {
        return size;
    }

    public boolean isEmpty(){
        return size() == 0;
    }
    
    //add to end
    public void add(T e) {
        if(isEmpty()) {
            head = new Node<T>(e, null);
            return;
        }
        Node<T> temp = head;
        while(temp.next != null) {
            temp = temp.next;
        }
        temp.next = new Node<T>(e, null);
        size++;
    }

    public T getFirst() {
        if(isEmpty()) throw new RuntimeException("Empty list");
        return head.data;
    }

    public T removeFirst() {
        if(isEmpty()) throw new RuntimeException("Empty list");
        T data = head.data;
        head = head.next;
        --size;
        return data;
    }

    private T remove(Node <T> node) {
        //temp store to return data
        T data = node.next.data;
        Node<T> temp = node.next;
        node.next = node.next.next; 
        //memory cleanup
        temp.data = null;
        temp = temp.next = null;
        --size;
        return data;
    }
    
    public T removeAt(int index) {
        if(index < 0 || index >= size) throw new IllegalArgumentException();
        int i;
        Node<T> temp;
        for(i = 0, temp = head; i != index - 1; i++) temp = temp.next;
        //send node previous to one that you want removed
        return remove(temp);
    }

    public boolean remove(Object obj) {
        Node<T> temp = head;
        //Null object deletion handling
        if(obj == null) {
            for(temp = head; temp != null; temp = temp.next){
                if(temp.data == null) {
                    remove(temp);
                    return true;
                }
            }
        } else {
            for(temp = head; temp != null; temp = temp.next) {
                if(obj.equals(temp.data)) {
                    remove(temp);
                    return true;
                }
            }
        }
        return false;
    } 

    public int indexOf(Object obj) {
        int index = 0;
        Node<T> temp = head;
        //check for null objects
        if(obj == null) {
            for(temp = head; temp != null; temp = temp.next, index++) {
                if(temp.data == null) return index;
            }
        } else {
            for(temp = head; temp != null; temp = temp.next, index++) {
                if(obj.equals(temp.data)) return index;
            }
        }
        return -1;
    }

    public boolean contains(Object obj) {
        return indexOf(obj) != -1;
    }

    @Override public java.util.Iterator<T> iterator() {
        return new java.util.Iterator<T> () {
            private Node<T> temp = head;
            @Override public boolean hasNext() { return temp != null; }
            @Override public T next() {
                T data = temp.data;
                temp = temp.next;
                return data;
            }
        };
    }

    @Override public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append("[");
        Node<T> temp = head;
        while(temp.next != null) {
            sb.append(temp.data + ", ");
            temp = temp.next;
        }
        sb.append(temp.next + " ]");
    }
}

