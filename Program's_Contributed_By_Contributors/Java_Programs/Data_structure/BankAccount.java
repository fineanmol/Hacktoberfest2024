public class BankAccount {
    double balance;
    public void bankAccount(double initialBalance)
    {
        balance = 0.0;
    }
    public  Double deposit(double amount) 
    {
        if(amount > balance)
        {
            throw new InsufficientFundsException("Insufficiant Balance");
        }
        balance = balance-amount;
        return (balance);
    }
    public double getBalance(){
        balance = balance-amount;
        return (balance);
    }

}
class InsufficientFundsException extends Exception{
    InsufficientFundsException(String str){
        super(str);
    }
}
