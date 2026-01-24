class A {
    private A() {

    }
}

final class B {
    int x;
}

public class Main {
    public static void main(String[] args) {
        B b = new B();
        System.out.println(b.x);
    }
}
