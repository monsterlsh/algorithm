

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		 long []a = new long [21];
		a[1] = 1;
		a[2] = 2;
		a[3] = 5;
		for(int i = 4;i<=20;i++)
			a[i] =a[i-1]*(4*i-2)/(i+1);
		while(scanner.hasNext()) {
			int n = scanner.nextInt();
			System.out.println(a[n]);
		}
	}

}

