import java.util.*;

public class Polynomial {
    private int maxExp;
    private double[] coefArray;
    static Scanner in;

    Polynomial() {
        maxExp = 0;
        coefArray = new double[101];
    }

    public Polynomial multi(Polynomial b) {
        Polynomial c = new Polynomial();
        c.maxExp = maxExp+b.maxExp;
        for(int i=0; i<=maxExp; i++){
            for(int j=0; j<=b.maxExp; j++){

                double temp = coefArray[i] * b.coefArray[j];
                c.coefArray[i+j] += temp;
            }
        }
        return c;
    }

    public void print(){
        String s = "c = ";
        for(int i=maxExp; i>=0; i--){
            if(coefArray[i] != 0){
                s += coefArray[i] + "x^" + i + " + ";
            }
        }
        s = s.substring(0, s.length()-2);
        System.out.println(s);
    }

    public static void main(String[] args){
        in = new Scanner(System.in);
        Polynomial a = new Polynomial();
        Polynomial b = new Polynomial();

        InitPolynomial(a, "a");
        System.out.println();
        InitPolynomial(b, "b");

        Polynomial c = new Polynomial();
        System.out.println();
        c = a.multi(b);
        c.print();
    }

    static void InitPolynomial(Polynomial p, String msg) {
        System.out.println("Init Polynomial " + msg);
        double coef;
        int exp;
        while (true) {
            System.out.println("Enter a term (coef, exp)");
            coef = in.nextDouble();
            exp = in.nextInt();
            if(exp == -1) {
                return;
            }
            p.coefArray[exp] = coef;
            p.maxExp = Math.max(exp, p.maxExp);
        }
    }
}