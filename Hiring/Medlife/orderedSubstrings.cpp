import java.io.*;
import java.util.*;

public
class TestClass {
  public
    static void main(String[] args) throws IOException {
        BufferedReader br =
            new BufferedReader(new InputStreamReader(System.in));
        PrintWriter wr = new PrintWriter(System.out);
        int T = Integer.parseInt(br.readLine().trim());
        for (int t_i = 0; t_i < T; t_i++) {
            String X = br.readLine().trim();
            int out_ = find_rank(X);
            wr.println(out_);
        }

        wr.close();
        br.close();
    }

    static int find_rank(String str) {

        int n = str.length();

        List<String> list = new ArrayList();
        list.clear();

        for (int i = 0; i < n; i++) {
           if(!list.contains(str.charAt(i)+"")
                list.add(str.charAt(i)+"");
        }

        for (int i = 1; i <= n; i++) {
            String sub1 = new String(str.charAt(i - 1) + "");
            // string sub2=str[i-1]+"";
            for (int j = i + 1; j <= n; j++) {
                sub1 += str.charAt(j - 1) + "";
                //  System.out.println(sub1);
                list.add(sub1);
                if (str.charAt(i - 1) != str.charAt(j - 1)) {
                    String temp = str.charAt(i - 1) + str.charAt(j - 1) + "";
                    // System.out.println(temp);
                    list.add(temp);
                }
            }
        }

        int index = 0;
        Collections.sort(list);

        for (String s : list) {
            index++;
            System.out.print(s + " ");
            if (s == str) {
                // break;
            }
        }

        System.out.println("\n");

        return index;
    }
}

/*

  2
  eren
  acb

  5
  3

*/