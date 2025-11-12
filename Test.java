public class Test {

    String telephone = "Telephone 1"; // global var

    void Room1() {
        String phone = "Iphone 13 Pro Max"; // local to Room1
        System.out.println("I can use " + phone + " " + telephone);
    }

    void Room2() {
        // local to Room2
        String phone1 = "iPhone x", phone2 = "Samsung";
        System.out.println("Mom can use: " + phone1 + " " + phone2 + " " + telephone); // mom
        System.out.println("Dad can use: " + phone1 + " " + phone2); // dad
    }

    void Room3() {
        String telephone = "New Telephone"; // variable overriden
        System.out.println(telephone); // New Telephone
    }

    public static void main(String[] args) {
        System.out.println("mad");
    }
}