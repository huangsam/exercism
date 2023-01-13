public class DoublyLinkedList<T> {

    private ListNode<T> head = null;
    private ListNode<T> tail = null;

    public DoublyLinkedList() {
    }

    private boolean isEmpty() {
        return head == null && tail == null;
    }

    private void setHeadTail(ListNode<T> node) {
        head = tail = node;
    }

    public void push(T item) {
        ListNode<T> node = new ListNode<T>(item);

        if (isEmpty()) {
            setHeadTail(node);
            return;
        }

        node.setPrev(tail);
        tail.setNext(node);
        tail = node;
    }

    public T pop() {
        T result = tail.getValue();
        ListNode<T> prev = tail.getPrev();

        if (prev != null) {
            prev.setNext(null);
            tail.setPrev(null);
        }

        tail = prev;
        return result;
    }

    public T shift() {
        T result = head.getValue();
        ListNode<T> next = head.getNext();

        if (next != null) {
            next.setPrev(null);
            head.setNext(null);
        }

        head = next;
        return result;
    }

    public void unshift(T item) {
        ListNode<T> node = new ListNode<T>(item);

        if (isEmpty()) {
            setHeadTail(node);
            return;
        }

        node.setNext(head);
        head.setPrev(node);
        head = node;
    }

}

class ListNode<T> {

    private T value;
    private ListNode<T> next = null;
    private ListNode<T> prev = null;

    ListNode(T item) {
        value = item;
    }

    public T getValue() {
        return value;
    }

    public ListNode<T> getNext() {
        return next;
    }

    public void setNext(ListNode<T> n) {
        next = n;
    }

    public ListNode<T> getPrev() {
        return prev;
    }

    public void setPrev(ListNode<T> p) {
        prev = p;
    }

}
