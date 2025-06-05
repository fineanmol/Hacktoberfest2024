
import java.util.*;
import java.io.*;
import java.math.*;

public class Main {
    // ArrayList<Integer> al = new ArrayList<>();
    // ArrayList<Pair<Integer, Integer>> al = new ArrayList<>();
    // Set<Integer> set = new TreeSet<>();
    // Pair<Integer, Integer> pair;
    // Map<Integer, Integer> map = new HashMap<>();
    // LinkedList<Integer> ll = new LinkedList<>();
    // for(Map.Entry<Integer,Integer> e:map.entrySet())pn(e.getKey()+"
    // "+e.getValue());
    // int n = c.i(), max = 0;
    // HashSet a[] = new HashSet[n], union = new HashSet<>(), ans = new
    // HashSet<>();for(
    // int i = 0;i<n;i++)
    // {
    // int k = c.i();
    // HashSet<Integer> set = new HashSet<>();
    // for (int j = 0; j < k; j++) {
    // int x = c.i();
    // set.add(x);
    // union.add(x);
    // }
    // a[i] = set;
    // }

    // pn(union);
    // for (int i = 0; i < n; i++) {
    // HashSet<Integer> curr = new HashSet<>();
    // for (int j = 0; j < n; j++) {
    // if (i == j)
    // continue;
    // curr.addAll(a[j]);
    // }
    // pn(curr);
    // if (curr.size() != union.size()) {
    // max = Math.max(max, curr.size());
    // ans = curr;
    // }
    // }
    // pn(ans);
    // pn(max);
    // *********************** Code Begins From Here*************************
    public static void solve() {
        int n = c.i(), k = c.i();
        long x = c.l();
        long sum = k * (k + 1L) >> 1, lastK = (n * (n + 1L) >> 1) - ((n - k) * (n - k + 1L) >> 1);
        if (sum <= x && lastK >= x) {
            pry();
            return;
        }
        prn();
    }

    public static void main(String[] args) throws FileNotFoundException {
        c = new FastScanner();
        pw = new PrintWriter(System.out);
        int tc = 1;
        tc = c.i();
        long start = System.currentTimeMillis();
        sieve(100);

        for (int i = 11; i < arr.length; i++)
            if (arr[i])
                primes.add(i);
        for (int t = 0; t < tc; t++) {
            // p("Case #" + (t + 1) + ": ");
            solve();
        }
        long end = System.currentTimeMillis();
        // if (System.getProperty("os.name").equals("Mac OS X")) {
        // pn("The Program takes " + (end - start) + "ms");
        // }
        pw.close();
    }

    // math util
    private static int lower(int a[], int x) {
        int l = 0, r = a.length - 1, mid, ans = 0;
        while (l <= r) {
            mid = l + ((r - l) >> 1);
            if (a[mid] <= x) {
                ans = max(ans, mid);
                l = mid + 1;
            } else
                r = mid - 1;
        }
        return ans;
    }

    private static int upper(int a[], int x) {
        int l = 0, r = a.length - 1, mid, ans = -1;
        while (l <= r) {
            mid = l + ((r - l) >> 1);
            if (a[mid] >= x) {
                ans = mid;
                r = mid - 1;
            } else
                l = mid + 1;
            // pn(l + " " + mid + " " + r);
        }
        return ans;
    }

    private static int cei(double d) {
        return (int) Math.ceil(d);
    }

    private static long ceil(double d) {
        return (long) Math.ceil(d);
    }

    private static int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    private static long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    private static int lcm(int a, int b) {
        return a * b / gcd(a, b);
    }

    private static int abs(int a, int b) {
        return (int) Math.abs(a - b);
    }

    private static int abs(int a) {
        return (int) Math.abs(a);
    }

    private static long abs(long a) {
        return (long) Math.abs(a);
    }

    private static long abs(long a, long b) {
        return (long) Math.abs(a - b);
    }

    private static int max(int a, int b) {
        if (a > b) {
            return a;
        } else {
            return b;
        }
    }

    private static int min(int a, int b) {
        if (a > b) {
            return b;
        } else {
            return a;
        }
    }

    private static long max(long a, long b) {
        if (a > b) {
            return a;
        } else {
            return b;
        }
    }

    private static long min(long a, long b) {
        if (a > b) {
            return b;
        } else {
            return a;
        }
    }

    private static void swap(int a, int b) {
        int c = a;
        a = b;
        b = c;
    }

    private static int pow(int base, int exp) {
        int result = 1;
        while (exp != 0) {
            if ((exp & 1) == 1)
                result *= base;
            exp >>= 1;
            base *= base;
        }
        return result;
    }

    private static long powerMod(long base, long exp, long mod) {
        long result = 1;
        base %= mod;
        while (exp > 0) {
            if ((exp & 1) != 0)
                result = (result * base) % mod;
            exp >>= 1;
            base = base * base % mod;
        }
        return result < 0 ? result + mod : result;
    }

    private static long addMod(long a, long b, long mod) {
        return (a % mod + b % mod) % mod;
    }

    private static long subMod(long a, long b, long mod) {
        return (a % mod - b % mod) % mod;
    }

    private static long mulMod(long a, long b, long mod) {
        return ((a % mod) * (b % mod)) % mod;
    }

    private static long pow(long base, long exp) {
        long result = 1;
        while (exp != 0) {
            if ((exp & 1) == 1)
                result = result * base;
            exp >>= 1;
            base *= base;
        }
        return result;
    }

    // array util
    private static void sortList(ArrayList<Integer> al) {
        Collections.sort(al);
    }

    private static void sortListP(ArrayList<Pair<Integer, Integer>> al) {
        Collections.sort(al);
    }

    private static void sort(int[] a) {
        ArrayList<Integer> al = new ArrayList<>();
        for (int e : a)
            al.add(e);
        sortList(al);
        int i = 0;
        for (int e : al)
            a[i++] = e;
    }

    private static void sort(double[] a) {
        ArrayList<Double> al = new ArrayList<>();
        for (double e : a)
            al.add(e);
        Collections.sort(al);
        int i = 0;
        for (double e : al)
            a[i++] = e;
    }

    private static void sort(char[] a) {
        ArrayList<Character> al = new ArrayList<>();
        for (char e : a)
            al.add(e);
        Collections.sort(al);
        int i = 0;
        for (char e : al)
            a[i++] = e;
    }

    private static void sort(long[] a) {
        ArrayList<Long> al = new ArrayList<>();
        for (long e : a)
            al.add(e);
        Collections.sort(al);
        int i = 0;
        for (long e : al)
            a[i++] = e;
    }

    private static int[] copy(int[] a) {
        int[] ans = new int[a.length];
        for (int i = 0; i < a.length; ++i)
            ans[i] = a[i];
        return ans;
    }

    private static char[] copy(char[] a) {
        char[] ans = new char[a.length];
        for (int i = 0; i < a.length; ++i)
            ans[i] = a[i];
        return ans;
    }

    private static long[] copy(long[] a) {
        long[] ans = new long[a.length];
        for (int i = 0; i < a.length; ++i)
            ans[i] = a[i];
        return ans;
    }
    // output

    public static void pn(Object o) {
        pw.println(o);
    }

    private static void p(Object o) {
        pw.print(o);
    }

    private static void pry() {
        pn("Yes");
    }

    private static void pY() {
        pn("YES");
    }

    private static void prn() {
        pn("No");
    }

    private static void pN() {
        pn("NO");
    }

    private static void flush() {
        pw.flush();
    }

    private static void watch(int[] a) {
        for (int e : a)
            p(e + " ");
        pn("");
    }

    private static void watch(long[] a) {
        for (long e : a)
            p(e + " ");
        pn("");
    }

    private static void watch(char[] a) {
        for (char e : a)
            p(e);
        pn("");
    }

    private static void watchList(ArrayList<Integer> al) {
        for (int e : al)
            p(e + " ");
        pn("");
    }

    private static Set<Integer> putSet(int[] a) {
        Set<Integer> set = new TreeSet<>();
        for (int e : a)
            set.add(e);
        return set;
    }

    private static boolean[] sieve(int n) {
        boolean[] isPrime = new boolean[n + 1];
        Arrays.fill(isPrime, true);
        isPrime[0] = false;
        isPrime[1] = false;
        for (int i = 2; i * i <= n; i++) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
        return isPrime;
    }

    static void permute(String s, String answer, ArrayList<Long> al) {
        if (s.length() == 0) {
            al.add(Long.parseLong(answer));
            return;
        }

        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            String left_substr = s.substring(0, i);
            String right_substr = s.substring(i + 1);
            String rest = left_substr + right_substr;
            permute(rest, answer + ch, al);
        }
    }

    private static boolean isPalindrome(String s) {
        int i = 0, j = s.length() - 1;
        while (i <= j)
            if (s.charAt(i++) != s.charAt(j--))
                return false;
        return true;
    }

    private static class Pair<U, V> implements Comparable<Pair<U, V>> {
        public final U first;
        public V second;

        public <U, V> Pair<U, V> makePair(U first, V second) {
            return new Pair<U, V>(first, second);
        }

        public Pair(U first, V second) {
            this.first = first;
            this.second = second;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) {
                return true;
            }
            if (o == null || getClass() != o.getClass()) {
                return false;
            }

            Pair pair = (Pair) o;

            return !(first != null ? !first.equals(pair.first) : pair.first != null)
                    && !(second != null ? !second.equals(pair.second) : pair.second != null);
        }

        @Override
        public int hashCode() {
            int result = first != null ? first.hashCode() : 0;
            result = 31 * result + (second != null ? second.hashCode() : 0);
            return result;
        }

        public Pair<V, U> swap() {
            return makePair(second, first);
        }

        @Override
        public String toString() {
            return "(" + first + "," + second + ")";
        }

        @SuppressWarnings({ "unchecked" })
        public int compareTo(Pair<U, V> o) {
            int value = ((Comparable<U>) first).compareTo(o.first);
            if (value != 0) {
                return value;
            }
            return ((Comparable<V>) second).compareTo(o.second);
        }
    }

    private static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner() throws FileNotFoundException {

            if (System.getProperty("os.name").equals("Mac OS X")) {
                // Input is a file
                br = new BufferedReader(new FileReader("input.txt"));

                // PrintWriter class prints formatted representations
                // of objects to a text-output stream.
                PrintStream pw = new PrintStream(new FileOutputStream("output.txt"));
                System.setOut(pw);
            } else {
                // Input is System.in
                br = new BufferedReader(new InputStreamReader(System.in), 32768);
                st = null;
            }
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int i() {
            return Integer.parseInt(next());
        }

        int[] intArray(int n) {
            int[] ret = new int[n];
            for (int i = 0; i < n; i++)
                ret[i] = i();
            return ret;
        }

        ArrayList<Integer> intList(int n) {
            ArrayList<Integer> al = new ArrayList<>();
            for (int i = 0; i < n; i++)
                al.add(i());
            return al;
        }

        long l() {
            return Long.parseLong(next());
        }

        long[] longArray(int n) {
            long[] ret = new long[n];
            for (int i = 0; i < n; i++)
                ret[i] = l();
            return ret;
        }

        ArrayList<Long> longList(int n) {
            ArrayList<Long> al = new ArrayList<>();
            for (int i = 0; i < n; i++)
                al.add(l());
            return al;
        }

        double d() {
            return Double.parseDouble(next());
        }

        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }

    private static boolean arr[] = sieve(1000001);
    private static ArrayList<Integer> primes = new ArrayList<>();
    private static int mod = (int) (1e9 + 7);
    private static final int IMAX = 2147483647;
    private static final int IMIN = -2147483648;
    private static final long LMAX = 9223372036854775807L;
    private static final long LMIN = -9223372036854775808L;
    private static FastScanner c;
    private static PrintWriter pw;
}