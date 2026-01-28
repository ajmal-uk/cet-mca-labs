class ComplexNumber {
    private double real;
    private double imaginary;
    public ComplexNumber(double real, double imaginary) {
        this.real = real;
        this.imaginary = imaginary;
    }
    public ComplexNumber add(ComplexNumber other) {
        double newReal = this.real + other.real;
        double newImaginary = this.imaginary + other.imaginary;
        return new ComplexNumber(newReal, newImaginary);
    }
    
    public void display() {
        if (imaginary >= 0) {
            System.out.println(real + " + " + imaginary + "i");
        } else {
            System.out.println(real + " - " + (-imaginary) + "i");
        }
    }
    @Override
    public String toString() {
        if (imaginary >= 0) {
            return real + " + " + imaginary + "i";
        } else {
            return real + " - " + (-imaginary) + "i";
        }
    }
    public double getReal() {
        return real;
    }
    
    public double getImaginary() {
        return imaginary;
    }

    public static void main(String[] args) {
        ComplexNumber c1 = new ComplexNumber(3, 4);
        
        ComplexNumber c2 = new ComplexNumber(2, 5);
        
        ComplexNumber result = c1.add(c2);
        
        System.out.println("Complex Number 1: " + c1);
        System.out.println("Complex Number 2: " + c2);
        System.out.println("Sum: " + result);
        
        System.out.println("\n--- Another Example ---");
        ComplexNumber c3 = new ComplexNumber(5, -2);
        ComplexNumber c4 = new ComplexNumber(3, 6);
        ComplexNumber result2 = c3.add(c4);
        
        System.out.println("Complex Number 3: " + c3);
        System.out.println("Complex Number 4: " + c4);
        System.out.println("Sum: " + result2);
    }
}