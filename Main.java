interface A {
    void call();

    void show();
}

abstract class C implements A {
    public void call() {
        System.out.println("Call from C");
    }
    // show() is not implemented here, making C abstract
}

class X extends C {
    public void show() {
        System.out.println("Show from A");
    }
}

public class Main {
    public static void main(String[] args) {
        A a = new B();
        a.call();
        a.show();
        B b = new B();
        b.call();
        b.show();
        b.show(6);

    }
}
