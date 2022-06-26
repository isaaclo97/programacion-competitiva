
import java.io.*;
import java.math.BigDecimal;
import java.util.Scanner;

public class main {

    static class Reader {
        final private int BUFFER_SIZE = 1 << 16;
        private DataInputStream din;
        private byte[] buffer;
        private int bufferPointer, bytesRead;

        public Reader()
        {
            din = new DataInputStream(System.in);
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }

        public Reader(String file_name) throws IOException
        {
            din = new DataInputStream(
                    new FileInputStream(file_name));
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }

        public String readLine() throws IOException
        {
            byte[] buf = new byte[64]; // line length
            int cnt = 0, c;
            while ((c = read()) != -1) {
                if (c == '\n') {
                    if (cnt != 0) {
                        break;
                    }
                    else {
                        continue;
                    }
                }
                buf[cnt++] = (byte)c;
            }
            return new String(buf, 0, cnt);
        }

        public int nextInt() throws IOException
        {
            int ret = 0;
            byte c = read();
            while (c <= ' ') {
                c = read();
            }
            boolean neg = (c == '-');
            if (neg)
                c = read();
            do {
                ret = ret * 10 + c - '0';
            } while ((c = read()) >= '0' && c <= '9');

            if (neg)
                return -ret;
            return ret;
        }

        public long nextLong() throws IOException
        {
            long ret = 0;
            byte c = read();
            while (c <= ' ')
                c = read();
            boolean neg = (c == '-');
            if (neg)
                c = read();
            do {
                ret = ret * 10 + c - '0';
            } while ((c = read()) >= '0' && c <= '9');
            if (neg)
                return -ret;
            return ret;
        }

        public double nextDouble() throws IOException
        {
            double ret = 0, div = 1;
            byte c = read();
            while (c <= ' ')
                c = read();
            boolean neg = (c == '-');
            if (neg)
                c = read();

            do {
                ret = ret * 10 + c - '0';
            } while ((c = read()) >= '0' && c <= '9');

            if (c == '.') {
                while ((c = read()) >= '0' && c <= '9') {
                    ret += (c - '0') / (div *= 10);
                }
            }

            if (neg)
                return -ret;
            return ret;
        }

        private void fillBuffer() throws IOException
        {
            bytesRead = din.read(buffer, bufferPointer = 0,
                    BUFFER_SIZE);
            if (bytesRead == -1)
                buffer[0] = -1;
        }

        private byte read() throws IOException
        {
            if (bufferPointer == bytesRead)
                fillBuffer();
            return buffer[bufferPointer++];
        }

        public void close() throws IOException
        {
            if (din == null)
                return;
            din.close();
        }
    }

    public static void main(String[] args) throws IOException {
        //Scanner in = new Scanner(System.in);
        Reader in = new Reader();
        BufferedWriter output = new BufferedWriter(new OutputStreamWriter(System.out));
        int n = in.nextInt();
        while (n!=0) {
            int m = in.nextInt();
            Double value = 3.0;
            BigDecimal res = new BigDecimal(1.0).setScale(m, BigDecimal.ROUND_DOWN);
            BigDecimal dividendo = new BigDecimal(1.0).setScale(m, BigDecimal.ROUND_DOWN);

            for(int i=1; i<n;i++){
                BigDecimal divisor = new BigDecimal(value).setScale(m, BigDecimal.ROUND_DOWN);
                divisor = dividendo.divide(divisor, BigDecimal.ROUND_DOWN).setScale(m, BigDecimal.ROUND_DOWN);
                if(i%2==0) res = res.add(divisor).setScale(m, BigDecimal.ROUND_DOWN);
                else res = res.subtract(divisor).setScale(m, BigDecimal.ROUND_DOWN);
                value+=2.0;
            }
            output.write(String.valueOf(res));
            if(m==0) output.write(".");
            output.write("\n");
            n = in.nextInt();
        }
        output.flush();
    }
}
