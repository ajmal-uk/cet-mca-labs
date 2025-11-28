print("<=== Bank Account Constructor And Methods ===>\n\n")

class BankAccount:
    def __init__(self, owner, balance):
        self.owner = owner
        self.balace = balance

    def desposite(self, amount):
        self.balace += amount
        print(f"{amount} Deposited Successfully. Balace : {self.balace}")
    
    def withdraw(self, amount):
        if self.balace< amount:
            print("Insufficient Balance")
        else:
            self.balace -= amount
            print(f"{amount} Withdrawed Successfully. Balace : {self.balace}")   

    def balance(self):
        print(f"Balace : {self.balace}")

    def display(self):
        print(f"Owner : {self.owner} and Balace : {self.balace}")


owner1 = BankAccount("Ajmal",1000)
owner2 = BankAccount("Amar",200)
owner3 = BankAccount("Abhinav",10)

print("\n\n<=== Printing the All User Details ===>\n")
owner1.display()
owner2.display()
owner3.display()

owner1.desposite(10000)
owner2.withdraw(100)
owner3.withdraw(1)

print("\n\n<=== Printing the All User Details After Moified===>\n")

owner1.display()
owner2.display()
owner3.display()


