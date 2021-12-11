package Java.Stack;

public class StackLinkedList<T> implements Iterable<T> {
    private java.util.LinkedList<T> list = new java.util.LinkedList<T>();

    public StackLinkedList() {

    }

    public StackLinkedList(T firstE) {
        push(firstE);
    }

    public int size() {
        return list.size();
    }

    public boolean isEmpty() {
        return size() == 0;
    }

    public void push(T e) {
        list.addLast(e);
    }

    public T pop() {
        if(isEmpty()) throw new java.util.EmptyStackException();
        return list.removeLast();
    }

    public T peek() {
        if(isEmpty()) throw new java.util.EmptyStackException();
        return list.peekLast();
    }

    @Override public java.util.Iterator<T> iterator() {
        return list.iterator();
    }
    
}