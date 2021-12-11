package Java.Queue;

public class QueueLinkedList<T> implements Iterable<T> {
    private java.util.LinkedList<T> list = new java.util.LinkedList<T>();

    public QueueLinkedList() {

    }

    public QueueLinkedList(T firstE) {
        enqueue(firstE);
    }

    public int size(){
        return list.size();
    }

    public boolean isEmpty() {
        return size() == 0;
    }

    public T peek() {
        if(isEmpty()) throw new RuntimeException("Queue empty");
        return list.peekFirst();
    }

    public T dequeue() {
        if(isEmpty()) throw new RuntimeException("Queue empty");
        return list.removeFirst();
    }

    public void enqueue(T e) {
        list.addLast(e);
    }

    @Override public java.util.Iterator <T> iterator() {
        return list.iterator();
    }
}
