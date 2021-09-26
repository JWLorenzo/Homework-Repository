//Jacob Lorenzo
public class CustomerOrder{
    String name, date;
    int quantity, balance;

    public CustomerOrder() {
    }
    public CustomerOrder(String name, String date, int quantity, int balance) {
        this.name = name;
        this.date = date;
        this.quantity = quantity;
        this.balance = balance;
    }
    public void ShipProduct(){
        if (getQuantity() > 0){
            setQuantity(getQuantity()-1);
        }else{
          System.out.println("Error: Quantity would become negative");
        }
    }
    public void PayBalance(int x){
        if (getBalance()-x >= 0){
            setBalance(getBalance()-x);
        }else{
            System.out.println("Error: Balance would become negative");
        }
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getDate() {
        return date;
    }

    public void setDate(String date) {
        this.date = date;
    }

    public int getQuantity() {
        return quantity;
    }

    public void setQuantity(int quantity) {
        this.quantity = quantity;
    }

    public int getBalance() {
        return balance;
    }

    public void setBalance(int balance) {
        this.balance = balance;
    }
    @Override
    public String toString(){
        return name + " " + date + " " + quantity + " " + balance;
    }
}
