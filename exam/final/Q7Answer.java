import java.util.*;
import java.io.*;

public class Q7Answer {
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);
    FileOutputStream fos = null;
    DataOutputStream dos = null;
    String s = sc.nextLine();
    int i = sc.nextInt();
    float f = sc.nextFloat();
    System.out.println(s);
    System.out.println(i);
    System.out.println(f);
    try {
      fos = new FileOutputStream(args[0]);
      /* dos = new DataOutputStream(fos); */
      /* dos = new DataOutputStream(fos); */
      dos = new DataOutputStream();
      dos.writeChars(s);
      dos.writeChars(Integer.valueOf(i).toString());
      dos.writeChars(Float.valueOf(f).toString());
    } catch(IOException e) {
      e.printStackTrace();
    }
  }
}
