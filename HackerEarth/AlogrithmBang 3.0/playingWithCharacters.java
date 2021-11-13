import java.io.BufferedReader;
import java.io.InputStreamReader;


public class zCheck {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n =  Integer.parseInt(br.readLine());
        String str = br.readLine();

        str = str.replace("a","$");
        str = str.replace("b","&");
        str = str.replace("c","#");

        //System.out.println(str);

        int ans = 0;
        for(int i=0;i<str.length();i++){
            ans += Integer.valueOf(str.charAt(i));
        }

        System.out.println(ans);
    }
}
