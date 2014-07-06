import java.util.*;
import java.io.*;
import java.math.*;

class Solution {
	public static void main(String[] args) {
		Solution value = new Solution();
		value.start();
		value.out.close();
	}
	InputStream inputStream = System.in;
	OutputStream outputStream = System.out;
	InputReader in = new InputReader(inputStream);
	PrintWriter out = new PrintWriter(outputStream);

	public BigInteger[] a = new BigInteger[40];

	public void start() {
		a[0] = BigInteger.ONE;
		int n = in.nextInt();
		for (int i = 1; i <= n; i++) {
			a[i] = BigInteger.ZERO;
			for (int j = 0; j < i; j++) {
				a[i] = a[i].add(a[j].multiply(a[i - j - 1]));
			}
		}
		out.println(a[n] + " " + (n + 1));
	}
}

class InputReader {
	private BufferedReader reader;
	private StringTokenizer tokenizer;
	public InputReader(InputStream stream) {
		reader = new BufferedReader(new InputStreamReader(stream));
		tokenizer = null;
	}
	public boolean hasNext() {
		try {
			while (tokenizer == null || !tokenizer.hasMoreTokens()) {
				String str = nextLine();
				if (str == null) {
					return false;
				}
				tokenizer = new StringTokenizer(str);
			}
		} catch (IOError e) {
			return false;
		}
		return true;
	}
	public String next() {
		if (hasNext()) {
			return tokenizer.nextToken();
		} else {
			return null;
		}
	}
	public int nextInt() {
		return Integer.parseInt(next());
	}
	public double nextDouble() {
		return Double.parseDouble(next());
	}
	public long nextLong() {
		return Long.parseLong(next());
	}
	public String nextLine() {
		try {
			return reader.readLine();
		} catch (IOException e) {
			throw new IOError(e);
		}
	}
}
