package Prototype;

import java.util.PrimitiveIterator;

public class runner {
    public static void main(String[] args) {
        ProtoType pa = new ProtoType("pa");
        ProtoType pa_cy = pa.Clone();

        System.out.println(pa_cy.GetField());
    }
}
