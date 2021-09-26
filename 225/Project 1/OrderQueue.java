//Jacob Lorenzo
public class OrderQueue<T> extends CustomerOrder implements Queue<T>{
    private LinkedNode<T> head;
    private LinkedNode<T> tail;
    private int size;
    private int stock;
    public OrderQueue(){
        head = null;
        tail = null;
        size = 0;
        stock = 0;
    }
    public OrderQueue(int x){
        head = null;
        tail = null;
        size = 0;
        stock = x;
    }
    public void AddOrder(T obj){
        enqueue(obj);
    }
    public void AddStock(int x){
        setStock(getStock()+x);
    }
    public void FulfillMost(){
        while (getStock()>0){
            FulfillOrder();
        }
    }
    public void ClearQueue(){
        head = null;
        tail = null;
        size = 0;
    }
    public void FulfillOrder(){
        if (getQuantity() <= 1){
            dequeue();
            setStock(getStock()-1);
        }else{
            setQuantity(getQuantity()-1);
            setStock(getStock()-1);
        }
    }
    public void ReduceBalance(int x){
        if (getBalance() - x >= 0){
            setBalance(getBalance()-x);
        }else{
            System.out.println("Error: Balance would become negative");
        }
    }

    @Override
    public void enqueue(T element) {	//O(1)
        LinkedNode<T> newNode = new LinkedNode<T>(element);
        if (!isEmpty()){
            tail.setNext(newNode);
            tail = tail.getNext();
        }
        else{
            head = newNode;
            tail = newNode;
        }
        size++;
    }

    @Override
    public T dequeue() {		//O(1)
        if (!isEmpty()){
            LinkedNode<T> returnedNode = head;
            head = head.getNext();
            size--;
            if (isEmpty()){
                tail = null;
            }
            return returnedNode.getElement();
        }
        else{
            return null;
        }
    }

    @Override
    public T getFront() {		//O(1)
        return head.getElement();
    }

    @Override
    public boolean isEmpty() {	//O(1)
        return head == null;
    }

    @Override
    public int size() {		//O(1)
        return size;
    }
    public int getStock() {
        return stock;
    }

    public void setStock(int stock) {
        this.stock = stock;
    }
    public int getQuantity() {
        return quantity;
    }

}