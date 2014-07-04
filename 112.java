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
		int a = in.nextInt(), b = in.nextInt();
		out.println(pow(a, b).subtract(pow(b, a)));
	}

	public BigInteger pow(int x, int y) {
		return BigInteger.valueOf(x).pow(y);
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
