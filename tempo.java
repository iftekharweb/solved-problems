import java.math.BigInteger;
import java.util.Scanner;
import java.io.IOException;

public class Main {
 
	private static final int MAXN = 150;
	private static BigInteger[] Fact, Q;
	private static Rational[] E, EQ;
	
	public static Rational p(int k, int n) {
		return new Rational(Q[k].multiply(new BigInteger(""+(n-k+1))),Fact[n]);
	}
	
	public static void precompute() {
		Fact = new BigInteger[MAXN+1];
		Fact[0] = BigInteger.ONE;
		for(int i=1;i<=MAXN;i++) Fact[i] = Fact[i-1].multiply(new BigInteger(""+i));
		
		Q = new BigInteger[MAXN+1];
		Q[0] = Q[1] = BigInteger.ZERO;
		Q[2] = BigInteger.ONE;
		for(int i=3;i<=MAXN;i++) Q[i] = Fact[i-2].multiply(new BigInteger(""+(i*i-3*i+3)));
		
		E = new Rational[MAXN+1];
		EQ = new Rational[MAXN+1];
		E[0] = E[1] = Rational.ZERO;
		Rational temp;
		for(int i=2;i<=MAXN;i++) {
			E[i] = Rational.ZERO;
			// for(int j=2;j<i;j++) E[i] = E[i].add(E[j].multiply(p(j,i)));
			for(int j=2;j<i;j++) E[i] = E[i].add(EQ[j].multiply(new BigInteger(""+(i-j+1))));
			E[i] = E[i].divide(Fact[i]);
			E[i] = E[i].add(Rational.ONE);
			temp = Rational.ONE;
			temp = temp.subtract(p(i,i));
			E[i] = E[i].divide(temp);
			EQ[i] = E[i].multiply(Q[i]);
		}
	}
	
	public static void main(String[] args) throws IOException {
		precompute();
		Scanner scanner = new Scanner(System.in);
		int t = scanner.nextInt();
		for(int tt=0;tt<t;++tt) {
			int n = scanner.nextInt();
			System.out.println(E[n]);
		}
	}
}

class Rational{
	public BigInteger x, y;
	public static final Rational ONE = new Rational(1);
	public static final Rational ZERO = new Rational(0);
	public Rational(int numerator, int denominator){
		x = new BigInteger(""+numerator);
		y = new BigInteger(""+denominator);
		normalize();
	}
	public Rational(int numerator){
		this(numerator, 1);
	}
	public Rational(BigInteger numerator){
		this(numerator, BigInteger.ONE);
	}
	public Rational(BigInteger numerator, BigInteger denominator){
		x = numerator;
		y = denominator;
		normalize();
	}
	public String toString(){
		if(y.equals(new BigInteger("1"))) return x.toString();
		return x+"/"+y;
	}
	public Rational multiply(BigInteger b) {
		return new Rational(x.multiply(b), y);
	}
	public Rational multiply(Rational b){
		return new Rational(x.multiply(b.x), y.multiply(b.y));
	}
	public Rational divide(BigInteger b) {
		return new Rational(x, y.multiply(b));
	}
	public Rational divide(Rational b){
		return new Rational(x.multiply(b.y), y.multiply(b.x));
	}
	public Rational add(Rational b){
		BigInteger X = x.multiply(b.y).add(y.multiply(b.x));
		BigInteger Y = y.multiply(b.y);
		return new Rational(X,Y);
	}
	public Rational negate(){
		return new Rational(x.negate(), y);
	}
	public Rational subtract(Rational b){
		return add(b.negate());
	}
	public void normalize(){
		BigInteger g = gcd(x.abs(), y.abs());
		x = x.divide(g);
		y = y.divide(g);
		if(!y.abs().equals(y)){
			x = x.negate();
			y = y.negate();
		}
	}
	private BigInteger gcd(BigInteger a, BigInteger b){
		while(!a.equals(BigInteger.ZERO)){
			BigInteger temp = b.mod(a);
			b = a;
			a = temp;
		}
		return b;
	}
}