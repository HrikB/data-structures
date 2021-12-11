package Java.LinkedList;

public class DoublyLinkedList<T> implements Iterable<T> {
    private int size = 0;
    private Node<T> head = null;
    private Node<T> tail = null;

    private class Node<T> {
        T data;
        Node<T> prev, next;
        public Node(T data, Node<T> prev, Node<T> next) {
            this.data = data;
            this.prev = prev;
            this.next = next;
        }
        @Override public String toString() {
            return data.toString();
        }
    }

    public void clear(){
        Node<T> temp = head;
        while(temp != null) {
            Node<T> next = temp.next;
            temp.prev = temp.next = null;
            temp.data = null;
            temp = next;
        }
        head = tail = temp = null;
        size = 0;
    }

    public int size() {
        return size;
    }

    public boolean isEmpty() {
        return size() == 0;
    }

    public void add(T e){
        addLast(e);
    }

    public void addFirst(T e) {
        if (isEmpty()) {
            head = tail = new Node<T> (e, null, null);
        } else {
            head.prev = new Node<T> (e, null, head);
            head = head.prev;
        }

        size++;
    }

    public void addLast(T e) {
        if(isEmpty()) {
            head = tail = new Node<T> (e, null, null);
        } else {
            tail.next = new Node<T> (e, tail, null);
            tail = tail.next;
        }
        size++;
    }

    public T getFirst() {
        if(isEmpty()) throw new RuntimeException("Empty List");   
        return head.data;
    }

    public T getLast() {
        if(isEmpty()) throw new RuntimeException("Empty list");
        return tail.data;
    }

    public T removeFirst() {
        if(isEmpty()) throw new RuntimeException("Empty list");
        T data = head.data;
        head = head.next;
        --size;
        if(isEmpty()) tail = null;
        else head.prev = null;
        return data;
    }

    public T removeLast() {
        if(isEmpty()) throw new RuntimeException("Empty list");
        T data = tail.data;
        tail = tail.prev;
        --size;
        if(isEmpty()) tail = null;
        else tail.next = null;
        return data;
    }

   private T remove(Node <T> node){
        if(node.prev == null) return removeFirst();
        if(node.next == null) return removeLast();
        //"skip" node
        node.next.prev = node.prev;
        node.prev.next = node.next;
        //temp store for data to return
        T data = node.data;
        //memory cleanup
        node.data = null;
        node = node.prev = node.next = null;
        --size;
        return data;
   }

   public T removeAt(int index) {
        if(index < 0 || index >= size) throw new IllegalArgumentException();
        int i;
        Node<T> temp;
        //Search front
        if (index < size / 2) {
            for(i = 0, temp = head; i != index; i++) temp = temp.next;
        } else { //Search back of list
            for(i = size - 1, temp = tail; i != index; i--) temp = temp.prev;
        }
        return remove(temp);
   }

   public boolean remove(Object obj) {
        Node <T> temp = head;
        //Need to be able delete null objects
        if(obj == null) {
            for(temp = head; temp != null; temp = temp.next) {
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
       Node <T> temp = head;
        //Check for null objects
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
           private Node <T> temp = head;
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
       return sb.toString();
   }
}
