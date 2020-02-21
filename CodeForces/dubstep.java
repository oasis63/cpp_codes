import java.util.Scanner;

public class Test{
    
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        String str = scn.nextLine();
        //String str = "WUBWEWUBAREWUBWUBTHEWUBCHAMPIONSWUBMYWUBFRIENDWUB";
        str = str.replaceAll("(WUB)"," ");
        str = str.replaceAll("[\" \"]+"," ");
        str = str.trim();
        System.out.println(str);
       
    }
}