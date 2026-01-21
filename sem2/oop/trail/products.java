class products {
    private int p_code;
    private String p_name;
    private int p_price;

    public products(int code, String name, int price) {
        this.p_code = code;
        this.p_name = name;
        this.p_price = price;
    }

    public int getCode() {
        return this.p_code;
    }

    public String getName() {
        return this.p_name;
    }

    public int getPrice() {
        return this.p_price;
    }
}

class main{
    public static void main(String[] args) {
        products p1 = new products(1, "Biscut", 100);
        products p2 = new products(2, "Biriyani", 400);
        products p3 = new products(3, "Mandhi", 600);

        if (p1.getPrice() < p2.getPrice()) {
            if(p1.getPrice() < p3.getPrice()){
                System.out.println(p1.getName() + "\t" + p1.getCode() + "\t" +  p1.getPrice());
            }
            else{
                System.out.println(p3.getName() + "\t" +  p3.getCode() + "\t" + p3.getPrice());
            }
        }else{
            if(p2.getPrice() < p3.getPrice()){
                System.out.println(p2.getName() + "\t" + p2.getCode() + "\t" + p2.getPrice());
            }
            else{
                System.out.println(p3.getName() + "\t" + p3.getCode() + "\t" + p3.getPrice());
            }
        }
    }
}
