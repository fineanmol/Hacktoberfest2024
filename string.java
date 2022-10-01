//string class can not give to permission to change their data
//in this we can only check that what character is an in which index it is present
public class norstring h {

    public static void main(String[] args)
    {
        String str1=new String("test string");
        System.out.println("the str1 is = "+str1);

        String str2 =new String(str1);
        System.out.println("str2 is = "+str2);

        String str3=new String();
        System.out.println("the str3 is = "+str3);

        String str4 =new String("another string");
        System.out.println("the last string is = "+str4);

        System.out.println("the str1 length is = "+str1.length());
        System.out.println("the str2 length is = "+str2.length());
        System.out.println("the str3 length is = "+str3.length());
        System.out.println("the str4 length is = "+str4.length());

        System.out.println("String1 character at 3 = "+str1.charAt(3));
        System.out.println("String1 index of character t = "+str1.indexOf('t'));
        System.out.println("string1 last index of character t = "+str1.lastIndexOf('t'));
        System.out.println("the string starting from index i to lastchr = "+str1.substring(0,9));
        System.out.println("string1 substring from index 1 to lastchr = "+str1.substring(0));

        if(str1==str2)
        {
            System.out.println("euqal");
        }
        else
        {
            System.out.println("not equal");
        }

        System.out.println(str1.equals(str2));
    }
}
