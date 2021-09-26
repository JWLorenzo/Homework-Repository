//Jacob Lorenzo
public class LinkedNode<T> {
    private T element;
    private int stock;
    private LinkedNode<T> next;

    public LinkedNode(){
        element = null;
        next = null;
    }

    public LinkedNode(T element){
        this.element = element;
        next = null;
    }

    public LinkedNode(int stock){
        this.stock = stock;
        element = null;
        next = null;
    }

    public T getElement() {
        return element;
    }

    public void setElement(T element) {
        this.element = element;
    }

    public LinkedNode<T> getNext() {
        return next;
    }

    public void setNext(LinkedNode<T> next) {
        this.next = next;
    }
}