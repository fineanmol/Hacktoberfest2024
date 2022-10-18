class ThreeSum {
    public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        Set<List<Integer>> result = new HashSet<>();
        for (int i = 0; i < nums.length - 1; i++) {
            int one = nums[i];
            for (int j = i; j < nums.length; j++) {
                if (i == j) continue;
                int two = nums[j];
                int three = 0 - one - two;
                int idxThree = Arrays.binarySearch(nums, three);
                if (idxThree >= 0 && idxThree != i && idxThree != j) {
                    List<Integer> list = new ArrayList<>();
                    if (three <= one) {
                        list.add(three);
                        list.add(one);
                        list.add(two);
                    } else if (three <= two) {
                        list.add(one);
                        list.add(three);
                        list.add(two);
                    } else {
                        list.add(one);
                        list.add(two);
                        list.add(three);
                    }
                    result.add(list);
                }
            }
        }
        return new ArrayList<>(result);
    }
}
