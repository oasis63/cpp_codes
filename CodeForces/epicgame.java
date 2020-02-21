import java.util.Scanner;

public class Test{
	static int gcd(int n1,int n2){
		if(n2==0)
			return n1;
		else
			return gcd(n2,n1%n2);
	}

	static void solve(int a,int b,int n,boolean sim){
		if(sim){
			if(n==0){
				System.out.println(1);
				return;
			}else{
				int g = gcd(a,n);
				n=n-g;
			}
		}else{
			if(n==0){
				System.out.println(0);
				return;
			}else{
				int g = gcd(b,n);
				n=n-g;
			}
		}
		solve(a,b,n,!sim);
	}

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);		
		int a = input.nextInt();
		int b = input.nextInt();
		int n = input.nextInt();

		solve(a,b,n,true);
	}
}