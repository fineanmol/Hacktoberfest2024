import org.testng.Assert;
import org.testng.annotations.Test;

import java.util.Arrays;
import java.util.Collections;
import java.util.List;

public class FunctionalOne {

    @Test
    public void doubling() {
        Assert.assertEquals(doubling(Arrays.asList(1,2,3)), Arrays.asList(2,4,6));
        Assert.assertEquals(doubling(Arrays.asList(6,8,6,8,-1)), Arrays.asList(12,16,12,16,-2));
        Assert.assertEquals(doubling(Collections.emptyList()), Collections.emptyList());
    }

    @Test
    public void square() {
        Assert.assertEquals(square(Arrays.asList(1,2,3)), Arrays.asList(1,4,9));
        Assert.assertEquals(square(Arrays.asList(6,8,-6,-8,1)), Arrays.asList(36,64,36,64,1));
        Assert.assertEquals(square(Collections.emptyList()), Collections.emptyList());
    }

    @Test
    public void addStar() {
        Assert.assertEquals(addStar(Arrays.asList("a", "bb", "ccc")), Arrays.asList("a*", "bb*", "ccc*"));
        Assert.assertEquals(addStar(Arrays.asList("hello", "there")), Arrays.asList("hello*", "there*"));
        Assert.assertEquals(addStar(Arrays.asList("*")), Arrays.asList("**"));
    }

    @Test
    public void copies3() {
        Assert.assertEquals(copies3(Arrays.asList("a", "bb", "ccc")), Arrays.asList("aaa", "bbbbbb", "ccccccccc"));
        Assert.assertEquals(copies3(Arrays.asList("24", "a", "")), Arrays.asList("242424", "aaa", ""));
        Assert.assertEquals(copies3(Arrays.asList("hello", "there")), Arrays.asList("hellohellohello", "theretherethere"));
    }

    @Test
    public void moreY() {
        Assert.assertEquals(moreY(Arrays.asList("a", "b", "c")), Arrays.asList("yay", "yby", "ycy"));
        Assert.assertEquals(moreY(Arrays.asList("hello", "there")), Arrays.asList("yhelloy", "ytherey"));
        Assert.assertEquals(moreY(Arrays.asList("yay")), Arrays.asList("yyayy"));
    }

    @Test
    public void math1() {
        Assert.assertEquals(math1(Arrays.asList(1,2,3)), Arrays.asList(20,30,40));
        Assert.assertEquals(math1(Arrays.asList(6,8,6,8,1)), Arrays.asList(70,90,70,90,20));
        Assert.assertEquals(math1(Arrays.asList(10)), Arrays.asList(110));
    }

    @Test
    public void rightDigit() {
        Assert.assertEquals(rightDigit(Arrays.asList(1, 22, 93)), Arrays.asList(1, 2, 3));
        Assert.assertEquals(rightDigit(Arrays.asList(16, 8, 886, 8, 1)), Arrays.asList(6, 8, 6, 8, 1));
        Assert.assertEquals(rightDigit(Arrays.asList(10, 0)), Arrays.asList(0, 0));
    }

    @Test
    public void lower() {
        Assert.assertEquals(lower(Arrays.asList("Hello", "Hi")), Arrays.asList("hello", "hi"));
        Assert.assertEquals(lower(Arrays.asList("AAA", "BBB", "ccc")), Arrays.asList("aaa", "bbb", "ccc"));
        Assert.assertEquals(lower(Arrays.asList("KitteN", "ChocolaTE")), Arrays.asList("kitten", "chocolate"));
    }

    @Test
    public void noX() {
        Assert.assertEquals(noX(Arrays.asList("ax", "bb", "cx")), Arrays.asList("a", "bb", "c"));
        Assert.assertEquals(noX(Arrays.asList("xxax", "xbxbx", "xxcx")), Arrays.asList("a", "bb", "c"));
        Assert.assertEquals(noX(Arrays.asList("x")), Collections.singletonList(""));
    }

    // ------------------------------------------ Methods ------------------------------------------------- //

    public List<Integer> doubling(List<Integer> nums) {
        nums.replaceAll(n -> n * 2);
        return nums;
    }

    public List<Integer> square(List<Integer> nums) {
        nums.replaceAll(n -> n * n);
        return nums;
    }

    public List<String> addStar(List<String> strings) {
        strings.replaceAll(string -> string + "*");
        return strings;
    }

    public List<String> copies3(List<String> strings) {
        strings.replaceAll(string -> string + string + string);
        return strings;
    }

    public List<String> moreY(List<String> strings) {
        strings.replaceAll(string -> "y" + string + "y");
        return strings;
    }

    public List<Integer> math1(List<Integer> nums) {
        nums.replaceAll(num -> (num + 1) * 10);
        return nums;
    }

    public List<Integer> rightDigit(List<Integer> nums) {
        nums.replaceAll(num -> num % 10);
        return nums;
    }

    public List<String> lower(List<String> strings) {
        strings.replaceAll(String::toLowerCase);
        return strings;
    }

    public List<String> noX(List<String> strings) {
        strings.replaceAll(string -> string.replace("x", ""));
        return strings;
    }
}
