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

	public void start() {
		BigInteger a = in.nextBigInteger();
		BigInteger low = BigInteger.ONE;
		BigInteger high = a;
		BigInteger two = BigInteger.ONE.add(BigInteger.ONE);
		BigInteger mid = low.add(high).divide(two);
		while (low.compareTo(high) <= 0) {
			if (mid.multiply(mid).compareTo(a) > 0) {
				high = mid.subtract(BigInteger.ONE);
			} else {
				low = mid.add(BigInteger.ONE);
			}
			mid = low.add(high).divide(two);
		}
		out.println(high);
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
	public BigInteger nextBigInteger() {
		return new BigInteger(next());
	}
	public String nextLine() {
		try {
			return reader.readLine();
		} catch (IOException e) {
			throw new IOError(e);
		}
	}
}
