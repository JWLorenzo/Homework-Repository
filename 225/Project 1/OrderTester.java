//Jacob Lorenzo
public class OrderTester{
    public static void main(String[] args) {
        OrderQueue<CustomerOrder> q = new OrderQueue<>(12);
        CustomerOrder a = new CustomerOrder("Janet","4/16/20",3,100);
        CustomerOrder b = new CustomerOrder("John","4/16/20",5,50);
        CustomerOrder c = new CustomerOrder("Jerry","4/16/20",8,70);
        CustomerOrder d = new CustomerOrder("Jacob","4/16/20",2,80);
        CustomerOrder e = new CustomerOrder("Jack","4/16/20",2,40);
        CustomerOrder f = new CustomerOrder("Janice","4/16/20",3,90);
        q.AddOrder(a);
        q.AddOrder(b);
        q.AddOrder(c);
        q.getFront().PayBalance(100);
        q.getFront().PayBalance(100);
        //I couldn't get the Fulfill functions to work
        // I can't reference the object elements inside the class for some reason
        q.setStock(22);
        q.AddStock(10);
        q.ClearQueue();
    }
}
