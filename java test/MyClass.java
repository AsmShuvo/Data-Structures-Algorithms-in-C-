interface A {
    default void display() {
        System.out.println("Hello from interface A");
    }
}

interface B {
    default void display() {
        System.out.println("Hello from interface A");
    }
}

class C {
    int x;

    static void display() {
        System.out.println("Hello from class C");
        // this.x = 10; // Error: Cannot use 'this' in a static context
    }
}

class X {
    X() {
        this(1);
    }

    X(int a) {
        System.out.println("Value: " + a);
    }
}

class F {
    static final double PI;
    // if final value is static and uninitialized, it must be initialized in static
    // block
    // instance final variables must be initialized in constructor
    // static block cant initialize instance final variables
    final int data;

    F() {
        // PI = 3.14; // Error: Cannot assign a value to final variable PI here
        data = 100;
    }

    static {
        PI = 3.14;
        data = 200; // Error: Cannot assign a value to final variable data here
    }
}

public class MyClass implements A, B {
    public void display() {
        A.super.display();
        B.super.display();
    }

    public static void main(String[] args) {
        MyClass myClass = new MyClass();
        myClass.display();
    }
}
